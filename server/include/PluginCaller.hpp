#ifndef PLUGINCALLER_H_
# define PLUGINCALLER_H_

# include	"PluginManager.hpp"
# include	"IPlugin.hh"

namespace	plugin
{
  template <typename Key, typename Sign>
  class Caller
  {
  public:
    Caller() {}
    virtual ~Caller() {}

  private:
    Caller(Caller const&);
    Caller& operator=(Caller const&);

  public:
    virtual void		setCallback(Key key, Sign callback)
    {
      _calls[key] = callback;
    }

    virtual void		loadPlugins(const plugin::Manager<Key, Sign> &calls)
    {
      const typename plugin::Manager<Key, Sign>::plugin_map	&plugins = calls.getAllPlugins();

      for (typename plugin::Manager<Key, Sign>::plugin_map::const_iterator it = plugins.begin();
	   it != plugins.end(); ++it)
	{
	  it->second->setActions(_calls);
	}
    }

  protected:
    std::map<Key, Sign>		_calls;
  };

}

#endif /* PLUGINCALLER_H_ */
