#include	<string>
#include	"Administrator.hh"

const std::string	Administrator::BAD_REQUEST = "Bad request";
const std::string	Administrator::OK = "Ok";
const std::string	Administrator::CONTENT = "Not enough content";
const std::string	Administrator::NOT_IMPLEMENT = "Not implemented yet";

Administrator::Administrator() :
  _shutdownServerHandler(&Administrator::ignoreCb, this),
  _dropDBHandler(&Administrator::ignoreCb, this),
  _saveDBHandler(&Administrator::ignoreCb, this)
{
  _calls["dropdb"] = &Administrator::dropDB;
  _calls["savedb"] = &Administrator::saveDB;
  _calls["shutdown"] = &Administrator::shutdown;
  _calls["help"] = &Administrator::help;
}

Administrator::~Administrator()
{
}

const std::string	Administrator::ignoreCb()
{
  return (NOT_IMPLEMENT);
}

void	Administrator::registerShutdownServer(Function<const std::string ()> handler)
{
  _shutdownServerHandler = handler;
}

void	Administrator::registerDropDB(Function<const std::string ()> handler)
{
  _dropDBHandler = handler;
}

void	Administrator::registerSaveDB(Function<const std::string ()> handler)
{
  _saveDBHandler = handler;
}

void	Administrator::shutdown(const args &args, buffer &response)
{
  if (args.size() > 1)
    response = CONTENT;
  else
    response = _shutdownServerHandler();
}

void	Administrator::dropDB(const args &args, buffer &response)
{
  if (args.size() > 1)
    response = CONTENT;
  else
    response = _dropDBHandler();
}

void	Administrator::saveDB(const args &args, buffer &response)
{
  if (args.size() > 1)
    response = CONTENT;
  else
    response = _saveDBHandler();
}

void	Administrator::help(const args &args, buffer &response)
{
  response =	"dropdb : Drop the Database\n";
  response +=	"savedb : Save the Database\n";
  response +=	"shutdown : Stop the server\n";
  response +=	"help : Display this help\n";
}

void	Administrator::operator()(const args &args, buffer &response)
{
  callback_map::iterator it = _calls.find(args[0]);

  if (it == _calls.end())
    {
      response = BAD_REQUEST;
      return;
    }
  (this->*(it->second))(args, response);
}
