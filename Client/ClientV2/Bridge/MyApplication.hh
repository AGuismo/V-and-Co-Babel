#ifndef MYAPPLICATION_HH
#define MYAPPLICATION_HH

#include  <QObject>
#include  "audio.h"
#include  "FakeMenu.h"
#include  "QTBridge.h"

class MyApplication
{
public:
  MyApplication(int argc, char *argv[]);
  void  run();

private:
  Bridge	_bridge;
  Audio		_audioStarter;
  FakeMenu	_menu;
};

#endif // MYAPPLICATION_HH
