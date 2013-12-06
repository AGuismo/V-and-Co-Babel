#include	<fstream>
#include	"Database.hh"
#include	"Serializer.hpp"
#include	"Protocol.hpp"
#include	"RequestFactory.hh"

Salt::size_type Salt::SALT = 42;

Database	&Database::getInstance()
{
  static Database	db;

  return (db);
}

Database::Database():
   _maxIdClient(0)
{
}

Database::~Database()
{

}

bool			Database::drop()
{
  boost::mutex::scoped_lock(_lock);
  _maxIdClient = 0;
  _clients.clear();
  return (true);
}

bool			Database::loadFile(const std::string path)
{
  std::fstream		stream;
  Serializer		bak;

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
  Serializer	bak;

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
  Protocol	p(backup);

  p << _maxIdClient;
  p << clientSize;
  for (client_list::iterator it = _clients.begin(); it != _clients.end(); ++it)
    {
      p << it->id;
      Ruint16	len = it->login.size();
      p << len;
      p.push(it->login);
      p.push(it->password, request::Crypt::PASS_SIZE);
      p << it->rights;
      p << it->privacy;
      p << it->status;
      len = it->statusDetail.size();
      p << len;
      p.push(it->statusDetail);
      len = it->friendList.size();
      p << len;
      for (list_friend::iterator itFr = it->friendList.begin(); itFr != it->friendList.end(); ++itFr)
	p << *itFr;
      len = it->waitRequest.size();
      p << len;
      for (list_request::iterator itReq = it->waitRequest.begin();
	   itReq != it->waitRequest.end(); ++itReq)
	(*itReq)->serialize(p);
    }
  backup = p;
  return (backup);
}

Serializer &	Database::load(Serializer &backup)
{
  boost::mutex::scoped_lock(_lock);
  Ruint16		nbClients;
  Protocol		p(backup);

  p >> _maxIdClient;
  p >> nbClients;
  for (client_list::size_type it = 0; it < nbClients; ++it)
    {
      Client	c;
      Ruint16	len;

      p >> c.id;
      p >> len;
      p.pop(c.login, len);
      p.pop(c.password, request::Crypt::PASS_SIZE);
      p >> c.rights;
      p >> c.privacy;
      p >> c.status;
      p >> len;
      p.pop(c.statusDetail, len);
      _clients.push_back(c);
      p >> len;
      for (Ruint16 i = 0; i < len; ++i)
	{
	  ID	id;

	  p >> id;
	  c.friendList.push_back(id);
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
	  c.waitRequest.push_back(req);
	}
    }
  backup = p;
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
  client_list::iterator it = std::find_if(_clients.begin(), _clients.end(), predicate::Login(login));
  Client		newC;

  if (it != _clients.end() && !trunc)
    return (false);
  newC.id = _maxIdClient++;
  newC.login = login;
  newC.password = password;
  newC.rights = right_level;
  newC.privacy = privacy;
  newC.status = status;
  newC.statusDetail = statusDetail;
  if (trunc && it != _clients.end())
    {
      *it = newC;
      return (true);
    }
  _clients.push_back(newC);
  return (true);
}

bool		Database::addFriend(const std::string &login,
				    const ID friendID)
{
  boost::mutex::scoped_lock(_lock);
  client_list::iterator it = std::find_if(_clients.begin(), _clients.end(), predicate::FriendID(friendID, login));
  if (it == _clients.end())
    return (false);
  it->friendList.push_back(friendID);
  return (true);
}

bool		Database::delFriend(const std::string &login,
				    const ID friendID)
{
  boost::mutex::scoped_lock(_lock);
  client_list::iterator it = std::find_if(_clients.begin(), _clients.end(), predicate::FriendID(friendID, login));
  if (it == _clients.end())
    return (false);
  it->friendList.remove(friendID);
  return (true);
}

bool		Database::delClient(const std::string &login,
				    const request::PasswordType &password)
{
  boost::mutex::scoped_lock(_lock);
  client_list::iterator it = std::find_if(_clients.begin(), _clients.end(), predicate::Login(login));

  if (it == _clients.end())
    return (false);
  if (it->password != password)
    return (false);
  _clients.erase(it);
  return (true);
}

bool		Database::setStatus(const std::string &login,
				    const request::Status &status,
				    const std::string &message)
{
  boost::mutex::scoped_lock(_lock);
  client_list::iterator it = std::find_if(_clients.begin(), _clients.end(), predicate::Login(login));

  if (it == _clients.end())
    return (false);
  it->status = status;
  if (message.size() != 0)
    it->statusDetail = message;
  return (true);
}

bool		Database::modClientPass(const std::string &login,
					const request::PasswordType &oldpassword,
					const request::PasswordType &newpassword)
{
  boost::mutex::scoped_lock(_lock);
  client_list::iterator it = std::find_if(_clients.begin(), _clients.end(), predicate::Login(login));

  if (it == _clients.end())
    return (false);
  if (it->password != oldpassword)
    return (false);
  it->password = newpassword;
  return (true);
}

bool		Database::getClient(const std::string &login, Client &client)
{
  boost::mutex::scoped_lock(_lock);
  client_list::iterator it = std::find_if(_clients.begin(), _clients.end(), predicate::Login(login));

  if (it == _clients.end())
    return (false);
  client = *it;
  return (true);
}

bool		Database::modPrivacy(const std::string &login, const request::Privacy privacy)
{
  boost::mutex::scoped_lock(_lock);
  client_list::iterator it = std::find_if(_clients.begin(), _clients.end(), predicate::Login(login));

  if (it == _clients.end())
    return (false);
  it->privacy = privacy;
  return (true);
}

bool		Database::clientExist(const std::string &login)
{
  return (std::find_if(_clients.begin(), _clients.end(), predicate::Login(login)) != _clients.end());
}

bool		Database::clientExist(const std::string &login,
				      const request::PasswordType &password)
{
  return (std::find_if(_clients.begin(), _clients.end(),
		       predicate::LoginPass(login, password)) != _clients.end());
}

bool		Database::clientExist(const std::string &login,
				      const request::PasswordType &password,
				      const request::Rights rights)
{
  return (std::find_if(_clients.begin(), _clients.end(),
		       predicate::LoginPassRights(login, password, rights)) != _clients.end());
}
