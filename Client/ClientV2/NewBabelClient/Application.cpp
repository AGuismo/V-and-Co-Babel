#include	"Application.h"
#include	"Function.hpp"
#include	"AuthRequest.hh"
#include	"PersoRequest.hh"
#include	"ChatRequest.hh"
#include	"CallRequest.hh"
#include	"FriendRequest.hh"
#include	"Protocol.hpp"
#include	"Env.hh"
#include	<QObject>
#include	<QDebug>

Application::Application(int ac, char *av[]):
  _ac(ac), _app(_ac, av), _bridge(150), _audioStarter(_bridge), _inCommunication(false)
{
  _requestActions[request::server::perso::PING] = callback_handler(&Application::ping_handler, this);
  _requestActions[request::server::friends::UPDATE] = callback_handler(&Application::update_friend_handler, this);
  _requestActions[request::client::friends::REQUEST] = callback_handler(&Application::get_friend_request_handler, this);
  _requestActions[request::server::auth::HANDSHAKE] = callback_handler(&Application::connection_response, this);
    _requestActions[request::client::chat::MESSAGE] = callback_handler(&Application::get_msg_handler, this);
	_requestActions[request::client::call::CALL] = callback_handler(&Application::get_call_request_handler, this);

	_requestActions[request::client::call::ACCEPT] = callback_handler(&Application::get_call_accept_handler, this);
	_requestActions[request::client::call::REFUSE] = callback_handler(&Application::get_call_refuse_handler, this);
	_requestActions[request::client::call::HANG_UP] = callback_handler(&Application::get_call_hang_up_handler, this);
	_requestActions[request::server::call::TIMEOUT] = callback_handler(&Application::get_call_timeout_handler, this);

	QObject::connect(&_graphic, SIGNAL(destroyed()), &_audioStarter, SLOT(stop()));
	QObject::connect(&_udpNetwork, SIGNAL(serverStarted()), &_audioStarter, SLOT(run()));
	QObject::connect(&_udpNetwork, SIGNAL(serverStopped()), &_audioStarter, SLOT(stop()));
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
	_tcpNetwork.setAboutToCloseHandler(Function<void ()>(&Application::triggerDisconnectedFromServer, this));
	_udpNetwork.setErrorHandler(Function<void (enum ANetwork::SocketState)>(&Application::triggerUdpError, this));
	_udpNetwork.setAvailableData(Function<void (const ANetwork::ByteArray)>(&Application::triggerUdpDataAvailable, this));
	_graphic.setTryConnectHandler(Function<void (unsigned short, const std::string &)>(&TCPNetwork::tryConnect, &_tcpNetwork));
	_graphic.setTryAuthentificationHandler(Function<void (const request::Username &, const request::PasswordType &)>(&Application::triggerTryLogin, this));
	_graphic.setTryCreateAccountHandler(Function<void (const request::Username &, const request::PasswordType &)>(&Application::triggerTryCreateAccount, this));
	_graphic.setTryChangeAccountPasswordHandler(Function<void (const request::PasswordType &, const request::PasswordType &)>(&Application::triggerTryChangeAccountPassword, this));
	_graphic.setTryChangeAccountPrivacyHandler(Function<void (const request::Privacy &)>(&Application::triggerTryChangeAccountPrivacy, this));
	_graphic.setTryDeleteAccountHandler(Function<void (const request::Username &, const request::PasswordType &)>(&Application::triggerTryDeleteAccount, this));
	_graphic.setDesAuthentificationHandler(Function<void ()>(&Application::triggerDesAuthentification, this));
	_graphic.setAboutToCloseHandler(Function<void ()>(&Application::triggerAboutToClose, this));

  // Here we go !
	_graphic.setStatusHandler(Function<void (const request::Status &, const request::Message &)>(&Application::triggerStatusHandler, this));	
	_graphic.setAddFriendHandler(Function<void (const request::Username &)>(&Application::triggerAddFriendHandler, this));
	_graphic.setDelFriendHandler(Function<void (const request::Username &)>(&Application::triggerDelFriendHandler, this));
	_graphic.setGetFriendHandler(Function<void (const request::Username &)>(&Application::triggerGetFriendHandler, this));
	_graphic.setChatHandler(Function<void (const request::Username &, const request::Message &)>(&Application::triggerChatHandler, this));
	_graphic.setCallHandler(Function<void (const request::Username &)>(&Application::triggerCallHandler, this));
	_graphic.setHangUpHandler(Function<void ()>(&Application::triggerHangUpHandler, this));
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

void		Application::stop_UDP()
{
	_udpNetwork.stop();
	_udpNetwork.reset();
	disconnect(&_bridge, SIGNAL(inputReadReady()), this, SLOT(handle_udp_input_read()));
}

bool		Application::init_UDP()
{
	if (!_udpNetwork.init())
		return (false);
	connect(&_bridge, SIGNAL(inputReadReady()), this, SLOT(handle_udp_input_read()), Qt::QueuedConnection);
	return (true);
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
  if (!_waitedResponses.empty() && (req->code() >= 1000 && req->code() <= 1100))
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

// Handlers

void		Application::update_friend_handler(const ARequest &req)
{
	_friendList.insertFriend(dynamic_cast<const request::friends::server::Update &>(req).username,  dynamic_cast<const request::friends::server::Update &>(req).detail, (Status)dynamic_cast<const request::friends::server::Update &>(req).status);
	_graphic.updateFriendList(_friendList.getFriendList());
	if (Env::getInstance().selectedFriend.name == dynamic_cast<const request::friends::server::Update &>(req).username)
		_graphic.receiveFriendInformation(_friendList.getFriend(dynamic_cast<const request::friends::server::Update &>(req).username));

}

void		Application::get_msg_handler(const ARequest &req)
{
	std::string			friendName(dynamic_cast<const request::chat::client::Message &>(req).from);

	_friendList.insertIncomingMsg(friendName, dynamic_cast<const request::chat::client::Message &>(req).msg);

	if (Env::getInstance().selectedFriend.name == dynamic_cast<const request::chat::client::Message &>(req).from)
	{
		_graphic.receiveFriendInformation(_friendList.getFriend(dynamic_cast<const request::chat::client::Message &>(req).from));
	}
}

void				Application::handle_udp_input_read()
{
	AudioChunk		*chunk;
	SAMPLE			*str;
	Serializer		serialize;
	Ruint8			opt;
	Ruint16			size;
	request::Time	time;

  chunk = _bridge.inputPop();
  if (chunk == 0)
	  return ;
  SET_STREAM_VER(opt, request::audio::VERSION);
  SET_STREAM_TYPE(opt, request::options::AUDIO);
  size = sizeof(opt) + sizeof(size) + sizeof(time) + chunk->size() + sizeof(Ruint16);
  time = QDateTime::currentMSecsSinceEpoch() / 1000;
  str = chunk->getContent();
  serialize << opt << size << time << (request::StreamLen)chunk->size();
  for (std::size_t it = 0; it < chunk->size(); ++it)
  {
	  serialize << str[it];
  }
  ANetwork::ByteArray			bytes(serialize.data(), serialize.data() + serialize.size());
	_udpNetwork.sendData(bytes);
	_bridge.pushUnused(chunk);
}

void		Application::get_call_request_handler(const ARequest &req)
{
	std::string			content("\"");
	std::string			name(dynamic_cast<const request::call::client::CallClient &>(req)._from);
	unsigned short int port = dynamic_cast<const request::call::client::CallClient &>(req)._port;
	int					ip = dynamic_cast<const request::call::client::CallClient &>(req)._ip;

	content += name;
	content += "\" is calling you ! Are you going to respond ?";
	Env::getInstance().callInfo.userName = Env::getInstance().userInfo.login;
	if (_graphic.request_server_response("Call incoming !", content))
	{
		Env::getInstance().callInfo.friendAddressIp = ip;
		Env::getInstance().callInfo.friendName = name;
		Env::getInstance().callInfo.friendPortUDP = port;
		_graphic.on_call_request_success();
		qDebug() << "request call accepted" << port << QHostAddress(ip).toString();
		if (!init_UDP())
			goto fail;
		send_request(request::call::client::AcceptClient(request::call::client::AcceptClient(Env::getInstance().userInfo.login, name, Env::getInstance().callInfo.userAddressIp, Env::getInstance().callInfo.userPortUDP)));
		_waitedResponses.push(response_handler(&Application::accept_response, this));
		_inCommunication = true;
	}
	else
	{
		fail:
		_graphic.on_call_request_error();
		send_request(request::call::client::RefuseClient(Env::getInstance().userInfo.login, name));
		_waitedResponses.push(response_handler(&Application::ignore_response, this));
		_inCommunication = false;
		qDebug() << "request call rejected";
	}
}

void		Application::get_call_accept_handler(const ARequest &req)
{
	const request::call::client::AcceptClient &origin = dynamic_cast<const request::call::client::AcceptClient &>(req);
	std::string			name(origin._from);
	unsigned short int	port(origin._port);
	int					ip(origin._ip);

	Env::getInstance().callInfo.friendAddressIp = ip;
	Env::getInstance().callInfo.friendName = name;
	Env::getInstance().callInfo.friendPortUDP = port;
	Env::getInstance().callInfo.userName = Env::getInstance().userInfo.login;
	_udpNetwork.tryConnect(port, ip);
	_udpNetwork.start();
	_graphic.on_call_request_success();
	_inCommunication = true;
	qDebug() << "request call accepted" << port << QHostAddress(ip).toString();
}

void	Application::get_call_timeout_handler(const ARequest &req)
{
	stop_UDP();
	_inCommunication = false;
	_graphic.on_call_request_error();
}

void		Application::get_call_refuse_handler(const ARequest &req)
{
	stop_UDP();
	_inCommunication = false;
}

void	Application::ping_handler(const ARequest &req)
{
  send_request(request::perso::client::Pong(dynamic_cast<const request::perso::server::Ping &>(req)._id));
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
		_waitedResponses.push(response_handler(&Application::ignore_response, this));
	}
	else
	{
	send_request(request::friends::client::Refuse(Env::getInstance().userInfo.login, dynamic_cast<const request::friends::client::Request &>(req).from));
	_waitedResponses.push(response_handler(&Application::ignore_response, this));
	qDebug() << "request friend rejected";
	}
}


void	Application::get_call_hang_up_handler(const ARequest &req)
{
	stop_UDP();
	_graphic.on_call_request_error();
}

// Responses

void  Application::connection_response(const ARequest &req)
{
  if (req.code() == request::server::auth::HANDSHAKE)
    {
      const request::auth::server::Handshake  &hs = dynamic_cast<const request::auth::server::Handshake &>(req);

      if (hs.version == SET_VERSION(request::version::MAJOR, request::version::MINOR))
	  {
		  send_request(hs);
		  return ;
	  }
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

void		Application::accept_response(const ARequest &resp)
{
	if (resp.code() != request::server::OK)
	{
		stop_UDP();
		_inCommunication = false;
	}
	else
	{
		_udpNetwork.tryConnect(Env::getInstance().callInfo.friendPortUDP, Env::getInstance().callInfo.friendAddressIp);
		_udpNetwork.start();
		_inCommunication = true;
	}
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

void	Application::hang_up_response(const ARequest &resp)
{
	if (resp.code() == request::server::OK)
	{
		stop_UDP();
		_inCommunication = false;
	}
}

void	Application::call_response(const ARequest &resp)
{
	if (resp.code() != request::server::OK)
	{
		stop_UDP();
		_graphic.on_call_request_error();
		_inCommunication = false;
		return ;
	}
	_inCommunication = true;
	_graphic.on_call_request_success();
}

// Triggers

void	Application::triggerDisconnectedFromServer()
{
	if (_inCommunication)
	{
		stop_UDP();
		_inCommunication = false;
	}
	_tcpNetwork.closeConnection();
	_graphic.disconnected();
}

void	Application::triggerDelFriendHandler(const request::Username &friendName)
{
	send_request(request::friends::client::DelFriend(friendName));
	_waitedResponses.push(response_handler(&Application::ignore_response, this));
}

void	Application::triggerGetFriendHandler(const request::Username &friendName)
{
	_graphic.receiveFriendInformation(_friendList.getFriend(friendName));
}

void	Application::triggerAboutToClose()
{
	if (_inCommunication)
	{
		send_request(request::call::client::HangupClient());
		stop_UDP();
	}
}

void	Application::triggerChatHandler(const request::Username &friendName, const request::Message &msg)
{
	qDebug() << "msg : " << msg.c_str();
	send_request(request::chat::client::Message(Env::getInstance().userInfo.login, friendName, 45, msg));
	
	_friendList.insertOutcomingMsg(friendName, msg);
	qDebug() << "msg : " << msg.c_str();
	_graphic.receiveFriendInformation(_friendList.getFriend(friendName));

	_waitedResponses.push(response_handler(&Application::ignore_response, this));
}

void					Application::triggerUdpDataAvailable(const ANetwork::ByteArray bytes)
{
	Serializer			serialize;
	Ruint8				opt;
	request::StreamLen	streamLen;			
	Ruint16				Totalsize;
	request::Time		time;

	for (std::size_t it = 0; it < bytes.size(); ++it)
		serialize << bytes[it];
	serialize >> opt >> Totalsize >> time >> streamLen;
	if (GET_STREAM_VER(opt) != request::audio::VERSION || Totalsize != bytes.size())
	{
		qDebug() << "Don't match" << GET_STREAM_VER(opt) << Totalsize;
		return ;
	}
	if ((QDateTime::currentMSecsSinceEpoch() / 1000) - time > 2)
	{
		qDebug() << "Timeout" << time << (QDateTime::currentMSecsSinceEpoch() / 1000);
		return ;
	}
	{
		AudioChunk		*chunk = _bridge.popUnused();

		chunk->assign(reinterpret_cast<const SAMPLE *>(serialize.data()), (streamLen / sizeof(SAMPLE)));
		_bridge.outputPush(chunk);
	}
}

void	Application::triggerStatusHandler(const request::Status &newStatus, const request::Message &msgStatus)
{
	send_request(request::perso::client::StatusClient(newStatus, msgStatus));
	_waitedResponses.push(response_handler(&Application::ignore_response, this));
	//à virer !!!!!
/*	_friendList.insertFriend("toto1", "feeff", ABSENT);
	_friendList.insertFriend("toto2", "pas top", CONNECTED);
	_friendList.insertFriend("toto3", "gdfg", INVISIBLE);
	_friendList.insertFriend("toto44", "gdfg4255", OCCUPIED);
	_friendList.insertFriend("totoaze1", "feeff", ABSENT);
	_friendList.insertFriend("tofefto2", "pas top", CONNECTED);
	_friendList.insertFriend("totefafo3", "gdfg", INVISIBLE);
	_friendList.insertFriend("tazezfoto44", "gdfg4255", OCCUPIED);
	_friendList.insertFriend("tobrbrbto1", "feeff", ABSENT);
	_friendList.insertFriend("togzergto2", "pas top", CONNECTED);
	_friendList.insertFriend("tosbdfsbdto3", "gdfg", INVISIBLE);
	_friendList.insertFriend("towcvcxto44", "gdfg4255", OCCUPIED);
	_friendList.insertFriend("totqfgro1", "feeff", ABSENT);
	_friendList.insertFriend("totbnztikruo2", "pas top", CONNECTED);
	_friendList.insertFriend("totruitio3", "gdfg", INVISIBLE);
	_friendList.insertFriend("totheto44", "gdfg4255", OCCUPIED);*/

	_graphic.updateFriendList(_friendList.getFriendList());
}

void	Application::triggerAddFriendHandler(const request::Username &newFriend)
{
	send_request(request::friends::client::Request(Env::getInstance().userInfo.login, newFriend));
	_waitedResponses.push(response_handler(&Application::add_friend_response, this));
}

void	Application::triggerCallHandler(const request::Username &friendName)
{
	if (_inCommunication)
		return ;
	if (!init_UDP())
		_graphic.on_call_request_error();
	else
	{
		_inCommunication = true;
		send_request(request::call::client::CallClient(Env::getInstance().userInfo.login, friendName, request::options::AUDIO, Env::getInstance().callInfo.userAddressIp, Env::getInstance().callInfo.userPortUDP));
		_waitedResponses.push(response_handler(&Application::call_response, this));
	}
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

void	Application::triggerHangUpHandler()
{
	if (_inCommunication)
	{
		send_request(request::call::client::HangupClient(Env::getInstance().userInfo.login, Env::getInstance().callInfo.friendName));
		stop_UDP();
		_inCommunication = false;
	}
}

void  Application::triggerUdpError(ANetwork::SocketState st)
{

}

void  Application::triggerTryConnect(const std::string &ip, unsigned short port)
{
  _tcpNetwork.tryConnect(port, ip);
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

void  Application::triggerAvailableData(const ANetwork::ByteArray data)
{
  bufferise(data);
  while (_buffer.size() && handle_request());
}

