#include	<iostream>
#include	"Auth.hh"
#include	"IRequestPlugin.hh"
#include	"RequestCode.hh"
#include	"AuthRequest.hh"
#include	"Database.hh"

Auth::Auth()
{

}

Auth::~Auth()
{

}

Auth::Auth(Auth const &src)
{

}

Auth	&Auth::operator=(Auth const &src)
{
  if (this != &src)
    {

    }
  return (*this);
}

plugin::IPlugin<request::ID, void (*)(Server *, Client::Pointer, const ARequest *)>	*Auth::clone()
{
  return (new Auth(*this));
}

void	Auth::unload()
{
  delete this;
}

void	Auth::new_account(Server *serv, Client::Pointer sender, const ARequest *req)
{
  const request::auth::client::NewClient	*origin = dynamic_cast<const request::auth::client::NewClient *>(req);

  std::cout << "Auth::new_account()" << std::endl;
  Database::getInstance().newClient(origin->_name, origin->_password);
}

void	Auth::connect(Server *serv, Client::Pointer sender, const ARequest *req)
{
  const request::auth::client::ConnectClient	*origin = dynamic_cast<const request::auth::client::ConnectClient *>(req);

  std::cout << "Auth::connect()" << std::endl;
  if (Database::getInstance().clientExist(origin->_name, origin->_password))
    std::cout << "Auth::connect(): " << "OK" << std::endl;
  else
    std::cout << "Auth::connect(): " << "FAIL" << std::endl;
}

void	Auth::setActions(std::map<request::ID, void (*)(Server *, Client::Pointer, const ARequest *)> &map)
{
  map[request::client::auth::NEW] = &Auth::new_account;
  map[request::client::auth::CONNECT] = &Auth::connect;
}


request::IRequestPlugin	*loadPlugin()
{
  return (new Auth);
}
