#include	<boost/asio.hpp>
#include	<boost/bind.hpp>
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
  _acceptor.bind(endpoint);
  _acceptor.listen();
  start_accept();
}

void	Server::run()
{
  _service.run();
}

void	Server::handle_request(Client::Pointer from, const ARequest *req)
{

}

void	Server::handle_accept(Client::Pointer new_connection,
			      const boost::system::error_code& error)
{
#if defined(DEBUG)
  std::cout << "New client: " << new_connection << std::endl;
#endif
  if (!error)
    new_connection->start();
  start_accept();
}

void	Server::handleClientClose(Client::Pointer clientClosed)
{
  _clientList.remove(clientClosed);
}

void Server::start_accept()
{
  Client::Pointer	new_connection = Client::create(_acceptor.get_io_service(), this);

  _acceptor.async_accept(new_connection->socket(),
			 boost::bind(&Server::handle_accept, this, new_connection,
				     boost::asio::placeholders::error));
  _clientList.push_back(new_connection->share());
}
