#include	<boost/asio.hpp>
#include	"Server.hh"

Server::Server(boost::asio::io_service &service) :
  _service(service), _acceptor(service)
{

}

Server::~Server()
{

}

// Env::network::Port

void	Server::init()
{
  boost::asio::ip::tcp::endpoint	endpoint(boost::asio::ip::tcp::v4(), 44201);

  _acceptor.open(endpoint.protocol());
  _acceptor.bind(endpoint());
  _acceptor.listen();
}

void	Server::run()
{
}
