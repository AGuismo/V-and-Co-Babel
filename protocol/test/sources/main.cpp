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
#include	"PersoRequest.hh"
#include	"Protocol.hpp"
#include	"Bridge.hh"
#include	"PAudioStream.hh"

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

	  _tcpWrite = data;
	  boost::asio::async_write(_tcpSock, boost::asio::buffer(_tcpWrite),
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
    Bridge::buffer	data;
    udp::endpoint receiver_endpoint (boost::asio::ip::address_v4(g_udp_ip_receiver),
				     g_receiver_portUDP);

    // data.assign(40, 0);
    _bridge.outputDispatch(data);
    std::cout << "Bridge output size: " << data.size() << std::endl;
    _udpServerSock.async_send_to(boost::asio::buffer(data, data.size()),
				 receiver_endpoint,
				 boost::bind(&client::write_udp_handler,
					     shared_from_this(),
					     boost::asio::placeholders::error,
					     boost::asio::placeholders::bytes_transferred));
  }

  void	readUDP()
  {
    _udpServerSock.async_receive(boost::asio::buffer(_udpOutput),
				 boost::bind(&client::read_udp_handler,
					     shared_from_this(),
					     boost::asio::placeholders::error,
					     boost::asio::placeholders::bytes_transferred));
  }

  void	startAudio()
  {
	  if (_audio->init())
		  _audio->record();
    _t.expires_from_now(boost::posix_time::seconds(5));
    _t.async_wait(boost::bind(&client::writeUDP,
    			      shared_from_this()));
  }

private:
  explicit client(boost::asio::io_service& io_service) :
    _service(io_service), _tcpSock(io_service), _udpClientSock(io_service),_udpServerSock(io_service),
    _t(io_service)
  {
	  _audio = new PAudioStream();
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
    // _t.async_wait(boost::bind(&client::writeUDP,
    // 			      shared_from_this()));
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
      case request::server::perso::PING:
	std::cout << "Ping N." << dynamic_cast<const request::perso::server::Ping *>(req)->_id << std::endl;
	send_req(request::perso::client::Pong(dynamic_cast<const request::perso::server::Ping *>(req)->_id));
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
    std::size_t	pad = 0;
    if (error)
      {
	std::cerr << "read UDP error: " << boost::system::system_error(error).what() << std::endl;
	return;
      }
    std::cerr << "read UDP received: " << bytes_transferred << std::endl;
    for (std::size_t it = 0; it < bytes_transferred; ++it)
      {
	std::cout << std::setprecision(2) << std::hex << (int)_udpOutput[it];
	if (pad != 0 && pad % 16 == 0)
	  std::cout << std::endl;
	else if (pad != 0 && pad % 4 == 0)
	  std::cout << " ";
      }
    readUDP();
  }

  void write_udp_handler(const boost::system::error_code& error, const size_t bytes_transferred)
  {
    if (error)
      {
	std::cerr << "write UDP error: " << boost::system::system_error(error).what() << std::endl;
	return;
      }
    std::cout << "Write UDP send: " << bytes_transferred << std::endl;
    _t.expires_from_now(boost::posix_time::seconds(5));
    _t.async_wait(boost::bind(&client::writeUDP,
			      shared_from_this()));
  }

  void		send_req(const ARequest &req)
  {
    std::vector<Protocol::Byte>	bytes;

    std::cout << "Send request code: " << req.code()
	      << std::endl;
    bytes = Protocol::product(req);
    writeTCP(bytes);
  }

private:
	std::vector<Protocol::Byte>	_tcpWrite;
  boost::asio::io_service		&_service;
  tcp::socket				_tcpSock;
  udp::socket				_udpClientSock;
  udp::socket				_udpServerSock;
  boost::array<Protocol::Byte, 1024>	_arr;
  Bridge::buffer			_udp;
  boost::array<Protocol::Byte, 1024>	_udpOutput;
  boost::asio::deadline_timer		_t;
  boost::thread				_audioThread;
  Bridge				_bridge;
  IAudioStream			*_audio;
};


class		input : public boost::enable_shared_from_this<input>
{
public:
  typedef boost::shared_ptr<input> Ptr;

public:
  static Ptr create(boost::asio::io_service& io_service, client::Ptr clientPtr)
  {
    Ptr new_input(new input(io_service, clientPtr));

    return (new_input);
  }

private:
  explicit input(boost::asio::io_service& io_service, client::Ptr clientPtr) :
    _client(clientPtr), _service(io_service)
  {
  }

public:
  void read()
  {
    while (true)
      read_handler();
  }

  void		send_req(ARequest *req)
  {
    std::vector<Protocol::Byte>	bytes;

    std::cout << "Send request code: " << req->code()
	      << std::endl;
    bytes = Protocol::product(*req);
    _client->writeTCP(bytes);
  }

  void read_handler()
  {
    std::cin >> _command;
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
  }

private:
  char						_command;
  client::Ptr					_client;
  boost::asio::io_service		&_service;
};



int			main(int ac, char **av)
{
  std::string	ip, port_udp, port_tcp;
#if defined(linux)
  if (ac != 4)
    {
      std::cerr << "USAGE : ./request_serializer IP PORT_TCP PORT_UDP" << std::endl;
      return (0);
    }
  std::stringstream	ss;

  ip = std::string(av[1]);
  port_tcp = std::string(av[2]);
  port_udp = std::string(av[3]);
#elif defined(WIN32)
  std::cout << "IP: ";
  std::cin >> ip;
  std::cout << "TCP Port: ";
  std::cin >> port_tcp;
  std::cout << "UDP Port: ";
  std::cin >> port_udp;
#endif

  g_portTCP = std::atoi(port_tcp.c_str());
  g_server_portUDP = std::atoi(port_udp.c_str());

  std::cout << "g_server_portUDP: " << g_server_portUDP << std::endl;

  boost::asio::io_service	io_service;
  boost::thread		th;
  client::Ptr			client = client::create(io_service, ip, port_tcp, port_udp);
  input::Ptr			input = input::create(io_service, client->ptr());
  th = boost::thread(boost::bind(&input::read, input->shared_from_this()));

  io_service.run();
  th.interrupt();
  th.join();
  return (0);
}
