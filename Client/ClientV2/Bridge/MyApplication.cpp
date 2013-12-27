#include "MyApplication.hh"

MyApplication::MyApplication(int argc, char *argv[]):
  _audioStarter(_bridge),
  _menu(_bridge, argv[1], QString(argv[2]).toInt(), QString(argv[3]).toInt())
{
  QObject::connect(&_menu, SIGNAL(destroyed()), &_audioStarter, SLOT(deleteLater()));
}

void  MyApplication::run()
{
  _audioStarter.run();
  _menu.show();
}
