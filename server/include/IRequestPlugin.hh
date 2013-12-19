#ifndef IREQUESTPLUGIN_H_
# define IREQUESTPLUGIN_H_

# include	"Client.hh"
# include	"IPlugin.hh"
# include	"types.hh"
# include	"Function.hpp"
# include	<list>

class		Server;
class		ARequest;
class		Database;
class		Env;

#if defined(WIN32)
# if defined(PLUGIN_API_EXPORT)
#  define PLUGIN_DLL_EXPORT	__declspec(dllexport)
# else
#  define PLUGIN_DLL_EXPORT
# endif
#elif defined(linux)
# define PLUGIN_DLL_EXPORT
#endif

namespace	plugin
{
  typedef Function<void (const std::list<IClient::Pointer> &, IClient::Pointer, const ARequest *)>	request_handler;
} // !plugin

namespace	request
{
  class PLUGIN_DLL_EXPORT IRequestPlugin : public plugin::IPlugin<request::ID, plugin::request_handler>
  {
  public:
    virtual ~IRequestPlugin() {};

  public:
    virtual IPlugin	*clone() = 0;
    virtual void	unload() = 0;
    virtual void	setActions(std::map<request::ID, plugin::request_handler> &) = 0;
    virtual void	getVersion(plugin::version::major &,
      plugin::version::minor &) const = 0;
  };
} // !request

extern	"C"
{
  PLUGIN_DLL_EXPORT request::IRequestPlugin	*loadPlugin(Database &, Env &);
}

#endif /* IREQUESTPLUGIN_H_ */
