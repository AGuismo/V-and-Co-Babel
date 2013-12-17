#include	"RequestCaller.hh"
#include	"Database.hh"

namespace	request
{
	PluginCaller::PluginCaller(const std::list<IClient::Pointer> &clients, Database &db) :
		_clients(clients), _database(db)
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
    it->second(_clients, _database, client, req);
    return (true);
  }
}
