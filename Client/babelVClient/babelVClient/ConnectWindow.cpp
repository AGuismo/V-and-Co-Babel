#include		"ConnectWindow.h"
#include		"Env.h"


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
/*	ui.passwordLabel->text();
	ui.passwordLabel->text();
	Env::getInstance().authenticateInfo.login;
	*/

	if (true)
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
