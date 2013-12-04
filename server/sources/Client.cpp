#include	"Client.hh"

Client::Client(boost::asio::io_service &service) :
  _service(service), _socket(service)
{
}

Client::~Client()
{
#if defined(DEBUG)
  std::cout << "Client " << this << " Disconnected" << std::endl;
#endif
}

Client::Pointer Client::create(boost::asio::io_service& io_service)
{
  return Pointer(new Client(io_service));
}

void		Client::handle_write(const boost::system::error_code& error,
				     std::size_t bytes_transferred)
{
  if (!error)
    {
#if defined(DEBUG)
      std::cout << "Send: " << bytes_transferred << " octets" << std::endl;
#endif
      Receive();
    }
  else
    {
#if defined(DEBUG)
      std::cerr << "Error when writing data" << std::endl;
#endif
    }
}

void		Client::handle_read(const boost::system::error_code& error,
				    std::size_t bytes_transferred)
{
  if (!error)
    {
#if defined(DEBUG)
      std::cout << "Received: " << bytes_transferred << " octets: \"" << _received.data() << "\"" << std::endl;
#endif
      _received.assign(0);
      Receive();
    }
  else
    {
#if defined(DEBUG)
      std::cerr << "Error when reading data" << std::endl;
#endif
    }
}

void		Client::Send()
{
  boost::asio::async_write(_socket, boost::asio::buffer("Hello World !"),
			   boost::bind(&Client::handle_write, shared_from_this(),
				       boost::asio::placeholders::error,
				       boost::asio::placeholders::bytes_transferred));
}

void		Client::Receive()
{
  _socket.async_read_some(boost::asio::buffer(_received),
			   boost::bind(&Client::handle_read, shared_from_this(),
				       boost::asio::placeholders::error,
				       boost::asio::placeholders::bytes_transferred));
}

void		Client::start()
{
  Send();
}

tcp::socket&	Client::socket()
{
  return (_socket);
}
