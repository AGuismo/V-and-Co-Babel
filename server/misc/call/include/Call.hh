#ifndef CALL_H_
# define CALL_H_

# include	<list>
# include	"IRequestPlugin.hh"
# include	"Database.hh"

class Call : public request::IRequestPlugin
{
public:
  Call(Database &, Env &);
  virtual ~Call();

public:
  IPlugin	*clone();
  void		unload();
  void		setActions(std::map<request::ID, plugin::request_handler> &);
void		getVersion(plugin::version::major &maj, plugin::version::minor &min) const;

private:
static bool	searchClient(const std::list<IClient::Pointer> &clients, const std::string &name, IClient::Pointer &);

private:
void	call(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req);
void	accept(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req);
void	refuse(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req);
void	hangup(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req);
  bool	verifCall(IClient::Pointer sender, IClient::Pointer receiver, Database::list_friend friends, const std::list<IClient::Pointer> &clients);

public:
Call(Call const&);
Call& operator=(Call const&);

private:
	Database	&_db;
	Env			&_env;
};

#endif /* CALL_H_ */
