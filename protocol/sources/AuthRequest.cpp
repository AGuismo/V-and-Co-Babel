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
      const char *DelClient::DELETE = "Delete client request";

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

      DelClient::DelClient():
	Auth(request::client::auth::DELETE)
      {
      }

      DelClient::DelClient(const request::Username &name,
			   const request::PasswordType &password):
	Auth(request::client::auth::DELETE), _name(name), _password(password)
      {
      }

      DelClient::~DelClient()
      {
      }

      DelClient::DelClient(const DelClient &src) :
	Auth(request::client::auth::DELETE), _name(src._name), _password(src._password)
      {
      }

      DelClient	&DelClient::operator=(const DelClient &src)
      {
	if (this != &src)
	  {
	    _name = src._name;
	    _password = src._password;
	  }
	return (*this);
      }

      ARequest	*DelClient::clone()
      {
	return (new DelClient());
      }

      bool	DelClient::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const DelClient	*tmp = dynamic_cast<const DelClient *>(req);
	return (tmp->_name == _name && tmp->_password == _password);
      }

      bool	DelClient::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&DelClient::serialize(Protocol &rhs) const
      {
	UsernameLen	NameLen;

	DelClient::serialize(rhs);

	NameLen = _name.size();
	rhs << NameLen;
	rhs.push(_name, NameLen);

	rhs << _password;

	return (rhs);
      }

      Protocol	&DelClient::unserialize(Protocol &rhs)
      {
	UsernameLen	NameLen;

	DelClient::unserialize(rhs);

	rhs >> NameLen;
	rhs.pop(_name, NameLen);

	rhs >> _password;

	return (rhs);
      }

    } // !client

  } // !auth

} // !request
