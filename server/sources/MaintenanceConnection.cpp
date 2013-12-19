#define		_SCL_SECURE_NO_WARNINGS
#include	<boost/bind.hpp>
#include	<boost/algorithm/string/split.hpp>
#include	<boost/algorithm/string/classification.hpp>
#include	"MaintenanceConnection.hh"
#include	"Administrator.hh"

MaintenanceConnection::MaintenanceConnection(boost::asio::io_service& io_service, Administrator &adm) :
  _socket(io_service), _administrator(adm)
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
  std::cout << "MaintenanceConnection::handle_read(): " << _input.size() << std::endl;
  _input.insert(_input.end(), _inputdata.begin(), _inputdata.begin() + bytes_transferred);
  std::cout << "MaintenanceConnection::handle_read(): " << _input.size() << std::endl;
  while (handle_request());
  read_data();
}

bool	MaintenanceConnection::handle_request()
{
  buffer::iterator	it = std::find(_input.begin(), _input.end(), '\n');
  buffer				request;
  std::vector<buffer>	argv;
  buffer				resp;

  if (it == _input.end())
    return (false);
  request.assign(_input.begin(), it);
  _input.erase(_input.begin(), it + 1);
  boost::split(argv, request, boost::is_any_of(" \t"), boost::token_compress_on);
  _administrator(argv, resp);
  write_data(resp);
  return (true);
}

void	MaintenanceConnection::read_data()
{
  _socket.async_read_some(boost::asio::buffer(_inputdata),
			  boost::bind(&MaintenanceConnection::handle_read, shared_from_this(),
				      boost::asio::placeholders::error,
				      boost::asio::placeholders::bytes_transferred));
}

void	MaintenanceConnection::write_data(const buffer &buff)
{
  std::size_t	size;

  size = (buff.size() > BUFF_SIZE ? BUFF_SIZE : buff.size());
  std::copy(buff.begin(),
	    buff.begin() + size,
	    _outputdata.begin());
  boost::asio::async_write(_socket, boost::asio::buffer(_outputdata, size),
			   boost::bind(&MaintenanceConnection::handle_write, shared_from_this(),
				       boost::asio::placeholders::error,
				       boost::asio::placeholders::bytes_transferred));
}

void	MaintenanceConnection::start()
{
  const buffer	message("V and co Babel mainteance interface\n");

  write_data(message);
  read_data();
}

boost::asio::ip::tcp::socket	&MaintenanceConnection::socket()
{
  return (_socket);
}

MaintenanceConnection::Pointer	MaintenanceConnection::create(boost::asio::io_service &io_service, Administrator &adm)
{
  return (Pointer(new MaintenanceConnection(io_service, adm)));
}
