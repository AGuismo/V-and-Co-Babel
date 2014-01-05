#include "UDPNetwork.h"
#include  <QtNetwork>

UDPNetwork::UDPNetwork()
{
  connect(&_sock, SIGNAL(readyRead()), this, SLOT(handleRead()));
}

UDPNetwork::~UDPNetwork()
{

}

void  UDPNetwork::tryConnect(unsigned short port, const std::string &ipAddress)
{
  _receiverIP.setAddress(ipAddress.c_str());
  _receiverPort = port;
  _sock.connectToHost(_receiverIP, _receiverPort);
}

unsigned short  UDPNetwork::localPort() const
{
  return (_sock.localPort());
}

void  UDPNetwork::sendData(const ANetwork::ByteArray &bytes)
{
  _sock.write(QByteArray(reinterpret_cast<const char *>(bytes.data()), bytes.size()));
}

void  UDPNetwork::closeConnection()
{
  _sock.close();
}

void  UDPNetwork::init()
{
}

void  UDPNetwork::run()
{
  if (!_sock.bind(QHostAddress::Any))
    _onErrorHandler(ANetwork::ERRUNKNOWN);
}

void  UDPNetwork::stop()
{
  closeConnection();
}

void  UDPNetwork::handleRead()
{
	if (_sock.hasPendingDatagrams())
	{
		QByteArray		bytes;
		QHostAddress	sender;
		quint16			senderPort;

		bytes.resize(_sock.pendingDatagramSize());
		_sock.readDatagram(bytes.data(), bytes.size(), &sender, &senderPort);
		_onAvailableData(ByteArray(bytes.begin(), bytes.end()));
	}
}
