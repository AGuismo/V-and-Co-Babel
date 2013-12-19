#ifndef PERSO_H_
# define PERSO_H_

# include	<list>
# include	"IRequestPlugin.hh"
# include	"Database.hh"
# include	"Env.hh"

class Perso : public request::IRequestPlugin
{
public:
  Perso(Database &db);
  virtual ~Perso();

public:
  IPlugin	*clone();
  void		unload();
  void		setActions(std::map<request::ID, void(*)(const std::list<IClient::Pointer> &,
							 IClient::Pointer,
							 const ARequest *)> &);
void		getVersion(plugin::version::major &maj, plugin::version::minor &min) const;

private:
  static void	privacy_mode(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
  static void	status(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
  static void	missed_calls(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
  static void	get_missed(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
  static void	del_missed(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
  static void	set_auto_answer(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
  static void	pong(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
  static void	unset_auto_answer(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
  static bool	createAnswerFile(IClient::Pointer sender);

private:
  Perso(Perso const&);
  Perso& operator=(Perso const&);

private:
  Database &_db;
};

#endif /* PERSO_H_ */
