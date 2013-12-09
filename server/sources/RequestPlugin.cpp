#include	"RequestPlugin.hh"
#include	"Server.hh"

namespace	request
{
  PluginManager::PluginManager()
  {

  }

  PluginManager::~PluginManager()
  {

  }

  plugin::IPlugin<request::ID, PluginManager::request_handler>	*PluginManager::loadPlugin(const std::string &path)
  {
    return (plugin::Manager<request::ID, Server::request_handler>::loadPlugin(path));
  }

  void			PluginManager::unloadPlugin(plugin::IPlugin<request::ID, request_handler> *plug)
  {
    plugin::Manager<request::ID, Server::request_handler>::unloadPlugin(plug);
  }
}
