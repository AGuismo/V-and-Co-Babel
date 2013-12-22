#include		"Application.hh"
#include		<QApplication>
#include		"Salt.hpp"

Salt::size_type	Salt::SALT = 42;

int main(int argc, char *argv[])
{
  Application app(argc, argv);

  app.init();
  app.run();
  app.stop();
}
