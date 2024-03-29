#ifndef AUTHREQUEST_H_
# define AUTHREQUEST_H_

# include	"ARequest.hh"

namespace	request
{

  namespace	auth
  {
    class Auth : public ARequest
    {
    protected:
      Auth(const request::ID id);
      virtual ~Auth();
      Auth(Auth const&);
      Auth& operator=(Auth const&);

    public:
      virtual Protocol		&serialize(Protocol &) const;
      virtual Protocol		&unserialize(Protocol &);
      virtual ARequest		*clone() const = 0;
    };

    namespace	client
    {
      struct	NewClient : public Auth
      {
	static const char	*NEW;

	NewClient();
	NewClient(const request::Username &name,
		  const request::PasswordType &password,
		  const request::Privacy privacy);
	~NewClient();
	NewClient(const NewClient &);
	NewClient	&operator=(const NewClient &);

	ARequest			*clone() const;
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	request::Username	_name;
	request::PasswordType	_password;
	request::Privacy	_privacy;
      };

      struct	DelClient : public Auth
      {
	static const char	*REMOVE;

	DelClient();
	DelClient(const request::Username &name,
		  const request::PasswordType &password);
	~DelClient();
	DelClient(const DelClient &);
	DelClient	&operator=(const DelClient &);

	ARequest			*clone() const;
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	request::Username	_name;
	request::PasswordType	_password;
      };

      struct	ModifyClient : public Auth
      {
	static const char	*MODIFY;

	ModifyClient();
	ModifyClient(const request::Username &name,
		     const request::PasswordType &oldPassword,
		     const request::PasswordType &newPassword);
	~ModifyClient();
	ModifyClient(const ModifyClient &);
	ModifyClient	&operator=(const ModifyClient &);

	ARequest			*clone() const;
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	request::Username	_name;
	request::PasswordType	_oldPassword;
	request::PasswordType	_newPassword;
      };

      struct	ConnectClient : public Auth
      {
	static const char	*CONNECT;

	ConnectClient();
	ConnectClient(const request::Username &name,
		      const request::PasswordType &password);
	~ConnectClient();
	ConnectClient(const ConnectClient &);
	ConnectClient	&operator=(const ConnectClient &);

	ARequest			*clone() const;
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	request::Username	_name;
	request::PasswordType	_password;
      };

      struct	DisconnectClient : public Auth
      {
	static const char	*DISCONNECT;

	DisconnectClient();
	~DisconnectClient();
	DisconnectClient(const DisconnectClient &);
	DisconnectClient	&operator=(const DisconnectClient &src);

	ARequest			*clone() const;
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);

      };
    } // !client

    namespace	server
    {
      struct	Handshake : public Auth
      {
	static const char	*HANDSHAKE;

	Handshake();
	Handshake(const request::Version);
	~Handshake();
	Handshake(const Handshake &);
	Handshake	&operator=(const Handshake &src);

	ARequest			*clone() const;
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	request::Version	version;
      };

    } // !server
  } // !auth
} // !request


#endif /* AUTHREQUEST_H_ */
