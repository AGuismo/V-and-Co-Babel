#ifndef MAINTENANCECONNECTION_H_
# define MAINTENANCECONNECTION_H_

# include	<boost/asio.hpp>
# include	<boost/shared_ptr.hpp>
# include	<boost/enable_shared_from_this.hpp>
# include	<boost/array.hpp>

class MaintenanceConnection
  : public boost::enable_shared_from_this<MaintenanceConnection>
{
public:
  typedef boost::shared_ptr<MaintenanceConnection> Pointer;
  typedef unsigned char	Byte;

  static Pointer create(boost::asio::io_service& io_service);
  boost::asio::ip::tcp::socket& socket();
  void	start();

private:
  MaintenanceConnection(boost::asio::io_service& io_service);
  void		handle_write(const boost::system::error_code& error,
			     std::size_t bytes_transferred);
  void		handle_read(const boost::system::error_code& error,
			    std::size_t bytes_transferred);
  void		read_data();
  void		write_data();

  boost::asio::ip::tcp::socket	_socket;
  boost::array<Byte, 1024>	_data;
};

#endif /* MAINTENANCECONNECTION_H_ */
