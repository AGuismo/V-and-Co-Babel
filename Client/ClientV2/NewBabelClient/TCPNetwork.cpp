#include  "TCPNetwork.hh"
#include  <QtNetwork>

TCPNetwork::TCPNetwork()
{

}

TCPNetwork::~TCPNetwork()
{

}

void  TCPNetwork::init()
{
  QObject::connect(&_sock, SIGNAL(readyRead()), this, SLOT(onRead()));
}

void  TCPNetwork::run()
{

}

void  TCPNetwork::tryConnect(unsigned short port, const std::string &ipAddress)
{
  qDebug() << ipAddress.c_str() << ":" << port;
  _sock.connectToHost(QString(ipAddress.c_str()), port);
  if (_sock.waitForConnected())
    _onConnectHandler();
  else
    _onErrorHandler((int)_sock.error());
}

void  TCPNetwork::onRead()
{
  QByteArray  bytes = _sock.readAll();

  _onAvailableData(std::string(bytes.data(), bytes.size()));
}
