#include	"Application.hh"
#include	"Function.hpp"
#include	"AuthRequest.hh"
#include	"PersoRequest.hh"
#include	"FriendRequest.hh"
#include	"Protocol.hpp"
#include	"Env.hh"

#include	<QDebug>

Application::Application(int ac, char *av[]):
  _ac(ac), _app(_ac, av)
{
  _requestActions[request::server::perso::PING] = callback_handler(&Application::ping_handler, this);
  _requestActions[request::server::friends::UPDATE] = callback_handler(&Application::update_friend_handler, this);
//  request::friends::client::Accept(from, to);
  _requestActions[request::client::friends::REQUEST] = callback_handler(&Application::get_friend_request_handler, this);
//  request::friends::client::Request
}

void		Application::update_friend_handler(const ARequest &)
{
	qDebug() << "update friend received MOTHERFUCKER";
}

void		Application::get_friend_request_handler(const ARequest &req)
{
	qDebug() << "request friend received";

	std::string content("\"");
	content += dynamic_cast<const request::friends::client::Request &>(req).from;
	content += "\" just asked you to be his friend.";
	if (_graphic.request_server_response("Friend request", content))
	{
		qDebug() << "request friend accepted";
		send_request(request::friends::client::Accept(Env::getInstance().userInfo.login, dynamic_cast<const request::friends::client::Request &>(req).from));
//				send_request(request::friends::client::Accept(dynamic_cast<const request::friends::client::Request &>(req).from, Env::getInstance().userInfo.login));

	}
	else
	{
	send_request(request::friends::client::Refuse(Env::getInstance().userInfo.login, dynamic_cast<const request::friends::client::Request &>(req).from));
		qDebug() << "request friend rejected";
	}
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
  _graphic.setTryChangeAccountPasswordHandler(Function<void (const request::PasswordType &, const request::PasswordType &)>(&Application::triggerTryChangeAccountPassword, this));
  _graphic.setTryChangeAccountPrivacyHandler(Function<void (const request::Privacy &)>(&Application::triggerTryChangeAccountPrivacy, this));
  _graphic.setTryDeleteAccountHandler(Function<void (const request::Username &, const request::PasswordType &)>(&Application::triggerTryDeleteAccount, this));
  _graphic.setDesAuthentificationHandler(Function<void ()>(&Application::triggerDesAuthentification, this));

  // Here we go !
  _graphic.setStatusHandler(Function<void (const request::Status &, const request::Message &)>(&Application::triggerStatusHandler, this));	
  _graphic.setAddFriendHandler(Function<void (const request::Username &)>(&Application::triggerAddFriendHandler, this));
  _graphic.setDelFriendHandler(Function<void (const request::Username &)>(&Application::triggerDelFriendHandler, this));
}


void	Application::triggerStatusHandler(const request::Status &newStatus, const request::Message &msgStatus)
{
	get_friend_request_handler(request::friends::client::Request(Env::getInstance().userInfo.login, "shit"));
//	send_request(request::perso::client::StatusClient(newStatus));
//	_waitedResponses.push(response_handler(&Application::ignore_response, this));
}

void	Application::triggerAddFriendHandler(const request::Username &newFriend)
{
	send_request(request::friends::client::Request(Env::getInstance().userInfo.login, newFriend));
	_waitedResponses.push(response_handler(&Application::add_friend_response, this));
}

void  Application::add_friend_response(const ARequest &req)
{
  if (req.code() == request::server::OK)
    {
      _graphic.on_add_friend_success();
      return ;
    }
	_graphic.on_add_friend_error("User do not exist");
}

void	Application::triggerDelFriendHandler(const request::Username &)
{
//	send_request(request:);
	_waitedResponses.push(response_handler(&Application::del_friend_response, this));
}

void  Application::del_friend_response(const ARequest &req)
{
	(void)req;
}




/*void	Application::triggerHandler(const request: &)
{
	send_request(request:);
	_waitedResponses.push(response_handler(&Application::ignore_response, this));
}

void  Application::_response(const ARequest &req)
{
  if (req.code() == request::server::OK)
    {
//      _graphic
      return ;
    }
//  _graphic
}*/










void  Application::triggerUdpError(ANetwork::SocketState st)
{

}

void  Application::triggerTryConnect(const std::string &ip, unsigned short port)
{
  _tcpNetwork.tryConnect(port, ip);
  _waitedResponses.push(response_handler(&Application::connection_response, this));
}


void	Application::triggerTryChangeAccountPassword(const request::PasswordType &currentPassword, const request::PasswordType &newPassword)
{
	send_request(request::auth::client::ModifyClient(Env::getInstance().userInfo.loginTry, md5(currentPassword), md5(newPassword)));
	_waitedResponses.push(response_handler(&Application::change_account_password_response, this));
}

void	Application::triggerTryChangeAccountPrivacy(const request::Privacy &newPrivacy)
{
	send_request(request::perso::client::ModifyPrivacy(newPrivacy));
	_waitedResponses.push(response_handler(&Application::change_account_privacy_response, this));
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


void  Application::change_account_password_response(const ARequest &req)
{
	qDebug() << "return change : " << req.code();
  if (req.code() == request::server::OK)
    {
      _graphic.on_change_account_password_success();
      return ;
    }
  _graphic.on_change_account_password_error("Error, password unchanged");
}


void  Application::change_account_privacy_response(const ARequest &req)
{
  if (req.code() == request::server::OK)
    {
      _graphic.on_change_account_privacy_success();
      return ;
    }
  _graphic.on_change_account_privacy_error("Error, privacy settings unchanged");
}


void  Application::delete_account_response(const ARequest &req)
{
  if (req.code() == request::server::OK)
    {
      _graphic.on_delete_account_success();
      return ;
    }
  _graphic.on_delete_account_error("Deletion Error");
}

void  Application::desauthentification_response(const ARequest &req)
{
  if (req.code() == request::server::OK)
    {
      _graphic.on_desauthentification_success();
      qDebug() << "(des-response ok)";
      return ;
    }
  _graphic.on_desauthentification_error();
  qDebug() << "(des-response not ok)";
}

void  Application::ignore_response(const ARequest & req)
{
	(void)req;
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

void  Application::triggerTryDeleteAccount(const request::Username &login, const request::PasswordType &password)
{
  send_request(request::auth::client::DelClient(login, md5(password)));
  _waitedResponses.push(response_handler(&Application::delete_account_response, this));
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
  if (!_waitedResponses.empty() && (req->code() >= 1000 && req->code() < 1100))
    {
      response_handler  handle = _waitedResponses.top();

      handle(*req);
      _waitedResponses.pop();
    }
  else
    {
      request_callback::iterator	it = _requestActions.find(req->code());

      if (it != _requestActions.end())
	it->second(*req);
    }
  delete req;
  return (true);
}

void  Application::triggerAvailableData(const ANetwork::ByteArray data)
{
  bufferise(data);
  while (_buffer.size() && handle_request());
}

void	Application::ping_handler(const ARequest &req)
{
  send_request(request::perso::client::Pong(dynamic_cast<const request::perso::server::Ping &>(req)._id));
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
