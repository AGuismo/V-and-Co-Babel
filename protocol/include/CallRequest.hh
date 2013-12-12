#ifndef PERSOREQUEST_H_
# define PERSOREQUEST_H_

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
      virtual ARequest		*clone() = 0;
    };

    namespace	client
    {
      class	CallClient : public Call
      {
	static const char	*CALL;

	CallClient();
	CallClient(const request::Username &from,
		   const request::Username &to,
		   const request::Options &option);
	~CallClient();
	CallClient(const CallClient &);
	CallClient	&operator=(const CallClient &);

	ARequest			*clone();
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	request::Username		_from;
	request::Username		_to;
	request::Options		_option;
      };

      class	AcceptClient : public Call
      {
	static const char	*ACCEPT;

	AcceptClient();
	AcceptClient(const request::Username &from,
		     const request::Username &to);
	~AcceptClient();
	AcceptClient(const AcceptClient &);
	AcceptClient	&operator=(const AcceptClient &);

	ARequest			*clone();
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	request::Username		_from;
	request::Username		_to;
      };

      class	RefuseClient : public Call
      {
	static const char	*REFUSE;

	RefuseClient();
	RefuseClient(const request::Username &from,
		     const request::Username &to);
	~RefuseClient();
	RefuseClient(const RefuseClient &);
	RefuseClient	&operator=(const RefuseClient &);

	ARequest			*clone();
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	request::Username	_from;
	request::Username	_to;
      };

      class	HangupClient : public Call
      {
	static const char	*HANG_UP;

	HangupClient();
	HangupClient(const request::Username &from,
		     const request::Username &to);
	~HangupClient();
	HangupClient(const HangupClient &);
	HangupClient	&operator=(const HangupClient &);

	ARequest			*clone();
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