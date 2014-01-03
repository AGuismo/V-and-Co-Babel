#include	"Protocol.hpp"
#include	"FriendRequest.hh"

namespace	request
{
  namespace	friends
  {
    namespace	server
    {
      const char *Update::UPDATE = "Friend Updating";
    } // !server

    namespace	client
    {
      const char *Request::REQUEST = "Friend Requesting";
      const char *DelFriend::DEL_FRIEND = "Friend deleting";
      const char *Accept::ACCEPT = "Friend accepting";
      const char *Refuse::REFUSE = "Friend refusing";
      const char *List::LIST = "Friend listing";
    } // !client

    Friend::Friend(const request::ID id):
      ARequest(id)
    {

    }

    Friend::~Friend()
    {

    }

    Friend::Friend(Friend const&src):
      ARequest(src)
    {

    }

    Friend&	Friend::operator=(Friend const&src)
    {
      if (&src != this)
	{
	  _code = src._code;
	}
      return (*this);
    }

    Protocol	&Friend::serialize(Protocol &rhs) const
    {
      rhs << _code;
      return (rhs);
    }

    Protocol	&Friend::unserialize(Protocol &rhs)
    {
      return (rhs);
    }

    bool	Friend::operator==(const ARequest *req) const
    {
      return (ARequest::operator==(req));
    }

    bool	Friend::operator!=(const ARequest *req) const
    {
      return (ARequest::operator!=(req));
    }

    namespace	server
    {
      Update::Update():
	Friend(request::server::friends::UPDATE)
      {
      }

      Update::Update(const request::Status st,
		     const request::StatusDetail &detail,
		     const request::Username &username):
	Friend(request::server::friends::UPDATE), status(st), detail(detail), username(username)
      {
      }

      Update::~Update()
      {
      }

      Update::Update(const Update &src) :
	Friend(request::server::friends::UPDATE), status(src.status), detail(src.detail), username(src.username)
      {

      }

      Update	&Update::operator=(const Update &src)
      {
	if (this != &src)
	  {
	    status = src.status;
	    detail = src.detail;
	    username = src.username;
	  }
	return (*this);
      }

      ARequest	*Update::clone() const
      {
	return (new Update(*this));
      }

      bool	Update::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const Update	*tmp = dynamic_cast<const Update *>(req);
	return (tmp->status == status && tmp->detail == detail && tmp->username == username);
      }

      bool	Update::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&Update::serialize(Protocol &rhs) const
      {
	UsernameLen	userLen = username.length();
	StatusDetailLen	detailLen = detail.length();

	Friend::serialize(rhs);
	rhs << userLen;
	rhs.push(username, userLen);
	rhs << status;
	rhs << detailLen;
	rhs.push(detail, detailLen);
	return (rhs);
      }

      Protocol	&Update::unserialize(Protocol &rhs)
      {
	UsernameLen	userLen;
	StatusDetailLen	detailLen;

	Friend::unserialize(rhs);
	rhs >> userLen;
	rhs.pop(username, userLen);
	rhs >> status;
	rhs >> detailLen;
	rhs.pop(detail, detailLen);
	return (rhs);
      }


    } // !server

    namespace	client
    {
      Request::Request():
	Friend(request::client::friends::REQUEST)
      {
      }

      Request::Request(const request::Username &from,
		       const request::Username &to):
	Friend(request::client::friends::REQUEST), from(from), to(to)
      {
      }

      Request::~Request()
      {
      }

      Request::Request(const Request &src) :
	Friend(request::client::friends::REQUEST), from(src.from), to(src.to)
      {

      }

      Request	&Request::operator=(const Request &src)
      {
	if (this != &src)
	  {
	    to = src.to;
	    from = src.from;
	  }
	return (*this);
      }

      ARequest	*Request::clone() const
      {
	return (new Request(*this));
      }

      bool	Request::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const Request	*tmp = dynamic_cast<const Request *>(req);
	std::cout << std::endl;
	std::cout << "__________________________" << std::endl;
	std::cout << "FROM DB : [" << from << "]" << std::endl;
	std::cout << "FROM REQ : [" << tmp->from << "]" << std::endl;
	std::cout << "TO DB : [" << to << "]" << std::endl;
	std::cout << "TO REQ : [" << tmp->to << "]" << std::endl;
	std::cout << "__________________________" << std::endl;
	std::cout << std::endl;
	return (tmp->from == from && tmp->to == to);
      }

      bool	Request::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&Request::serialize(Protocol &rhs) const
      {
	UsernameLen	userLen;

	Friend::serialize(rhs);
	userLen = from.length();
	rhs << userLen;
	rhs.push(from, userLen);

	userLen = to.length();
	rhs << userLen;
	rhs.push(to, userLen);
	return (rhs);
      }

      Protocol	&Request::unserialize(Protocol &rhs)
      {
	UsernameLen	userLen;

	Friend::unserialize(rhs);

	rhs >> userLen;
	rhs.pop(from, userLen);

	rhs >> userLen;
	rhs.pop(to, userLen);
	return (rhs);
      }

      DelFriend::DelFriend():
	Friend(request::client::friends::DEL_FRIEND)
      {
      }

      DelFriend::DelFriend(const request::Username &from):
	Friend(request::client::friends::DEL_FRIEND), from(from)
      {
      }

      DelFriend::~DelFriend()
      {
      }

      DelFriend::DelFriend(const DelFriend &src) :
	Friend(request::client::friends::DEL_FRIEND), from(src.from)
      {

      }

      DelFriend	&DelFriend::operator=(const DelFriend &src)
      {
	if (this != &src)
	  {
	    from = src.from;
	  }
	return (*this);
      }

      ARequest	*DelFriend::clone() const
      {
	return (new DelFriend(*this));
      }

      bool	DelFriend::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const DelFriend	*tmp = dynamic_cast<const DelFriend *>(req);
	return (tmp->from == from);
      }

      bool	DelFriend::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&DelFriend::serialize(Protocol &rhs) const
      {
	UsernameLen	userLen;

	Friend::serialize(rhs);
	userLen = from.length();
	rhs << userLen;
	rhs.push(from, userLen);
	return (rhs);
      }

      Protocol	&DelFriend::unserialize(Protocol &rhs)
      {
	UsernameLen	userLen;

	Friend::unserialize(rhs);

	rhs >> userLen;
	rhs.pop(from, userLen);

	return (rhs);
      }


      Accept::Accept():
	Friend(request::client::friends::ACCEPT)
      {
      }

      Accept::Accept(const request::Username &from,
		     const request::Username &to):
	Friend(request::client::friends::ACCEPT), from(from), to(to)
      {
      }

      Accept::~Accept()
      {
      }

      Accept::Accept(const Accept &src) :
	Friend(request::client::friends::ACCEPT), from(src.from), to(src.to)
      {

      }

      Accept	&Accept::operator=(const Accept &src)
      {
	if (this != &src)
	  {
	    to = src.to;
	    from = src.from;
	  }
	return (*this);
      }

      ARequest	*Accept::clone() const
      {
	return (new Accept(*this));
      }

      bool	Accept::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const Accept	*tmp = dynamic_cast<const Accept *>(req);
	return (tmp->from == from && tmp->to == to);
      }

      bool	Accept::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&Accept::serialize(Protocol &rhs) const
      {
	UsernameLen	userLen;

	Friend::serialize(rhs);
	userLen = from.length();
	rhs << userLen;
	rhs.push(from, userLen);

	userLen = to.length();
	rhs << userLen;
	rhs.push(to, userLen);
	return (rhs);
      }

      Protocol	&Accept::unserialize(Protocol &rhs)
      {
	UsernameLen	userLen;

	Friend::unserialize(rhs);

	rhs >> userLen;
	rhs.pop(from, userLen);

	rhs >> userLen;
	rhs.pop(to, userLen);
	return (rhs);
      }

      Refuse::Refuse():
	Friend(request::client::friends::REFUSE)
      {
      }

      Refuse::Refuse(const request::Username &from,
		     const request::Username &to):
	Friend(request::client::friends::REFUSE), from(from), to(to)
      {
      }

      Refuse::~Refuse()
      {
      }

      Refuse::Refuse(const Refuse &src) :
	Friend(request::client::friends::REFUSE), from(src.from), to(src.to)
      {

      }

      Refuse	&Refuse::operator=(const Refuse &src)
      {
	if (this != &src)
	  {
	    to = src.to;
	    from = src.from;
	  }
	return (*this);
      }

      ARequest	*Refuse::clone() const
      {
	return (new Refuse(*this));
      }

      bool	Refuse::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const Refuse	*tmp = dynamic_cast<const Refuse *>(req);
	return (tmp->from == from && tmp->to == to);
      }

      bool	Refuse::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&Refuse::serialize(Protocol &rhs) const
      {
	UsernameLen	userLen;

	Friend::serialize(rhs);
	userLen = from.length();
	rhs << userLen;
	rhs.push(from, userLen);

	userLen = to.length();
	rhs << userLen;
	rhs.push(to, userLen);
	return (rhs);
      }

      Protocol	&Refuse::unserialize(Protocol &rhs)
      {
	UsernameLen	userLen;

	Friend::unserialize(rhs);

	rhs >> userLen;
	rhs.pop(from, userLen);

	rhs >> userLen;
	rhs.pop(to, userLen);
	return (rhs);
      }

      List::List():
	Friend(request::client::friends::LIST)
      {
      }

      List::~List()
      {
      }

      List::List(const List &src) :
	Friend(request::client::friends::LIST)
      {
	(void)src;
      }

      List	&List::operator=(const List &src)
      {
	if (this != &src)
	  {
	  }
	return (*this);
      }

      ARequest	*List::clone() const
      {
	return (new List(*this));
      }

    } // !client

  } // !friends
} // !request
