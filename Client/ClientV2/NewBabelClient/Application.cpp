#include  "Application.hh"
#include  "Function.hpp"

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
  _tcpNetwork.setErrorHandler(Function<void (int)>(&Graphic::on_connection_error, &_graphic));
  _tcpNetwork.setOnConnectHandler(Function<void ()>(&Graphic::on_connection_success, &_graphic));
  _tcpNetwork.setAvailableData(Function<void (const std::string)>(&Application::triggerAvailableData, this));
  _graphic.setTryConnectHandler(Function<void (unsigned short, const std::string &)>(&TCPNetwork::tryConnect, &_tcpNetwork));
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

void  Application::triggerTryConnect(const std::string &ip, unsigned short port)
{
  _tcpNetwork.tryConnect(port, ip);
}

void  Application::triggerAvailableData(const std::string data)
{
  ARequest *req;
  int      consumed;

  _buffer.insert(_buffer.end(), data.c_str(), data.c_str() + data.size());
  qDebug() << "Data Received: " << data.size();
  try
  {
    req = Protocol::consume(_buffer, consumed);
  }
  catch (const Serializer::invalid_argument &e)
  {
    qDebug() << e.what();
    return ;
  }
  _buffer.erase(_buffer.begin(), _buffer.begin() + consumed);
  qDebug() << req->code();
}
