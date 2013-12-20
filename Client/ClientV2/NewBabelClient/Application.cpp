#include "Application.hh"

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
  _tcpNetwork.setErrorHandler();
  _tcpNetwork.setOnConnectHandler();
  _graphic.init();
}

void  Application::run()
{
  _tcpNetwork.run();
//  _graphic.run();
  _app.exec();
}

void  Application::stop()
{

}

void  Application::triggerTryConnect(const std::string &ip, unsigned short port)
{
  _tcpNetwork.tryConnect(port, ip);
}
