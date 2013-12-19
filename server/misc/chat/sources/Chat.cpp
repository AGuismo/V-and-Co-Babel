#include	<iostream>
#include	"Chat.hh"
#include	"IRequestPlugin.hh"
#include	"RequestCode.hh"
#include	"ChatRequest.hh"
#include	"ServerRequest.hh"
#include	"Database.hh"
#include	"types.hh"
#include	"Function.hpp"

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

void	Chat::message(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::chat::client::Message	*origin = dynamic_cast<const request::chat::client::Message *>(req);

  std::cout << "Chat::Message()" << std::endl;
  std::cout << "From : " << origin->from << std::endl;
  std::cout << "To : " << origin->to << std::endl;
  std::cout << "Time : " << origin->time << std::endl;
  std::cout << "Msg : " << origin->msg << std::endl;
}

void	Chat::setActions(std::map<request::ID, plugin::request_handler> &map)
{
  map[request::client::chat::MESSAGE] = plugin::request_handler(&Chat::message, this);
}


request::IRequestPlugin	*loadPlugin(Database &db, Env &env)
{
  return (new Chat(db, env));
}
