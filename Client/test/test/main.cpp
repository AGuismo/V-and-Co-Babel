#include "Application.hh"
#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
  IApplication *w = new Application(argc, argv);

  w->init();
  w->run();
  w->stop();
}
