#include	<iostream>
#include	"Auth.hh"
#include	"types.hh"
#include	"RequestCode.hh"
#include	"AuthRequest.hh"
#include	"FriendRequest.hh"
#include	"ServerRequest.hh"
#include	"Database.hh"

Auth::Auth(Database &db, Env &env):
  _db(db), _env(env)
{

}

Auth::~Auth()
{

}

Auth::Auth(Auth const &src):
  _db(src._db), _env(src._env)
{
  (void)src;
}

Auth	&Auth::operator=(Auth const &src)
{
  if (this != &src)
    {
    }
  return (*this);
}

plugin::IPlugin<request::ID, plugin::request_handler>	*Auth::clone()
{
  return (new Auth(*this));
}

void	Auth::unload()
{
  delete this;
}

void	Auth::getVersion(plugin::version::major &maj, plugin::version::minor &min) const
{
  maj = plugin::version::MAJOR;
  min = plugin::version::MINOR;
}

void	Auth::new_account(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::auth::client::NewClient	*origin = dynamic_cast<const request::auth::client::NewClient *>(req);

  if (_db.newClient(origin->_name, origin->_password))
    {
#if defined(DEBUG)
      std::cout << "Create a new account for : [" << origin->_name << "]" << std::endl;
#endif
      sender->Authenticated(false);
      sender->Username(origin->_name);
      sender->privacy(request::User::PUBLIC);
      sender->status(request::User::Status::DISCONNECTED);
      sender->serialize_data(request::server::Ok());
    }
  else
    {
#if defined(DEBUG)
      std::cout << "Fail create a new account for : [" << origin->_name << "]" << std::endl;
#endif
      sender->serialize_data(request::server::Forbidden());
    }
}

void	Auth::sendStatusFriends(const IClient::Pointer &sender,
				const Database::list_friend &friends,
				const std::list<IClient::Pointer> &clients,
				const request::Status st) const
{
  for (std::list<IClient::Pointer>::const_iterator itClient = clients.begin();
       itClient != clients.end(); ++itClient)
    {
      for (Database::list_friend::const_iterator it = friends.begin();
	   it != friends.end(); ++it)
	{
	  if ((*itClient)->Username() == *it)
	    {
	      if ((*itClient)->Authenticated())
		{
		  sender->serialize_data(request::friends::server::Update((*itClient)->status(), (*itClient)->statusDetail(), (*itClient)->Username()));
		  (*itClient)->serialize_data(request::friends::server::Update(st, std::string(),
									   sender->Username()));
		}
	      else
		sender->serialize_data(request::friends::server::Update(request::User::Status::DISCONNECTED, std::string(), (*itClient)->Username()));
	    }
	}
    }
}

void	Auth::connect(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::auth::client::ConnectClient	*origin = dynamic_cast<const request::auth::client::ConnectClient *>(req);

  if (sender->Authenticated() == false &&
      _db.clientExist(origin->_name, origin->_password))
    {
      Database::list_friend	friends;
#if defined(DEBUG)
      std::cout << "Connection on the account : [" << origin->_name << "]" << std::endl;
#endif
      sender->serialize_data(request::server::Ok());
      sender->Authenticated(true);
      sender->status(request::User::Status::CONNECTED);
      sender->Username(origin->_name);
      if (_db.listFriend(sender->Username(), friends))
	sendStatusFriends(sender, friends, clients, request::User::Status::CONNECTED);
      if (_db.waitRequest(sender->Username()))
	{
	  std::vector<ARequest *>	reqList = _db.getAllRequest(sender->Username());

	  for (std::vector<ARequest *>::const_iterator it = reqList.begin();
	       it != reqList.end(); ++it)
	    {
	      sender->serialize_data(**it);
	      delete *it;
	    }
	}
    }
  else
    {
#if defined(DEBUG)
      std::cout << "Fail connection on the account : [" << origin->_name << "]" << std::endl;
#endif
      sender->serialize_data(request::server::Forbidden());
    }
}

void	Auth::modify(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::auth::client::ModifyClient	*origin = dynamic_cast<const request::auth::client::ModifyClient *>(req);

  std::cout << "Auth::modify()" << std::endl;
  if (sender->Authenticated() &&
      _db.modClientPass(origin->_name, origin->_oldPassword, origin->_newPassword))
    {
#if defined(DEBUG)
      std::cout << "Succeed of changing password on the account : [" << origin->_name << "]" << std::endl;
#endif
      sender->serialize_data(request::server::Ok());
    }
  else
    {
#if defined(DEBUG)
      std::cout << "Failed of changing password on the account : [" << origin->_name << "]" << std::endl;
#endif
      sender->serialize_data(request::server::Forbidden());
    }
}

void	Auth::deleteFriendList(IClient::Pointer sender, const Database::list_friend &friends, const std::list<IClient::Pointer> &clients)
{
  for (std::list<IClient::Pointer>::const_iterator itClient = clients.begin();
       itClient != clients.end(); ++itClient)
    {
      for (Database::list_friend::const_iterator it = friends.begin();
	   it != friends.end(); ++it)
	{
	  if ((*itClient)->Username() == *it)
	    {
	      _db.delFriend(sender->Username(), (*itClient)->Username());
	    }
	}
    }
}

void	Auth::remove(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::auth::client::DelClient	*origin = dynamic_cast<const request::auth::client::DelClient *>(req);

  std::cout << "Auth::delete()" << std::endl;
  if (sender->Authenticated() == false && _db.clientExist(origin->_name, origin->_password))
    {
      Database::list_friend	friends;

      sendStatusFriends(sender, friends, clients, request::User::Status::DELETED);
      deleteFriendList(sender, friends, clients);
      _db.delClient(origin->_name, origin->_password);
#if defined(DEBUG)
      std::cout << "The account : [" << origin->_name << "] has been deleted" << std::endl;
#endif
      sender->serialize_data(request::server::Ok());
    }
  else
    {
#if defined(DEBUG)
      std::cout << "Failed to deleted the account : [" << origin->_name << "]" << std::endl;
#endif
      sender->serialize_data(request::server::Forbidden());
    }
}


void	Auth::disconnect(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::auth::client::DisconnectClient	*origin = dynamic_cast<const request::auth::client::DisconnectClient *>(req);

  std::cout << "Auth::disconnect()" << std::endl;
  (void)origin;

  if (sender->Authenticated() == true)
    {
      Database::list_friend	friends;

#if defined(DEBUG)
      std::cout << "The client has been disconnected" << std::endl;
#endif
      sender->serialize_data(request::server::Ok());
      sender->Authenticated(false);
      sender->status(request::User::Status::DISCONNECTED);
      if (_db.listFriend(sender->Username(), friends))
	sendStatusFriends(sender, friends, clients, request::User::Status::DISCONNECTED);
    }
  else
    {
#if defined(DEBUG)
      std::cout << "Can't disconnect the client" << std::endl;
#endif
      sender->serialize_data(request::server::Forbidden());
    }
}

void	Auth::setActions(std::map<request::ID, plugin::request_handler> &map)
{
  map[request::client::auth::NEW] = plugin::request_handler(&Auth::new_account, this);
  map[request::client::auth::CONNECT] = plugin::request_handler(&Auth::connect, this);
  map[request::client::auth::MODIFY] = plugin::request_handler(&Auth::modify, this);
  map[request::client::auth::REMOVE] = plugin::request_handler(&Auth::remove, this);
  map[request::client::auth::DISCONNECT] = plugin::request_handler(&Auth::disconnect, this);
}

request::IRequestPlugin	*loadPlugin(Database &db, Env &env)
{
  return (new Auth(db, env));
}
