#ifndef SERVER_H_
# define SERVER_H_

#include	"Client.hh"

namespace boost
{
  namespace asio
  {
    class io_service;
  }
}

class Server
{
public:
  Server(boost::asio::io_service &service);
  ~Server();

public:
  void	init();
  void	run();

private:
  void	start_accept();
  void	handle_accept(Client::Pointer, const boost::system::error_code &error);

private:
  Server(Server const&);
  Server& operator=(Server const&);

private:
  boost::asio::io_service		&_service;
  boost::asio::ip::tcp::acceptor	_acceptor;
};

#endif /* SERVER_H_ */
