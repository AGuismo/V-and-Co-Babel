#ifndef AUTH_H_
# define AUTH_H_

# include	<list>
# include	"IRequestPlugin.hh"

#if defined(WIN32)
# if defined(PLUGIN_API_EXPORT)
#  define CALL_PLUGIN_DLL_EXPORT	__declspec(dllexport)
# endif
#elif defined(linux)
# define CALL_PLUGIN_DLL_EXPORT
#endif

class CALL_PLUGIN_DLL_EXPORT Auth : public request::IRequestPlugin
{
public:
  Auth();
  virtual ~Auth();

public:
  IPlugin	*clone();
  void		unload();
  void		setActions(std::map<request::ID, void (*)(const std::list<IClient::Pointer> &,
							  IClient::Pointer,
							  const ARequest *)> &);
  void		getVersion(plugin::version::major &maj, plugin::version::minor &min) const;

private:
	static void	new_account(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
	static void	modify(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
	static void	remove(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
	static void	connect(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);
  static void	disconnect(const std::list<IClient::Pointer> &, IClient::Pointer sender, const ARequest *req);

public:
  Auth(Auth const&);
  Auth& operator=(Auth const&);
};

#endif /* AUTH_H_ */
