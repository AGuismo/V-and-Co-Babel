#include	<limits>
#include	<sstream>
#include	<iomanip>
#include	"FakeMenu.h"
#include	"ui_FakeMenu.h"
#include	"OpAudioCodec.hh"
#include	"AudioParams.hh"

FakeMenu::FakeMenu(Bridge &bridge) :
  _bridge(bridge),
  _ui(new Ui::FakeMenu)
{
	_codec = new OpAudioCodec();
	_codec->init();
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

  while (_sock->hasPendingDatagrams())
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
	SAMPLE					decoded[SOUNDBUFF_SIZE];
	AudioChunk				*chunk = _bridge.popUnused();
	unsigned int			numFrames;
	std::ostringstream		ss;

	memset(decoded, 0, SOUNDBUFF_SIZE);
	chunk->clean();
//	chunk->assign(reinterpret_cast<const SAMPLE *>(bytes.data()), (bytes.size() / sizeof(SAMPLE)));
	numFrames = _codec->decode(reinterpret_cast<const unsigned char *>(bytes.data()), bytes.size(), decoded, MAX_FRAME_SIZE);
	chunk->assign(decoded, (numFrames * NUM_CHANNELS));
	_bridge.outputPush(chunk);
}

void				FakeMenu::handleInputRead()
{
  AudioChunk		*chunk;
  unsigned char		str[MAX_PACKET_SIZE];
  int				numBytes;
  QMutexLocker		_locker(&_sockLocker);

  qDebug() << QThread::currentThreadId() << "HandleInputRead";
  if (!_sock)
    return ;
  chunk = _bridge.inputPop();

  memset(str, 0, MAX_PACKET_SIZE);
  numBytes = _codec->encode(chunk->getContent(), FRAMES_PER_BUFFER, str, MAX_PACKET_SIZE);

  QByteArray			bytes(reinterpret_cast<char *>(str), numBytes);
//  QByteArray			bytes(reinterpret_cast<char *>(chunk->getContent()), (chunk->size() * sizeof(SAMPLE)));
  qDebug() << QThread::currentThreadId() << "Write " << bytes.size() << "octets";
  _sock->writeDatagram(bytes, QHostAddress(_clientIP), _clientPort);
  _bridge.pushUnused(chunk);
}
