#include	<boost/asio.hpp>
#include	<boost/bind.hpp>
#include	"Maintenance.hh"
#include	"Env.hh"
#include	"Administrator.hh"

Maintenance::Maintenance(boost::asio::io_service &service, Administrator &adm) :
_service(service), _acceptor(service), _adm(adm)
{

}

Maintenance::~Maintenance()
{

}

void	Maintenance::init()
{
  _acceptor.open(boost::asio::ip::tcp::v4());
  _acceptor.bind(boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"),
						Env::getInstance().server.MaintenancePort));
  _acceptor.listen();
  start_accept();
}

void	Maintenance::handle_accept(MaintenanceConnection::Pointer new_connection,
				   const boost::system::error_code& error)
{
  if (!error)
    {
      new_connection->start();
    }
  start_accept();
}

void	Maintenance::start_accept()
{
  MaintenanceConnection::Pointer new_connection = MaintenanceConnection::create(_acceptor.get_io_service(), _adm);

  _acceptor.async_accept(new_connection->socket(),
			 boost::bind(&Maintenance::handle_accept, this, new_connection,
				     boost::asio::placeholders::error));
}

///////////////////////
//  Exception Class  //
///////////////////////

Maintenance::Exception::Exception(const std::string &what) throw() :
  _what(what)
{

}

Maintenance::Exception::Exception(const Exception &src) throw() :
  _what(src._what)
{

}

Maintenance::Exception::~Exception() throw()
{
}

Maintenance::Exception	&Maintenance::Exception::operator=(const Maintenance::Exception &src) throw()
{
  if (&src != this)
    {
      _what = src._what;
    }
  return (*this);
}

const char	*Maintenance::Exception::what() const throw()
{
  return (_what.c_str());
}
