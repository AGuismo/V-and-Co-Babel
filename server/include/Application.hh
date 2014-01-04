#ifndef APPLICATION_H_
# define APPLICATION_H_

# include	<exception>
# include	<string>
# include	<boost/asio.hpp>
# include	"Server.hh"
# include	"Database.hh"
# include	"Maintenance.hh"
# include	"Administrator.hh"

class Application
{
  static const char	*confFile;
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
  void	init(const char *confPath = 0);
  void	run();
  void	shutdown();

private:
  const std::string	shutdownServer();
  const std::string	dropDB();
  const std::string	saveDB();
  const std::string	dumpDB();
  void			autosaveDB(const boost::system::error_code &e);

private:
  Application(Application const&);
  Application& operator=(Application const&);

private:
  boost::asio::io_service	_service;
  boost::asio::deadline_timer	_autosaveDB;
  Server			_server;
  Database			_database;
  Administrator			_adm;
  Maintenance			_maintenance;
};


#endif /* APPLICATION_H_ */
