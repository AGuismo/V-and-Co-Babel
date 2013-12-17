#include		"LoginWindow.h"
#include		"Env.h"


LoginWindow::LoginWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setModal(true);
	connect(ui.closePushButton, SIGNAL(clicked()), this, SLOT(on_close_button_clicked()));
	connect(ui.loginPushButton, SIGNAL(clicked()), this, SLOT(on_login_button_clicked()));
}

void					LoginWindow::on_close_button_clicked()
{
	close();
}

void					LoginWindow::on_login_button_clicked()
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

LoginWindow::~LoginWindow()
{

}