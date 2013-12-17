#include	<iostream>
#include	"Perso.hh"
#include	"IRequestPlugin.hh"
#include	"RequestCode.hh"
#include	"PersoRequest.hh"
#include	"ServerRequest.hh"
#include	"Database.hh"
#include	"types.hh"

Perso::Perso()
{

}

Perso::~Perso()
{

}

Perso::Perso(Perso const &src)
{
  (void)src;
}

Perso	&Perso::operator=(Perso const &src)
{
  if (this != &src)
    {

    }
  return (*this);
}

plugin::IPlugin<request::ID, void (*)(const std::list<IClient::Pointer> &, IClient::Pointer, const ARequest *)>	*Perso::clone()
{
  return (new Perso(*this));
}

void	Perso::unload()
{
  delete this;
}

void	Perso::getVersion(plugin::version::major &maj, plugin::version::minor &min) const
{
  maj = plugin::version::MAJOR;
  min = plugin::version::MINOR;
}

void	Perso::privacy_mode(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::perso::client::ModifyPrivacy	*origin = dynamic_cast<const request::perso::client::ModifyPrivacy *>(req);

#if defined(DEBUG)
  std::cout << "Set Privacy request" << std::endl;
#endif
  if (Database::getInstance().modPrivacy(sender->Username(), origin->_privacy))
    {
#if defined(DEBUG)
      std::cout << "Privacy set" << std::endl;
#endif
      sender->serialize_data(request::server::Ok());
    }
  else
    {
#if defined(DEBUG)
      std::cout << "Can't set Privacy" << std::endl;
#endif
      sender->serialize_data(request::server::Forbidden());
    }
}

void	Perso::status(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::perso::client::StatusClient	*origin = dynamic_cast<const request::perso::client::StatusClient *>(req);

#if defined(DEBUG)
  std::cout << "Change status request" << std::endl;
#endif
  if (Database::getInstance().setStatus(sender->Username(), origin->_status, origin->_statusDetails))
    {
#if defined(DEBUG)
      std::cout << "Status has been set" << std::endl;
#endif
      sender->serialize_data(request::server::Ok());
    }
  else
    {
#if defined(DEBUG)
      std::cout << "Status has been set" << std::endl;
#endif
      sender->serialize_data(request::server::Forbidden());
    }
}

void	Perso::missed_calls(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::perso::client::MissedCallClient	*origin = dynamic_cast<const request::perso::client::MissedCallClient *>(req);

  std::cout << "Perso::missed_call()" << std::endl;
}

void	Perso::get_missed(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::perso::client::GetMissedClient	*origin = dynamic_cast<const request::perso::client::GetMissedClient *>(req);

  std::cout << "Perso::get_Missed()" << std::endl;
  std::cout << "IDX ANSWER : " << origin->_idxAnswer << std::endl;
}

void	Perso::del_missed(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::perso::client::DelMissedClient	*origin = dynamic_cast<const request::perso::client::DelMissedClient *>(req);

  std::cout << "Perso::del_missed()" << std::endl;
  std::cout << "IDX ANSWER : " << origin->_idxAnswer << std::endl;
}

void	Perso::set_auto_answer(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::perso::client::SetAutoAnswerClient	*origin = dynamic_cast<const request::perso::client::SetAutoAnswerClient *>(req);

  std::cout << "Perso::set_auto_answer()" << std::endl;
  std::cout << "Answer : " << origin->_answer << std::endl;
}

void	Perso::pong(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::perso::client::Pong	*origin = dynamic_cast<const request::perso::client::Pong *>(req);

  std::cout << "Perso::Pong()" << std::endl;
}

void	Perso::unset_auto_answer(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::perso::client::UnsetAutoAnswer	*origin = dynamic_cast<const request::perso::client::UnsetAutoAnswer *>(req);

  std::cout << "Perso::unset_auto_answer()" << std::endl;
}

void	Perso::setActions(std::map<request::ID, void (*)(const std::list<IClient::Pointer> &, IClient::Pointer, const ARequest *)> &map)
{
  map[request::client::perso::PRIVACY_MODE] = &Perso::privacy_mode;
  map[request::client::perso::STATUS] = &Perso::status;
  map[request::client::perso::MISSED_CALLS] = &Perso::missed_calls;
  map[request::client::perso::GET_MISSED] = &Perso::get_missed;
  map[request::client::perso::DEL_MISSED] = &Perso::del_missed;
  map[request::client::perso::SET_AUTO_ANSWER] = &Perso::set_auto_answer;
  map[request::client::perso::PONG] = &Perso::pong;
  map[request::client::perso::UNSET_AUTO_ANSWER] = &Perso::unset_auto_answer;
}


request::IRequestPlugin	*loadPlugin()
{
  return (new Perso);
}
