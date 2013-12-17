#ifndef REQUESTCALLER_H_
# define REQUESTCALLER_H_

# include	<list>
# include	"Client.hh"
# include	"types.hh"
# include	"PluginCaller.hpp"

class		ARequest;
class		Database;

namespace	request
{

  class PluginCaller : public plugin::Caller<request::ID,
	  void(*)(const std::list<IClient::Pointer> &, Database &, IClient::Pointer, const ARequest *)>
  {
  private:
	  typedef void(*request_callback)(const std::list<IClient::Pointer> &, Database &, IClient::Pointer, const ARequest *);
    typedef std::map<request::ID, request_callback>	callback_map;
  public:
    PluginCaller(const std::list<IClient::Pointer> &, Database &);
    virtual ~PluginCaller();

    bool		operator()(IClient::Pointer, const ARequest *);

  private:
    PluginCaller(PluginCaller const&);
    PluginCaller& operator=(PluginCaller const&);

  private:
    const std::list<IClient::Pointer>	&_clients;
	Database							&_database;
  };

}

#endif /* REQUESTCALLER_H_ */
