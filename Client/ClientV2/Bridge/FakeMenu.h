#ifndef FAKEMENU_H
#define FAKEMENU_H

#include	<QMainWindow>
#include	<QUdpSocket>
#include	"QTBridge.h"
#include	"IAudioCodec.hh"

namespace Ui {
  class FakeMenu;
}

class FakeMenu : public QMainWindow
{
  Q_OBJECT

public:
  explicit FakeMenu(Bridge &bridge);
  ~FakeMenu();
  const Ui::FakeMenu *ui() const {return (_ui);}
  QString	clientIP() const;
  quint16	clientPort() const;

private slots:
  void  handleInputRead();
  void  handleOutputWrite(const QByteArray &bytes);
  void  readPendingDatagrams();
  void	clicConnect();
  void	clicDisconnect();

signals:
  void	serverStop();
  void	serverStart();

private:
  Bridge        &_bridge;
  Ui::FakeMenu	*_ui;
  quint16       _serverPort;
  QString       _clientIP;
  quint16       _clientPort;
  QUdpSocket	*_sock;
  QMutex		_sockLocker;
  IAudioCodec	*_codec;
};

#endif // FAKEMENU_H
