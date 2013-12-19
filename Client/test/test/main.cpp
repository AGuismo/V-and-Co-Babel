#include "application.hh"
#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
  IApplication *w = new application(argc, argv);

  w->init();
  w->run();
  w->stop();
}
