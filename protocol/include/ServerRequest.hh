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
    virtual ARequest		*clone() const = 0;

  };

  namespace	server
  {
    struct Ok : public Server
    {
      static const char	*OK;

      Ok(): Server(server::OK) {}
      ARequest	*clone() const { return (new Ok(*this)); }
    };

    struct BadRequest : public Server
    {
      static const char	*BAD_REQ;

      BadRequest(): Server(server::BAD_REQ) {}
      ARequest	*clone() const { return (new BadRequest(*this)); }
    };

    struct Forbidden : public Server
    {
      static const char	*FORBIDDEN;

      Forbidden(): Server(server::FORBIDDEN) {}
      ARequest	*clone() const { return (new Forbidden(*this)); }
    };

    struct NotImplemented : public Server
    {
      static const char	*NOT_IMPLEMENTED;

      NotImplemented(): Server(server::NOT_IMPLEMENTED) {}
      ARequest	*clone() const { return (new NotImplemented(*this)); }
    };

    struct NoContent : public Server
    {
      static const char	*NO_CONTENT;

      NoContent(): Server(server::NO_CONTENT) {}
      ARequest	*clone() const { return (new NoContent(*this)); }
    };

    struct PartialContent : public Server
    {
      static const char	*PARTIAL_CONTENT;

      PartialContent(): Server(server::PARTIAL_CONTENT) {}
      ARequest	*clone() const { return (new PartialContent(*this)); }
    };

    struct NoSlots : public Server
    {
      static const char	*NO_SLOTS;

      NoSlots(): Server(server::NO_SLOTS) {}
      ARequest	*clone() const { return (new NoSlots(*this)); }
    };
  }
}

#endif /* SERVERREQUEST_H_ */
