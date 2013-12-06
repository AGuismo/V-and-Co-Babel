#ifndef IPLUGIN_H_
# define IPLUGIN_H_

namespace	plugin
{
  class IPlugin
  {
  public:
    virtual ~IPlugin() {};

    virtual IPlugin	*clone() = 0;
  };
}

#endif /* IPLUGIN_H_ */
