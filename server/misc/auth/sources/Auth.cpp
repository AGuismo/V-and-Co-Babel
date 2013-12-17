#include	<iostream>
#include	"Auth.hh"
#include	"types.hh"
#include	"RequestCode.hh"
#include	"AuthRequest.hh"
#include	"ServerRequest.hh"
#include	"Database.hh"

Auth::Auth()
{

}

Auth::~Auth()
{

}

Auth::Auth(Auth const &src)
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

plugin::IPlugin<request::ID, void (*)(const std::list<IClient::Pointer> &, IClient::Pointer, const ARequest *)>	*Auth::clone()
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

  if (Database::getInstance().newClient(origin->_name, origin->_password))
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

void	Auth::connect(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::auth::client::ConnectClient	*origin = dynamic_cast<const request::auth::client::ConnectClient *>(req);

  std::cout << "Auth::Connect(): " << (void *)(&Database::getInstance()) << std::endl;

  if (sender->Authenticated() == false &&
      Database::getInstance().clientExist(origin->_name, origin->_password))
    {
#if defined(DEBUG)
      std::cout << "Connection on the account : [" << origin->_name << "]" << std::endl;
#endif
      sender->serialize_data(request::server::Ok());
      sender->Authenticated(true);
      sender->status(request::User::Status::CONNECTED);
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
  if (sender->Authenticated() == true &&
      Database::getInstance().modClientPass(origin->_name, origin->_oldPassword, origin->_newPassword))
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

void	Auth::remove(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::auth::client::DelClient	*origin = dynamic_cast<const request::auth::client::DelClient *>(req);

  std::cout << "Auth::delete()" << std::endl;
  if (sender->Authenticated() == false &&
      Database::getInstance().delClient(origin->_name, origin->_password))
    {
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
#if defined(DEBUG)
      std::cout << "The client has been disconnected" << std::endl;
#endif
      sender->serialize_data(request::server::Ok());
      sender->Authenticated(false);
      sender->status(request::User::Status::DISCONNECTED);
    }
  else
    {
#if defined(DEBUG)
      std::cout << "Can't disconnect the client" << std::endl;
#endif
    }
}

void	Auth::setActions(std::map<request::ID, void(*)(const std::list<IClient::Pointer> &, IClient::Pointer, const ARequest *)> &map)
{
  map[request::client::auth::NEW] = &Auth::new_account;
  map[request::client::auth::CONNECT] = &Auth::connect;
  map[request::client::auth::MODIFY] = &Auth::modify;
  map[request::client::auth::REMOVE] = &Auth::remove;
  map[request::client::auth::DISCONNECT] = &Auth::disconnect;
}

request::IRequestPlugin	*loadPlugin()
{
	return (new Auth);
}
