#include			"LoginWindow.h"
#include			"Graphic.h"

LoginWindow::LoginWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setModal(true);
	connect(ui.closePushButton, SIGNAL(clicked()), this, SLOT(on_close_button_clicked()));
	connect(ui.loginPushButton, SIGNAL(clicked()), this, SLOT(on_login_button_clicked()));
}

void				LoginWindow::on_close_button_clicked()
{
	close();
}

void				LoginWindow::on_login_button_clicked()
{
	emit(login_try(ui.loginLineEdit->text().toStdString(), ui.passwordLineEdit->text().toStdString()));
}

void				LoginWindow::displayLoginResponse(const QString &response)
{
	ui.serverResponseLabel->setText(response);
}

void				LoginWindow::clearServerResponse()
{
	ui.serverResponseLabel->clear();
}