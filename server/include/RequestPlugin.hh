#ifndef REQUESTPLUGIN_H_
# define REQUESTPLUGIN_H_

# include	"PluginManager.hpp"
# include	"types.hh"
# include	"Client.hh"

class	ARequest;
class	IRequestPlugin;
class	Server;

namespace	request
{
  class PluginManager : public plugin::Manager<request::ID,
					       void (*)(Server *, Client::Pointer, const ARequest *)>
  {
  public:
    typedef void (*request_handler)(Server *, Client::Pointer, const ARequest *);
  public:
    PluginManager();
    virtual ~PluginManager();

  public:
    static plugin::IPlugin<request::ID, request_handler>	*loadPlugin(const std::string &path);
    static void			unloadPlugin(plugin::IPlugin<request::ID, request_handler> *plug);

  private:
    PluginManager(PluginManager const&);
    PluginManager& operator=(PluginManager const&);
  };
}

#endif /* REQUESTPLUGIN_H_ */
