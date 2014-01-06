#if defined(DEBUG)
# include	<locale>
# include	<iomanip>
# include	<cctype>
#endif
#include	"Client.hh"
#include	"Server.hh"
#include	"AuthRequest.hh"
#include	"PersoRequest.hh"
#include	"Env.hh"
#include	"Database.hh"

Client::Client(boost::asio::io_service &service, Server *server) :
  _service(service), _input(DEFAULT_SIZE), _socket(service), _server(server),
  _pongTimer(service), _currentPong(0)
{
  InfosClient._isConnect = false;
  InfosClient._name = "";
  InfosClient._privacy = request::User::PUBLIC;
  InfosClient._status = request::User::Status::DISCONNECTED;
  InfosClient._inCommunication = false;
}

Client::~Client()
{
#if defined(DEBUG)
  std::cout << "Client " << this << " Disconnected" << std::endl;
#endif
}

IClient::Pointer Client::create(boost::asio::io_service& io_service, Server *server)
{
  return IClient::Pointer(new Client(io_service, server));
}

void		Client::start_ping(const boost::system::error_code &e)
{
  if (!e)
    {
#if defined(DEBUG)
      std::cout << "Client " << this << ": Ping N." << _currentPong + 1 << std::endl;
#endif
      serialize_data(request::perso::server::Ping(++_currentPong));
      _pongTimer.expires_from_now(boost::posix_time::seconds(Env::getInstance().client.pongDelay));
      _pongTimer.async_wait(boost::bind(&Client::handle_timeout_pong, boost::dynamic_pointer_cast<Client>(shared_from_this()), boost::asio::placeholders::error));
    }
}

void		Client::handle_timeout_pong(const boost::system::error_code &e)
{
  if (!e)
    {
#if defined(DEBUG)
      std::cout << "Client " << this << ": Pong Timeout" << std::endl;
#endif
      _socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
      close();
    }
}

void		Client::reset_pong()
{
#if defined(DEBUG)
  std::cout << "Client " << this << ": Reset pong" << std::endl;
#endif
  _pongTimer.expires_from_now(boost::posix_time::seconds(Env::getInstance().client.pongRefresh));
  _pongTimer.async_wait(boost::bind(&Client::start_ping, boost::dynamic_pointer_cast<Client>(shared_from_this()), boost::asio::placeholders::error));
}

void		Client::close()
{
	_pongTimer.cancel();
	_service.post(boost::bind(&Server::handleClientClose, _server, share()));
  //_socket.close();
}

void		Client::handle_write(const boost::system::error_code &error,
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
      close();
    }
}

void		Client::handle_read(const boost::system::error_code& error,
				    std::size_t bytes_transferred)
{
  buffer	data;

  if (!error)
    {
      reset_pong();
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
      while (execRequest());
    }
  else
    {
#if defined(DEBUG)
      std::cerr << "Error when reading data" << std::endl;
#endif
      (void)bytes_transferred;
      close();
    }
}

void		Client::async_read()
{
  _socket.async_read_some(boost::asio::buffer(_input, DEFAULT_SIZE),
			  boost::bind(&Client::handle_read, boost::dynamic_pointer_cast<Client>(shared_from_this()),
				      boost::asio::placeholders::error,
				      boost::asio::placeholders::bytes_transferred));
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
      if (std::string(e.what()) == "Invalid Code")
	close();
      return (false);
    }
  buff.erase(buff.begin(), buff.begin() + extracted);
  _waitedRequest.push_back(req);
  return (true);
}

bool		Client::execRequest()
{
  ARequest	*req;

  if (_waitedRequest.empty())
    return (false);
  req = _waitedRequest.front();
  _waitedRequest.pop_front();
  _service.post(boost::bind(&Server::handle_request,
			    _server,
			    shared_from_this(),
			    req));
  return (true);
}

void		Client::addRequest(const ARequest &req)
{
  _waitedRequest.push_back(req.clone());
}

void		Client::start()
{
  _pongTimer.expires_from_now(boost::posix_time::seconds(Env::getInstance().client.pongRefresh));
  _pongTimer.async_wait(boost::bind(&Client::start_ping, boost::dynamic_pointer_cast<Client>(shared_from_this()), boost::asio::placeholders::error));
  serialize_data(request::auth::server::Handshake(SET_VERSION(request::version::MAJOR,
							      request::version::MINOR)));
  async_read();
}

tcp::socket&	Client::socket()
{
  return (_socket);
}

IClient::Pointer	Client::share()
{
  return (IClient::shared_from_this());
}

bool	Client::serialize_data(const ARequest &req)
{
  async_write(Protocol::product(req));
  return (true);
}

void	Client::async_write(const IClient::buffer &buff)
{
  _output = buff;
#if defined(DEBUG)
  std::cout << "Client::async_write(): " << _output.size() << std::endl;
#endif
  boost::asio::async_write(_socket, boost::asio::buffer(_output),
			   boost::bind(&Client::handle_write, boost::dynamic_pointer_cast<Client>(shared_from_this()),
				       boost::asio::placeholders::error,
				       boost::asio::placeholders::bytes_transferred));
}
