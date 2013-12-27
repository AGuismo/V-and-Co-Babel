#ifndef FAKEMENU_H
#define FAKEMENU_H

#include <QMainWindow>
#include  <QUdpSocket>
#include  "QTBridge.h"

namespace Ui {
  class FakeMenu;
}

class FakeMenu : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit FakeMenu(Bridge &bridge, const QString &, int, int);
  ~FakeMenu();
  const Ui::FakeMenu *ui() const {return (_ui);}

private slots:
  void  handleInputRead();
  void  handleOutputWrite(const QByteArray &bytes);
  void  handleClicked();
  void  readPendingDatagrams();

private:
  Bridge        &_bridge;
  Ui::FakeMenu *_ui;
  quint16       _serverPort;
  QString       _clientIP;
  quint16       _clientPort;
  QUdpSocket   _sock;
};

#endif // FAKEMENU_H
