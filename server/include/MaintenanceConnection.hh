#ifndef MAINTENANCECONNECTION_H_
# define MAINTENANCECONNECTION_H_

# include	<boost/asio.hpp>
# include	<boost/shared_ptr.hpp>
# include	<boost/enable_shared_from_this.hpp>
# include	<boost/array.hpp>

class	Administrator;

class MaintenanceConnection
  : public boost::enable_shared_from_this<MaintenanceConnection>
{
public:
  typedef boost::shared_ptr<MaintenanceConnection>	Pointer;
  typedef unsigned char								Byte;
  typedef std::string								buffer;
  static const unsigned int							BUFF_SIZE = 1024;

  static Pointer create(boost::asio::io_service& io_service, Administrator &);
  boost::asio::ip::tcp::socket& socket();
  void	start();

private:
	MaintenanceConnection(boost::asio::io_service& io_service, Administrator &);
  void		handle_write(const boost::system::error_code& error,
			     std::size_t bytes_transferred);
  void		handle_read(const boost::system::error_code& error,
			    std::size_t bytes_transferred);
  bool		handle_request();
  void		read_data();
  void		write_data(const buffer &);

  boost::asio::ip::tcp::socket	_socket;
  boost::array<Byte, BUFF_SIZE>		_inputdata;
  boost::array<Byte, BUFF_SIZE>		_outputdata;
  buffer						_input;
  buffer						_output;
  Administrator					&_administrator;
};

#endif /* MAINTENANCECONNECTION_H_ */
