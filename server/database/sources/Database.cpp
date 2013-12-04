#include	<fstream>
#include	"Database.hh"
#include	"Backup.hpp"

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

bool			Database::loadFile(const std::string path)
{
  std::fstream		stream;
  save::Backup		bak;

  stream.open(path.c_str(), std::ios_base::in);
  if (!stream.is_open())
    return (false);
  try
    {
      stream >> bak;
    }
  catch (save::invalid_argument &e)
    {
      std::cerr << "Database: Unable to load file " << path << std::endl
		<< "Error detail: " << e.what() << std::endl;
      return (false);
    }
  load(bak);
  return (true);
}

bool		Database::saveFile(const std::string path)
{
  std::ofstream	stream(path.c_str());
  save::Backup	bak;

  if (stream.bad())
    return (false);
  save(bak);
  stream << bak;
  return (true);
}

save::Backup &	Database::save(save::Backup &backup)
{
  boost::mutex::scoped_lock(_lock);
  Ruint16		clientSize = _clients.size();

  backup << clientSize;
  backup << _maxIdClient;
  for (client_list::iterator it = _clients.begin(); it != _clients.end(); ++it)
    {
      backup << it->id;
      Ruint16	len = it->login.size();
      backup << len;
      backup.push(it->login, len);
      backup.push(it->password, request::Crypt::PASS_SIZE);
      backup << it->rights;
      backup << it->privacy;
      backup << it->status;
      len = it->statusDetail.size();
      backup << len;
      backup.push(it->statusDetail, len);
      len = it->friendList.size();
      backup << len;
      for (list_friend::iterator itFr = it->friendList.begin(); itFr != it->friendList.end(); ++itFr)
	backup << *itFr;
    }
  return (backup);
}

save::Backup &	Database::load(save::Backup &backup)
{
  boost::mutex::scoped_lock(_lock);
  Ruint16		nbClients;

  backup >> _maxIdClient;
  backup >> nbClients;
  for (client_list::size_type it = 0; it < nbClients; ++it)
    {
      Client	c;
      Ruint16	len;
      ID	id;

      backup >> c.id;
      backup >> len;
      backup.pop(c.login, len);
      backup.pop(c.password, request::Crypt::PASS_SIZE);
      backup >> c.rights;
      backup >> c.privacy;
      backup >> c.status;
      backup >> len;
      backup.pop(c.statusDetail, len);
      _clients.push_back(c);
      backup >> len;
      for (unsigned int i = 0; i != len; ++i)
	{
	  backup >> id;
	  c.friendList.push_back(id);
	}
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
