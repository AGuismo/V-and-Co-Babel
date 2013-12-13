#ifndef IREQUESTPLUGIN_H_
# define IREQUESTPLUGIN_H_

# include	"IPlugin.hh"
# include	"types.hh"
# include	"Client.hh"

class		Server;
class		ARequest;

namespace	request
{
  class IRequestPlugin : public plugin::IPlugin<request::ID,
						void (*)(Server *, Client::Pointer, const ARequest *)>
  {
  public:
    virtual ~IRequestPlugin() {};

  public:
    virtual IPlugin	*clone() = 0;
    virtual void	unload() = 0;
    virtual void	setActions(std::map<request::ID, void (*)(Server *,
								  Client::Pointer,
								  const ARequest *)> &) = 0;
    virtual void	getVersion(plugin::version::major &,
				   plugin::version::minor &) const = 0;
  };
} // !request

extern	"C"
{
  request::IRequestPlugin	*loadPlugin(void);
}

#endif /* IREQUESTPLUGIN_H_ */
