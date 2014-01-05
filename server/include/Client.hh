#ifndef CLIENT_H_
# define CLIENT_H_

# include	<boost/asio.hpp>
# include	<boost/bind.hpp>
# include	<boost/shared_ptr.hpp>
# include	<vector>
# include	<list>
# include	"Protocol.hpp"
# include	"IClient.hh"

using	boost::asio::ip::tcp;
class	Server;

class Client : public IClient
{
public:
  static const int			DEFAULT_SIZE = 1024;
  typedef boost::shared_ptr<Client>	Pointer;
  typedef std::list<ARequest *>		request_list;

private:
  Client(boost::asio::io_service &service, Server *);

public:
  static IClient::Pointer	create(boost::asio::io_service& io_service, Server *);
  virtual			~Client();
  void				async_read();

private:
  bool				unserialize_data(IClient::buffer &buff);
  void				handle_request(const ARequest *req);
  void				handle_write(const boost::system::error_code& error,
					     std::size_t bytes_transferred);
  void				handle_read(const boost::system::error_code& error,
					    std::size_t bytes_transferred);
  bool				execRequest();
  void				addRequest(const ARequest &);

private:
  void				start_ping(const boost::system::error_code &);
  void				handle_timeout_pong(const boost::system::error_code &);

public:
  void				reset_pong();
  void				close();

public:
  bool				serialize_data(const ARequest &req);
  void				start();
  void				async_write(const IClient::buffer &);

  const request::Username	&Username() const
  { return (InfosClient._name); };
  void				Username(const request::Username &uname)
  { InfosClient._name = uname; };
  const request::PasswordType	&Password() const
  { return (InfosClient._password); };
  void				Password(const request::PasswordType &password)
  { InfosClient._password = password; };
  const request::PasswordType	&OldPassword() const
  { return (InfosClient._oldPassword); };
  void				OldPassword(const request::PasswordType &oldPassword)
  { InfosClient._oldPassword = oldPassword; };
  bool				Authenticated() const
  { return (InfosClient._isConnect); };
  void				Authenticated(bool auth)
  { InfosClient._isConnect = auth; };
  bool				Communication() const
  { return (InfosClient._inCommunication); };
  void				Communication(bool comm)
  { InfosClient._inCommunication = comm; };
  request::Privacy		privacy() const
  { return (InfosClient._privacy); };
  void				privacy(request::Privacy privacy)
  { InfosClient._privacy = privacy; };
  const request::Username		&Caller()
  { return (InfosClient._caller); };
  void				Caller(const request::Username &caller)
  { InfosClient._caller = caller; };
  request::Status		status() const
  { return (InfosClient._status); };
  void				status(request::Status status)
  { InfosClient._status = status; };
  request::StatusDetail		statusDetail() const
  { return (InfosClient._statusDetail); };
  void				statusDetail(request::StatusDetail &detail)
  { InfosClient._statusDetail = detail; };
  request::IP			IP() const
  { return (_socket.remote_endpoint().address().to_v4().to_ulong()); };
  const request::Stream		&AutoAnswer() const
  { return (InfosClient._autoAnswer);};
  Protocol			&serializeAnswer()
  { return (_serializeAnswer);};
  request::PingPongID		pong() const
  { return (_currentPong); }
  void				pong(request::PingPongID id)
  { _currentPong = id; }

  tcp::socket			&socket();
  IClient::Pointer		share();

private:
  Client(Client const&);
  Client&			operator=(Client const&);

private:
  boost::asio::io_service	&_service;
  buffer			_input;
  buffer			_bufferised;
  buffer			_output;
  tcp::socket			_socket;
  Server			*_server;
  Protocol			_serializeAnswer;
  boost::asio::deadline_timer	_pongTimer;
  request::PingPongID		_currentPong;
  request_list			_waitedRequest;

public:
  struct
  {
    bool			_isConnect;
    bool			_inCommunication;
    request::Username  		_name;
    request::PasswordType	_password;
    request::PasswordType	_oldPassword;
    request::Privacy		_privacy;
    request::Status		_status;
    request::StatusDetail	_statusDetail;
    request::Stream		_autoAnswer;
    request::Username		_caller;
  }				InfosClient;
};
#endif /* CLIENT_H_ */
