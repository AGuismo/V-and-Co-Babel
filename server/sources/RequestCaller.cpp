#include	"RequestCaller.hh"
#include	"Database.hh"

namespace	request
{
	PluginCaller::PluginCaller(const std::list<IClient::Pointer> &clients) :
		_clients(clients)
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
    it->second(_clients, Database::getInstance(), client, req);
    return (true);
  }
}
