#ifndef AREQUEST_H_
# define AREQUEST_H_

# include	<string>
# include	<exception>
# include	"types.hh"
# include	"RequestCode.hh"
# include	"ITransformers.hh"

class ARequest : public ITransformers
{
public:
  class Exception : public std::exception
  {
  public:
    virtual const char	*what() const throw();
    Exception(const std::string &) throw();
    Exception(const Exception &) throw();
    virtual ~Exception() throw();

  public:
    Exception& operator=(Exception const&) throw();

  private:
    std::string		_what;
  };

public:
  ARequest(const request::ID);
  virtual ~ARequest();

public:
  request::ID		code() const;
  void			code(const request::ID);

public:
  ARequest(ARequest const&);
  ARequest& operator=(ARequest const&);

public:
  virtual ARequest	*clone() = 0;
  virtual Protocol	&serialize(Protocol &) const = 0;
  virtual Protocol	&unserialize(Protocol &) = 0;
  virtual bool		operator==(const ARequest *req) const;
  virtual bool		operator!=(const ARequest *req) const;

protected:
  request::ID		_code;
};

#endif /* AREQUEST_H_ */
