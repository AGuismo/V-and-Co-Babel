#ifndef IPLUGIN_H_
# define IPLUGIN_H_

# include	<map>

namespace	plugin
{
  template <typename Key, typename Sign>
  class IPlugin
  {
  protected:
    virtual ~IPlugin() {};

  public:
    virtual IPlugin	*clone() = 0;
    virtual void	unload() = 0;
    virtual void	setActions(std::map<Key, Sign> &) = 0;
  };
}

#endif /* IPLUGIN_H_ */
