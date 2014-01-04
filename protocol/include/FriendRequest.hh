#ifndef		__FRIENDREQUEST_HH__
# define	__FRIENDREQUEST_HH__

# include	"ARequest.hh"

namespace	request
{
  namespace	friends
  {
    class Friend : public ARequest
    {
    protected:
      Friend(const request::ID id);
      virtual ~Friend();
      Friend(Friend const&);
      Friend& operator=(Friend const&);

    public:
      virtual bool		operator==(const ARequest *req) const;
      virtual bool		operator!=(const ARequest *req) const;

    public:
      virtual Protocol		&serialize(Protocol &) const;
      virtual Protocol		&unserialize(Protocol &);
      virtual ARequest		*clone() const = 0;
    };

    namespace	client
    {
      struct Request : public Friend
      {
	static const char	*REQUEST;

	Request();
	Request(const request::Username &from, const request::Username &to);
	~Request();
	Request(const Request &);
	Request	&operator=(const Request &);

	ARequest	*clone() const;
	Protocol	&serialize(Protocol &) const;
	Protocol	&unserialize(Protocol &);

	bool		operator==(const ARequest *req) const;
	bool		operator!=(const ARequest *req) const;

	request::Username	from;
	request::Username	to;
      };

      struct DelFriend : public Friend
      {
	static const char	*DEL_FRIEND;

	DelFriend();
	DelFriend(const request::Username &to);
	~DelFriend();
	DelFriend(const DelFriend &);
	DelFriend	&operator=(const DelFriend &);

	ARequest	*clone() const;
	Protocol	&serialize(Protocol &) const;
	Protocol	&unserialize(Protocol &);

	bool		operator==(const ARequest *req) const;
	bool		operator!=(const ARequest *req) const;

	request::Username	to;
      };

      struct Accept : public Friend
      {
	static const char	*ACCEPT;

	Accept();
	Accept(const request::Username &from, const request::Username &to);
	~Accept();
	Accept(const Accept &);
	Accept			&operator=(const Accept &);

	ARequest		*clone() const;
	Protocol		&serialize(Protocol &) const;
	Protocol		&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	request::Username	from;
	request::Username	to;
      };

      struct Refuse : public Friend
      {
	static const char	*REFUSE;

	Refuse();
	Refuse(const request::Username &from, const request::Username &to);
	~Refuse();
	Refuse(const Refuse &);
	Refuse			&operator=(const Refuse &);

	ARequest		*clone() const;
	Protocol		&serialize(Protocol &) const;
	Protocol		&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	request::Username	from;
	request::Username	to;
      };

      struct List : public Friend
      {
	static const char	*LIST;

	List();
	~List();
	List(const List &);
	List			&operator=(const List &);

	ARequest		*clone() const;
      };

    } // !client

    namespace	server
    {
      struct Update : public Friend
      {
	static const char	*UPDATE;

	Update();
	Update(const request::Status, const request::StatusDetail &, const request::Username &);
	~Update();
	Update(const Update &);
	Update	&operator=(const Update &);

	ARequest		*clone() const;
	Protocol		&serialize(Protocol &) const;
	Protocol		&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	request::Status		status;
	request::StatusDetail	detail;
	request::Username	username;
      };

    } // !server
  } // !friends
} // !request
#endif	/* !__FRIENDREQUEST_HH__ */
