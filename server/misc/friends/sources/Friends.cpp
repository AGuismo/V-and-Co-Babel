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

plugin::IPlugin<request::ID, void (*)(Server *, Client::Pointer, const ARequest *)>	*Friends::clone()
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

void	Friends::request(Server *serv, Client::Pointer sender, const ARequest *req)
{
  (void)serv;
  const request::friends::client::Request	*origin = dynamic_cast<const request::friends::client::Request *>(req);

  std::cout << "Friends::request()" << std::endl;
  std::cout << "From : " << origin->from << std::endl;
  std::cout << "To : " << origin->to << std::endl;
}

void	Friends::del_friend(Server *serv, Client::Pointer sender, const ARequest *req)
{
  (void)serv;
  const request::friends::client::DelFriend	*origin = dynamic_cast<const request::friends::client::DelFriend *>(req);

  std::cout << "Friends::del_friend()" << std::endl;
  std::cout << "From : " << origin->from << std::endl;
  std::cout << "To : " << origin->to << std::endl;
}

void	Friends::accept(Server *serv, Client::Pointer sender, const ARequest *req)
{
  (void)serv;
  const request::friends::client::Accept	*origin = dynamic_cast<const request::friends::client::Accept *>(req);

  std::cout << "Friends::refuse()" << std::endl;
  std::cout << "From : " << origin->from << std::endl;
  std::cout << "To : " << origin->to << std::endl;
}

void	Friends::refuse(Server *serv, Client::Pointer sender, const ARequest *req)
{
  (void)serv;
  const request::friends::client::Refuse	*origin = dynamic_cast<const request::friends::client::Refuse *>(req);

  std::cout << "Friends::refuse()" << std::endl;
  std::cout << "From : " << origin->from << std::endl;
  std::cout << "To : " << origin->to << std::endl;
}

void	Friends::list(Server *serv, Client::Pointer sender, const ARequest *req)
{
  (void)serv;
  const request::friends::client::List	*origin = dynamic_cast<const request::friends::client::List *>(req);

  std::cout << "Friends::List()" << std::endl;

}

void	Friends::setActions(std::map<request::ID, void (*)(Server *, Client::Pointer, const ARequest *)> &map)
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
