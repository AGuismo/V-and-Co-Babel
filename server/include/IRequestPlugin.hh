#ifndef IREQUESTPLUGIN_H_
# define IREQUESTPLUGIN_H_

# include	"Client.hh"
# include	"IPlugin.hh"
# include	"types.hh"

class		Server;
class		ARequest;
class	Database;

#if defined(WIN32)
# if defined(PLUGIN_API_EXPORT)
#  define PLUGIN_DLL_EXPORT	__declspec(dllexport)
# else
#  define PLUGIN_DLL_EXPORT
# endif
#elif defined(linux)
# define PLUGIN_DLL_EXPORT
#endif

namespace	request
{
  class PLUGIN_DLL_EXPORT IRequestPlugin : public plugin::IPlugin<request::ID,
	  void(*)(const std::list<IClient::Pointer> &, Database &, IClient::Pointer, const ARequest *)>
  {
  public:
    virtual ~IRequestPlugin() {};

  public:
    virtual IPlugin	*clone() = 0;
    virtual void	unload() = 0;
	virtual void	setActions(std::map<request::ID, void(*)(const std::list<IClient::Pointer> &,
									Database &,
								  IClient::Pointer,
								  const ARequest *)> &) = 0;
    virtual void	getVersion(plugin::version::major &,
				   plugin::version::minor &) const = 0;
  };
} // !request

extern	"C"
{
  PLUGIN_DLL_EXPORT request::IRequestPlugin	*loadPlugin(void);
}

#endif /* IREQUESTPLUGIN_H_ */
