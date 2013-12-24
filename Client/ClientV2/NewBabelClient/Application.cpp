#include  "Application.hh"
#include  "Function.hpp"
#include  "AuthRequest.hh"
#include  "Protocol.hpp"

Application::Application(int ac, char *av[]):
  _ac(ac), _app(_ac, av)
{
}

Application::~Application()
{

}

void  Application::init()
{
  _tcpNetwork.init();
  _graphic.init();
  _tcpNetwork.setErrorHandler(Function<void (enum ANetwork::SocketState)>(&Graphic::on_connection_error, &_graphic));
  _tcpNetwork.setOnConnectHandler(Function<void ()>(&Graphic::on_connection_success, &_graphic));
  _tcpNetwork.setAvailableData(Function<void (const ANetwork::ByteArray)>(&Application::triggerAvailableData, this));
  _udpNetwork.setErrorHandler(Function<void (enum ANetwork::SocketState)>(&Application::triggerUdpError, this));
  _graphic.setTryConnectHandler(Function<void (unsigned short, const std::string &)>(&TCPNetwork::tryConnect, &_tcpNetwork));
  _graphic.setTryAuthentificationHandler(Function<void (const request::Username &, const request::PasswordType &)>(&Application::triggerTryLogin, this));
   _graphic.setTryCreateAccountHandler(Function<void (const request::Username &, const request::PasswordType &)>(&Application::triggerTryCreateAccount, this));
   _graphic.setDesAuthentificationHandler(Function<void ()>(&Application::triggerDesAuthentification, this));
}

void  Application::run()
{
  _tcpNetwork.run();
  _graphic.run();
  _app.exec();
}

void  Application::stop()
{

}

void  Application::triggerUdpError(ANetwork::SocketState st)
{

}

void  Application::triggerTryConnect(const std::string &ip, unsigned short port)
{
  _tcpNetwork.tryConnect(port, ip);
  _waitedResponses.push(response_handler(&Application::connection_response, this));
}

void  Application::triggerDesAuthentification()
{
	_tcpNetwork.sendData(Protocol::product(request::auth::client::DisconnectClient()));
	_waitedResponses.push(response_handler(&Application::desauthentification_response, this));
}

void  Application::connection_response(const ARequest &req)
{
  if (req.code() == request::server::auth::HANDSHAKE)
    {
      const request::auth::server::Handshake  &hs = dynamic_cast<const request::auth::server::Handshake &>(req);

      if (hs.version == SET_VERSION(request::version::MAJOR, request::version::MINOR))
        return ;
    }
  _tcpNetwork.closeConnection();
  _graphic.on_connection_error(ANetwork::ERRHANDSHAKE);
}

void  Application::login_response(const ARequest &req)
{
  if (req.code() == request::server::OK)
    {
      _graphic.on_login_success();
      return ;
    }
  _graphic.on_login_error("Login Error");
}

void  Application::create_account_response(const ARequest &req)
{
  if (req.code() == request::server::OK)
    {
      _graphic.on_create_account_success();
      return ;
    }
  _graphic.on_create_account_error("Creation Error");
}

void  Application::desauthentification_response(const ARequest &req)
{
	if (req.code() == request::server::OK)
    {
      _graphic.on_desauthentification_success();
	  qDebug() << "oh mon keke il a deco, le batard ! (des-response ok)";
      return ;
    }
    _graphic.on_desauthentification_error();
	qDebug() << "oh mon keke il a deco, le batard ! (des-response not ok)";
}

void  Application::triggerTryLogin(const request::Username &login, const request::PasswordType &password)
{
  send_request(request::auth::client::ConnectClient(login, md5(password)));
  _waitedResponses.push(response_handler(&Application::login_response, this));
}

void  Application::triggerTryCreateAccount(const request::Username &login, const request::PasswordType &password)
{
	send_request(request::auth::client::NewClient(login, md5(password), false));
	_waitedResponses.push(response_handler(&Application::create_account_response, this));
}

void  Application::bufferise(const ANetwork::ByteArray &data)
{
  qDebug() << "Data Received: " << data.size();
  _buffer.insert(_buffer.end(), data.begin(), data.end());

}

void  Application::send_request(const ARequest &req)
{
  _tcpNetwork.sendData(Protocol::product(req));
}

bool  Application::handle_request()
{
  ARequest *req;
  int      consumed;

  try
  {
    req = Protocol::consume(_buffer, consumed);
  }
  catch (const Serializer::invalid_argument &e)
  {
    qDebug() << e.what();
    return (false);
  }
  _buffer.erase(_buffer.begin(), _buffer.begin() + consumed);
  qDebug() << req->code();
  if (!_waitedResponses.empty())
    {
      response_handler  handle = _waitedResponses.top();

      handle(*req);
      _waitedResponses.pop();
    }
  delete req;
  return (true);
}

void  Application::triggerAvailableData(const ANetwork::ByteArray data)
{
  bufferise(data);
  while (_buffer.size() && handle_request());
}
