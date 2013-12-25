#ifndef FRIENDS_H_
# define FRIENDS_H_

# include	<list>
# include	"IRequestPlugin.hh"

class	Database;

class Friends : public request::IRequestPlugin
{
public:
  Friends(Database &, Env &);
  virtual ~Friends();

public:
  IPlugin	*clone();
  void		unload();
  void		setActions(std::map<request::ID, plugin::request_handler> &);
  void		getVersion(plugin::version::major &maj, plugin::version::minor &min) const;

private:
  bool		searchClient(const std::list<IClient::Pointer> &clients,
			     const std::string &name, IClient::Pointer &);
  void		sendFriendStatus(IClient::Pointer &sender, const std::list<IClient::Pointer> &clients,
				 const std::string &username);

private:
  void	request(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
  void	del_friend(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
  void	refuse(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
  void	accept(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
  void	list(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);

public:
  Friends(Friends const&);
  Friends& operator=(Friends const&);

private:
  Database	&_db;
  Env		&_env;
};

#endif /* FRIENDS_H_ */
