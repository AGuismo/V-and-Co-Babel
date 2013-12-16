#include "servertester.h"
#include <QApplication>

#include "Salt.hpp"
Salt::size_type Salt::SALT = 42;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ServerTester w;
    w.show();

    return a.exec();
}
