#ifndef CALLREQUEST_H_
# define CALLREQUEST_H_

# include	"ARequest.hh"

namespace	request
{

  namespace	call
  {
    class Call : public ARequest
    {
    protected:
      Call(const request::ID id);
      virtual ~Call();
      Call(Call const&);
      Call& operator=(Call const&);

    public:
      virtual Protocol		&serialize(Protocol &) const;
      virtual Protocol		&unserialize(Protocol &);
      virtual ARequest		*clone() const = 0;
    };

    namespace	client
    {
      struct	CallClient : public Call
      {
	static const char	*CALL;

	CallClient();
	CallClient(const request::Username &from,
		   const request::Username &to,
		   const request::Options &option,
		   const request::IP	   &ip,
		   const request::Port	   &port);
	~CallClient();
	CallClient(const CallClient &);
	CallClient	&operator=(const CallClient &);

	ARequest			*clone() const;
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	request::Username		_from;
	request::Username		_to;
	request::Options		_option;
	request::IP			_ip;
	request::Port			_port;
      };

      struct	AcceptClient : public Call
      {
	static const char	*ACCEPT;

	AcceptClient();
	AcceptClient(const request::Username &from,
		     const request::Username &to,
		     const request::IP	     &ip,
		     const request::Port     &port);
	~AcceptClient();
	AcceptClient(const AcceptClient &);
	AcceptClient	&operator=(const AcceptClient &);

	ARequest			*clone() const;
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	request::Username		_from;
	request::Username		_to;
	request::IP			_ip;
	request::Port			_port;
      };

      struct	RefuseClient : public Call
      {
	static const char	*REFUSE;

	RefuseClient();
	RefuseClient(const request::Username &from,
		     const request::Username &to);
	~RefuseClient();
	RefuseClient(const RefuseClient &);
	RefuseClient	&operator=(const RefuseClient &);

	ARequest			*clone() const;
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	request::Username	_from;
	request::Username	_to;
      };

      struct	HangupClient : public Call
      {
	static const char	*HANG_UP;

	HangupClient();
	HangupClient(const request::Username &from,
		     const request::Username &to);
	~HangupClient();
	HangupClient(const HangupClient &);
	HangupClient	&operator=(const HangupClient &);

	ARequest			*clone() const;
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	request::Username	_from;
	request::Username	_to;
      };


    } // !client

    namespace	server
    {


    } // !server
  } // !call


} // !request


#endif /* CALLREQUEST_H_ */
