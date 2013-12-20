#include "Graphic.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Graphic w;
	w.show();
	return a.exec();
}
