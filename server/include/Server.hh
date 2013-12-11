#ifndef SERVER_H_
# define SERVER_H_

# include	<list>
# include	<string>
# include	"Client.hh"
# include	"RequestPlugin.hh"
# include	"RequestCaller.hh"

namespace boost
{
  namespace asio
  {
    class io_service;
  }
}
class	ARequest;

class Server
{
  typedef std::list<Client::Pointer>	client_list;

public:
  typedef void (*request_handler)(Server *, Client::Pointer, const ARequest *);

public:
  class Exception
  {
  public:
    Exception(const std::string &) throw();
    virtual ~Exception() throw();

  public:
    Exception(Exception const&) throw();
    Exception& operator=(Exception const&) throw();

  public:
    const char	*what() const throw();

  private:
    std::string	_what;
  };

public:
  Server(boost::asio::io_service &service);
  ~Server();

public:
  void	init();
  void	run();
  void	handleClientClose(Client::Pointer clientClosed);
  void	handle_request(Client::Pointer from, const ARequest *);

private:
  void	start_accept();
  void	handle_accept(Client::Pointer, const boost::system::error_code &error);

private:
  Server(Server const&);
  Server& operator=(Server const&);

private:
  boost::asio::io_service		&_service;
  boost::asio::ip::tcp::acceptor	_acceptor;
  client_list				_clientList;
  request::PluginManager		_plugs;
  request::PluginCaller			_calls;
};

#endif /* SERVER_H_ */
