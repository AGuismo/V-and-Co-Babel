#include	<iostream>
#include	"Call.hh"
#include	"IRequestPlugin.hh"
#include	"RequestCode.hh"
#include	"CallRequest.hh"
#include	"ServerRequest.hh"
#include	"Database.hh"
#include	"types.hh"
#include	"Server.hh"

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

void	Call::getVersion(plugin::version::major &maj, plugin::version::minor &min) const
{
  maj = plugin::version::MAJOR;
  min = plugin::version::MINOR;
}

bool	Call::searchClient(Server *serv, const std::string &name, Client::Pointer &client)
{
  const Server::client_list	&clients = serv->getClients();

  for (Server::client_list::const_iterator it = clients.begin(); it != clients.end(); ++it)
    {
      if ((*it)->InfosClient._name == name)
	{
	  client = *it;
	  return (true);
	}
    }
  return (false);
}

void	Call::call(Server *serv, Client::Pointer sender, const ARequest *req)
{
  (void)serv;
  const request::call::client::CallClient	*origin = dynamic_cast<const request::call::client::CallClient *>(req);
  Client::Pointer				receiver;

  std::cout << "Call::call()" << std::endl;
  std::cout << "From : " << origin->_from << std::endl;
  std::cout << "To : " << origin->_to << std::endl;
  std::cout << "Option : " << origin->_option << std::endl;

  if (sender->InfosClient._isConnect &&
      sender->InfosClient._status == request::User::Status::CONNECTED &&
      Database::getInstance().clientExist(origin->_from) &&
      Database::getInstance().clientExist(origin->_to))
    {
#if defined(DEBUG)
      std::cout << "Receive a call request from [" << origin->_from << "] to [" << origin->_to << "]" << std::endl;
#endif
      if (searchClient(serv, origin->_to, receiver))
	{
#if defined(DEBUG)
	  std::cout << "Call send ..." << std::endl;
#endif
	  request::call::client::CallClient fwd(*origin);
	  fwd._ip = sender->socket().remote_endpoint().address().to_v4().to_ulong();

	  if (receiver->InfosClient._isConnect &&
	      receiver->InfosClient._status == request::User::Status::CONNECTED)
	    receiver->serialize_data(fwd);
	  else
	    sender->serialize_data(request::server::Forbidden());
	  return ;
	}
    }
  sender->serialize_data(request::server::Forbidden());
}

void	Call::accept(Server *serv, Client::Pointer sender, const ARequest *req)
{
  (void)serv;
  const request::call::client::AcceptClient	*origin = dynamic_cast<const request::call::client::AcceptClient *>(req);
  Client::Pointer				receiver;

  if (sender->InfosClient._isConnect &&
      sender->InfosClient._status == request::User::Status::CONNECTED &&
      Database::getInstance().clientExist(origin->_from) &&
      Database::getInstance().clientExist(origin->_to))
    {
#if defined(DEBUG)
      std::cout << "Receive an accept request from [" << origin->_from << "] to [" << origin->_to << "]" << std::endl;
#endif
      if (searchClient(serv, origin->_to, receiver))
	{
#if defined(DEBUG)
	  std::cout << "Sending..." << std::endl;
#endif
	  request::call::client::AcceptClient fwd(*origin);
	  fwd._ip = sender->socket().remote_endpoint().address().to_v4().to_ulong();
	  if (receiver->InfosClient._isConnect &&
	      receiver->InfosClient._status == request::User::Status::CONNECTED)
	    receiver->serialize_data(fwd);
	  else
	    sender->serialize_data(request::server::Forbidden());
	  return ;
	}
    }
  sender->serialize_data(request::server::Forbidden());
}

void	Call::refuse(Server *serv, Client::Pointer sender, const ARequest *req)
{
  (void)serv;
  const request::call::client::RefuseClient	*origin = dynamic_cast<const request::call::client::RefuseClient *>(req);
  Client::Pointer				receiver;

  if (sender->InfosClient._isConnect &&
      sender->InfosClient._status == request::User::Status::CONNECTED &&
      Database::getInstance().clientExist(origin->_from) &&
      Database::getInstance().clientExist(origin->_to))
    {
#if defined(DEBUG)
      std::cout << "Receive a refuse request from [" << origin->_from << "] to [" << origin->_to << "]" << std::endl;
#endif
      if (searchClient(serv, origin->_to, receiver))
	{
#if defined(DEBUG)
	  std::cout << "Refuse Send..." << std::endl;
#endif
	  if (receiver->InfosClient._isConnect &&
	      receiver->InfosClient._status == request::User::Status::CONNECTED)
	    receiver->serialize_data(*origin);
	  else
	    sender->serialize_data(request::server::Forbidden());
	  return ;
	}
    }
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
