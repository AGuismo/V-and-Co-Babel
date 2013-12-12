#include	<iostream>
#include	"Call.hh"
#include	"IRequestPlugin.hh"
#include	"RequestCode.hh"
#include	"CallRequest.hh"
#include	"ServerRequest.hh"
#include	"Database.hh"
#include	"types.hh"

Call::Call()
{

}

Call::~Call()
{

}

Call::Call(Call const &src)
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

plugin::IPlugin<request::ID, void (*)(Server *, Client::Pointer, const ARequest *)>	*Call::clone()
{
  return (new Call(*this));
}

void	Call::unload()
{
  delete this;
}

void	Call::call(Server *serv, Client::Pointer sender, const ARequest *req)
{
  (void)serv;
  const request::call::client::CallClient	*origin = dynamic_cast<const request::call::client::CallClient *>(req);

  std::cout << "Call::call()" << std::endl;
  std::cout << "From : " << origin->_from << std::endl;
  std::cout << "To : " << origin->_to << std::endl;
  std::cout << "Option : " << origin->_option << std::endl;

  if (Database::getInstance().clientExist(origin->_from) &&
      Database::getInstance().clientExist(origin->_to))
    {
    }

  /* FORWARD LA REQUETE */

}

void	Call::accept(Server *serv, Client::Pointer sender, const ARequest *req)
{
  (void)serv;
  const request::call::client::AcceptClient	*origin = dynamic_cast<const request::call::client::AcceptClient *>(req);

  std::cout << "Call::accept()" << std::endl;
  std::cout << "From : " << origin->_from << std::endl;
  std::cout << "To : " << origin->_to << std::endl;
}

void	Call::refuse(Server *serv, Client::Pointer sender, const ARequest *req)
{
  (void)serv;
  const request::call::client::RefuseClient	*origin = dynamic_cast<const request::call::client::RefuseClient *>(req);

  std::cout << "Call::refuse()" << std::endl;
  std::cout << "From : " << origin->_from << std::endl;
  std::cout << "To : " << origin->_to << std::endl;
}

void	Call::hangup(Server *serv, Client::Pointer sender, const ARequest *req)
{
  (void)serv;
  const request::call::client::HangupClient	*origin = dynamic_cast<const request::call::client::HangupClient *>(req);

  std::cout << "Call::Hangup()" << std::endl;
  std::cout << "From : " << origin->_from << std::endl;
  std::cout << "To : " << origin->_to << std::endl;
}


void	Call::setActions(std::map<request::ID, void (*)(Server *, Client::Pointer, const ARequest *)> &map)
{
  map[request::client::call::CALL] = &Call::call;
  map[request::client::call::ACCEPT] = &Call::accept;
  map[request::client::call::REFUSE] = &Call::refuse;
  map[request::client::call::HANG_UP] = &Call::hangup;
}


request::IRequestPlugin	*loadPlugin()
{
  return (new Call);
}
