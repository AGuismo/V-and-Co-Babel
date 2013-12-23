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
  typedef Function<void (const ARequest &)>  response_handler;
  typedef std::stack<response_handler>  stack_response_handler;

public:
  Application(int ac, char *av[]);
  ~Application();

private:
  void  triggerTryConnect(const std::string &ip, unsigned short int port);
  void  triggerTryLogin(const request::Username &, const request::PasswordType &);
  void  triggerAvailableData(const ANetwork::ByteArray);
  void  triggerUdpError(enum ANetwork::SocketState);

private:
  void  bufferise(const ANetwork::ByteArray &);
  bool  handle_request();
  void  send_request(const ARequest &);

private:
  void  connection_response(const ARequest &);
  void  login_response(const ARequest &);

public:
  void  init();
  void  run();
  void  stop();

private:
  int           _ac;
  QApplication  _app;
  Graphic       _graphic;
  TCPNetwork    _tcpNetwork;
  UDPNetwork    _udpNetwork;
  Protocol::serialized_data _buffer;
  stack_response_handler    _waitedResponses;
};

#endif // APPLICATION_HH
