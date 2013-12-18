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
  class ConstructRequest : public Serializer::invalid_argument
  {
  public:
    virtual const char	*what() const throw();
    ConstructRequest(const std::string &) throw();
    ConstructRequest(const ConstructRequest &) throw();
    virtual ~ConstructRequest() throw();

  public:
    ConstructRequest& operator=(ConstructRequest const&) throw();
  };
public:
  typedef Serializer::Byte	Byte;
  typedef std::vector<Byte>	serialized_data;

public:
  Protocol();
  virtual ~Protocol();

public:
  static ARequest		*consume(const serialized_data &, int &);
  static serialized_data	product(const ARequest &);

public:
  Protocol(const Serializer &);

private:
  Protocol(Protocol const&);
  Protocol& operator=(Protocol const&);
};

#endif /* PROTOCOL_H_ */
