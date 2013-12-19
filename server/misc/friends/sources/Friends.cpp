#include	<iostream>
#include	"Friends.hh"
#include	"IRequestPlugin.hh"
#include	"RequestCode.hh"
#include	"FriendRequest.hh"
#include	"ServerRequest.hh"
#include	"Database.hh"
#include	"types.hh"

Friends::Friends()
{

}

Friends::~Friends()
{

}

Friends::Friends(Friends const &src)
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

plugin::IPlugin<request::ID, void(*)(const std::list<IClient::Pointer> &, Database &, IClient::Pointer, const ARequest *)>	*Friends::clone()
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

void	Friends::request(const std::list<IClient::Pointer> &clients, Database &db, IClient::Pointer sender, const ARequest *req)
{
  const request::friends::client::Request	*origin = dynamic_cast<const request::friends::client::Request *>(req);
  IClient::Pointer				receiver;


  if (sender->Authenticated() &&
      // tester si le sender à déjà le receiver en ami
      sender->status() == request::User::Status::CONNECTED &&
      db.clientExist(origin->to) &&
      db.clientExist(origin->from))
    {
#if defined(DEBUG)
      std::cout << "Receive a friend request from [" << origin->from << "] to [" << origin->to << "]" << std::endl;
#endif
      if (searchClient(clients, origin->_to, receiver))
	{
#if defined(DEBUG)
	  std::cout << "Friend request send ..." << std::endl;
#endif
	  if (receiver->Authenticated() &&
	      receiver->status() == request::User::Status::CONNECTED)
	    receiver->serialize_data(origin);
	  else
	    sender->serialize_data(request::server::Forbidden());
	  return ;
	}
    }
  sender->serialize_data(request::server::Forbidden());
}

void	Friends::del_friend(const std::list<IClient::Pointer> &clients, Database &db, IClient::Pointer sender, const ARequest *req)
{
  const request::friends::client::DelFriend	*origin = dynamic_cast<const request::friends::client::DelFriend *>(req);

  if (sender->Authenticated() &&
      // tester si le sender à déjà le receiver en ami
      sender->status() == request::User::Status::CONNECTED &&
      db.clientExist(origin->to) &&
      db.clientExist(origin->from))
      //&& inclure db.delFriend(origin->from, [Comment avoir le FriendID])
    {
#if defined(DEBUG)
      std::cout << "Receive a delete friend request from [" << origin->from << "] to [" << origin->to << "]" << std::endl;
#endif
  sender->serialize_data(request::server::Ok());
    }
  sender->serialize_data(request::server::Forbidden());
}

void	Friends::accept(const std::list<IClient::Pointer> &clients, Database &db, IClient::Pointer sender, const ARequest *req)
{
  const request::friends::client::Accept	*origin = dynamic_cast<const request::friends::client::Accept *>(req);
  IClient::Pointer				receiver;

  if (sender->Authenticated() &&
      // tester si le sender à déjà le receiver en ami
      sender->status() == request::User::Status::CONNECTED &&
      db.clientExist(origin->to) &&
      db.clientExist(origin->from))
      //&& inclure db.delFriend(origin->from, [Comment avoir le FriendID])
    {
      if (searchClient(clients, origin->_to, receiver))
	{
#if defined(DEBUG)
	  std::cout << "accept request send ..." << std::endl;
#endif
	  if (receiver->Authenticated() &&
	      receiver->status() == request::User::Status::CONNECTED)
	    receiver->serialize_data(origin);
	  else
	    sender->serialize_data(request::server::Forbidden());
	  return ;
	}
    }
  sender->serialize_data(request::server::Forbidden());
}

void	Friends::refuse(const std::list<IClient::Pointer> &clients, Database &db, IClient::Pointer sender, const ARequest *req)
{
  const request::friends::client::Refuse	*origin = dynamic_cast<const request::friends::client::Refuse *>(req);
  IClient::Pointer				receiver;

  if (sender->Authenticated() &&
      // tester si le sender à déjà le receiver en ami
      sender->status() == request::User::Status::CONNECTED &&
      db.clientExist(origin->to) &&
      db.clientExist(origin->from))
      //&& inclure db.delFriend(origin->from, [Comment avoir le FriendID])
    {
      if (searchClient(clients, origin->_to, receiver))
	{
#if defined(DEBUG)
	  std::cout << "refuse request send ..." << std::endl;
#endif
	  if (receiver->Authenticated() &&
	      receiver->status() == request::User::Status::CONNECTED)
	    receiver->serialize_data(origin);
	  else
	    sender->serialize_data(request::server::Forbidden());
	  return ;
	}
    }
  sender->serialize_data(request::server::Forbidden());
}

void	Friends::list(const std::list<IClient::Pointer> &clients, Database &db, IClient::Pointer sender, const ARequest *req)
{
  const request::friends::client::List	*origin = dynamic_cast<const request::friends::client::List *>(req);

  std::cout << "Friends::List()" << std::endl;
  if (sender->Authenticated() &&
      sender->status() == request::User::Status::CONNECTED &&
      db.clientExist(origin->to))
      //&& inclure db.listFriend(origin->to)
    {
      //envoyer la list des amis
    }
  else
    sender->serialize_data(request::server::Forbidden());
}

void	Friends::setActions(std::map<request::ID, void(*)(const std::list<IClient::Pointer> &, Database &, IClient::Pointer, const ARequest *)> &map)
{
  map[request::client::friends::REQUEST] = &Friends::request;
  map[request::client::friends::DEL_FRIEND] = &Friends::del_friend;
  map[request::client::friends::ACCEPT] = &Friends::accept;
  map[request::client::friends::REFUSE] = &Friends::refuse;
  map[request::client::friends::LIST] = &Friends::list;
}


request::IRequestPlugin	*loadPlugin()
{
  return (new Friends);
}
