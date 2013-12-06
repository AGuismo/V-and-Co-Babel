#ifndef CHATREQUEST_H_
# define CHATREQUEST_H_

# include	"ARequest.hh"

namespace	request
{

  namespace	chat
  {
    class Chat : public ARequest
    {
    protected:
      Chat(const request::ID id);
      virtual ~Chat();
      Chat(Chat const&);
      Chat& operator=(Chat const&);

    public:
      virtual Protocol		&serialize(Protocol &) const;
      virtual Protocol		&unserialize(Protocol &);
      virtual ARequest		*clone() = 0;
    };

    namespace	client
    {
      class	Message : public Chat
      {
	static const char	*MESSAGE;

	Message();
	Message(const request::Username &from, const request::Username &to,
		const request::Time time, const request::Message &msg);
	~Message();
	Message(const Message &);
	Message	&operator=(const Message &);

	ARequest			*clone();
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	request::Username	from;
	request::Username	to;
	request::Time		time;
	request::Message	msg;
      };
    } // !client
  } // !chat

  namespace	server
  {

  } // !server

} // !request


#endif /* CHATREQUEST_H_ */
