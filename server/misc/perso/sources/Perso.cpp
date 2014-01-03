#include	<iostream>
#include	<fstream>
#include	<cstdio>
#include	"Perso.hh"
#include	"IRequestPlugin.hh"
#include	"RequestCode.hh"
#include	"PersoRequest.hh"
#include	"FriendRequest.hh"
#include	"ServerRequest.hh"
#include	"types.hh"
#include	"Database.hh"
#include	"Env.hh"
#include	"Server.hh"

Perso::Perso(Database &db, Env &env):
_db(db), _env(env)
{

}

Perso::~Perso()
{

}

Perso::Perso(Perso const &src):
_db(src._db), _env(src._env)
{
}

plugin::IPlugin<request::ID, plugin::request_handler>	*Perso::clone()
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
  if (sender->privacy() != origin->_privacy && _db.modPrivacy(sender->Username(), origin->_privacy))
    {
#if defined(DEBUG)
      std::cout << "Privacy set" << std::endl;
#endif
      sender->privacy(origin->_privacy);
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

void	Perso::sendChangeStatusFriends(const IClient::Pointer &sender,
				       const Database::list_friend &friends,
				       const request::perso::client::StatusClient *origin,
				       const std::list<IClient::Pointer> &clients)
{
  for (std::list<IClient::Pointer>::const_iterator itClient = clients.begin();
       itClient != clients.end(); ++itClient)
    {
      for (Database::list_friend::const_iterator it = friends.begin();
	   it != friends.end(); ++it)
	{
	  if ((*itClient)->Authenticated() && (*itClient)->Username() == *it)
	    (*itClient)->serialize_data(request::friends::server::Update(origin->_status,
									 origin->_statusDetails,
									 sender->Username()));
	}
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
      Database::list_friend	friends;

      if (_db.listFriend(sender->Username(), friends))
	sendChangeStatusFriends(sender, friends, origin, clients);
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
  Rint32 nb;
  if (sender->Authenticated() &&
      ((nb = _db.getNbMissed(sender->Username())) != -1))
    sender->serialize_data(request::perso::server::MissedCallServer(nb));
  else
    sender->serialize_data(request::server::Forbidden());
}

void	Perso::get_missed(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::perso::client::GetMissedClient	*origin = dynamic_cast<const request::perso::client::GetMissedClient *>(req);

  std::string filename;

  if (sender->Authenticated() &&
      ((filename = _db.getMessage(sender->Username(), origin->_idxAnswer)) != ""))
    {
      std::ofstream	file;

      file.open(std::string("./misc/auto_answer/" + sender->Username() + _env.auto_answer.AutoAnswerExtension).c_str(),
		std::ios::trunc);
      if (file.bad())
	{
	  sender->serialize_data(request::server::Forbidden());
	  return ;
	}
      // La faut coder ce que lamber veut :3
    }
}

void	Perso::del_missed(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::perso::client::DelMissedClient	*origin = dynamic_cast<const request::perso::client::DelMissedClient *>(req);

  if (sender->Authenticated() &&
      _db.delMessage(sender->Username(), origin->_idxAnswer))
    sender->serialize_data(request::server::Ok());
  else
    sender->serialize_data(request::server::Forbidden());
}

bool	Perso::createAnswerFile(IClient::Pointer sender)
{
  std::ofstream	file;

  file.open(std::string("./misc/auto_answer/" + sender->Username() + _env.auto_answer.AutoAnswerExtension).c_str(),
	    std::ios::trunc);
  if (file.bad())
    return false;

  file << sender->serializeAnswer();
  file.close();
  return true;
}

bool	Perso::createVoiceMessageFile(IClient::Pointer sender, const std::string &date)
{
  std::ofstream	file;

  std::string time = std::string("./misc/voice_message/" + md5(sender->Username() + date) + _env.auto_answer.voiceMessageExtension);

  file.open(time.c_str(), std::ios::trunc);
  if (file.bad())
    return false;

  _db.addMessage(sender->Username(), time);

  file << sender->serializeAnswer();
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
      req->serialize(sender->serializeAnswer());
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

bool	Perso::searchClient(const std::list<IClient::Pointer> &clients, const std::string &name, IClient::Pointer &client)
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

void	Perso::let_message(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::perso::client::LetMessage	*origin = dynamic_cast<const request::perso::client::LetMessage *>(req);
  IClient::Pointer				receiver;

  if (sender->Authenticated() &&
      sender->status() == request::User::Status::CONNECTED &&
      _db.clientExist(origin->_from) &&
      _db.clientExist(origin->_to))
    {
#if defined(DEBUG)
      std::cout << "Receive a voice message request from [" << origin->_from << "] to [" << origin->_to << "]" << std::endl;
#endif
      if (origin->_stream.size() != 0)
	{
#if defined(DEBUG)
	  std::cout << "Receive : [" << origin->_stream.size() << "] " << std::endl;
#endif
	  req->serialize(sender->serializeAnswer());
	}
      else
	{
#if defined(DEBUG)
	  std::cout << "File is full" << std::endl;
#endif
	  if (searchClient(clients, origin->_to, receiver))
	    {
#if defined(DEBUG)
	      std::cout << "message create ..." << std::endl;
#endif
	      std::stringstream	date;
	      std::string	strDate;

	      date << origin->_time;
	      date >> strDate;
	      if (createVoiceMessageFile(sender, strDate))
		{
#if defined(DEBUG)
		  std::cout << "File Message was successfuly created !" << std::endl;
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
    }
}

void	Perso::pong(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::perso::client::Pong	*origin = dynamic_cast<const request::perso::client::Pong *>(req);

  std::cout << "Perso::Pong()" << std::endl;
  if (sender->pong() != origin->_id)
    sender->close();
  else
    sender->reset_pong();
}

void	Perso::unset_auto_answer(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req)
{
  const request::perso::client::UnsetAutoAnswer	*origin = dynamic_cast<const request::perso::client::UnsetAutoAnswer *>(req);

  if ((remove(std::string("/misc/auto_answer/" + sender->Username() + _env.auto_answer.AutoAnswerExtension).c_str())) != 0)
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

void	Perso::setActions(std::map<request::ID, plugin::request_handler> &map)
{
  map[request::client::perso::PRIVACY_MODE] = plugin::request_handler(&Perso::privacy_mode, this);
  map[request::client::perso::STATUS] = plugin::request_handler(&Perso::status, this);
  map[request::client::perso::MISSED_CALLS] = plugin::request_handler(&Perso::missed_calls, this);
  map[request::client::perso::GET_MISSED] = plugin::request_handler(&Perso::get_missed, this);
  map[request::client::perso::DEL_MISSED] = plugin::request_handler(&Perso::del_missed, this);
  map[request::client::perso::SET_AUTO_ANSWER] = plugin::request_handler(&Perso::set_auto_answer, this);
  map[request::client::perso::PONG] = plugin::request_handler(&Perso::pong, this);
  map[request::client::perso::LET_MESSAGE] = plugin::request_handler(&Perso::let_message, this);
  map[request::client::perso::UNSET_AUTO_ANSWER] = plugin::request_handler(&Perso::unset_auto_answer, this);
}

request::IRequestPlugin	*loadPlugin(Database &db, Env &env)
{
  return (new Perso(db, env));
}
