#include	<fstream>
#include	"Database.hh"
#include	"Serializer.hpp"
#include	"Protocol.hpp"
#include	"RequestFactory.hh"

Salt::size_type Salt::SALT = 42;

Database::Database()
{
}

Database::~Database()
{

}

bool			Database::drop()
{
  boost::mutex::scoped_lock(_lock);
  _clients.clear();
  return (true);
}

bool			Database::loadFile(const std::string path)
{
  std::fstream		stream;
  Protocol		bak;

  stream.open(path.c_str(), std::ios_base::in);
  if (!stream.is_open())
    return (false);
  try
    {
      stream >> bak;
      load(bak);
    }
  catch (Serializer::invalid_argument &e)
    {
      std::cerr << "Database: Unable to load file " << path << std::endl
		<< "Error detail: " << e.what() << std::endl;
      return (false);
    }
  return (true);
}

bool		Database::saveFile(const std::string path)
{
  std::ofstream	stream(path.c_str());
  Protocol	bak;

  if (stream.bad())
    return (false);
  try
    {
      save(bak);
      stream << bak;
    }
  catch (Serializer::invalid_argument &e)
    {
      std::cerr << "Database: Unable to Save file " << path << std::endl
		<< "Error detail: " << e.what() << std::endl;
      return (false);
    }
  return (true);
}

Serializer &	Database::save(Serializer &backup)
{
  boost::mutex::scoped_lock(_lock);
  Ruint16	clientSize = _clients.size();
  Protocol	&p = dynamic_cast<Protocol &>(backup);

  p << clientSize;
  for (clients::iterator it = _clients.begin(); it != _clients.end(); ++it)
    {
      Client			*c = it->second;
      request::StatusDetailLen	statusLen = c->statusDetail.size();
      Ruint16			len;
      request::UsernameLen	userLen;

      userLen = c->login.size();
      p << userLen;
      p.push(c->login, userLen);
      p.push(c->password, request::Crypt::PASS_SIZE);
      p << c->rights;
      p << c->privacy;
      p << c->status;
      p << statusLen;
      p.push(c->statusDetail, statusLen);
      len = c->friendList.size();
      p << len;
      for (list_friend::iterator itFr = c->friendList.begin(); itFr != c->friendList.end(); ++itFr)
	{
	  request::UsernameLen	UsernameLen = itFr->size();

	  p << UsernameLen;
	  p.push(*itFr, UsernameLen);
	}
      len = c->waitRequest.size();
      p << len;
      for (list_request::iterator itReq = c->waitRequest.begin();
      	   itReq != c->waitRequest.end(); ++itReq)
      	(*itReq)->serialize(p);
    }
  return (backup);
}

Serializer &	Database::load(Serializer &backup)
{
  boost::mutex::scoped_lock(_lock);
  Ruint16		nbClients;
  Protocol		&p = dynamic_cast<Protocol &>(backup);

  p >> nbClients;
  for (clients::size_type it = 0; it < nbClients; ++it)
    {
      Client		*c = new Client;
      request::UsernameLen	userLen;
      request::StatusDetailLen	statLen;
      Ruint16		len;

      p >> userLen;
      p.pop(c->login, userLen);
      p.pop(c->password, request::Crypt::PASS_SIZE);
      p >> c->rights;
      p >> c->privacy;
      p >> c->status;
      p >> statLen;
      p.pop(c->statusDetail, statLen);
      p >> len;
      for (Ruint16 i = 0; i < len; ++i)
	{
	  request::UsernameLen	UsernameLen;
	  std::string		Friend;

	  p >> UsernameLen;
	  p.pop(Friend, UsernameLen);
	  c->friendList.push_back(Friend);
	}
      p >> len;
      for (Ruint16 i = 0; i != len; ++i)
      	{
      	  request::ID	id;
      	  ARequest	*req;

      	  p >> id;
      	  try
      	    {
      	      req = request::Factory::factory(id);
      	      req->unserialize(p);
      	    }
      	  catch (const ARequest::Exception &e)
      	    {
      	      throw Serializer::invalid_argument("Database Load error");
      	    }
      	  c->waitRequest.push_back(req);
      	}
      _clients[c->login] = c;
    }
  return (backup);
}

bool		Database::newClient(const std::string &login,
				    const request::PasswordType &password,
				    const request::Rights right_level,
				    const request::Privacy privacy,
				    const request::Status status,
				    const std::string &statusDetail,
				    bool trunc)
{
  boost::mutex::scoped_lock(_lock);
  clients::iterator it = _clients.find(login);
  Client		*newC = new Client;

  if (it != _clients.end() && !trunc)
    return (false);
  newC->login = login;
  newC->password = password;
  newC->rights = right_level;
  newC->privacy = privacy;
  newC->status = status;
  newC->statusDetail = statusDetail;
  if (trunc && it != _clients.end())
    {
      _clients[login] = newC;
      return (true);
    }
  _clients[login] = newC;
  return (true);
}

bool		Database::addFriend(const std::string &login,
				    const std::string &FriendLogin)
{
  boost::mutex::scoped_lock(_lock);
  clients::iterator	it;

  if ((it = _clients.find(login)) == _clients.end() || _clients.find(FriendLogin) == _clients.end())
    return (false);
  for (list_friend::iterator itFr = it->second->friendList.begin();
       itFr != it->second->friendList.end(); ++itFr)
    {
      if (*itFr == FriendLogin)
	return (false);
    }
  it->second->friendList.push_back(FriendLogin);
  return (true);
}

bool		Database::delFriend(const std::string &login,
				    const std::string &FriendLogin)
{
  boost::mutex::scoped_lock(_lock);
  clients::iterator	it;

  if ((it = _clients.find(login)) == _clients.end())
    return (false);
  for (list_friend::iterator itFr = it->second->friendList.begin();
       itFr != it->second->friendList.end(); ++itFr)
    {
      if (*itFr == FriendLogin)
	{
	  it->second->friendList.erase(itFr);
	  return (true);
	}
    }
  return (false);
}

bool		Database::isFriend(const std::string &login,
				   const std::string &FriendLogin) const
{
  clients::const_iterator	it = _clients.find(login);

  if (it == _clients.end())
    return (false);
  for (list_friend::const_iterator itFr = it->second->friendList.begin();
       itFr != it->second->friendList.end(); ++itFr)
    {
      if (*itFr == FriendLogin)
	return (true);
    }
  return (false);
}

bool		Database::bothFriend(const std::string &login1,
				     const std::string &login2) const
{
  return (isFriend(login1, login2) && isFriend(login2, login1));
}

bool		Database::listFriend(const std::string &login,
				     list_friend &friends) const
{
  clients::const_iterator	it = _clients.find(login);

  if (it == _clients.end())
    return (false);
  friends = it->second->friendList;
  return (true);
}

bool		Database::delClient(const std::string &login,
				    const request::PasswordType &password)
{
  boost::mutex::scoped_lock(_lock);
  clients::iterator it = _clients.find(login);

  if (it == _clients.end())
    return (false);
  if (it->second->password != password)
    return (false);
  _clients.erase(it);
  return (true);
}

bool		Database::setStatus(const std::string &login,
				    const request::Status &status,
				    const std::string &message)
{
  boost::mutex::scoped_lock(_lock);
  clients::iterator it = _clients.find(login);

  if (it == _clients.end())
    return (false);
  it->second->status = status;
  if (message.size() != 0)
    it->second->statusDetail = message;
  return (true);
}

bool		Database::modClientPass(const std::string &login,
					const request::PasswordType &oldpassword,
					const request::PasswordType &newpassword)
{
  boost::mutex::scoped_lock(_lock);
  clients::iterator it = _clients.find(login);

  if (it == _clients.end())
    return (false);
  if (it->second->password != oldpassword)
    return (false);
  it->second->password = newpassword;
  return (true);
}

bool		Database::getClient(const std::string &login, Client &client) const
{
  boost::mutex::scoped_lock(_lock);
  clients::const_iterator it = _clients.find(login);

  if (it == _clients.end())
    return (false);
  client = *(it->second);
  return (true);
}

bool		Database::modPrivacy(const std::string &login, const request::Privacy privacy)
{
  boost::mutex::scoped_lock(_lock);
  clients::iterator it = _clients.find(login);

  if (it == _clients.end())
    return (false);
  it->second->privacy = privacy;
  return (true);
}

bool		Database::clientExist(const std::string &login) const
{
  return (_clients.find(login) != _clients.end());
}

bool		Database::clientExist(const std::string &login,
				      const request::PasswordType &password) const
{
  clients::const_iterator	it = _clients.find(login);

  return (it != _clients.end() && it->second->password == password);
}

bool		Database::clientExist(const std::string &login,
				      const request::PasswordType &password,
				      const request::Rights rights) const
{
  clients::const_iterator	it = _clients.find(login);

  return (it != _clients.end() && it->second->password == password && it->second->rights == rights);
}
