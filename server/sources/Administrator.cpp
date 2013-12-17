#include	"Administrator.hh"

const std::string	Administrator::BAD_REQUEST = "Bad request";
const std::string	Administrator::OK = "Ok";
const std::string	Administrator::CONTENT = "Not enough content";
const std::string	Administrator::NOT_IMPLEMENT = "Not implemented yet";

Administrator::Administrator()
{
	_calls["DROP_DB"] = &Administrator::dropDB;
	_calls["SAVE_DB"] = &Administrator::saveDB;
	_calls["SHUTDOWN"] = &Administrator::shutdown;
}

Administrator::~Administrator()
{
}

void	Administrator::shutdown(const args &args, buffer &response)
{
	response = NOT_IMPLEMENT;
}

void	Administrator::dropDB(const args &args, buffer &response)
{
	response = NOT_IMPLEMENT;
}

void	Administrator::saveDB(const args &args, buffer &response)
{
	response = NOT_IMPLEMENT;
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