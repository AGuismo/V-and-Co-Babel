#include	"Protocol.hpp"
#include	"AuthRequest.hh"

namespace	request
{


  namespace	auth
  {

    Auth::Auth(const request::ID id):
      ARequest(id)
    {

    }

    Auth::~Auth()
    {

    }

    Auth::Auth(Auth const&src):
      ARequest(src)
    {

    }

    Auth&	Auth::operator=(Auth const&src)
    {
      if (&src != this)
	{
	  _code = src._code;
	}
      return (*this);
    }

    Protocol	&Auth::serialize(Protocol &rhs) const
    {
      rhs << _code;
      return (rhs);
    }

    Protocol	&Auth::unserialize(Protocol &rhs)
    {
      return (rhs);
    }

    namespace	client
    {
      const char *NewClient::NEW = "New client request";

      NewClient::NewClient():
	Auth(request::client::auth::NEW)
      {
      }

      NewClient::NewClient(const request::Username &name,
			   const request::PasswordType &password,
			   const request::Privacy privacy):
	Auth(request::client::auth::NEW), _name(name), _password(password), _privacy(privacy)
      {
      }

      NewClient::~NewClient()
      {
      }

      NewClient::NewClient(const NewClient &src) :
	Auth(request::client::auth::NEW), _name(src._name), _password(src._password), _privacy(src._privacy)
      {
      }

      NewClient	&NewClient::operator=(const NewClient &src)
      {
	if (this != &src)
	  {
	    _name = src._name;
	    _password = src._password;
	    _privacy = src._privacy;
	  }
	return (*this);
      }

      ARequest	*NewClient::clone()
      {
	return (new NewClient());
      }

      bool	NewClient::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const NewClient	*tmp = dynamic_cast<const NewClient *>(req);
	return (tmp->_name == _name && tmp->_password == _password && tmp->_privacy == _privacy);
      }

      bool	NewClient::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&NewClient::serialize(Protocol &rhs) const
      {
	UsernameLen	NameLen;

	NewClient::serialize(rhs);

	NameLen = _name.size();
	rhs << NameLen;
	rhs.push(_name, NameLen);

	rhs << _password;

	rhs << _privacy;

	return (rhs);
      }

      Protocol	&NewClient::unserialize(Protocol &rhs)
      {
	UsernameLen	NameLen;

	NewClient::unserialize(rhs);

	rhs >> NameLen;
	rhs.pop(_name, NameLen);

	rhs >> _password;

	rhs >> _privacy;

	return (rhs);
      }

    } // !client

  } // !auth

} // !request
