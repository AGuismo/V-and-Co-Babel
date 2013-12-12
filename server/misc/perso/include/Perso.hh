#ifndef PERSO_H_
# define PERSO_H_

# include	"IRequestPlugin.hh"

class Perso : public request::IRequestPlugin
{
public:
  Perso();
  virtual ~Perso();

public:
  IPlugin	*clone();
  void		unload();
  void		setActions(std::map<request::ID, void (*)(Server *,
							  Client::Pointer,
							  const ARequest *)> &);

private:
  static void	privacy_mode(Server *serv, Client::Pointer sender, const ARequest *req);
  static void	status(Server *serv, Client::Pointer sender, const ARequest *req);
  static void	missed_calls(Server *serv, Client::Pointer sender, const ARequest *req);
  static void	get_missed(Server *serv, Client::Pointer sender, const ARequest *req);
  static void	del_missed(Server *serv, Client::Pointer sender, const ARequest *req);
  static void	set_auto_answer(Server *serv, Client::Pointer sender, const ARequest *req);
  static void	unset_auto_answer(Server *serv, Client::Pointer sender, const ARequest *req);

public:
  Perso(Perso const&);
  Perso& operator=(Perso const&);
};

#endif /* PERSO_H_ */
