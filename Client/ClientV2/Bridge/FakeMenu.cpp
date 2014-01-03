#include	<limits>
#include	<sstream>
#include	<iomanip>
#include	"FakeMenu.h"
#include	"ui_FakeMenu.h"

FakeMenu::FakeMenu(Bridge &bridge) :
  _bridge(bridge),
  _ui(new Ui::FakeMenu)
{
  _ui->setupUi(this);
  connect(_ui->Connect, SIGNAL(clicked()), this, SLOT(clicConnect()));
  connect(_ui->Disconnect, SIGNAL(clicked()), this, SLOT(clicDisconnect()));
}

void		FakeMenu::clicConnect()
{
  QMutexLocker	_locker(&_sockLocker);

  _sock = new QUdpSocket;
  connect(_sock, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()), Qt::QueuedConnection);
  connect(&_bridge, SIGNAL(inputReadReady()), this, SLOT(handleInputRead()), Qt::QueuedConnection);
  if (!_sock->bind(QHostAddress::Any, _ui->ServerPort->text().toInt()))
    {
      _ui->Display_2->setPlainText("Unable to create server");
      return ;
    }
  _clientIP = _ui->ClientIP->text();
  _clientPort = _ui->ClientPort->text().toInt();
  _ui->Display_2->setPlainText("Server Started");
  _ui->Disconnect->setEnabled(true);
  _ui->Connect->setEnabled(false);
  emit (serverStart());
}

QString	FakeMenu::clientIP() const
{
  return (_clientIP);
}

quint16	FakeMenu::clientPort() const
{
  return (_clientPort);
}

void		FakeMenu::clicDisconnect()
{
  QMutexLocker	_locker(&_sockLocker);

  _sock->disconnect();
  disconnect(&_bridge, SIGNAL(inputReadReady()), this, SLOT(handleInputRead()));
  _sock->close();
  delete _sock;
  _sock = 0;
  _ui->Disconnect->setEnabled(false);
  _ui->Connect->setEnabled(true);
  _ui->Display_2->setPlainText("Server Stopped");
  emit (serverStop());
}

FakeMenu::~FakeMenu()
{
  delete _ui;
}

void		FakeMenu::readPendingDatagrams()
{
  QHostAddress	sender;
  quint16	senderPort;
  QMutexLocker	_locker(&_sockLocker);

  if (_sock->hasPendingDatagrams())
    {
		QByteArray	datagram;

		datagram.resize(_sock->pendingDatagramSize());
		_sock->readDatagram(datagram.data(), datagram.size(),
				  &sender, &senderPort);
      qDebug() << QThread::currentThreadId() << "Read " << datagram.size() << "octets";
      handleOutputWrite(datagram);
    }
}

void				FakeMenu::handleOutputWrite(const QByteArray &bytes)
{
  AudioBridge::input_buffer	buff;
  std::ostringstream		ss;
  std::size_t			i = 0;

  for (QByteArray::const_iterator it = bytes.begin(); it != bytes.end(); ++it)
    {
      if (i != 0 && i % 4 == 0)
        ss << " ";
      if (i != 0 && i % 36 == 0)
        ss << std::endl;
      ss << std::hex << std::fixed << std::setprecision(2) << (unsigned int)(*it);
      ++i;
    }
  _ui->Display->setPlainText(QString(ss.str().c_str()));
  buff.assign(bytes.data(), bytes.data() + bytes.size());
  _bridge.outputWrite(buff);
}

void				FakeMenu::handleInputRead()
{
  AudioBridge::input_buffer	buff;
  QByteArray			bytes;
  QMutexLocker			_locker(&_sockLocker);

  qDebug() << QThread::currentThreadId() << "HandleInputRead";
  if (!_sock)
    return ;
  _bridge.inputRead(buff, std::numeric_limits<std::size_t>::max(), false);
  for (AudioBridge::input_buffer::const_iterator it = buff.begin(); it != buff.end(); ++it)
    bytes += *it;
  qDebug() << QThread::currentThreadId() << "Write " << bytes.size() << "octets";
  _sock->writeDatagram(bytes, QHostAddress(_clientIP), _clientPort);
}
