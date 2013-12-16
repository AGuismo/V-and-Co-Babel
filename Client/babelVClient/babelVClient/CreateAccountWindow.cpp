#include	"Env.h"
#include	"CreateAccountWindow.h"

CreateAccountWindow::CreateAccountWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setModal(true);
	connect(ui.closePushButton, SIGNAL(clicked()), this, SLOT(on_close_button_clicked()));
	connect(ui.createPushButton, SIGNAL(clicked()), this, SLOT(on_create_button_clicked()));
}

void					CreateAccountWindow::on_close_button_clicked()
{
	close();
}

void					CreateAccountWindow::on_create_button_clicked()
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

CreateAccountWindow::~CreateAccountWindow()
{

}
