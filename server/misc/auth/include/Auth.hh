#ifndef AUTH_H_
# define AUTH_H_

# include	"IRequestPlugin.hh"

class Auth : public request::IRequestPlugin
{
public:
  Auth();
  virtual ~Auth();

public:
  IPlugin	*clone();
  void		unload();
  void		setActions(std::map<request::ID, void (*)(Server *,
							  Client::Pointer,
							  const ARequest *)> &);

private:
  static void	new_account(Server *serv, Client::Pointer sender, const ARequest *req);
  static void	connect(Server *serv, Client::Pointer sender, const ARequest *req);
  static void	modify(Server *serv, Client::Pointer sender, const ARequest *req);

public:
  Auth(Auth const&);
  Auth& operator=(Auth const&);
};

#endif /* AUTH_H_ */
