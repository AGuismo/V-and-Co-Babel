#ifndef BABEL_PLUGIN_H_
# define BABEL_PLUGIN_H_

# include	"IPlugin.hh"
# include	"Server.hh"

class BabelPlugin : public plugin::IPlugin<request::ID,
					   Server::request_handler>
{
public:
  virtual ~APlugin();
  virtual IPlugin	*clone() = 0;
  virtual void		setActions(std::map<request::ID, Server::request_handler> &) = 0;
};

#endif /* BABEL_PLUGIN_H_ */
