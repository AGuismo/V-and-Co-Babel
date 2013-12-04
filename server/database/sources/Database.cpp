#include	<fstream>
#include	"Database.hh"
#include	"Backup.hpp"

Database	&Database::getInstance()
{
  static Database	db;

  return (db);
}

Database::Database()
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
  _lock.lock();
  Ruint16		clientSize = _clients.size();

  backup << clientSize;
  for (client_list::iterator it = _clients.begin(); it != _clients.end(); ++it)
    {
      Ruint16	len = it->login.size();
      backup << len;
      backup.push(it->login, len);
      backup.push(it->password, Crypt::PASS_SIZE);
      backup << it->rights;
      backup << it->privacy;
      backup << it->status;
      len = it->statusDetail.size();
      backup << len;
      backup.push(it->statusDetail, len);
    }
  _lock.unlock();
  return (backup);
}

save::Backup &	Database::load(save::Backup &backup)
{
  _lock.lock();
  Ruint16		nbClients;

  backup >> nbClients;
  for (client_list::size_type it = 0; it < nbClients; ++it)
    {
      Client	c;
      Ruint16	len;

      backup >> len;
      backup.pop(c.login, len);
      backup.pop(c.password, Crypt::PASS_SIZE);
      backup >> c.rights;
      backup >> c.privacy;
      backup >> c.status;
      backup >> len;
      backup.pop(c.statusDetail.len);
      _clients.push_back(c);
    }
  _lock.unlock();
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
  _lock.lock();
  client_list::iterator it = std::find_if(_clients.begin(), _clients.end(), PredicateLogin(login));
  Client		newC;

  if (it != _clients.end() && !trunc)
    {
      _lock.unlock();
      return (false);
    }
  newC.login = login;
  newC.password = password;
  newC.rights = right_level;
  newC.privacy = privacy;
  newC.status = status;
  newC.statusDetail = statusDetail;
  if (trunc && it != _clients.end())
    {
      *it = newC;
      _lock.unlock();
      return (true);
    }
  _clients.push_back(newC);
      _lock.unlock();
  return (true);
}

bool		Database::delClient(const std::string &login,
				    const request::PasswordType &password)
{
  _lock.lock();
  client_list::iterator it = std::find_if(_clients.begin(), _clients.end(), PredicateLogin(login));

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
  _lock.lock();
  client_list::iterator it = std::find_if(_clients.begin(), _clients.end(), PredicateLogin(login));

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
  _lock.lock();
  client_list::iterator it = std::find_if(_clients.begin(), _clients.end(), PredicateLogin(login));

  if (it == _clients.end())
    return (false);
  if (it->password != oldpassword)
    return (false);
  it->password = newpassword;
  return (true);
}

bool		Database::getClient(const std::string &login, Client &client)
{
  _lock.lock();
  client_list::iterator it = std::find_if(_clients.begin(), _clients.end(), PredicateLogin(login));

  if (it == _clients.end())
    {
      _lock.unlock();
      return (false);
    }
  client = *it;
  _lock.unlock();
  return (true);
}

bool		Database::modPrivacy(const std::string &login, const request::Privacy privacy)
{
  _lock.lock();
  client_list::iterator it = std::find_if(_clients.begin(), _clients.end(), PredicateLogin(login));

  if (it == _clients.end())
    return (false);
  it->privacy = privacy;
  return (true);
}

bool		Database::clientExist(const std::string &login)
{
  return (std::find_if(_clients.begin(), _clients.end(), PredicateLogin(login)) != _clients.end());
}

bool		Database::clientExist(const std::string &login,
				      const request::PasswordType &password)
{
  return (std::find_if(_clients.begin(), _clients.end(),
		       PredicateLoginPass(login, password)) != _clients.end());
}

bool		Database::clientExist(const std::string &login,
				      const request::PasswordType &password,
				      const request::Rights rights)
{
  return (std::find_if(_clients.begin(), _clients.end(),
		       PredicateLoginPassRights(login, password, rights)) != _clients.end());
}
