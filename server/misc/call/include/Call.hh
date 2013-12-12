#ifndef CALL_H_
# define CALL_H_

# include	"IRequestPlugin.hh"

class Call : public request::IRequestPlugin
{
public:
  Call();
  virtual ~Call();

public:
  IPlugin	*clone();
  void		unload();
  void		setActions(std::map<request::ID, void (*)(Server *,
							  Client::Pointer,
							  const ARequest *)> &);

private:
  static void	call(Server *serv, Client::Pointer sender, const ARequest *req);
  static void	accept(Server *serv, Client::Pointer sender, const ARequest *req);
  static void	refuse(Server *serv, Client::Pointer sender, const ARequest *req);
  static void	hangup(Server *serv, Client::Pointer sender, const ARequest *req);

public:
  Call(Call const&);
  Call& operator=(Call const&);
};

#endif /* CALL_H_ */
