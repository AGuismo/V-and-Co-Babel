#include	"Client.hh"
#include	"Server.hh"
#include	"ARequest.hh"
#include	"ServerRequest.hh"
#include	"Database.hh"

void	win32_symbol_loader()
{
	&Client::serialize_data;
	&ARequest::operator==;
	&ARequest::operator!=;
	&request::Server::serialize;
	&request::Server::unserialize;
	&Database::getInstance;
	&Database::newClient;
	//&Database::clientExist;
	//&Database::addRequest;
	//&Database::delRequest;
	&Database::addFriend;
	&Database::delClient;
	&Database::delFriend;
	&Database::modClientPass;
	&Database::modPrivacy;
	&Database::setClientStatus;
	&Database::setStatus;
}