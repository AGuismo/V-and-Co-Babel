#ifndef REQUESTCALLER_H_
# define REQUESTCALLER_H_

# include	"PluginCaller.hpp"
# include	"types.hh"
# include	"Client.hh"

class		ARequest;

namespace	request
{

  class PluginCaller : public plugin::Caller<request::ID,
					     void (*)(Server *, Client::Pointer, const ARequest *)>
{
public:
  PluginCaller();
  virtual ~PluginCaller();

private:
  PluginCaller(PluginCaller const&);
  PluginCaller& operator=(PluginCaller const&);
};

}

#endif /* REQUESTCALLER_H_ */
