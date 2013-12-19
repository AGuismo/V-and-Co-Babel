#ifndef CALL_H_
# define CALL_H_

# include	<list>
# include	"IRequestPlugin.hh"

class	Database;

class Call : public request::IRequestPlugin
{
public:
  Call();
  virtual ~Call();

public:
  IPlugin	*clone();
  void		unload();
  void		setActions(std::map<request::ID, void(*)(const std::list<IClient::Pointer> &,
							 Database &,
							 IClient::Pointer,
							 const ARequest *)> &);
void		getVersion(plugin::version::major &maj, plugin::version::minor &min) const;

private:
static bool	searchClient(const std::list<IClient::Pointer> &clients, const std::string &name, IClient::Pointer &);

private:
void	call(const std::list<IClient::Pointer> &clients, Database &, IClient::Pointer sender, const ARequest *req);
void	accept(const std::list<IClient::Pointer> &clients, Database &, IClient::Pointer sender, const ARequest *req);
void	refuse(const std::list<IClient::Pointer> &clients, Database &, IClient::Pointer sender, const ARequest *req);
void	hangup(const std::list<IClient::Pointer> &clients, Database &, IClient::Pointer sender, const ARequest *req);

public:
Call(Call const&);
Call& operator=(Call const&);
};

#endif /* CALL_H_ */
