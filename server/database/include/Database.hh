#ifndef DATABASE_H_
# define DATABASE_H_

# include	<string>
# include	<vector>
# include	<list>
# include	<boost/thread/mutex.hpp>
# include	"IDatabase.hh"
# include	"types.hh"

class Database : public IDatabase
{
  typedef Ruint16		AUTO_INCREMENT;
  typedef AUTO_INCREMENT	ID;
  typedef std::list<ID>		list_friend;

private:
  Database();
  virtual ~Database();

public:
  static Database	&getInstance();

public:
  bool		loadFile(const std::string path);
  bool		saveFile(const std::string path);

public:
  bool		addFriend(const std::string &login,
			  const ID friendID);
  bool		delFriend(const std::string &login,
			  const ID friendID);
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
  bool		clientExist(const std::string &login);
  bool		clientExist(const std::string &login,
			    const request::PasswordType &password);
  bool		clientExist(const std::string &login,
			    const request::PasswordType &password,
			    const request::Rights rights);
  bool		setClientStatus(const std::string &login,
				const std::string &message,
				const request::Status status);
private:
  Database(Database const&);
  Database& operator=(Database const&);

public:
  save::Backup &	save(save::Backup &);
  save::Backup &	load(save::Backup &);

public:
  struct			Client
  {
    ID				id;
    std::string			login;
    std::string			statusDetail;
    request::Status		status;
    request::Privacy		privacy;
    request::PasswordType	password;
    list_friend			friendList;
    request::Rights		rights;

    Client() : rights(0) {};
  };

public:
  bool		getClient(const std::string &login, Client &);

private:
  struct Predicate : public std::unary_function<Client, bool>
  {
    virtual bool	operator()(const Client obj) const = 0;
  };

  struct predicate
  {
    struct			Login : public Predicate
    {
      Login(const std::string &login): _login(login) {}
      virtual bool	operator()(const Client obj) const
      {
	return (_login == obj.login);
      }
    protected:
      const std::string	_login;
    };

    struct			FriendID : public Login
    {
      FriendID(const Database::ID id, const std::string &login): Login(login), _id(id) {}
      virtual bool	operator()(const Client obj) const
      {
	if (!Login::operator()(obj))
	  return (false);
	for (list_friend::const_iterator it = obj.friendList.begin(); it != obj.friendList.end(); ++it)
	  if (*it == _id)
	    return (true);
	return (false);
      }
    protected:
      const Database::ID	_id;
    };

    struct			LoginPass : public Login
    {
      LoginPass(const std::string &login,
		request::PasswordType p): Login(login), _pass(p) {}
      virtual bool	operator()(const Client obj) const
      {
	return (_login == obj.login && _pass == obj.password);
      }
    protected:
      const request::PasswordType	_pass;
    };

    struct			LoginPassRights : public LoginPass
    {
      LoginPassRights(const std::string &login,
		      request::PasswordType p,
		      request::Rights r): LoginPass(login, p), _right(r) {}
      virtual bool	operator()(const Client obj) const
      {
	return (_login == obj.login && _pass == obj.password && _right == obj.rights);
      }
    protected:
      const request::Rights	_right;
    };
  };

private:
  typedef std::vector<Client>	client_list;

private:
  AUTO_INCREMENT		_maxIdClient;
  client_list			_clients;
  boost::mutex			_lock;
};

#endif /* DATABASE_H_ */
