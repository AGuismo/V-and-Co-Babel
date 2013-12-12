#include	<iostream>
#include	"Chat.hh"
#include	"IRequestPlugin.hh"
#include	"RequestCode.hh"
#include	"ChatRequest.hh"
#include	"ServerRequest.hh"
#include	"Database.hh"
#include	"types.hh"

Chat::Chat()
{

}

Chat::~Chat()
{

}

Chat::Chat(Chat const &src)
{
  (void)src;
}

Chat	&Chat::operator=(Chat const &src)
{
  if (this != &src)
    {

    }
  return (*this);
}

plugin::IPlugin<request::ID, void (*)(Server *, Client::Pointer, const ARequest *)>	*Chat::clone()
{
  return (new Chat(*this));
}

void	Chat::unload()
{
  delete this;
}

void	Chat::message(Server *serv, Client::Pointer sender, const ARequest *req)
{
  (void)serv;
  const request::chat::client::Message	*origin = dynamic_cast<const request::chat::client::Message *>(req);

  std::cout << "Chat::Message()" << std::endl;
  std::cout << "From : " << origin->from << std::endl;
  std::cout << "To : " << origin->to << std::endl;
  std::cout << "Time : " << origin->time << std::endl;
  std::cout << "Msg : " << origin->msg << std::endl;
}


void	Chat::setActions(std::map<request::ID, void (*)(Server *, Client::Pointer, const ARequest *)> &map)
{
  map[request::client::chat::MESSAGE] = &Chat::message;
}


request::IRequestPlugin	*loadPlugin()
{
  return (new Chat);
}