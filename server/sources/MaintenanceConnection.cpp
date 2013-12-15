#include	<boost/bind.hpp>
#include	"MaintenanceConnection.hh"

MaintenanceConnection::MaintenanceConnection(boost::asio::io_service& io_service):
  _socket(io_service)
{

}

void	MaintenanceConnection::handle_write(const boost::system::error_code& error,
					    std::size_t bytes_transferred)
{
  (void)bytes_transferred;
  if (error)
    {
      _socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
      _socket.close();
      return ;
    }
  read_data();
}

void	MaintenanceConnection::handle_read(const boost::system::error_code& error,
					   std::size_t bytes_transferred)
{
  if (error)
    {
      _socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
      _socket.close();
      return ;
    }
  read_data();
}

void	MaintenanceConnection::read_data()
{
  _socket.async_read_some(boost::asio::buffer(_data),
			  boost::bind(&MaintenanceConnection::handle_read, shared_from_this(),
				      boost::asio::placeholders::error,
				      boost::asio::placeholders::bytes_transferred));
}

void	MaintenanceConnection::write_data()
{
  const std::string	message("Just a message");

  boost::asio::async_write(_socket, boost::asio::buffer(message),
			   boost::bind(&MaintenanceConnection::handle_write, shared_from_this(),
				       boost::asio::placeholders::error,
				       boost::asio::placeholders::bytes_transferred));
}

void	MaintenanceConnection::start()
{
  const std::string	message("V and co Babel mainteance interface");

  boost::asio::async_write(_socket, boost::asio::buffer(message),
			   boost::bind(&MaintenanceConnection::handle_write, shared_from_this(),
				       boost::asio::placeholders::error,
				       boost::asio::placeholders::bytes_transferred));
}

boost::asio::ip::tcp::socket	&MaintenanceConnection::socket()
{
  return (_socket);
}

MaintenanceConnection::Pointer	MaintenanceConnection::create(boost::asio::io_service &io_service)
{
  return (Pointer(new MaintenanceConnection(io_service)));
}
