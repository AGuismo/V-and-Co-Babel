#include	"Protocol.hpp"
#include	"CallRequest.hh"

namespace	request
{

  namespace	call
  {

    Call::Call(const request::ID id):
      ARequest(id)
    {

    }

    Call::~Call()
    {

    }

    Call::Call(Call const&src):
      ARequest(src)
    {

    }

    Call&	Call::operator=(Call const&src)
    {
      if (&src != this)
	{
	  _code = src._code;
	}
      return (*this);
    }

    Protocol	&Call::serialize(Protocol &rhs) const
    {
      rhs << _code;
      return (rhs);
    }

    Protocol	&Call::unserialize(Protocol &rhs)
    {
      return (rhs);
    }

    namespace	client
    {
      const char *CallClient::CALL = "Call client request";
      const char *AcceptClient::ACCEPT = "Accept Call client request";
      const char *RefuseClient::REFUSE = "Refuse Call client request";
      const char *HangupClient::HANG_UP = "Hang Up client request";

      CallClient::CallClient():
	Call(request::client::call::CALL)
      {
      }

      CallClient::CallClient(const request::Username &from,
			     const request::Username &to,
			     const request::Options  &option,
			     const request::IP	     &ip,
			     const request::Port     &port):
	Call(request::client::call::CALL), _from(from), _to(to), _option(option), _ip(ip), _port(port)
      {
      }
      CallClient::~CallClient()
      {
      }

      CallClient::CallClient(const CallClient &src) :
	Call(request::client::call::CALL), _from(src._from), _to(src._to), _option(src._option), _ip(src._ip), _port(src._port)
      {
      }

      CallClient	&CallClient::operator=(const CallClient &src)
      {
	if (this != &src)
	  {
	    _from = src._from;
	    _to = src._to;
	    _option = src._option;
	    _ip = src._ip;
	    _port = src._port;
	  }
	return (*this);
      }

      ARequest	*CallClient::clone()
      {
	return (new CallClient());
      }

      bool	CallClient::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const CallClient	*tmp = dynamic_cast<const CallClient *>(req);
	return (tmp->_from == _from && tmp->_to == _to && tmp->_option == _option && tmp->_ip == _ip && tmp->_port == _port);
      }

      bool	CallClient::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&CallClient::serialize(Protocol &rhs) const
      {
	request::UsernameLen	lenFrom;
	request::UsernameLen	lenTo;

	Call::serialize(rhs);


	rhs << _option;

	lenFrom = _from.size();
	rhs << lenFrom;
	rhs.push(_from, lenFrom);

	lenTo = _to.size();
	rhs << lenTo;
	rhs.push(_to, lenTo);

	rhs << _ip;

	rhs << _port;

	return (rhs);
      }

      Protocol	&CallClient::unserialize(Protocol &rhs)
      {
	request::UsernameLen	lenFrom;
	request::UsernameLen	lenTo;

	Call::unserialize(rhs);


	rhs >> _option;

	rhs >> lenFrom;
	rhs.pop(_from, lenFrom);

	rhs >> lenTo;
	rhs.pop(_to, lenTo);

	rhs >> _ip;

	rhs >> _port;

	return (rhs);
      }

      AcceptClient::AcceptClient():
	Call(request::client::call::ACCEPT)
      {
      }

      AcceptClient::AcceptClient(const request::Username &from,
				 const request::Username &to,
				 const request::IP	 &ip,
				 const request::Port	 &port):
	Call(request::client::call::ACCEPT), _from(from), _to(to), _ip(ip), _port(port)
      {
      }
      AcceptClient::~AcceptClient()
      {
      }

      AcceptClient::AcceptClient(const AcceptClient &src) :
	Call(request::client::call::ACCEPT), _from(src._from), _to(src._to), _ip(src._ip), _port(src._port)
      {
      }

      AcceptClient	&AcceptClient::operator=(const AcceptClient &src)
      {
	if (this != &src)
	  {
	    _from = src._from;
	    _to = src._to;
	    _ip = src._ip;
	    _port = src._port;
	  }
	return (*this);
      }

      ARequest	*AcceptClient::clone()
      {
	return (new AcceptClient());
      }

      bool	AcceptClient::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const AcceptClient	*tmp = dynamic_cast<const AcceptClient *>(req);
	return (tmp->_from == _from && tmp->_to == _to && tmp->_ip == _ip && tmp->_port == _port);
      }

      bool	AcceptClient::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&AcceptClient::serialize(Protocol &rhs) const
      {
	request::UsernameLen	lenFrom;
	request::UsernameLen	lenTo;

	Call::serialize(rhs);

	lenFrom = _from.size();
	rhs << lenFrom;
	rhs.push(_from, lenFrom);

	lenTo = _to.size();
	rhs << lenTo;
	rhs.push(_to, lenTo);

	rhs << _ip;

	rhs << _port;

	return (rhs);
      }

      Protocol	&AcceptClient::unserialize(Protocol &rhs)
      {
	request::UsernameLen	lenFrom;
	request::UsernameLen	lenTo;

	Call::unserialize(rhs);

	rhs >> lenFrom;
	rhs.pop(_from, lenFrom);

	rhs >> lenTo;
	rhs.pop(_to, lenTo);

	rhs >> _ip;

	rhs >> _port;

	return (rhs);
      }

      RefuseClient::RefuseClient():
	Call(request::client::call::REFUSE)
      {
      }

      RefuseClient::RefuseClient(const request::Username &from,
			     const request::Username &to):
	Call(request::client::call::REFUSE), _from(from), _to(to)
      {
      }
      RefuseClient::~RefuseClient()
      {
      }

      RefuseClient::RefuseClient(const RefuseClient &src) :
	Call(request::client::call::REFUSE), _from(src._from), _to(src._to)
      {
      }

      RefuseClient	&RefuseClient::operator=(const RefuseClient &src)
      {
	if (this != &src)
	  {
	    _from = src._from;
	    _to = src._to;
	  }
	return (*this);
      }

      ARequest	*RefuseClient::clone()
      {
	return (new RefuseClient());
      }

      bool	RefuseClient::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const RefuseClient	*tmp = dynamic_cast<const RefuseClient *>(req);
	return (tmp->_from == _from && tmp->_to == _to);
      }

      bool	RefuseClient::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&RefuseClient::serialize(Protocol &rhs) const
      {
	request::UsernameLen	lenFrom;
	request::UsernameLen	lenTo;

	Call::serialize(rhs);

	lenFrom = _from.size();
	rhs << lenFrom;
	rhs.push(_from, lenFrom);

	lenTo = _to.size();
	rhs << lenTo;
	rhs.push(_to, lenTo);

	return (rhs);
      }

      Protocol	&RefuseClient::unserialize(Protocol &rhs)
      {
	request::UsernameLen	lenFrom;
	request::UsernameLen	lenTo;

	Call::unserialize(rhs);

	rhs >> lenFrom;
	rhs.pop(_from, lenFrom);

	rhs >> lenTo;
	rhs.pop(_to, lenTo);

	return (rhs);
      }

      HangupClient::HangupClient():
	Call(request::client::call::HANG_UP)
      {
      }

      HangupClient::HangupClient(const request::Username &from,
			     const request::Username &to):
	Call(request::client::call::HANG_UP), _from(from), _to(to)
      {
      }
      HangupClient::~HangupClient()
      {
      }

      HangupClient::HangupClient(const HangupClient &src) :
	Call(request::client::call::HANG_UP), _from(src._from), _to(src._to)
      {
      }

      HangupClient	&HangupClient::operator=(const HangupClient &src)
      {
	if (this != &src)
	  {
	    _from = src._from;
	    _to = src._to;
	  }
	return (*this);
      }

      ARequest	*HangupClient::clone()
      {
	return (new HangupClient());
      }

      bool	HangupClient::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const HangupClient	*tmp = dynamic_cast<const HangupClient *>(req);
	return (tmp->_from == _from && tmp->_to == _to);
      }

      bool	HangupClient::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&HangupClient::serialize(Protocol &rhs) const
      {
	request::UsernameLen	lenFrom;
	request::UsernameLen	lenTo;

	Call::serialize(rhs);

	lenFrom = _from.size();
	rhs << lenFrom;
	rhs.push(_from, lenFrom);

	lenTo = _to.size();
	rhs << lenTo;
	rhs.push(_to, lenTo);

	return (rhs);
      }

      Protocol	&HangupClient::unserialize(Protocol &rhs)
      {
	request::UsernameLen	lenFrom;
	request::UsernameLen	lenTo;

	Call::unserialize(rhs);

	rhs >> lenFrom;
	rhs.pop(_from, lenFrom);

	rhs >> lenTo;
	rhs.pop(_to, lenTo);

	return (rhs);
      }


    } // !server

  } // !call

} // !request
