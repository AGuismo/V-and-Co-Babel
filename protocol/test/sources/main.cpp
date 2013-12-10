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
#include	"Protocol.hpp"

using boost::asio::ip::tcp;

class		client : public boost::enable_shared_from_this<client>
{
public:
  typedef boost::shared_ptr<client> Ptr;

public:
  static Ptr create(boost::asio::io_service& io_service, const std::string &ip, const std::string &port)
  {
    Ptr new_client(new client(io_service));
    new_client->connect(ip, port);

    return (new_client);
  }

public:
  client::Ptr	ptr()
  {
    return (shared_from_this());
  }

  void	write(const std::vector<Protocol::Byte> &data)
  {

    boost::asio::async_write(_socket, boost::asio::buffer(data),
			     boost::bind(&client::write_handler,
			    shared_from_this(),
			    boost::asio::placeholders::error,
			    boost::asio::placeholders::bytes_transferred));
  }

  void	read()
  {
    _socket.async_read_some(boost::asio::buffer(_arr),
			    boost::bind(&client::read_handler,
					shared_from_this(),
					boost::asio::placeholders::error,
					boost::asio::placeholders::bytes_transferred));
  }


private:
  explicit client(boost::asio::io_service& io_service) :
    _service(io_service), _socket(io_service)
  {
  }

  void	connect(const std::string &ip, const std::string &port)
  {
    tcp::resolver		resolver(_service);
    tcp::resolver::query	query(ip, port);
    tcp::resolver::iterator	endpoint_iterator = resolver.resolve(query);

    boost::asio::connect(_socket, endpoint_iterator);
    read();
  }

  void read_handler(const boost::system::error_code& error, const size_t bytes_transferred)
  {
    if (error)
      {
	std::cerr << "read error: " << boost::system::system_error(error).what() << std::endl;
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
    std::cout << "Extracted: " << count << std::endl;
    std::cout << "Received request code: " << req->code()
	      << std::endl;
    read();
  }

  void write_handler(const boost::system::error_code& error, const size_t bytes_transferred)
  {
    if (error)
      {
	std::cerr << "write error: " << boost::system::system_error(error).what() << std::endl;
	return;
      }
    std::cout << "Write send " << bytes_transferred << std::endl;
    read();
  }

private:
  boost::asio::io_service		&_service;
  tcp::socket				_socket;
  boost::array<Protocol::Byte, 1024>	_arr;
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
    _client->write(bytes);
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
	send_req(new request::auth::client::ConnectClient("Ruby", md5("1664")));
	break;
      case 'h':
	std::cout << "a: " << "Auth::Connect" << std::endl;
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
  if (ac != 3)
    return (0);

  boost::asio::io_service	io_service;
  client::Ptr			client = client::create(io_service, av[1], av[2]);
  input::Ptr			input = input::create(io_service, client->ptr());

  io_service.run();
  return (0);
}
