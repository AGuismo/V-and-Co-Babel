#ifndef IPLUGIN_H_
# define IPLUGIN_H_

# include	<map>

namespace	plugin
{
  struct	version
  {
    typedef unsigned char	minor;
    typedef unsigned char	major;

    static const major		MAJOR = 1;
    static const minor		MINOR = 1;
  };

  template <typename Key, typename Sign>
  class IPlugin
  {
  protected:
    virtual ~IPlugin() {};

  public:
    virtual IPlugin	*clone() = 0;
    virtual void	unload() = 0;
    virtual void	setActions(std::map<Key, Sign> &) = 0;
    virtual void	getVersion(version::major &, version::minor &) const = 0;
  };
} // !plugin

#endif /* IPLUGIN_H_ */
