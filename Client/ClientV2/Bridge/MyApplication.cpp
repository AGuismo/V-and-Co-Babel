#include "MyApplication.hh"

MyApplication::MyApplication(int argc, char *argv[]):
  _audioStarter(_bridge),
  _menu(_bridge)
{
  QObject::connect(&_menu, SIGNAL(destroyed()), &_audioStarter, SLOT(stop()));
  QObject::connect(&_menu, SIGNAL(serverStart()), &_audioStarter, SLOT(run()));
  QObject::connect(&_menu, SIGNAL(serverStop()), &_audioStarter, SLOT(stop()));
}

void  MyApplication::run()
{
  _menu.show();
}
