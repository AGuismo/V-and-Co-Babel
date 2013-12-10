#include	"RequestPlugin.hh"
#include	"Server.hh"

namespace	request
{
  PluginManager::PluginManager()
  {

  }

  PluginManager::~PluginManager()
  {
    for (plugin_map::iterator it = _plugins.begin(); it != _plugins.end(); ++it)
      {
	it->second->unload();
      }

    for (dyn_plugin::iterator it = _loadedPlugins.begin(); it != _loadedPlugins.end(); ++it)
      {
	if (!it->second.DynamicClose())
	  std::cerr << "Warning: Unable to close correctly opened Library ("
		    << std::string(it->second.error()) << ")" << std::endl;
      }
  }

  void			PluginManager::loadPlugin(const std::string &path, const std::string &name)
  {
    DynamicAbstract	plugLib;
    plugin::IPlugin<request::ID, PluginManager::request_handler>	*(*plugin_ctor)(void);
    plugin::IPlugin<request::ID, PluginManager::request_handler>	*plugin;

    if (!plugLib.DynamicOpen(path))
      throw plugin::Exception("Unable to open Library(" + std::string(plugLib.error()) + ")");
    plugin_ctor = (plugin::IPlugin<request::ID, PluginManager::request_handler> *(*)(void))(plugLib.DynamicLoadSym("loadPlugin"));
    if (plugin_ctor == 0)
      throw plugin::Exception("Unable to find symbol (" + std::string(plugLib.error()) + ")");
    plugin = plugin_ctor();
    if (plugin == 0)
      throw plugin::Exception("Error while creating plugin (" + path + ")");
    _loadedPlugins[name] = plugLib;
    plugin::Manager<request::ID, PluginManager::request_handler>::addPlugin(name, plugin);
  }

  void			PluginManager::unloadPlugin(const std::string &name)
  {
    dyn_plugin::iterator	itDyn = _loadedPlugins.find(name);
    plugin_map::iterator	itPlug = _plugins.find(name);

    if (itDyn == _loadedPlugins.end() || itPlug == _plugins.end())
      throw plugin::Exception("Unable to unload plugin named: " + name + " (didn't exist)");
    itPlug->second->unload();
    itDyn->second.DynamicClose();
  }
}
