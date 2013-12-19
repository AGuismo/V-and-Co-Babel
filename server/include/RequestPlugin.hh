#ifndef REQUESTPLUGIN_H_
# define REQUESTPLUGIN_H_

# include	<map>
# include	"IRequestPlugin.hh"
# include	"PluginManager.hpp"
# include	"types.hh"
# include	"Client.hh"
# include	"DynamicAbstract.hh"

class	ARequest;
class	IRequestPlugin;
class	Server;
class	Database;
class	Env;

namespace	request
{
  class PluginManager : public plugin::Manager<request::ID, plugin::request_handler>
  {
  public:
    typedef std::map<std::string, DynamicAbstract>	dyn_plugin;
  public:
    PluginManager(Database &, Env &);
    virtual ~PluginManager();

  public:
    void	loadPlugin(const std::string &path, const std::string &name);
    void	unloadPlugin(const std::string &name);

  private:
    PluginManager(PluginManager const&);
    PluginManager& operator=(PluginManager const&);

  private:
    dyn_plugin		_loadedPlugins;
    Database		&_db;
    Env			&_env;
  };
}

#endif /* REQUESTPLUGIN_H_ */
