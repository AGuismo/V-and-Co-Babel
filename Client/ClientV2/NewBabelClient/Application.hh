#ifndef APPLICATION_HH
#define APPLICATION_HH

# include "IApplication.hh"
# include "Graphic.h"
# include "TCPNetwork.h"
# include "UDPNetwork.h"
# include "Protocol.hpp"
# include <stack>

class Application : public IApplication
{
public:
  typedef Function<void (const ARequest &)>		response_handler;
  typedef Function<void (const ARequest &)>		callback_handler;
  typedef std::stack<response_handler>			stack_response_handler;
  typedef std::map<request::ID, callback_handler>	request_callback;

public:
  Application(int ac, char *av[]);
  ~Application();

private:
  void  triggerTryConnect(const std::string &ip, unsigned short int port);
  void  triggerTryLogin(const request::Username &, const request::PasswordType &);
  void  triggerAvailableData(const ANetwork::ByteArray);
  void  triggerUdpError(enum ANetwork::SocketState);
  void	triggerDesAuthentification();
  void	triggerTryCreateAccount(const request::Username &, const request::PasswordType &);
  void	triggerTryDeleteAccount(const request::Username &, const request::PasswordType &);
  void	triggerTryChangeAccountPassword(const request::PasswordType &, const request::PasswordType &);
  void	triggerTryChangeAccountPrivacy(const request::Privacy &);

  // Work needed here
  void	triggerStatusHandler(const request::Status &);
  void	triggerStatusTxtHandler(const request::Message &);

  void	triggerAddFriendHandler(const request::Username &);
  void	triggerDelFriendHandler(const request::Username &);

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
  void	del_friend_response(const ARequest &);
  void	call_response(const ARequest &);
  void	hang_up_response(const ARequest &);
  void	set_answer_response(const ARequest &);
  void	unset_answer_response(const ARequest &);
  void	ignore_response(const ARequest &);
  // End of work needed here


private:
  void	ping_handler(const ARequest &);
  void	update_friend_handler(const ARequest &);

public:
  void  init();
  void  run();
  void  stop();

private:
  int						_ac;
  QApplication				_app;
  Graphic					_graphic;
  TCPNetwork				_tcpNetwork;
  UDPNetwork				_udpNetwork;
  Protocol::serialized_data	_buffer;
  stack_response_handler	_waitedResponses;
  request_callback			_requestActions;
};

#endif // APPLICATION_HH
