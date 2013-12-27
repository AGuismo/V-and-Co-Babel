#include  <QApplication>
#include  <QtWidgets>
#include  <QObject>
#include  "audio.h"
#include  "FakeMenu.h"
#include  "QTBridge.h"

int main(int argc, char *argv[])
{
  if (argc != 4)
    {
      qDebug() << argv[0] << ": [ip] [UDPServerPort] [UDPClientPort]";
      return (0);
    }

  QApplication  a(argc, argv);
  Bridge        bridge;
  Audio         audioLayer(bridge);
  FakeMenu      menu(bridge, argv[1], QString(argv[2]).toInt(), QString(argv[3]).toInt());
  QThread       _th1;

  audioLayer.moveToThread(&_th1);
  // audio
  //QObject::connect(&bridge, SIGNAL(outputReadReady()), &audioLayer, SLOT(handleOutputRead()));
  QObject::connect(&_th1, SIGNAL(started()), &audioLayer, SLOT(run()));

  _th1.start();
  menu.show();
  return a.exec();
}
