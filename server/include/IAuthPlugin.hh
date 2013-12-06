#ifndef IAUTHPLUGIN_H_
# define IAUTHPLUGIN_H_

namespace	plugin
{
  class IAuth : public IPlugin
  {
  public:
    virtual ~IAuth() {};

  public:
    virtual bool	Connect();
  };
}

#endif /* IAUTHPLUGIN_H_ */
