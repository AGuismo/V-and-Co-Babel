#ifndef APPLICATION_HH
#define APPLICATION_HH

# include	<QObject>
# include	<stack>
# include	"IApplication.hh"
# include	"Graphic.h"
# include	"TCPNetwork.h"
# include	"UDPNetwork.h"
# include	"Protocol.hpp"
# include	"FriendList.hh"
# include	"audio.h"
# include	"QTBridge.h"
# include	"IAudioCodec.hh"

class Application : public QObject, public IApplication
{
	Q_OBJECT
public:
  typedef Function<void (const ARequest &)>		response_handler;
  typedef Function<void (const ARequest &)>		callback_handler;
  typedef std::stack<response_handler>			stack_response_handler;
  typedef std::map<request::ID, callback_handler>	request_callback;

private:
	FriendList			_friendList;

public:
  Application(int ac, char *av[]);
  ~Application();

private:
  void  triggerTryConnect(const std::string &ip, unsigned short int port);
  void  triggerTryLogin(const request::Username &, const request::PasswordType &);
  void  triggerAvailableData(const ANetwork::ByteArray);
  void  triggerUdpError(enum ANetwork::SocketState);
  void	triggerUdpDataAvailable(const ANetwork::ByteArray);
  void	triggerDesAuthentification();
  void	triggerTryCreateAccount(const request::Username &, const request::PasswordType &);
  void	triggerTryDeleteAccount(const request::Username &, const request::PasswordType &);
  void	triggerTryChangeAccountPassword(const request::PasswordType &, const request::PasswordType &);
  void	triggerTryChangeAccountPrivacy(const request::Privacy &);
  void	triggerAboutToClose();
  void	triggerDisconnectedFromServer();

  // Work needed here
  void	triggerStatusHandler(const request::Status &, const request::Message &);

  void	triggerAddFriendHandler(const request::Username &);
  void	triggerDelFriendHandler(const request::Username &);
  void	triggerGetFriendHandler(const request::Username &);

  void	triggerCallHandler(const request::Username &);
  void	triggerHangUpHandler();
  void	triggerChatHandler(const request::Username &, const request::Message &);
  void	triggerSetAnswerHandler();
  void	triggerUnSetAnswerHandler();
  // End of need work here :p

private:
  void  bufferise(const ANetwork::ByteArray &);
  bool  handle_request();
  void  send_request(const ARequest &);

private:
  void  connection_response(const ARequest &);
  void  desauthentification_response(const ARequest &);
  void  login_response(const ARequest &);
  void  create_account_response(const ARequest &);
  void  delete_account_response(const ARequest &);
  void  change_account_password_response(const ARequest &);
  void  change_account_privacy_response(const ARequest &);

  // Work needed here
  void	add_friend_response(const ARequest &);		
  void	call_response(const ARequest &);
  void	accept_response(const ARequest &);
  void	hang_up_response(const ARequest &);
  void	set_answer_response(const ARequest &);
  void	unset_answer_response(const ARequest &);
  void	ignore_response(const ARequest &);
  // End of work needed here


private:
  void	ping_handler(const ARequest &);
  void	update_friend_handler(const ARequest &);
  void	get_friend_request_handler(const ARequest &);
  void	get_msg_handler(const ARequest &);
  void	get_call_request_handler(const ARequest &);

  void  get_call_accept_handler(const ARequest &);
  void  get_call_refuse_handler(const ARequest &);
  void	get_call_hang_up_handler(const ARequest &);
  void	get_call_timeout_handler(const ARequest &);

private:
	bool	init_UDP();
	void	stop_UDP();

private slots:
	void	handle_udp_input_read();

public:
  void  init();
  void  run();
  void  stop();

private:
  int						_ac;
  QApplication				_app;
  Graphic					_graphic;
  Bridge					_bridge;
  TCPNetwork				_tcpNetwork;
  UDPNetwork				_udpNetwork;
  Audio						_audioStarter;
  Protocol::serialized_data	_buffer;
  stack_response_handler	_waitedResponses;
  request_callback			_requestActions;
  bool						_inCommunication;
  IAudioCodec				*_codec;
};

#endif // APPLICATION_HH
