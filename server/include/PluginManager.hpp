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

  protected:
    static IPlugin<Key, Sign>	*loadPlugin(const std::string &path)
    {
      return (0);
    }

    static void			unloadPlugin(IPlugin<Key, Sign> *plug)
    {
      plug->unload();
    }

  public:
    void			addPlugin(const std::string &name, IPlugin<Key, Sign> *plug)
    {
      if (_plugins.find(name) != _plugins.end())
	delPlugin(name);
      _plugins[name] = plug;
    }

    void			delPlugin(const std::string &name)
    {
      typename plugin_map::iterator	it = _plugins.find(name);

      if (it == _plugins.end())
	return ;
      unloadPlugin(it->second);
      _plugins.erase(it);
    }

    IPlugin<Key, Sign>		*getPlugin(const std::string &name) const
    {
      return (_plugins[name]);
    }

  private:
    Manager(Manager const&);
    Manager& operator=(Manager const&);

  protected:
    plugin_map	_plugins;
  };
}

#endif /* PLUGINMANAGER_H_ */
