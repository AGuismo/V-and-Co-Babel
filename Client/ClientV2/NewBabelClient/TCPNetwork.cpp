#include  "TCPNetwork.h"
#include  <QtNetwork>

TCPNetwork::TCPNetwork()
{

}

bool  TCPNetwork::init()
{
  QObject::connect(&_sock, SIGNAL(readyRead()), this, SLOT(onRead()));
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

void	TCPNetwork::stateChanged(QAbstractSocket::SocketState st)
{
	switch (st)
	{
	case QAbstractSocket::ClosingState:
		_aboutToCloseHandler();
		break;
	}
}

void  TCPNetwork::closeConnection()
{
  _sock.close();
  QObject::connect(&_sock, SIGNAL(stateChanged(SocketState)), this, SLOT(stateChanged(SocketState)));
}

void  TCPNetwork::sendData(const ANetwork::ByteArray &data)
{
  _sock.write(QByteArray(reinterpret_cast<const char *>(data.data()), data.size()));
}

void  TCPNetwork::tryConnect(unsigned short port, const std::string &ipAddress)
{
  qDebug() << ipAddress.c_str() << ":" << port;
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
