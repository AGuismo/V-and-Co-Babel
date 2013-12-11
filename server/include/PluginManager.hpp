#ifndef PLUGINMANAGER_H_
# define PLUGINMANAGER_H_

# include	<map>
# include	<string>
# include	"IPlugin.hh"

namespace	plugin
{
  class Exception
  {
  public:
    Exception(const std::string &) throw();
    virtual ~Exception() throw();

  public:
    Exception(Exception const&) throw();
    Exception& operator=(Exception const&) throw();

  public:
    const char	*what() const throw();

  private:
    std::string	_what;
  };

  template <typename Key, typename Sign>
  class Manager
  {
  public:
    typedef std::map<const std::string, IPlugin<Key, Sign> *>	plugin_map;

  public:
    Manager() {}
    virtual ~Manager() {}

  public:
    virtual void	addPlugin(const std::string &name, IPlugin<Key, Sign> *plug)
    {
      if (_plugins.find(name) != _plugins.end())
	_plugins[name]->unload();
      _plugins[name] = plug;
    }

    virtual void	delPlugin(const std::string &name)
    {
      typename plugin_map::iterator	it = _plugins.find(name);

      if (it == _plugins.end())
	return ;
      it->second->unload();
      _plugins.erase(it);
    }

    virtual IPlugin<Key, Sign>	*getPlugin(const std::string &name)
    {
      return (_plugins[name]);
    }

    const plugin_map	&getAllPlugins() const {return (_plugins);}

  private:
    Manager(Manager const&);
    Manager& operator=(Manager const&);

  protected:
    plugin_map	_plugins;

  };
}

#endif /* PLUGINMANAGER_H_ */
