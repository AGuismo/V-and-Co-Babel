#ifndef PERSO_H_
# define PERSO_H_

# include	<list>
# include	"IRequestPlugin.hh"
# include	"Database.hh"
# include	"Env.hh"
# include	"PersoRequest.hh"

class Perso : public request::IRequestPlugin
{
public:
  Perso(Database &db, Env &env);
  virtual ~Perso();

public:
  IPlugin	*clone();
  void		unload();
  void		setActions(std::map<request::ID, plugin::request_handler> &);
void		getVersion(plugin::version::major &maj, plugin::version::minor &min) const;

private:
  void	privacy_mode(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
  void	status(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
  void	missed_calls(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
  void	get_missed(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
  void	del_missed(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
  void	set_auto_answer(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
  void	let_message(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
  void	pong(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
  void	unset_auto_answer(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
  bool	createAnswerFile(IClient::Pointer sender);
  bool	createVoiceMessageFile(IClient::Pointer sender, const std::string &);
  bool	searchClient(const std::list<IClient::Pointer> &clients, const std::string &name, IClient::Pointer &client);

  void	sendChangeStatusFriends(const IClient::Pointer &sender,
				const Database::list_friend &friends,
				const request::perso::client::StatusClient *,
				const std::list<IClient::Pointer> &clients);

private:
  Perso(Perso const&);
  Perso& operator=(Perso const&);

private:
  Database	&_db;
  Env		&_env;
};

#endif /* PERSO_H_ */
