#ifndef SERVERREQUEST_H_
# define SERVERREQUEST_H_

# include	"RequestCode.hh"
# include	"ARequest.hh"

class	Protocol;

namespace	request
{
  class	Server : public ARequest
  {

  protected:
    Server(const request::ID);
    ~Server();

    Server(Server const&);
    Server& operator=(Server const&);

  public:
    Protocol			&serialize(Protocol &) const;
    Protocol			&unserialize(Protocol &);
    virtual ARequest		*clone() = 0;

  };

  namespace	server
  {
    struct Ok : public Server
    {
      static const char	*OK;

      Ok(): Server(server::OK) {}
      ARequest	*clone() { return (new Ok()); }
    };

    struct BadRequest : public Server
    {
      static const char	*BAD_REQ;

      BadRequest(): Server(server::BAD_REQ) {}
      ARequest	*clone() { return (new BadRequest()); }
    };

    struct Forbidden : public Server
    {
      static const char	*FORBIDDEN;

      Forbidden(): Server(server::FORBIDDEN) {}
      ARequest	*clone() { return (new Forbidden()); }
    };

    struct NotImplemented : public Server
    {
      static const char	*NOT_IMPLEMENTED;

      NotImplemented(): Server(server::NOT_IMPLEMENTED) {}
      ARequest	*clone() { return (new NotImplemented()); }
    };

    struct NoContent : public Server
    {
      static const char	*NO_CONTENT;

      NoContent(): Server(server::NO_CONTENT) {}
      ARequest	*clone() { return (new NoContent()); }
    };

    struct PartialContent : public Server
    {
      static const char	*PARTIAL_CONTENT;

      PartialContent(): Server(server::PARTIAL_CONTENT) {}
      ARequest	*clone() { return (new PartialContent()); }
    };

    struct NoSlots : public Server
    {
      static const char	*NO_SLOTS;

      NoSlots(): Server(server::NO_SLOTS) {}
      ARequest	*clone() { return (new NoSlots()); }
    };
  }
}

#endif /* SERVERREQUEST_H_ */
