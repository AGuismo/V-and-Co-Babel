#include "Application.hh"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
  Application app(argc, argv);

  app.init();
  app.run();
  app.stop();
}
