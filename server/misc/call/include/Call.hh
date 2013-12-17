#ifndef CALL_H_
# define CALL_H_

# include	<list>
# include	"IRequestPlugin.hh"

class Call : public request::IRequestPlugin
{
public:
  Call();
  virtual ~Call();

public:
  IPlugin	*clone();
  void		unload();
  void		setActions(std::map<request::ID, void(*)(const std::list<IClient::Pointer> &,
							  IClient::Pointer,
							  const ARequest *)> &);
  void		getVersion(plugin::version::major &maj, plugin::version::minor &min) const;

private:
	static bool	searchClient(const std::list<IClient::Pointer> &clients, const std::string &name, IClient::Pointer &);

private:
	static void	call(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req);
	static void	accept(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req);
	static void	refuse(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req);
	static void	hangup(const std::list<IClient::Pointer> &clients, IClient::Pointer sender, const ARequest *req);

public:
  Call(Call const&);
  Call& operator=(Call const&);
};

#endif /* CALL_H_ */
