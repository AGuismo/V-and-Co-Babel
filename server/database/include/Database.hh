#ifndef DATABASE_H_
# define DATABASE_H_

# include	<string>
# include	<vector>
# include	<boost/thread/mutex.hpp>
# include	"IDatabase.hh"
# include	"types.hh"

class Database : public IDatabase
{
private:
  Database();
  virtual ~Database();

public:
  static Database	&getInstance();

public:
  bool		loadFile(const std::string path);
  bool		saveFile(const std::string path);

public:
  bool		newClient(const std::string &login,
			  const request::PasswordType &password,
			  const request::Rights right_level = request::user::USER,
			  const request::Privacy privacy = request::user::PRIVATE,
			  const request::Status status = request::user::status::DISCONNECTED,
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
    std::string			login;
    std::string			statusDetail;
    request::Status		status;
    request::Privacy		privacy;
    request::PasswordType	password;
    request::Rights		rights;

    Client() : rights(0) {}
  };

public:
  bool		getClient(const std::string &login, Client &);

private:
  struct			PredicateLogin : public std::unary_function<Client, bool>
  {
    PredicateLogin(const std::string &login): _login(login) {}
    bool	operator()(const Client obj) const
    {
      return (_login == obj.login);
    }
  protected:
    const std::string	_login;
  };

  struct			PredicateLoginPass : public PredicateLogin
  {
    PredicateLoginPass(const std::string &login,
		       request::PasswordType p): PredicateLogin(login), _pass(p) {}
    bool	operator()(const Client obj) const
    {
      return (_login == obj.login && _pass == obj.password);
    }
  protected:
    const request::PasswordType	_pass;
  };

  struct			PredicateLoginPassRights : public PredicateLoginPass
  {
    PredicateLoginPassRights(const std::string &login,
			     request::PasswordType p,
			     request::Rights r): PredicateLoginPass(login, p), _right(r) {}
    bool	operator()(const Client obj) const
    {
      return (_login == obj.login && _pass == obj.password && _right == obj.rights);
    }
  protected:
    const request::Rights	_right;
  };

private:
  typedef std::vector<Client>	client_list;

private:
  client_list			_clients;
  boost::mutex			_lock;
};

#endif /* DATABASE_H_ */
