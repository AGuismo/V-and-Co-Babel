#ifndef PLUGINMANAGER_H_
# define PLUGINMANAGER_H_

# include	<map>

namespace	plugin
{
  class	IPlugin;

  class Manager
  {
    typedef std::map<const std::string, IPlugin *>	plugin_map;
  public:
    Manager();
    virtual ~Manager();

  public:
    bool	addPlugin(const std::string &, IPlugin *);
    bool	delPlugin(const std::string &, IPlugin *);
    IPlugin	*getPlugin(const std::string &) const;

  private:
    Manager(Manager const&);
    Manager& operator=(Manager const&);

  private:
    plugin_map	_plugins;
  };
}

#endif /* PLUGINMANAGER_H_ */
