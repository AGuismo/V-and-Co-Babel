#ifndef FRIENDS_H_
# define FRIENDS_H_

# include	<list>
# include	"IRequestPlugin.hh"

class	Database;

class Friends : public request::IRequestPlugin
{
public:
  Friends();
  virtual ~Friends();

public:
  IPlugin	*clone();
  void		unload();
  void		setActions(std::map<request::ID, void (*)(const std::list<IClient::Pointer> &,
								Database &,
								IClient::Pointer,
							  const ARequest *)> &);
  void		getVersion(plugin::version::major &maj, plugin::version::minor &min) const;

private:
  static void	request(const std::list<IClient::Pointer> &, Database &,IClient::Pointer sender, const ARequest *req);
  static void	del_friend(const std::list<IClient::Pointer> &, Database &, IClient::Pointer sender, const ARequest *req);
  static void	refuse(const std::list<IClient::Pointer> &, Database &, IClient::Pointer sender, const ARequest *req);
  static void	accept(const std::list<IClient::Pointer> &, Database &, IClient::Pointer sender, const ARequest *req);
  static void	list(const std::list<IClient::Pointer> &, Database &, IClient::Pointer sender, const ARequest *req);

public:
  Friends(Friends const&);
  Friends& operator=(Friends const&);
};

#endif /* FRIENDS_H_ */
