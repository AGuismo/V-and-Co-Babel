#include	"Protocol.hpp"
#include	"ChatRequest.hh"

namespace	request
{

  namespace	chat
  {
    Chat::Chat(const request::ID id):
      ARequest(id)
    {

    }

    Chat::~Chat()
    {

    }

    Chat::Chat(Chat const&src):
      ARequest(src)
    {

    }

    Chat&	Chat::operator=(Chat const&src)
    {
      if (&src != this)
	{
	  _code = src._code;
	}
      return (*this);
    }

    Protocol	&Chat::serialize(Protocol &rhs) const
    {
      rhs << _code;
      return (rhs);
    }

    Protocol	&Chat::unserialize(Protocol &rhs)
    {
      return (rhs);
    }

    namespace	client
    {
      const char *Message::MESSAGE = "Message request";

      Message::Message():
	Chat(request::client::chat::MESSAGE)
      {
      }

      Message::Message(const request::Username &from, const request::Username &to,
		       const request::Time time, const request::Message &msg):
	Chat(request::client::chat::MESSAGE), from(from), to(to), time(time), msg(msg)
      {
      }

      Message::~Message()
      {
      }

      Message::Message(const Message &src) :
	Chat(request::client::chat::MESSAGE), from(src.from), to(src.to), time(src.time), msg(src.msg)
      {

      }

      Message	&Message::operator=(const Message &src)
      {
	if (this != &src)
	  {
	    from = src.from;
	    to = src.to;
	    time = src.time;
	    msg = src.msg;
	  }
	return (*this);
      }

      ARequest	*Message::clone()
      {
	return (new Message());
      }

      bool	Message::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const Message	*tmp = dynamic_cast<const Message *>(req);
	return (tmp->from == from && tmp->to == to && tmp->time == time && tmp->msg == msg);
      }

      bool	Message::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&Message::serialize(Protocol &rhs) const
      {
	UsernameLen	UserLen;
	MessageLen	MsgLen;

	Chat::serialize(rhs);

	UserLen = from.size();
	rhs << UserLen;
	rhs.push(from, UserLen);

	UserLen = to.size();
	rhs << UserLen;
	rhs.push(to, UserLen);

	rhs << time;

	MsgLen = msg.size();
	rhs << MsgLen;
	rhs.push(msg, MsgLen);
	return (rhs);
      }

      Protocol	&Message::unserialize(Protocol &rhs)
      {
	UsernameLen	UserLen;
	MessageLen	MsgLen;

	Chat::unserialize(rhs);

	rhs >> UserLen;
	rhs.pop(from, UserLen);

	rhs >> UserLen;
	rhs.push(to, UserLen);

	rhs >> time;

	rhs >> MsgLen;
	rhs.pop(msg, MsgLen);
	return (rhs);
      }

    } // !client

  } // !chat

} // !request
