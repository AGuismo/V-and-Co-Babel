#ifndef CLIENT_H_
# define CLIENT_H_

# include	<boost/asio.hpp>
# include	<boost/bind.hpp>
# include	<boost/shared_ptr.hpp>
# include	<boost/enable_shared_from_this.hpp>

using	boost::asio::ip::tcp;
class	Server;

class Client : public boost::enable_shared_from_this<Client>
{
public:
  typedef boost::shared_ptr<Client> Pointer;

public:
  static Pointer create(boost::asio::io_service& io_service, Server *);
  Client(boost::asio::io_service &service, Server *);
  virtual ~Client();

private:
  void		handle_write(const boost::system::error_code& error,
			     std::size_t bytes_transferred);
  void		handle_read(const boost::system::error_code& error,
			    std::size_t bytes_transferred);

public:
  void		start();
  void		Send();
  void		Receive();
  tcp::socket	&socket();
  Pointer	share();

private:
  Client(Client const&);
  Client& operator=(Client const&);

private:
  boost::asio::io_service	&_service;
  boost::array<char, 1024>	_received;
  tcp::socket			_socket;
  Server			*_server;
};

#endif /* CLIENT_H_ */
