#ifndef APPLICATION_HH
#define APPLICATION_HH

# include "IApplication.hh"
# include "Graphic.h"
# include "TCPNetwork.hh"

class Application : public IApplication
{
public:
  Application(int ac, char *av[]);
  ~Application();

private:
  void  triggerTryConnect(const std::string &ip, unsigned short int port);

public:
  void  init();
  void  run();
  void  stop();

private:
  int           _ac;
  QApplication  _app;
  Graphic       _graphic;
  TCPNetwork    _tcpNetwork;
};

#endif // APPLICATION_HH
