#ifndef REQUESTCALLER_H_
# define REQUESTCALLER_H_

# include	<list>
# include	"Client.hh"
# include	"types.hh"
# include	"PluginCaller.hpp"
# include	"IRequestPlugin.hh"

class		ARequest;
class		Database;

namespace	request
{

  class PluginCaller : public plugin::Caller<request::ID, plugin::request_handler>
  {
  private:
    typedef std::map<request::ID, plugin::request_handler>	callback_map;
  public:
    PluginCaller(const std::list<IClient::Pointer> &);
    virtual ~PluginCaller();

    bool		operator()(IClient::Pointer, const ARequest *);

  private:
    PluginCaller(PluginCaller const&);
    PluginCaller& operator=(PluginCaller const&);

  private:
    const std::list<IClient::Pointer>	&_clients;
  };

}

#endif /* REQUESTCALLER_H_ */
