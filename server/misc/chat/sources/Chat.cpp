#include	<iostream>
#include	"Chat.hh"
#include	"IRequestPlugin.hh"
#include	"RequestCode.hh"
#include	"ChatRequest.hh"
#include	"ServerRequest.hh"
#include	"Database.hh"
#include	"types.hh"
#include	"Function.hpp"
#include	"Server.hh"

Chat::Chat(Database &db, Env &env):
  _db(db), _env(env)
{

}

Chat::~Chat()
{

}

Chat::Chat(Chat const &src):
  _db(src._db), _env(src._env)
{
}

Chat	&Chat::operator=(Chat const &src)
{
  if (this != &src)
    {

    }
  return (*this);
}

plugin::IPlugin<request::ID, plugin::request_handler>	*Chat::clone()
{
  return (new Chat(*this));
}

void	Chat::unload()
{
  delete this;
}

void	Chat::getVersion(plugin::version::major &maj, plugin::version::minor &min) const
{
  maj = plugin::version::MAJOR;
  min = plugin::version::MINOR;
}

bool	Chat::searchClient(const std::list<IClient::Pointer> &clients, const std::string &name, IClient::Pointer &client)
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

void	Chat::message(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::chat::client::Message	*origin = dynamic_cast<const request::chat::client::Message *>(req);
  IClient::Pointer receiver;

  if (sender->Authenticated() &&
      sender->Username() == origin->from &&
      _db.clientExist(origin->to))
    {
#if defined(DEBUG)
      std::cout << "Message FROM : [" << origin->from << "], TO : [" << origin->to << "] CONTENT : [" << origin->msg << "], DATE : [" << origin->time << "]" << std::endl;
#endif
      if (searchClient(clients, origin->to, receiver))
	{
#if defined(DEBUG)
	  std::cout << "Message send ..." << std::endl;
#endif
	  if (receiver->Authenticated())
	    {
	      receiver->serialize_data(*origin);
	      sender->serialize_data(request::server::Ok());
	      return ;
	    }
	}
    }
  sender->serialize_data(request::server::Forbidden());
}

void	Chat::setActions(std::map<request::ID, plugin::request_handler> &map)
{
  map[request::client::chat::MESSAGE] = plugin::request_handler(&Chat::message, this);
}


request::IRequestPlugin	*loadPlugin(Database &db, Env &env)
{
  return (new Chat(db, env));
}
