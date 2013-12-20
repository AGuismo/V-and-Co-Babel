#include		"ConnectWindow.h"
#include		"Graphic.h"

ConnectWindow::ConnectWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setModal(true);
	connect(ui.closePushButton, SIGNAL(clicked()), this, SLOT(on_close_button_clicked()));
	connect(ui.connectPushButton, SIGNAL(clicked()), this, SLOT(on_connect_button_clicked()));
}

void					ConnectWindow::on_close_button_clicked()
{
	close();
}

void					ConnectWindow::on_connect_button_clicked()
{
	emit(connect_try(ui.ipLineEdit->text().toStdString(), ui.portTcpLineEdit->text().toInt()));
}