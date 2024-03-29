#include	<boost/asio.hpp>
#include	<boost/bind.hpp>
#include	"Server.hh"
#include	"IRequestPlugin.hh"
#include	"Env.hh"
#include	"RequestPlugin.hh"
#include	"RequestCaller.hh"
#include	"ServerRequest.hh"
#include	"Database.hh"
#include	"FriendRequest.hh"
#include	"CallRequest.hh"

Server::Server(boost::asio::io_service &service, Database &db) :
  _service(service), _db(db), _acceptor(service), _plugs(new request::PluginManager(db, Env::getInstance())),
  _calls(new request::PluginCaller(this->_clientList))
{

}

Server::~Server()
{

}

// Env::network::Port

void	Server::init()
{
  try
    {
      Env::plugin_list	plugs = Env::getInstance().plugin.plugins;

      for (Env::plugin_list::const_iterator it = plugs.begin(); it != plugs.end(); ++it)
	{
	  if (it->used)
	    {
	      _plugs->loadPlugin(it->path, it->name);
#if defined(DEBUG)
	      std::cout << "Plugins: " << it->name << ": loaded" << std::endl;
#endif
	    }
	}

      _calls->loadPlugins(*_plugs);
      _acceptor.open(boost::asio::ip::tcp::v4());
      _acceptor.bind(boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),
						    Env::getInstance().server.ClientPort));
      _acceptor.listen();
      start_accept();
    }
  catch (const plugin::Exception &e)
    {
      std::cerr << "Server::init() failed to load: " << e.what() << std::endl;
      throw Server::Exception("Failed to load plugins");
    }
  catch (const boost::system::system_error &e)
    {
      std::cerr << "Server::init() failed to load: " << e.what() << std::endl;
      throw Server::Exception("Failed to start server");
    }
}

const Server::client_list	&Server::getClients() const
{
  return (_clientList);
}

void	Server::handle_request(IClient::Pointer from, const ARequest *req)
{
#if defined(DEBUG)
  std::cout << "Server::handle_request: " << req->code() << std::endl;
#endif
  if ((*_calls)(from, req))
    {
#if defined(DEBUG)
      std::cout << "Server::handle_request: Call complete" << std::endl;
#endif
    }
  else
    {
#if defined(DEBUG)
      std::cout << "Server::handle_request: Call don't exist" << std::endl;
#endif
      from->serialize_data(request::server::NotImplemented());
    }
  delete req;
}

void	Server::handle_accept(IClient::Pointer new_connection,
			      const boost::system::error_code& error)
{
#if defined(DEBUG)
  std::cout << "New client: " << new_connection << std::endl;
#endif
  if (!error)
    new_connection->start();
  start_accept();
}

void		Server::clientAboutToClose(IClient::Pointer &client)
{
  Database::list_friend	friends;

  _db.listFriend(client->Username(), friends);
  for (std::list<IClient::Pointer>::const_iterator itClient = _clientList.begin();
       itClient != _clientList.end(); ++itClient)
    {
      for (Database::list_friend::const_iterator it = friends.begin();
	   it != friends.end(); ++it)
	{
	  if ((*itClient)->Username() == client->Caller())
	    {
#if defined(DEBUG)
	      std::cout << "Timeout send to : [" << (*itClient)->Username() << "]" << std::endl;
#endif
	      (*itClient)->serialize_data(request::call::server::Timeout());
		  (*itClient)->Communication(false);
	    }
	  if ((*itClient)->Username() == *it && (*itClient)->Authenticated())
	    {
	      (*itClient)->serialize_data(request::friends::server::Update(request::User::Status::DISCONNECTED, std::string(), client->Username()));
	    }
	}
    }
}

void	Server::handleClientClose(IClient::Pointer clientClosed)
{
  clientAboutToClose(clientClosed);
  _clientList.remove(clientClosed);
}

void Server::start_accept()
{
  IClient::Pointer	new_connection = Client::create(_acceptor.get_io_service(), this);
  Client::Pointer	p = boost::dynamic_pointer_cast<Client>(new_connection);

  _acceptor.async_accept(p->socket(),
			 boost::bind(&Server::handle_accept, this, p,
				     boost::asio::placeholders::error));
  _clientList.push_back(p->share());
}


///////////////////////
//  Exception Class  //
///////////////////////

Server::Exception::Exception(const std::string &what) throw() :
  _what(what)
{

}

Server::Exception::Exception(const Exception &src) throw() :
  _what(src._what)
{

}

Server::Exception::~Exception() throw()
{
}

Server::Exception	&Server::Exception::operator=(const Server::Exception &src) throw()
{
  if (&src != this)
    {
      _what = src._what;
    }
  return (*this);
}

const char	*Server::Exception::what() const throw()
{
  return (_what.c_str());
}
