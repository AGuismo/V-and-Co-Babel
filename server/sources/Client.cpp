#if defined(DEBUG)
# include	<locale>
# include	<iomanip>
# include	<cctype>
#endif
#include	"Client.hh"
#include	"Server.hh"
#include	"AuthRequest.hh"

Client::Client(boost::asio::io_service &service, Server *server) :
  _service(service), _input(DEFAULT_SIZE), _socket(service), _server(server)
{
}

Client::~Client()
{
#if defined(DEBUG)
  std::cout << "Client " << this << " Disconnected" << std::endl;
#endif
}

Client::Pointer Client::create(boost::asio::io_service& io_service, Server *server)
{
  return Pointer(new Client(io_service, server));
}

void		Client::handle_write(const boost::system::error_code& error,
				     std::size_t bytes_transferred)
{
  if (!error)
    {
#if defined(DEBUG)
      std::cout << "Send: " << bytes_transferred << " octets" << std::endl;
#endif
      async_read();
    }
  else
    {
#if defined(DEBUG)
      std::cerr << "Error when writing data" << std::endl;
#endif
      (void)bytes_transferred;
      _service.post(boost::bind(&Server::handleClientClose,
				_server,
				share()));
    }
}

bool		Client::serialize_data(const ARequest &req)
{
  async_write(Protocol::product(req));
  return (true);
}

bool		Client::unserialize_data(buffer &buff)
{
  int		extracted;
  ARequest	*req;

  try
    {
      req = Protocol::consume(buff, extracted);
    }
  catch (const Serializer::invalid_argument &e)
    {
      return (false);
    }
  buff.erase(buff.begin(), buff.begin() + extracted);
  _service.post(boost::bind(&Server::handle_request,
			    _server,
			    shared_from_this(),
			    req));
  return (true);
}

void		Client::handle_read(const boost::system::error_code& error,
				    std::size_t bytes_transferred)
{
  buffer	data;

  if (!error)
    {
#if defined(DEBUG)
      std::cout << "Received: " << bytes_transferred << " octets." << std::endl;
      for (std::size_t it = 0; it < bytes_transferred; ++it)
	{
	  if (it != 0 && it % 4 == 0)
	    std::cout << " ";
	  if (it != 0 && it % 16 == 0)
	    std::cout << std::endl;
	  std::cout << std::hex << std::setfill('0') << std::setw(2) << (int)_input[it];
	}
      std::cout << std::dec << std::endl;
#endif
      if (!_bufferised.empty())
	{
	  data.insert(data.end(), _bufferised.begin(), _bufferised.end());
	}
      data.insert(data.end(), _input.begin(), _input.begin() + bytes_transferred);
      while (unserialize_data(data));
      if (data.empty())
	_bufferised.clear();
      else
	_bufferised = data;
      async_read();
    }
  else
    {
#if defined(DEBUG)
      std::cerr << "Error when reading data" << std::endl;
#endif
      (void)bytes_transferred;
      _service.post(boost::bind(&Server::handleClientClose,
				_server,
				share()));
    }
}

template <typename BUFF>
void		Client::async_write(const BUFF &buff)
{
  boost::asio::async_write(_socket, boost::asio::buffer(buff),
			   boost::bind(&Client::handle_write, shared_from_this(),
				       boost::asio::placeholders::error,
				       boost::asio::placeholders::bytes_transferred));
}

void		Client::async_read()
{
  _socket.async_read_some(boost::asio::buffer(_input),
			  boost::bind(&Client::handle_read, shared_from_this(),
				      boost::asio::placeholders::error,
				      boost::asio::placeholders::bytes_transferred));
}

void		Client::start()
{
  serialize_data(request::auth::server::Handshake(SET_VERSION(request::version::MAJOR,
							      request::version::MINOR)));
  async_read();
}

tcp::socket&	Client::socket()
{
  return (_socket);
}

Client::Pointer	Client::share()
{
  return (shared_from_this());
}
