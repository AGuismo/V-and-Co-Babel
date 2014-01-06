#include	"UDPNetwork.h"
#include	"QTBridge.h"
#include	"Env.hh"
#include	<QtNetwork>
#include	<QMutexLocker>
#include	<QMutex>

UDPNetwork::UDPNetwork():
	_sock(0)
{
}

UDPNetwork::~UDPNetwork()
{

}

bool	UDPNetwork::init()
{
	QMutexLocker	_locker(&_lock);

	_sock = new QUdpSocket;
	if (!_sock->bind())
	{
		_onErrorHandler(ANetwork::ERRUNKNOWN);
		qDebug("Failed to start UDP Server");
		return (false);
	}
	if (connect(_sock, SIGNAL(readyRead()), this, SLOT(handleOutputRead()), Qt::QueuedConnection))
		qDebug("Connection Success");
	Env::getInstance().callInfo.userPortUDP = localPort();
	Env::getInstance().callInfo.userAddressIp = 0;
	qDebug() << "Client Port:" << Env::getInstance().callInfo.userPortUDP;
	return (true);
}

void  UDPNetwork::tryConnect(unsigned short port, const std::string &ipAddress)
{
	QMutexLocker	_locker(&_lock);

	_receiverIP.setAddress(ipAddress.c_str());
	_receiverPort = port;
	_sock->connectToHost(_receiverIP, _receiverPort);
	qDebug() << "tryConnect():" << "Friend Port:" << port << _receiverIP.toString();
}

void  UDPNetwork::tryConnect(unsigned short port, int ipAddress)
{
	QMutexLocker	_locker(&_lock);

	_receiverIP.setAddress(ipAddress);
	_receiverPort = port;
	qDebug() << "tryConnect():" << "Friend Port:" << port << _receiverIP.toString();
}

unsigned short  UDPNetwork::localPort() const
{
  return (_sock->localPort());
}

void  UDPNetwork::sendData(const ANetwork::ByteArray &bytes)
{
	QMutexLocker	_locker(&_lock);

	if (_sock == 0)
		return ;
	qDebug() << "UDPNetwork::sendData():" << "Port:" << _receiverPort << ", IP:" << _receiverIP.toString() << ", PacketSize:" << bytes.size();
	_sock->writeDatagram(QByteArray(reinterpret_cast<const char *>(bytes.data()), bytes.size()), _receiverIP, _receiverPort);
}

void  UDPNetwork::closeConnection()
{
	QMutexLocker	_locker(&_lock);

	if (_sock == 0)
		return ;
	_sock->disconnect();
	_sock->close();
}

bool	UDPNetwork::reset()
{
	QMutexLocker	_locker(&_lock);

	delete _sock;
	_sock = 0;
	return (true);
}

void  UDPNetwork::start()
{
	run();
	emit(serverStarted());
}

void  UDPNetwork::run()
{
}

void  UDPNetwork::stop()
{
  closeConnection();
  emit(serverStopped());
}

void  UDPNetwork::handleOutputRead()
{
	QMutexLocker	_locker(&_lock);
	
	qDebug("handleOutputRead()");
	if (_sock == 0)
		return ;
	if (_sock->hasPendingDatagrams())
	{
		QByteArray		bytes;
		QHostAddress	sender;
		quint16			senderPort;

		bytes.resize(_sock->pendingDatagramSize());
		_sock->readDatagram(bytes.data(), bytes.size(), &sender, &senderPort);
		if (sender == _receiverIP && senderPort == _receiverPort)
			_onAvailableData(ByteArray(bytes.begin(), bytes.end()));
		else
			qDebug("Invalid Send: Client is not the good one");
	}
}
