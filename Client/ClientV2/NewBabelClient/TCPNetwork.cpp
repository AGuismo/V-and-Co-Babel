#include  "TCPNetwork.h"
#include  <QtNetwork>

TCPNetwork::TCPNetwork()
{

}

void  TCPNetwork::init()
{
  QObject::connect(&_sock, SIGNAL(readyRead()), this, SLOT(onRead()));
}

void  TCPNetwork::run()
{

}

void	TCPNetwork::translateError()
{
  switch (_sock.error())
    {
    case QAbstractSocket::ConnectionRefusedError:
      _onErrorHandler(ANetwork::ECONNREFUSED);
      break;
    case QAbstractSocket::SocketTimeoutError:
      _onErrorHandler(ANetwork::ETIMEDOUT);
      break;
    default:
      _onErrorHandler(ANetwork::EUNKNOWN);
      break;
    }
}

void  TCPNetwork::tryConnect(unsigned short port, const std::string &ipAddress)
{
  qDebug() << ipAddress.c_str() << ":" << port;
  _sock.connectToHost(QString(ipAddress.c_str()), port);
  if (_sock.waitForConnected(300))
    _onConnectHandler();
  else
    translateError();
}

void  TCPNetwork::onRead()
{
  QByteArray  bytes = _sock.readAll();

  _onAvailableData(std::string(bytes.data(), bytes.size()));
}
