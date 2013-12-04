#ifndef		__FRIENDREQUEST_HH__
# define	__FRIENDREQUEST_HH__

namespace	request
{
  class Friend
  {
  protected:
    Friend();
    virtual ~Friend();
    Friend(Friend const&);
    Friend& operator=(Friend const&);

  public:
    Protocol			&serialize(Protocol &) const;
    Protocol			&unserialize(Protocol &);
    virtual ARequest		*clone() = 0;
  };

  namespace	client
  {
  }

  namespace	server
  {
    struct Update : public Server
    {
      static const char	*UPDATE;

      Update(): Friend(server::friends::UPDATE) {}
      ARequest	*clone() { return (new Update()); }
      virtual bool	operator==(const ARequest *req)
      {
	return (ARequest::operator==(req) && );
      }


    };

  }
}
#endif	/* !__FRIENDREQUEST_HH__ */
