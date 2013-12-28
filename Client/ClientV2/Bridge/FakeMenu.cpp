#include "FakeMenu.h"
#include "ui_FakeMenu.h"
#include  <limits>

FakeMenu::FakeMenu(Bridge &bridge) :
  _bridge(bridge),
  _ui(new Ui::FakeMenu)
{
  _ui->setupUi(this);
//  _sock.bind(QHostAddress::Any, serverPort);
  connect(&_sock, SIGNAL(readyRead()),
               this, SLOT(readPendingDatagrams()));
  QObject::connect(&bridge, SIGNAL(inputReadReady()), this, SLOT(handleInputRead()));
//  QObject::connect(_ui->outputWrite, SIGNAL(clicked()), this, SLOT(handleClicked()));
  connect(_ui->Connect, SIGNAL(clicked()), this, SLOT(clicConnect()));
  connect(_ui->Disconnect, SIGNAL(clicked()), this, SLOT(clicDisconnect()));
}

void	FakeMenu::clicConnect()
{
	if (!_sock.bind(QHostAddress::Any, _ui->ServerPort->text().toInt()))
	{
		_ui->Display_2->setPlainText("Unable to create server");
		return ;
	}
	_clientIP = _ui->ClientIP->text();
	_clientPort = _ui->ClientPort->text().toInt();
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

void	FakeMenu::clicDisconnect()
{
	_sock.close();
	emit (serverStop());
}

FakeMenu::~FakeMenu()
{
  delete _ui;
}

void  FakeMenu::readPendingDatagrams()
{
  while (_sock.hasPendingDatagrams())
    {
          QByteArray datagram;
          QHostAddress sender;
          quint16 senderPort;

          datagram.resize(_sock.pendingDatagramSize());
          _sock.readDatagram(datagram.data(), datagram.size(),
                                  &sender, &senderPort);
          qDebug() << "Read " << datagram.size() << "octets";
          handleOutputWrite(datagram);
      }
}

void  FakeMenu::handleOutputWrite(const QByteArray &bytes)
{
  AudioBridge::input_buffer buff;
  QString                   str;
  std::size_t               i = 0;

  for (QByteArray::const_iterator it = bytes.begin(); it != bytes.end(); ++it)
    {
      if (i != 0 && i % 4 == 0)
        str += " ";
      if (i != 0 && i % 16 == 0)
        str += '\n';
      str += *it;
      ++i;
    }
  _ui->Display->setPlainText(str);

  buff.assign(bytes.data(), bytes.data() + bytes.size());
  _bridge.outputWrite(buff);
}

void  FakeMenu::handleInputRead()
{
  AudioBridge::input_buffer buff;
  QByteArray                bytes;

  _bridge.inputRead(buff, std::numeric_limits<std::size_t>::max());
  for (AudioBridge::input_buffer::const_iterator it = buff.begin(); it != buff.end(); ++it)
    bytes += *it;
  qDebug() << "Write " << bytes.size() << "octets";
  _sock.writeDatagram(bytes, QHostAddress(_clientIP), _clientPort);
}
