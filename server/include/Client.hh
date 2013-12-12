#ifndef CLIENT_H_
# define CLIENT_H_

# include	<boost/asio.hpp>
# include	<boost/bind.hpp>
# include	<boost/shared_ptr.hpp>
# include	<boost/enable_shared_from_this.hpp>
# include	<vector>
# include	"Protocol.hpp"

using	boost::asio::ip::tcp;
class	Server;

class Client : public boost::enable_shared_from_this<Client>
{
public:
  static const int					DEFAULT_SIZE = 1024;
  typedef boost::shared_ptr<Client>			Pointer;
  typedef Protocol::serialized_data			buffer;

public:
  static Pointer create(boost::asio::io_service& io_service, Server *);
  Client(boost::asio::io_service &service, Server *);
  virtual ~Client();

private:
  bool		unserialize_data(buffer &buff);
  void		handle_request(const ARequest *req);
  void		handle_write(const boost::system::error_code& error,
			     std::size_t bytes_transferred);
  void		handle_read(const boost::system::error_code& error,
			    std::size_t bytes_transferred);

public:
  bool		serialize_data(const ARequest &req);
  void		start();
  void		async_read();
  template <typename BUFF>
  void		async_write(const BUFF &buff);
  tcp::socket	&socket();
  Pointer	share();

private:
  Client(Client const&);
  Client& operator=(Client const&);

private:
  boost::asio::io_service	&_service;
  buffer			_input;
  buffer			_bufferised;
  tcp::socket			_socket;
  Server			*_server;

public:
  struct
  {
    bool			_isConnect;
    std::string			_name;
    request::Privacy		_privacy;
    request::Status		_status;
  }				InfosClient;
};

#endif /* CLIENT_H_ */
