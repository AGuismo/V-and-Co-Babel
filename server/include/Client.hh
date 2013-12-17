#ifndef CLIENT_H_
# define CLIENT_H_

# include	<boost/asio.hpp>
# include	<boost/bind.hpp>
# include	<boost/shared_ptr.hpp>
# include	<vector>
# include	"Protocol.hpp"
# include	"IClient.hh"

using	boost::asio::ip::tcp;
class	Server;

class Client : public IClient
{
public:
	static const int					DEFAULT_SIZE = 1024;
	typedef boost::shared_ptr<Client>	Pointer;

private:
	Client(boost::asio::io_service &service, Server *);

public:
	static IClient::Pointer create(boost::asio::io_service& io_service, Server *);
	virtual		~Client();
	void		async_read();

private:
	bool		unserialize_data(IClient::buffer &buff);
	void		handle_request(const ARequest *req);
	void		handle_write(const boost::system::error_code& error,
							std::size_t bytes_transferred);
	void		handle_read(const boost::system::error_code& error,
							std::size_t bytes_transferred);

public:
	bool		serialize_data(const ARequest &req);
	void		start();
	void		async_write(const IClient::buffer &);

	const request::Username	&Username() const { return (InfosClient._name); };
	void					Username(const request::Username &uname) { InfosClient._name = uname; };
	bool					Authenticated() const { return (InfosClient._isConnect); };
	void					Authenticated(bool auth) { InfosClient._isConnect = auth; };
	request::Privacy		privacy() const { return (InfosClient._privacy); };
	void					privacy(request::Privacy privacy) { InfosClient._privacy = privacy; };
	request::Status			status() const { return (InfosClient._status); };
	void					status(request::Status status) { InfosClient._status = status; };
	request::IP				IP() const { return (_socket.remote_endpoint().address().to_v4().to_ulong()); };

	tcp::socket	&socket();
	IClient::Pointer	share();

private:
	Client(Client const&);
	Client& operator=(Client const&);

private:
	boost::asio::io_service	&_service;
	buffer			_input;
	buffer			_bufferised;
	buffer			_output;
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
