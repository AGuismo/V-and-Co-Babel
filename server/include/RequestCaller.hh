#ifndef REQUESTCALLER_H_
# define REQUESTCALLER_H_

# include	<list>
# include	"Client.hh"
# include	"types.hh"
# include	"PluginCaller.hpp"

class		ARequest;

namespace	request
{

  class PluginCaller : public plugin::Caller<request::ID,
	  void(*)(const std::list<IClient::Pointer> &, IClient::Pointer, const ARequest *)>
  {
  private:
	  typedef void(*request_callback)(const std::list<IClient::Pointer> &, IClient::Pointer, const ARequest *);
    typedef std::map<request::ID, request_callback>	callback_map;
  public:
    PluginCaller(Server *);
    virtual ~PluginCaller();

    bool		operator()(IClient::Pointer, const ARequest *);

  private:
    PluginCaller(PluginCaller const&);
    PluginCaller& operator=(PluginCaller const&);

  private:
    Server	*_server;
  };

}

#endif /* REQUESTCALLER_H_ */
