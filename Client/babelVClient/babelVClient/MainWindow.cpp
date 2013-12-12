#include		"FriendList.h"
#include		"MainWindow.h"

MainWindow::MainWindow(QWidget *parent)	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowTitle("VBabel");
}

Ui::MainWindowClass			&MainWindow::getUi()
{
	return (ui);
}

MainWindow							&MainWindow::getInstance()
{
	static MainWindow				MainWindow;
//	MainWindow.getUi().setupUi(this);
//	setWindowTitle("VBabel");

	

	return (MainWindow);
}

MainWindow::~MainWindow()
{

}
