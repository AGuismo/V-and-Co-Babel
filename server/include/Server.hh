#ifndef SERVER_H_
# define SERVER_H_

# include	<list>
# include	<string>
# include	"Client.hh"

namespace boost
{
  namespace asio
  {
    class io_service;
  }
}
class	ARequest;
class	Database;
namespace	request
{
  class	PluginManager;
  class	PluginCaller;
}

class Server
{
public:
  typedef std::list<IClient::Pointer>	client_list;
  typedef void (*request_handler)(const client_list &, IClient::Pointer, const ARequest *);

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
  Server(boost::asio::io_service &service, Database &);
  ~Server();

public:
  void			init();
  void			handleClientClose(IClient::Pointer clientClosed);
  void			handle_request(IClient::Pointer from, const ARequest *);
  const client_list	&getClients() const;

private:
  void	start_accept();
  void	handle_accept(IClient::Pointer, const boost::system::error_code &error);

private:
  Server(Server const&);
  Server& operator=(Server const&);

private:
  boost::asio::io_service		&_service;
  boost::asio::ip::tcp::acceptor	_acceptor;
  client_list				_clientList;
  request::PluginManager		*_plugs;
  request::PluginCaller			*_calls;
};

#endif /* SERVER_H_ */
