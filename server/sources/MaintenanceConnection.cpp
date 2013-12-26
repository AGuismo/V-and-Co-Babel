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

MaintenanceConnection::~MaintenanceConnection()
{
#if defined(DEBUG)
  std::cout << "MaintenanceClient " << this << " Disconnected" << std::endl;
#endif
}

void	MaintenanceConnection::handle_write(const boost::system::error_code& error,
					    std::size_t bytes_transferred)
{
  (void)bytes_transferred;
  if (error)
    {
#if defined(DEBUG)
      std::cout << "MaintenanceClient " << this << " Disconnected" << std::endl;
#endif
      return ;
    }
  read_data();
}

void	MaintenanceConnection::handle_read(const boost::system::error_code& error,
					   std::size_t bytes_transferred)
{
  if (error)
    {
      _socket.close();
#if defined(DEBUG)
      std::cout << "MaintenanceClient " << this << " Disconnected" << std::endl;
#endif
      return ;
    }
  _input.insert(_input.end(), _inputdata.begin(), _inputdata.begin() + bytes_transferred);
  while (handle_request());
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

#if defined(DEBUG)
  std::cout << "MaintenanceClient " << this << " Connected" << std::endl;
#endif
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
