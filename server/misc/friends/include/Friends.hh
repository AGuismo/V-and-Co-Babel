#ifndef FRIENDS_H_
# define FRIENDS_H_

# include	"IRequestPlugin.hh"

class Friends : public request::IRequestPlugin
{
public:
  Friends();
  virtual ~Friends();

public:
  IPlugin	*clone();
  void		unload();
  void		setActions(std::map<request::ID, void (*)(Server *,
							  Client::Pointer,
							  const ARequest *)> &);

private:
  static void	request(Server *serv, Client::Pointer sender, const ARequest *req);
  static void	del_friend(Server *serv, Client::Pointer sender, const ARequest *req);
  static void	refuse(Server *serv, Client::Pointer sender, const ARequest *req);
  static void	accept(Server *serv, Client::Pointer sender, const ARequest *req);
  static void	list(Server *serv, Client::Pointer sender, const ARequest *req);

public:
  Friends(Friends const&);
  Friends& operator=(Friends const&);
};

#endif /* FRIENDS_H_ */
