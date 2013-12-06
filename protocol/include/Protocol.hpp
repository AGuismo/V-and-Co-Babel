#ifndef		PROTOCOL_H_
# define	PROTOCOL_H_

# include	<string>
# include	<deque>
# include	<vector>
# include	"ARequest.hh"
# include	"types.hh"
# include	"RequestCode.hh"
# include	"Serializer.hpp"

class Protocol : public Serializer
{
public:
  class ConstructRequest : public std::exception
  {
  public:
    virtual const char	*what() const throw();
    ConstructRequest(const std::string &) throw();
    ConstructRequest(const ConstructRequest &) throw();
    virtual ~ConstructRequest() throw();

  public:
    ConstructRequest& operator=(ConstructRequest const&) throw();

  private:
    std::string		_what;
  };

public:
  Protocol();
  virtual ~Protocol();

public:
  static ARequest			*consume(std::vector<Serializer::Byte> &, int &);
  static std::vector<Serializer::Byte>	product(const ARequest &);

public:
  Protocol(const Serializer &);

private:
  Protocol(Protocol const&);
  Protocol& operator=(Protocol const&);
};

#endif /* PROTOCOL_H_ */
