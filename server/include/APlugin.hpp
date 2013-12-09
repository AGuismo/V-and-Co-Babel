#ifndef APLUGIN_H_
# define APLUGIN_H_

# include	"IPlugin.hh"
# include	"Server.hh"

class BabelPlugin : public plugin::IPlugin<request::ID,
					   Server::request_handler>
{
public:
  virtual ~APlugin();
  virtual void	setActions(std::map<request::ID, >)

};

#endif /* APLUGIN_H_ */
