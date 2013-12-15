#include	<map>
#include	<iostream>
#include	<iomanip>
#include	<vector>
#include	<typeinfo>
#include	<boost/asio.hpp>
#include	<boost/bind.hpp>
#include	<boost/shared_ptr.hpp>
#include	<boost/enable_shared_from_this.hpp>
#include	"types.hh"
#include	"RequestCode.hh"
#include	"AuthRequest.hh"
#include	"CallRequest.hh"
#include	"Protocol.hpp"

static unsigned short g_portUDP;
static unsigned short g_portTCP;

using boost::asio::ip::tcp;
using boost::asio::ip::udp;

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

  void	writeUDP(const std::vector<Protocol::Byte> &data)
  {

    _udpSock.async_send(boost::asio::buffer(data),
			boost::bind(&client::write_udp_handler,
				    shared_from_this(),
				    boost::asio::placeholders::error,
				    boost::asio::placeholders::bytes_transferred));
  }

  void	readUDP()
  {
    _udpSock.async_receive(boost::asio::buffer(_udp),
			   boost::bind(&client::read_udp_handler,
				       shared_from_this(),
				       boost::asio::placeholders::error,
				       boost::asio::placeholders::bytes_transferred));
  }

private:
  explicit client(boost::asio::io_service& io_service) :
    _service(io_service), _tcpSock(io_service), _udpSock(io_service)
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
    _udpSock.open(udp::v4());
    _udpSock.bind(udp::endpoint(udp::v4(), portVal));
    readUDP();
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
  udp::socket				_udpSock;
  boost::array<Protocol::Byte, 1024>	_arr;
  boost::array<Protocol::Byte, 1024>	_udp;
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
	send_req(new request::call::client::CallClient("toto", "tata", 1, 0x7F000001, g_portUDP));
	break;
      case 'f':
	send_req(new request::call::client::CallClient("tata", "toto", 1, 0x7F000001, g_portUDP));
	break;
      case 'g':
	send_req(new request::call::client::AcceptClient("toto", "tata", 0x7F000001, g_portUDP));
	break;
      case 'h':
	send_req(new request::call::client::AcceptClient("tata", "toto", 0x7F000001, g_portUDP));
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
  std::stringstream	ss;

  if (ac != 4)
    return (0);

  boost::asio::io_service	io_service;
  client::Ptr			client = client::create(io_service, av[1], av[2], av[3]);
  input::Ptr			input = input::create(io_service, client->ptr());

  ss << av[2];
  ss >> g_portTCP;
  ss << av[3];
  ss >> g_portUDP;

  io_service.run();
  return (0);
}
