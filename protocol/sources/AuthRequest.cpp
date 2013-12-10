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
      const char *DelClient::REMOVE = "Delete client request";

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

	Auth::serialize(rhs);

	NameLen = _name.size();
	rhs << NameLen;
	rhs.push(_name, NameLen);

	rhs.push(_password, request::Crypt::PASS_SIZE);

	rhs << _privacy;

	return (rhs);
      }

      Protocol	&NewClient::unserialize(Protocol &rhs)
      {
	UsernameLen	NameLen;

	Auth::unserialize(rhs);

	rhs >> NameLen;
	rhs.pop(_name, NameLen);

	rhs.pop(_password, request::Crypt::PASS_SIZE);

	rhs >> _privacy;
	return (rhs);
      }

      DelClient::DelClient():
	Auth(request::client::auth::REMOVE)
      {
      }

      DelClient::DelClient(const request::Username &name,
			   const request::PasswordType &password):
	Auth(request::client::auth::REMOVE), _name(name), _password(password)
      {
      }

      DelClient::~DelClient()
      {
      }

      DelClient::DelClient(const DelClient &src) :
	Auth(request::client::auth::REMOVE), _name(src._name), _password(src._password)
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

	Auth::serialize(rhs);

	NameLen = _name.size();
	rhs << NameLen;
	rhs.push(_name, NameLen);

	rhs.push(_password, request::Crypt::PASS_SIZE);

	return (rhs);
      }

      Protocol	&DelClient::unserialize(Protocol &rhs)
      {
	UsernameLen	NameLen;

	Auth::unserialize(rhs);

	rhs >> NameLen;
	rhs.pop(_name, NameLen);

	rhs.pop(_password, request::Crypt::PASS_SIZE);

	return (rhs);
      }

      ModifyClient::ModifyClient():
	Auth(request::client::auth::MODIFY)
      {
      }

      ModifyClient::ModifyClient(const request::Username &name,
				 const request::PasswordType &oldPassword,
				 const request::PasswordType &newPassword):
	Auth(request::client::auth::MODIFY), _name(name), _oldPassword(oldPassword), _newPassword(newPassword)
      {
      }

      ModifyClient::~ModifyClient()
      {
      }

      ModifyClient::ModifyClient(const ModifyClient &src) :
	Auth(request::client::auth::MODIFY), _name(src._name), _oldPassword(src._oldPassword), _newPassword(src._newPassword)
      {
      }

      ModifyClient	&ModifyClient::operator=(const ModifyClient &src)
      {
	if (this != &src)
	  {
	    _name = src._name;
	    _oldPassword = src._oldPassword;
	    _newPassword = src._newPassword;
	  }
	return (*this);
      }

      ARequest	*ModifyClient::clone()
      {
	return (new ModifyClient());
      }

      bool	ModifyClient::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const ModifyClient	*tmp = dynamic_cast<const ModifyClient *>(req);
	return (tmp->_name == _name && tmp->_oldPassword == _oldPassword && tmp->_newPassword == _newPassword);
      }

      bool	ModifyClient::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&ModifyClient::serialize(Protocol &rhs) const
      {
	UsernameLen	NameLen;

	Auth::serialize(rhs);

	NameLen = _name.size();
	rhs << NameLen;
	rhs.push(_name, NameLen);

	rhs.push(_oldPassword, request::Crypt::PASS_SIZE);
	rhs.push(_newPassword, request::Crypt::PASS_SIZE);
	return (rhs);
      }

      Protocol	&ModifyClient::unserialize(Protocol &rhs)
      {
	UsernameLen	NameLen;

	Auth::unserialize(rhs);

	rhs >> NameLen;
	rhs.pop(_name, NameLen);

	rhs.pop(_oldPassword, request::Crypt::PASS_SIZE);
	rhs.pop(_newPassword, request::Crypt::PASS_SIZE);

	return (rhs);
      }

      ConnectClient::ConnectClient():
	Auth(request::client::auth::CONNECT)
      {
      }

      ConnectClient::ConnectClient(const request::Username &name,
				 const request::PasswordType &password):
	Auth(request::client::auth::CONNECT), _name(name), _password(password)
      {
      }

      ConnectClient::~ConnectClient()
      {
      }

      ConnectClient::ConnectClient(const ConnectClient &src) :
	Auth(request::client::auth::CONNECT), _name(src._name), _password(src._password)
      {
      }

      ConnectClient	&ConnectClient::operator=(const ConnectClient &src)
      {
	if (this != &src)
	  {
	    _name = src._name;
	    _password = src._password;
	  }
	return (*this);
      }

      ARequest	*ConnectClient::clone()
      {
	return (new ConnectClient());
      }

      bool	ConnectClient::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const ConnectClient	*tmp = dynamic_cast<const ConnectClient *>(req);
	return (tmp->_name == _name && tmp->_password == _password);
      }

      bool	ConnectClient::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&ConnectClient::serialize(Protocol &rhs) const
      {
	UsernameLen	NameLen;

	Auth::serialize(rhs);

	NameLen = _name.size();
	rhs << NameLen;
	rhs.push(_name, NameLen);

	rhs.push(_password, request::Crypt::PASS_SIZE);

	return (rhs);
      }

      Protocol	&ConnectClient::unserialize(Protocol &rhs)
      {
	UsernameLen	NameLen;

	Auth::unserialize(rhs);

	rhs >> NameLen;
	rhs.pop(_name, NameLen);

	rhs.pop(_password, request::Crypt::PASS_SIZE);

	return (rhs);
      }

      DisconnectClient::DisconnectClient():
	Auth(request::client::auth::DISCONNECT)
      {
      }

      DisconnectClient::~DisconnectClient()
      {
      }

      DisconnectClient::DisconnectClient(const DisconnectClient &src) :
	Auth(request::client::auth::DISCONNECT)
      {
	(void)src;
      }

      ARequest	*DisconnectClient::clone()
      {
	return (new DisconnectClient());
      }

      Protocol		&DisconnectClient::serialize(Protocol &rhs) const
      {
	Auth::serialize(rhs);
	return (rhs);
      }

      Protocol	&DisconnectClient::unserialize(Protocol &rhs)
      {
	Auth::unserialize(rhs);
	return (rhs);
      }

    } // !client

  } // !auth

} // !request
