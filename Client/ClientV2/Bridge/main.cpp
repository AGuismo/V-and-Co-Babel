#include  <QApplication>
#include  <QtWidgets>
#include  "MyApplication.hh"


int main(int argc, char *argv[])
{
  if (argc != 4)
    {
      qDebug() << argv[0] << ": [ip] [UDPServerPort] [UDPClientPort]";
      return (0);
    }

  QApplication  a(argc, argv);
  MyApplication app(argc, argv);

  // audio
  //QObject::connect(&bridge, SIGNAL(outputReadReady()), &audioLayer, SLOT(handleOutputRead()));

  app.run();
  a.exec();
}
