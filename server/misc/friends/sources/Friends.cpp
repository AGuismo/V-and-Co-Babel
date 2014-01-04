#include	<iostream>
#include	"Friends.hh"
#include	"IRequestPlugin.hh"
#include	"RequestCode.hh"
#include	"FriendRequest.hh"
#include	"ServerRequest.hh"
#include	"Database.hh"
#include	"types.hh"
#include	"Server.hh"

Friends::Friends(Database &db, Env &env):
  _db(db), _env(env)
{

}

Friends::~Friends()
{

}

Friends::Friends(Friends const &src):
  _db(src._db), _env(src._env)
{
  (void)src;
}

Friends	&Friends::operator=(Friends const &src)
{
  if (this != &src)
    {

    }
  return (*this);
}

plugin::IPlugin<request::ID, plugin::request_handler>	*Friends::clone()
{
  return (new Friends(*this));
}

void	Friends::getVersion(plugin::version::major &maj, plugin::version::minor &min) const
{
  maj = plugin::version::MAJOR;
  min = plugin::version::MINOR;
}

void	Friends::unload()
{
  delete this;
}

bool	Friends::searchClient(const std::list<IClient::Pointer> &clients, const std::string &name, IClient::Pointer &client)
{
  for (Server::client_list::const_iterator it = clients.begin(); it != clients.end(); ++it)
    {
      if ((*it)->Username() == name)
	{
	  client = *it;
	  return (true);
	}
    }
  return (false);
}

void	Friends::request(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::friends::client::Request	*origin = dynamic_cast<const request::friends::client::Request *>(req);
  IClient::Pointer				receiver;


  if (sender->Authenticated() &&
      sender->Username() == origin->from &&
      !_db.bothFriend(origin->to, origin->from))
    {
#if defined(DEBUG)
      std::cout << "Receive a friend request from [" << origin->from << "] to [" << origin->to << "]" << std::endl;
#endif
      if (!_db.addRequest(origin->from, *origin) || !_db.addRequest(origin->to, *origin))
	{
	  _db.delRequest(origin->from, *origin);
	  sender->serialize_data(request::server::Forbidden());
	  return ;
	}
      if (searchClient(clients, origin->to, receiver))
	{
#if defined(DEBUG)
	  std::cout << "Friend request send ..." << std::endl;
#endif
	  if (receiver->Authenticated())
	    receiver->serialize_data(*origin);
	}
      sender->serialize_data(request::server::Ok());
      return ;
    }
  sender->serialize_data(request::server::Forbidden());
}

void	Friends::del_friend(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::friends::client::DelFriend	*origin = dynamic_cast<const request::friends::client::DelFriend *>(req);

#if defined(DEBUG)
  std::cout << "Delete request from : [" << sender->Username() << "] For : [" << origin->to << "]" << std::endl;
#endif
  if (sender->Authenticated() &&
      _db.isFriend(sender->Username(), origin->to))
    {
#if defined(DEBUG)
      std::cout << "Deleting..." << std::endl;
#endif
      if (_db.delFriend(sender->Username(), origin->to))
	{
	  sender->serialize_data(request::server::Ok());
	  sender->serialize_data(request::friends::server::Update(request::User::Status::DELETED, std::string(), origin->to));
	  if (_db.isFriend(origin->to, sender->Username()))
	    {
	      IClient::Pointer		receiver;

	      _db.delFriend(origin->to, sender->Username());
	      if (searchClient(clients, origin->to, receiver))
		receiver->serialize_data(request::friends::server::Update(request::User::Status::DELETED, std::string(), sender->Username()));
	    }
	  return;
	}
    }
  sender->serialize_data(request::server::Forbidden());
}

void	Friends::accept(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::friends::client::Accept	*origin = dynamic_cast<const request::friends::client::Accept *>(req);

#if defined(DEBUG)
  std::cout << origin->from << " accept request from " << origin->to << std::endl;
#endif
  if (sender->Authenticated() &&
      sender->Username() == origin->from &&
      _db.isRequestExist(origin->from, request::friends::client::Request(origin->to, origin->from)) &&
      _db.isRequestExist(origin->to, request::friends::client::Request(origin->to, origin->from)))
    {
      IClient::Pointer				receiver;
      if (_db.addFriend(origin->from, origin->to) && _db.addFriend(origin->to, origin->from))
	{
	  if (searchClient(clients, origin->to, receiver) && receiver->Authenticated())
	    {
 	      receiver->serialize_data(*origin);
	      sendFriendStatus(receiver, clients, origin->from);
	    }
	  else
	    _db.addRequest(origin->to, *origin);
	  _db.delRequest(origin->from, request::friends::client::Request(origin->to, origin->from));
	  _db.delRequest(origin->to, request::friends::client::Request(origin->to, origin->from));
	  sender->serialize_data(request::server::Ok());
	  sendFriendStatus(sender, clients, origin->to);
	  return ;
	}
    }
  sender->serialize_data(request::server::Forbidden());
}

void	Friends::refuse(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::friends::client::Refuse	*origin = dynamic_cast<const request::friends::client::Refuse *>(req);
  IClient::Pointer				receiver;

  if (sender->Authenticated() &&
      sender->Username() == origin->from &&
      _db.isRequestExist(origin->from, request::friends::client::Request(origin->to, origin->from)) &&
      _db.isRequestExist(origin->to, request::friends::client::Request(origin->to, origin->from)))
    {
      IClient::Pointer				receiver;

      if (searchClient(clients, origin->to, receiver) && receiver->Authenticated())
	{
#if defined(DEBUG)
	  std::cout << origin->from << " refuse request from " << origin->to << std::endl;
#endif
	  receiver->serialize_data(*origin);
	}
      else
	_db.addRequest(origin->to, *origin);
      _db.delRequest(origin->from, request::friends::client::Request(origin->to, origin->from));
      _db.delRequest(origin->to, request::friends::client::Request(origin->to, origin->from));
      sender->serialize_data(request::server::Ok());
      return ;
    }
  sender->serialize_data(request::server::Forbidden());
}

void	Friends::sendFriendStatus(IClient::Pointer &sender,
				  const std::list<IClient::Pointer> &clients,
				  const std::string &username)
{
  IClient::Pointer	receiver;

  if (searchClient(clients, username, receiver))
    {
      std::cout << "Moi" <<  sender->Username() << std::endl;
      std::cout << "Amis ajouter" <<  receiver->Username() << std::endl;
      sender->serialize_data(request::friends::server::Update(receiver->status(),
							    receiver->statusDetail(),
							    username));
    }
  else
    sender->serialize_data(request::friends::server::Update(request::User::Status::DISCONNECTED,
							    std::string(),
							    username));
}

void	Friends::list(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  Database::list_friend		friends;

  (void)req;
#if defined(DEBUG)
  std::cout << "Friends::List()" << std::endl;
#endif
  if (sender->Authenticated() &&
      _db.clientExist(sender->Username()) &&
      _db.listFriend(sender->Username(), friends))
    {
      // sender->serialize_data(request::server::Ok());
      for (Database::list_friend::const_iterator it = friends.begin(); it != friends.end(); ++it)
	{
	  if (!_db.clientExist(*it))
	    {
	      _db.delFriend(sender->Username(), *it);
	      sender->serialize_data(request::friends::server::Update(request::User::Status::DELETED,
								      std::string(),
								      *it));
	    }
	  else
	    sendFriendStatus(sender, clients, *it);
	}
    }
  else
    sender->serialize_data(request::server::Forbidden());
}

void	Friends::setActions(std::map<request::ID, plugin::request_handler> &map)
{
  map[request::client::friends::REQUEST] = plugin::request_handler(&Friends::request, this);
  map[request::client::friends::DEL_FRIEND] = plugin::request_handler(&Friends::del_friend, this);
  map[request::client::friends::ACCEPT] = plugin::request_handler(&Friends::accept, this);
  map[request::client::friends::REFUSE] = plugin::request_handler(&Friends::refuse, this);
  map[request::client::friends::LIST] = plugin::request_handler(&Friends::list, this);
}

request::IRequestPlugin	*loadPlugin(Database &db, Env &env)
{
  return (new Friends(db, env));
}
