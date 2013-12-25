#ifndef DATABASE_H_
# define DATABASE_H_

# include	<string>
# include	<vector>
# include	<list>
# include	<boost/thread/mutex.hpp>
# include	"IDatabase.hh"
# include	"types.hh"
# include	"ARequest.hh"

class Database : public IDatabase
{
public:
  typedef std::string			Username;
  typedef std::list<ARequest *>		list_request;
  typedef std::list<Username>		list_friend;
  struct			Client
  {
    request::Username		login;
    request::Username		statusDetail;
    request::Status		status;
    request::Privacy		privacy;
    request::PasswordType	password;
    list_friend			friendList;
    list_request		waitRequest;
    request::Rights		rights;
  };

private:
  typedef std::map<Username, Client *>	clients;

public:
  Database();
  virtual ~Database();

private:
  Database(Database const&);
  Database& operator=(Database const&);

public:
  bool		loadFile(const std::string path);
  bool		saveFile(const std::string path);
  bool		drop();

public:
  bool		addFriend(const std::string &login,
			  const std::string &FriendLogin);
  bool		delFriend(const std::string &login,
			  const std::string &FriendLogin);
  bool		isFriend(const std::string &login,
			 const std::string &FriendLogin) const;
  bool		bothFriend(const std::string &login1,
			   const std::string &login2) const;
  bool		listFriend(const std::string &login, list_friend &) const;
  bool		newClient(const std::string &login,
			  const request::PasswordType &password,
			  const request::Rights right_level = request::User::USER,
			  const request::Privacy privacy = request::User::PRIVATE,
			  const request::Status status = request::User::Status::DISCONNECTED,
			  const std::string &statusDetail = std::string(),
			  bool trunc = false);
  bool		delClient(const std::string &login,
			  const request::PasswordType &password);
  bool		modClientPass(const std::string &login,
			      const request::PasswordType &oldpassword,
			      const request::PasswordType &newpassword);
  bool		modPrivacy(const std::string &login,
			   const request::Privacy privacy);
  bool		setStatus(const std::string &login,
			  const request::Status &status,
			  const std::string &message);
  bool		clientExist(const std::string &login) const;
  bool		clientExist(const std::string &login,
			    const request::PasswordType &password) const;
  bool		clientExist(const std::string &login,
			    const request::PasswordType &password,
			    const request::Rights rights) const;
  bool		setClientStatus(const std::string &login,
				const std::string &message,
				const request::Status status);
  template <typename Request>
  bool		addRequest(const request::Username &login, const Request &req);
  template <typename Request>
  bool		delRequest(const request::Username &login, const Request &req);
  template <typename Request>
  bool		isRequestExist(const request::Username &login, const Request &req);


private:
  Serializer &	save(Serializer &);
  Serializer &	load(Serializer &);

public:
  bool		getClient(const std::string &login, Client &) const;

private:
  clients			_clients;
  boost::mutex			_lock;
};

template <typename Request>
bool		Database::addRequest(const request::Username &login, const Request &req)
{
  boost::mutex::scoped_lock(_lock);
  clients::iterator	itClient = _clients.find(login);

  if (itClient == _clients.end())
    return (false);
  for (list_request::iterator itReq = itClient->second->waitRequest.begin();
       itReq != itClient->second->waitRequest.end(); ++itReq)
    if (req.operator==(*itReq))
      return (false);
  itClient->second->waitRequest.push_back(new Request(req));
  return (true);
}

template <typename Request>
bool		Database::delRequest(const request::Username &login, const Request &req)
{
  boost::mutex::scoped_lock(_lock);
  clients::iterator	itClient = _clients.find(login);

  if (itClient == _clients.end())
    return (false);
  for (list_request::iterator itReq = itClient->second->waitRequest.begin();
       itReq != itClient->second->waitRequest.end(); ++itReq)
    if (req.operator==(*itReq))
      {
	itClient->second->waitRequest.erase(itReq);
	return (true);
      }
  return (false);
}


template <typename Request>
bool		Database::isRequestExist(const request::Username &login, const Request &req)
{
  boost::mutex::scoped_lock(_lock);
  clients::iterator	itClient = _clients.find(login);

  if (itClient == _clients.end())
    return (false);
  for (list_request::iterator itReq = itClient->second->waitRequest.begin();
       itReq != itClient->second->waitRequest.end(); ++itReq)
    if (req.operator==(*itReq))
      return (true);
  return (false);
}

#endif /* DATABASE_H_ */
