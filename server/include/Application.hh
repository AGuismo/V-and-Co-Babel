#ifndef APPLICATION_H_
# define APPLICATION_H_

# include	<exception>
# include	<string>
# include	<boost/asio.hpp>
# include	"Server.hh"

class Application
{
public:
  class InitExcept : public std::exception
  {
  public:
    virtual const char	*what() const throw();
    InitExcept(const std::string &) throw();
    InitExcept(const InitExcept &) throw();
    virtual ~InitExcept() throw();

  public:
    InitExcept& operator=(InitExcept const&) throw();

  private:
    std::string		_what;
  };

public:
  Application();
  virtual ~Application();

public:
  void	init();
  void	run();
  void	shutdown();

private:
  Application(Application const&);
  Application& operator=(Application const&);

private:
  boost::asio::io_service	_service;
  Server			_server;
};


#endif /* APPLICATION_H_ */
