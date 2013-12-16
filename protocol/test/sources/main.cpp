#include	<map>
#include	<iostream>
#include	<iomanip>
#include	<vector>
#include	<typeinfo>
#include	<boost/asio.hpp>
#include	<boost/bind.hpp>
#include	<boost/array.hpp>
#include	<boost/thread.hpp>
#include	<boost/shared_ptr.hpp>
#include	<boost/enable_shared_from_this.hpp>
#include	"types.hh"
#include	"RequestCode.hh"
#include	"AuthRequest.hh"
#include	"CallRequest.hh"
#include	"Protocol.hpp"
#include	"Bridge.hh"
#include	"FakeAudio.hh"

static unsigned short	g_portTCP;
static unsigned short	g_server_portUDP;
static unsigned short	g_receiver_portUDP;
static unsigned long	g_udp_ip_receiver;

using boost::asio::ip::tcp;
using boost::asio::ip::udp;

static std::string g_client = "";
static std::string g_client_join = "";

class		client : public boost::enable_shared_from_this<client>
{
public:
  typedef boost::shared_ptr<client> Ptr;

public:
  static Ptr create(boost::asio::io_service& io_service, const std::string &ip, const std::string &portTCP, const std::string &portUDP)
  {
    Ptr new_client(new client(io_service));
    new_client->connect(ip, portTCP);
    new_client->openUdp(portUDP);

    return (new_client);
  }

public:
  client::Ptr	ptr()
  {
    return (shared_from_this());
  }

  void	writeTCP(const std::vector<Protocol::Byte> &data)
  {

    boost::asio::async_write(_tcpSock, boost::asio::buffer(data),
			     boost::bind(&client::write_tcp_handler,
					 shared_from_this(),
					 boost::asio::placeholders::error,
					 boost::asio::placeholders::bytes_transferred));
  }

  void	readTCP()
  {
    _tcpSock.async_read_some(boost::asio::buffer(_arr),
			     boost::bind(&client::read_tcp_handler,
					 shared_from_this(),
					 boost::asio::placeholders::error,
					 boost::asio::placeholders::bytes_transferred));
  }

  void	writeUDP()
  {
    std::vector<Protocol::Byte>	data;
    udp::endpoint receiver_endpoint (boost::asio::ip::address_v4(g_udp_ip_receiver),
				     g_receiver_portUDP);

    data.assign(40, 0);
    _udpServerSock.send_to(boost::asio::buffer(data), receiver_endpoint);
    _t.expires_from_now(boost::posix_time::seconds(5));
    _t.async_wait(boost::bind(&client::writeUDP,
			      shared_from_this()));
  }

  void	readUDP()
  {
    _udpServerSock.async_receive(boost::asio::buffer(_udp),
				 boost::bind(&client::read_udp_handler,
					     shared_from_this(),
					     boost::asio::placeholders::error,
					     boost::asio::placeholders::bytes_transferred));
  }

  void	startAudio()
  {
    _audio.run();
    _t.expires_from_now(boost::posix_time::seconds(5));
  }

private:
  explicit client(boost::asio::io_service& io_service) :
    _service(io_service), _tcpSock(io_service), _udpClientSock(io_service),_udpServerSock(io_service),
    _t(io_service), _audio(_bridge)
  {
  }

  void	connect(const std::string &ip, const std::string &port)
  {
    tcp::resolver		resolver(_service);
    tcp::resolver::query	query(ip, port);
    tcp::resolver::iterator	endpoint_iterator = resolver.resolve(query);

    boost::asio::connect(_tcpSock, endpoint_iterator);
    readTCP();
  }

  void	openUdp(const std::string &port)
  {
    std::stringstream	ss(port);
    unsigned short	portVal;

    ss >> portVal;
    _udpServerSock.open(udp::v4());
    _udpServerSock.bind(udp::endpoint(udp::v4(), portVal));
    readUDP();
    // _t.expires_from_now(boost::posix_time::seconds(5));
    _t.async_wait(boost::bind(&client::writeUDP,
			      shared_from_this()));
  }

  void	accept_call(const ARequest *req)
  {
    const request::call::client::AcceptClient	*origin = dynamic_cast<const request::call::client::AcceptClient *>(req);

    g_udp_ip_receiver = origin->_ip;
    g_receiver_portUDP = origin->_port;
    std::cout << std::hex << g_udp_ip_receiver << ":" << std::dec << g_receiver_portUDP << std::endl;
    startAudio();
  }

  void read_tcp_handler(const boost::system::error_code& error, const size_t bytes_transferred)
  {
    if (error)
      {
	std::cerr << "read TCP error: " << boost::system::system_error(error).what() << std::endl;
	return;
      }
    std::vector<Protocol::Byte>	bytes(_arr.begin(), _arr.begin() + bytes_transferred);
    int				count;
    ARequest			*req;

    try
      {
	req = Protocol::consume(bytes, count);
      }
    catch (...)
      {
	std::cout << "Get Req fail" << std::endl;
	return ;
      }
    std::cout << "TCP Extracted: " << count << std::endl;
    std::cout << "TCP Received request code: " << req->code()
	      << std::endl;
    switch (req->code())
      {
      case request::client::call::ACCEPT:
	accept_call(req);
	break;
      case request::client::call::CALL:
	g_receiver_portUDP = dynamic_cast<const request::call::client::CallClient *>(req)->_port;
	g_udp_ip_receiver = dynamic_cast<const request::call::client::CallClient *>(req)->_ip;
	std::cout << std::hex << g_udp_ip_receiver << ":" << std::dec
		  << g_receiver_portUDP << std::endl;
	break;
      case request::server::auth::HANDSHAKE:
	std::cout << "Handshake: " << std::endl
		  << "Major: " << GET_MAJOR(dynamic_cast<const request::auth::server::Handshake *>(req)->version) << std::endl
		  << "Minor: " << GET_MINOR(dynamic_cast<const request::auth::server::Handshake *>(req)->version) << std::endl;
	break;
      }
    readTCP();
  }

  void write_tcp_handler(const boost::system::error_code& error, const size_t bytes_transferred)
  {
    if (error)
      {
	std::cerr << "write TCP error: " << boost::system::system_error(error).what() << std::endl;
	return;
      }
    std::cout << "Write TCP send " << bytes_transferred << std::endl;
    readTCP();
  }

  void read_udp_handler(const boost::system::error_code& error, const size_t bytes_transferred)
  {
    if (error)
      {
	std::cerr << "read UDP error: " << boost::system::system_error(error).what() << std::endl;
	return;
      }
    std::cerr << "read UDP received: " << bytes_transferred << std::endl;
    readUDP();
  }

  void write_udp_handler(const boost::system::error_code& error, const size_t bytes_transferred)
  {
    if (error)
      {
	std::cerr << "write error: " << boost::system::system_error(error).what() << std::endl;
	return;
      }
    std::cout << "Write send " << bytes_transferred << std::endl;
    readUDP();
  }

private:
  boost::asio::io_service		&_service;
  tcp::socket				_tcpSock;
  udp::socket				_udpClientSock;
  udp::socket				_udpServerSock;
  boost::array<Protocol::Byte, 1024>	_arr;
  boost::array<Protocol::Byte, 1024>	_udp;
  boost::asio::deadline_timer		_t;
  boost::thread				_audioThread;
  Bridge				_bridge;
  FakeAudio				_audio;
};


class		input : public boost::enable_shared_from_this<input>
{
public:
  typedef boost::shared_ptr<input> Ptr;

public:
  static Ptr create(boost::asio::io_service& io_service, client::Ptr clientPtr)
  {
    Ptr new_input(new input(io_service, clientPtr));
    new_input->read();
    return (new_input);
  }

private:
  explicit input(boost::asio::io_service& io_service, client::Ptr clientPtr) :
    _input(io_service), _client(clientPtr)
  {
    _input.assign(STDIN_FILENO);
  }

  void read()
  {
    boost::asio::async_read(_input,
			    boost::asio::buffer(&_command, sizeof(_command)),
			    boost::bind(&input::read_handler,
					shared_from_this(),
					boost::asio::placeholders::error,
					boost::asio::placeholders::bytes_transferred));
  }


  void		send_req(ARequest *req)
  {
    std::vector<Protocol::Byte>	bytes;

    std::cout << "Send request code: " << req->code()
	      << std::endl;
    bytes = Protocol::product(*req);
    _client->writeTCP(bytes);
  }

  void read_handler(const boost::system::error_code& error, const size_t bytes_transferred)
  {
    if (error)
      {
	std::cerr << "read error: " << boost::system::system_error(error).what() << std::endl;
	return;
      }

    switch (_command)
      {
      case '\0':
	exit(0);
      case 'a':
	send_req(new request::auth::client::NewClient("toto", md5("poil"), false));
	break;
      case 'b':
	send_req(new request::auth::client::NewClient("tata", md5("poil"), false));
	break;
      case 'c':
	send_req(new request::auth::client::ConnectClient("toto", md5("poil")));
	break;
      case 'd':
	send_req(new request::auth::client::ConnectClient("tata", md5("poil")));
	break;
      case 'e':
	send_req(new request::call::client::CallClient("toto", "tata", 1, 0x7F000001, g_server_portUDP));
	break;
      case 'f':
	send_req(new request::call::client::CallClient("tata", "toto", 1, 0x7F000001, g_server_portUDP));
	break;
      case 'g':
	send_req(new request::call::client::AcceptClient("toto", "tata", 0x7F000001, g_server_portUDP));
	_client->startAudio();
	break;
      case 'h':
	send_req(new request::call::client::AcceptClient("tata", "toto", 0x7F000001, g_server_portUDP));
	_client->startAudio();
	break;
      case 'i':
	send_req(new request::call::client::RefuseClient("toto", "tata"));
	break;
      case 'j':
	send_req(new request::call::client::RefuseClient("tata", "toto"));
	break;
      default:
	break;
      }
    this->read();
  }

private:
  boost::asio::posix::stream_descriptor _input;
  char					_command;
  client::Ptr				_client;
};



int			main(int ac, char **av)
{
  if (ac != 4)
    {
      std::cerr << "USAGE : ./request_serializer IP PORT_TCP PORT_UDP" << std::endl;
      return (0);
    }
  std::stringstream	ss;

  g_portTCP = std::atoi(av[2]);
  g_server_portUDP = std::atoi(av[3]);

  std::cout << "g_server_portUDP: " << g_server_portUDP << std::endl;


  boost::asio::io_service	io_service;
  client::Ptr			client = client::create(io_service, av[1], av[2], av[3]);
  input::Ptr			input = input::create(io_service, client->ptr());

  io_service.run();
  return (0);
}
