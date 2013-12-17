#ifndef REQUESTPLUGIN_H_
# define REQUESTPLUGIN_H_

# include	<map>
# include	"PluginManager.hpp"
# include	"types.hh"
# include	"Client.hh"
# include	"DynamicAbstract.hh"

class	ARequest;
class	IRequestPlugin;
class	Server;

namespace	request
{
  class PluginManager : public plugin::Manager<request::ID,
					       void (*)(const std::list<IClient::Pointer> &, IClient::Pointer, const ARequest *)>
  {
  public:
	  typedef void(*request_handler)(const std::list<IClient::Pointer> &, IClient::Pointer, const ARequest *);
    typedef std::map<std::string, DynamicAbstract>	dyn_plugin;
  public:
    PluginManager();
    virtual ~PluginManager();

  public:
    void	loadPlugin(const std::string &path, const std::string &name);
    void	unloadPlugin(const std::string &name);

  private:
    PluginManager(PluginManager const&);
    PluginManager& operator=(PluginManager const&);

  private:
    dyn_plugin		_loadedPlugins;
  };
}

#endif /* REQUESTPLUGIN_H_ */
