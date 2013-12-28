#include  <QApplication>
#include  <QtWidgets>
#include  "MyApplication.hh"


int main(int argc, char *argv[])
{
  QApplication  a(argc, argv);
  MyApplication app(argc, argv);

  // audio
  //QObject::connect(&bridge, SIGNAL(outputReadReady()), &audioLayer, SLOT(handleOutputRead()));

  app.run();
  a.exec();
}
