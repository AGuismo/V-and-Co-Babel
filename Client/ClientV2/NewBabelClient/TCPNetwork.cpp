#include  "TCPNetwork.h"
#include  <QtNetwork>


TCPNetwork::TCPNetwork()
{

}

bool  TCPNetwork::init()
{
  QObject::connect(&_sock, SIGNAL(readyRead()), this, SLOT(onRead()));
  QObject::connect(&_sock, SIGNAL(disconnected()), this, SLOT(on_disconnect()));
  return (true);
}

void  TCPNetwork::run()
{

}

void	TCPNetwork::translateError()
{
  switch (_sock.error())
    {
    case QAbstractSocket::ConnectionRefusedError:
      _onErrorHandler(ANetwork::ERRCONNREFUSED);
      break;
    case QAbstractSocket::SocketTimeoutError:
      _onErrorHandler(ANetwork::ERRTIMEDOUT);
      break;
    default:
      _onErrorHandler(ANetwork::ERRUNKNOWN);
      break;
    }
}

void	TCPNetwork::on_disconnect()
{
	_aboutToCloseHandler();
}

void  TCPNetwork::closeConnection()
{
  _sock.close();
}

void  TCPNetwork::sendData(const ANetwork::ByteArray &data)
{
  _sock.write(QByteArray(reinterpret_cast<const char *>(data.data()), data.size()));
}

void  TCPNetwork::tryConnect(unsigned short port, const std::string &ipAddress)
{
  _sock.connectToHost(QString(ipAddress.c_str()), port);
  if (_sock.waitForConnected(1000))
    _onConnectHandler();
  else
    translateError();
}

void  TCPNetwork::onRead()
{
  QByteArray  bytes = _sock.readAll();

  _onAvailableData(ANetwork::ByteArray(bytes.data(), bytes.data() + bytes.size()));
}
