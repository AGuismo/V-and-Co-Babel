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

plugin::IPlugin<request::ID, void (*)(Server *, Client::Pointer, const ARequest *)>	*Auth::clone()
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

void	Auth::new_account(Server *serv, Client::Pointer sender, const ARequest *req)
{
  (void)serv;
  const request::auth::client::NewClient	*origin = dynamic_cast<const request::auth::client::NewClient *>(req);

  std::cout << "Auth::new_account()" << std::endl;
  if (Database::getInstance().newClient(origin->_name, origin->_password))
    {
      sender->InfosClient._isConnect = false;
      sender->InfosClient._name = origin->_name;
      sender->InfosClient._privacy = request::User::PUBLIC;
      sender->InfosClient._status = request::User::Status::DISCONNECTED;
      sender->serialize_data(request::server::Ok());
    }
  else
    sender->serialize_data(request::server::Forbidden());
}

void	Auth::connect(Server *serv, Client::Pointer sender, const ARequest *req)
{
  (void)serv;
  const request::auth::client::ConnectClient	*origin = dynamic_cast<const request::auth::client::ConnectClient *>(req);

  std::cout << "Auth::connect()" << std::endl;
  if (Database::getInstance().clientExist(origin->_name, origin->_password))
    {
      sender->serialize_data(request::server::Ok());
      sender->InfosClient._isConnect = true;
      sender->InfosClient._status = request::User::Status::CONNECTED;
    }
  else
    sender->serialize_data(request::server::Forbidden());
}

void	Auth::disconnect(Server *serv, Client::Pointer sender, const ARequest *req)
{
  const request::auth::client::DisconnectClient	*origin = dynamic_cast<const request::auth::client::DisconnectClient *>(req);

  std::cout << "Auth::disconnect()" << std::endl;
  // if (Database::getInstance().clientExist(origin->_name, origin->_password))
  (void)origin;
  (void)serv;
  sender->serialize_data(request::server::Ok());
  sender->InfosClient._isConnect = false;
  sender->InfosClient._status = request::User::Status::DISCONNECTED;
  // else
  //   sender->serialize_request(request::server::FORBIDDEN);
}

void	Auth::setActions(std::map<request::ID, void (*)(Server *, Client::Pointer, const ARequest *)> &map)
{
  map[request::client::auth::NEW] = &Auth::new_account;
  map[request::client::auth::CONNECT] = &Auth::connect;
  // map[request::client::auth::MODIFY] = &Auth::modify;
  // map[request::client::auth::REMOVE] = &Auth::remove;
  map[request::client::auth::DISCONNECT] = &Auth::disconnect;
}

request::IRequestPlugin	*loadPlugin()
{
	return (new Auth);
}