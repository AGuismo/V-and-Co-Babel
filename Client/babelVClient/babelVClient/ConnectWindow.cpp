#include		"ConnectWindow.h"
#include		"Env.h"
#include		"MainWindow.h"

ConnectWindow::ConnectWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setModal(true);
	_poop = qobject_cast<MainWindow *>(parent);
	connect(ui.closePushButton, SIGNAL(clicked()), this, SLOT(on_close_button_clicked()));
	connect(ui.connectPushButton, SIGNAL(clicked()), this, SLOT(on_connect_button_clicked()));
}

void					ConnectWindow::on_close_button_clicked()
{
	close();
}

void					ConnectWindow::on_connect_button_clicked()
{
/*	ui.passwordLabel->text();
	ui.passwordLabel->text();
	Env::getInstance().authenticateInfo.login;
	*/

	Env::getInstance().authenticateInfo.portTCP = ui.portTcpLineEdit->text().toInt();
	Env::getInstance().authenticateInfo.addressIp = ui.ipLineEdit->text();

	 _poop->on_connection_try();

//	parent()->on_connection_try();
//	parentWidget()->on_connection_try();

	if (Env::getInstance().userInfo.connected)
	{
		ui.serverResponseLabel->setText("Success\n");
		Env::getInstance().userInfo.connected = true;
	}
	else
	{
		ui.serverResponseLabel->setText("Failure\n");
		Env::getInstance().userInfo.connected = false;
	}

}

ConnectWindow::~ConnectWindow()
{

}
