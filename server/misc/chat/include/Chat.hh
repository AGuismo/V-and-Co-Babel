#ifndef CHAT_H_
# define CHAT_H_

# include	<list>
# include	"IRequestPlugin.hh"

class	Database;
class	Env;

class Chat : public request::IRequestPlugin
{
public:
  Chat(Database &db, Env &env);
  virtual ~Chat();

public:
  IPlugin	*clone();
  void		unload();
  void		setActions(std::map<request::ID, plugin::request_handler> &);
  void		getVersion(plugin::version::major &maj, plugin::version::minor &min) const;
  bool		searchClient(const std::list<IClient::Pointer> &clients, const std::string &name, IClient::Pointer &client);

private:
  void	message(const std::list<IClient::Pointer> &,
		IClient::Pointer sender, const ARequest *req);

public:
  Chat(Chat const&);
  Chat& operator=(Chat const&);

private:
  Database	&_db;
  Env		&_env;
};

#endif /* CHAT_H_ */
