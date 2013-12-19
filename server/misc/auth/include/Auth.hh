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

class	Database;

class CALL_PLUGIN_DLL_EXPORT Auth : public request::IRequestPlugin
{
 public:
  Auth();
  virtual ~Auth();

 public:
  IPlugin	*clone();
  void		unload();
  void		setActions(std::map<request::ID, void (*)(const std::list<IClient::Pointer> &,
							  Database &,
							  IClient::Pointer,
							  const ARequest *)> &);
void		getVersion(plugin::version::major &maj, plugin::version::minor &min) const;

private:
 void	new_account(const std::list<IClient::Pointer> &, Database &, IClient::Pointer sender, const ARequest *req);
 void	modify(const std::list<IClient::Pointer> &, Database &, IClient::Pointer sender, const ARequest *req);
 void	remove(const std::list<IClient::Pointer> &, Database &, IClient::Pointer sender, const ARequest *req);
 void	connect(const std::list<IClient::Pointer> &, Database &, IClient::Pointer sender, const ARequest *req);
 void	disconnect(const std::list<IClient::Pointer> &, Database &, IClient::Pointer sender, const ARequest *req);

public:
Auth(Auth const&);
Auth& operator=(Auth const&);
};

#endif /* AUTH_H_ */
