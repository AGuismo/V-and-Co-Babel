#include "servertester.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ServerTester w;
    w.show();

    return a.exec();
}
