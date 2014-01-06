#include	<iostream>
#include	"Call.hh"
#include	"IRequestPlugin.hh"
#include	"RequestCode.hh"
#include	"CallRequest.hh"
#include	"ServerRequest.hh"
#include	"Database.hh"
#include	"types.hh"
#include	"Server.hh"

Call::Call(Database &db, Env &env) :
_db(db), _env(env)
{

}

Call::~Call()
{

}

Call::Call(Call const &src):
	_db(src._db), _env(src._env)
{
  (void)src;
}

Call	&Call::operator=(Call const &src)
{
  if (this != &src)
    {

    }
  return (*this);
}

plugin::IPlugin<request::ID, plugin::request_handler>	*Call::clone()
{
	return (new Call(*this));
}
void	Call::unload()
{
  delete this;
}

void	Call::getVersion(plugin::version::major &maj, plugin::version::minor &min) const
{
  maj = plugin::version::MAJOR;
  min = plugin::version::MINOR;
}

bool	Call::searchClient(const std::list<IClient::Pointer> &clients, const std::string &name, IClient::Pointer &client)
{
  for (Server::client_list::const_iterator it = clients.begin(); it != clients.end(); ++it)
    {
      if ((*it)->Username() == name && (*it)->Authenticated())
	{
	  client = *it;
	  return (true);
	}
    }
  return (false);
}

bool	Call::verifCall(IClient::Pointer sender, IClient::Pointer receiver, Database::list_friend friends, const std::list<IClient::Pointer> &clients)
{
  for (std::list<IClient::Pointer>::const_iterator itClient = clients.begin();
       itClient != clients.end(); ++itClient)
    {
      for (Database::list_friend::const_iterator it = friends.begin();
	   it != friends.end(); ++it)
	{
	  if ((*itClient)->Username() == *it && (*itClient)->Username() == receiver->Username())
	    {
	      return true;
	    }
	}
    }
/*  if (receiver->privacy() == request::User::PRIVATE)
    return false;
  else
    return true;*/
  return (false);
}

void	Call::call(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::call::client::CallClient	*origin = dynamic_cast<const request::call::client::CallClient *>(req);
  IClient::Pointer				receiver;


  if (sender->Authenticated() &&
      sender->status() == request::User::Status::CONNECTED &&
      sender->Communication() == false &&
      _db.clientExist(origin->_from) &&
      _db.clientExist(origin->_to))
    {
      Database::list_friend friends;


#if defined(DEBUG)
      std::cout << "Receive a call request from [" << origin->_from << "] to [" << origin->_to << "]" << std::endl;
#endif
      if (_db.listFriend(sender->Username(), friends))
	{
	  if (searchClient(clients, origin->_to, receiver))
	    {
#if defined(DEBUG)
	      std::cout << "Call send ..." << std::endl;
#endif
	      request::call::client::CallClient fwd(*origin);
	      fwd._ip = sender->IP();

		  // verifCall(sender, receiver, friends, clients)
	      if (receiver->Authenticated() &&
		  receiver->Communication() == false)
		{
#if defined(DEBUG)
	      std::cout << "Call: receiver Auth, no in communic already" << std::endl;
#endif

		  sender->Communication(true);
		  receiver->serialize_data(fwd);
		  sender->serialize_data(request::server::Ok());
		}
	      else
		sender->serialize_data(request::server::Forbidden());
	      return ;
	    }
	}
    }
  sender->serialize_data(request::server::Forbidden());
}

void	Call::accept(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::call::client::AcceptClient	*origin = dynamic_cast<const request::call::client::AcceptClient *>(req);
  IClient::Pointer				receiver;

  std::cout << "Call::accept()" << std::endl;
  std::cout << "From : " << origin->_from << std::endl;
  std::cout << "To : " << origin->_to << std::endl;
  if (sender->Authenticated() &&
      sender->status() == request::User::Status::CONNECTED &&
      _db.clientExist(origin->_from) &&
      _db.clientExist(origin->_to))
    {
#if defined(DEBUG)
      std::cout << "Receive an accept request from [" << origin->_from << "] to [" << origin->_to << "]" << std::endl;
#endif
      if (searchClient(clients, origin->_to, receiver))
	{
#if defined(DEBUG)
	  std::cout << "Sending..." << std::endl;
#endif
	  request::call::client::AcceptClient fwd(*origin);
	  fwd._ip = sender->IP();
	  if (receiver->Authenticated() &&
	      receiver->status() == request::User::Status::CONNECTED)
	    {
	      sender->Communication(true);
	      sender->serialize_data(request::server::Ok());
	      receiver->serialize_data(fwd);
	      receiver->Caller(sender->Username());
	      sender->Caller(receiver->Username());
	    }
	  else
	    sender->serialize_data(request::server::Forbidden());
	  return ;
	}
    }
  sender->serialize_data(request::server::Forbidden());
}

void	Call::refuse(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::call::client::RefuseClient	*origin = dynamic_cast<const request::call::client::RefuseClient *>(req);
  IClient::Pointer				receiver;

  std::cout << "Call::refuse()" << std::endl;
  std::cout << "From : " << origin->_from << std::endl;
  std::cout << "To : " << origin->_to << std::endl;
  if (sender->Authenticated() &&
      sender->status() == request::User::Status::CONNECTED &&
      _db.clientExist(origin->_from) &&
      _db.clientExist(origin->_to))
    {
#if defined(DEBUG)
      std::cout << "Receive a refuse request from [" << origin->_from << "] to [" << origin->_to << "]" << std::endl;
#endif
      if (searchClient(clients, origin->_to, receiver))
	{
#if defined(DEBUG)
	  std::cout << "Refuse Send..." << std::endl;
#endif
	  if (receiver->Authenticated() &&
	      receiver->status() == request::User::Status::CONNECTED)
	    {
	      receiver->Communication(false);
	      receiver->serialize_data(*origin);
	      sender->serialize_data(request::server::Ok());
	    }
	  else
	    sender->serialize_data(request::server::Forbidden());
	  return ;
	}
    }
  sender->serialize_data(request::server::Forbidden());
}

void	Call::hangup(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::call::client::HangupClient	*origin = dynamic_cast<const request::call::client::HangupClient *>(req);
  IClient::Pointer				receiver;

  if (sender->Authenticated() &&
      _db.clientExist(origin->_from) &&
      _db.clientExist(origin->_to))
    {
#if defined(DEBUG)
      std::cout << "Receive a hang up request from [" << origin->_from << "] to [" << origin->_to << "]" << std::endl;
#endif
      if (searchClient(clients, origin->_to, receiver))
	{
#if defined(DEBUG)
	  std::cout << "Hang up send ..." << std::endl;
#endif
	  if (receiver->Authenticated())
	    {
	      sender->Communication(false);
	      receiver->Communication(false);
	      receiver->serialize_data(*origin);
	      sender->serialize_data(request::server::Ok());
	      receiver->Caller("");
	      sender->Caller("");
	    }
	  else
	    sender->serialize_data(request::server::Forbidden());
	  return ;
	}
    }
  sender->serialize_data(request::server::Forbidden());
}


void	Call::setActions(std::map<request::ID, plugin::request_handler> &map)
{
  map[request::client::call::CALL] = plugin::request_handler(&Call::call, this);
  map[request::client::call::ACCEPT] = plugin::request_handler(&Call::accept, this);
  map[request::client::call::REFUSE] = plugin::request_handler(&Call::refuse, this);
  map[request::client::call::HANG_UP] = plugin::request_handler(&Call::hangup, this);
}


request::IRequestPlugin	*loadPlugin(Database &db, Env &env)
{
  return (new Call(db, env));
}
