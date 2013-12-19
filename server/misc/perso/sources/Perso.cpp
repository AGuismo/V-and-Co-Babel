#include	<iostream>
#include	<fstream>
#include	<cstdio>
#include	"Perso.hh"
#include	"IRequestPlugin.hh"
#include	"RequestCode.hh"
#include	"PersoRequest.hh"
#include	"ServerRequest.hh"
#include	"types.hh"


Perso::Perso(Database &db):
  _db(db)
{

}

Perso::~Perso()
{

}

Perso::Perso(Perso const &src):
  _db(src._db)
{
}

Perso	&Perso::operator=(Perso const &src)
{
  if (this != &src)
    {
      _db = src._db;
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
  if (_db.modPrivacy(sender->Username(), origin->_privacy))
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
  if (_db.setStatus(sender->Username(), origin->_status, origin->_statusDetails))
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

bool	Perso::createAnswerFile(IClient::Pointer sender)
{
  std::ofstream	file;

  file.open(std::string("./misc/auto_answer/" + sender->Username() + ".rep").c_str(), // to change
	    std::ios::trunc);
  if (file.bad())
    return false;

  sender->serializeAnswer() << sender->AutoAnswer().size();
  sender->serializeAnswer() << sender->AutoAnswer();
  file << sender->serializeAnswer().data();
  file.close();
  return true;
}

void	Perso::set_auto_answer(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::perso::client::SetAutoAnswerClient	*origin = dynamic_cast<const request::perso::client::SetAutoAnswerClient *>(req);

  if (origin->_answer.size() != 0)
    {
#if defined(DEBUG)
      std::cout << "Receive : [" << origin->_answer.size() << "] " << std::endl;
#endif
      sender->updateAutoAnswer(origin->_answer);
    }
  else
    {
#if defined(DEBUG)
      std::cout << "File is full" << std::endl;
#endif
      if (createAnswerFile(sender))
	{
#if defined(DEBUG)
	  std::cout << "File was successfuly created !" << std::endl;
#endif
	}
      else
	{
#if defined(DEBUG)
	  std::cout << "Failed since the file creation" << std::endl;
#endif
	}
    }
}

void	Perso::pong(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::perso::client::Pong	*origin = dynamic_cast<const request::perso::client::Pong *>(req);

  std::cout << "Perso::Pong()" << std::endl;
}

void	Perso::unset_auto_answer(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::perso::client::UnsetAutoAnswer	*origin = dynamic_cast<const request::perso::client::UnsetAutoAnswer *>(req);

  if ((remove("/misc/auto_answer/" + sender->Username() + ".rep").c_str()) != 0)
    {
#if defined(DEBUG)
      std::cout << "Can't remove the file" << std::endl;
#endif
      sender->serialize_data(request::server::Forbidden());
    }
  else
    {
#if defined(DEBUG)
      std::cout << "The file has been removed" << std::endl;
#endif
      sender->serialize_data(request::server::Ok());
    }
}

void	Perso::setActions(std::map<request::ID, void(*)(const std::list<IClient::Pointer> & IClient::Pointer, const ARequest *)> &map)
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

request::IRequestPlugin	*loadPlugin(Database &db)
{
  return (new Perso(db));
}
