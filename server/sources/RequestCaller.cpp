#include	"RequestCaller.hh"
#include	"Server.hh"

namespace	request
{
  PluginCaller::PluginCaller(Server *serv):
    _server(serv)
  {

  }

  PluginCaller::~PluginCaller()
  {

  }

  bool	PluginCaller::operator()(IClient::Pointer client, const ARequest *req)
  {
    callback_map::iterator	it = _calls.find(req->code());

    if (it == _calls.end())
      return (false);
    it->second(_server->getClients(), client, req);
    return (true);
  }
}
