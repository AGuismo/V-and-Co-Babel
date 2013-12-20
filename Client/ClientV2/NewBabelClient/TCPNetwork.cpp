#include  "TCPNetwork.hh"
#include  <QDebug>

TCPNetwork::TCPNetwork()
{

}

TCPNetwork::~TCPNetwork()
{

}

void  TCPNetwork::init()
{

}

void  TCPNetwork::run()
{

}

void  TCPNetwork::tryConnect(unsigned short port, const std::string &ipAddress)
{
  qDebug() << ipAddress.c_str() << ":" << port;
  _sock.connectToHost(QString(ipAddress.c_str()), port);
  if (_sock.waitForConnected(300))
    _onConnectHandler();
  else
    _onErrorHandler((int)_sock.error());
}
