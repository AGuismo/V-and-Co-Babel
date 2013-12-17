#ifndef CHAT_H_
# define CHAT_H_

# include	<list>
# include	"IRequestPlugin.hh"

class Chat : public request::IRequestPlugin
{
public:
  Chat();
  virtual ~Chat();

public:
  IPlugin	*clone();
  void		unload();
  void		setActions(std::map<request::ID, void (*)(const std::list<IClient::Pointer> &,
							  IClient::Pointer,
							  const ARequest *)> &);
  void		getVersion(plugin::version::major &maj, plugin::version::minor &min) const;

private:
  static void	message(const std::list<IClient::Pointer> &,
			IClient::Pointer sender, const ARequest *req);

public:
  Chat(Chat const&);
  Chat& operator=(Chat const&);
};

#endif /* CHAT_H_ */
