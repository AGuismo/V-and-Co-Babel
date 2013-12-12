#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowTitle("VBabel");
	/*QGridLayout		*ly = new QGridLayout;

	ly->addWidget(ui.centralWidget);

	setLayout(ly);*/
}

MainWindow::~MainWindow()
{

}
