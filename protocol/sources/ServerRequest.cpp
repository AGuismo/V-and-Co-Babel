#include	<map>
#include	"ServerRequest.hh"
#include	"ARequest.hh"
#include	"Protocol.hpp"
#include	"RequestInfo.hpp"

namespace	request
{
  namespace	server
  {
    const char *Ok::OK = "OK";
    const char *BadRequest::BAD_REQ = "Bad request";
    const char *Forbidden::FORBIDDEN = "Forbidden request";
    const char *NotImplemented::NOT_IMPLEMENTED = "Request not implemented";
    const char *NoContent::NO_CONTENT = "No content found";
    const char *PartialContent::PARTIAL_CONTENT = "Partial content";
    const char *NoSlots::NO_SLOTS = "No slot available";
  }

  Server::Server(const request::ID id):
    ARequest(id)
  {
  }

  Server::~Server()
  {

  }

  Server::Server(Server const&src):
    ARequest(src)
  {

  }

  Server&	Server::operator=(Server const&src)
  {
    if (&src != this)
      {
	_code = src._code;
      }
    return (*this);
  }

  Protocol	&Server::serialize(Protocol &rhs) const
  {
    rhs << _code;
    return (rhs);
  }

  Protocol	&Server::unserialize(Protocol &rhs)
  {
    return (rhs);
  }
}
