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
      virtual ARequest		*clone() = 0;
    };

    namespace	client
    {
      class	NewClient : public Auth
      {
	static const char	*NEW;

	NewClient();
	NewClient(const request::Username &name,
		  const request::PasswordType &password,
		  const request::Privacy privacy);
	~NewClient();
	NewClient(const NewClient &);
	NewClient	&operator=(const NewClient &);

	ARequest			*clone();
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	request::Username	_name;
	request::PasswordType	_password;
	request::Privacy	_privacy;
      };
    } // !client
  } // !auth

  namespace	server
  {

  } // !server

} // !request


#endif /* AUTHREQUEST_H_ */
