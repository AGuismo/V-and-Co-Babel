#include "CreateAccountWindow.h"

CreateAccountWindow::CreateAccountWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setModal(true);
	connect(ui.closePushButton, SIGNAL(clicked()), this, SLOT(on_close_button_clicked()));
	connect(ui.createPushButton, SIGNAL(clicked()), this, SLOT(on_create_account_button_clicked()));

	this->setFixedSize(this->size());
}

void					CreateAccountWindow::clearServerResponse()
{
	ui.serverResponseLabel->clear();
}

void					CreateAccountWindow::on_close_button_clicked()
{
	close();
}

void					CreateAccountWindow::on_create_account_button_clicked()
{
	emit(create_account_try(ui.loginLineEdit->text().toStdString(), ui.passwordLineEdit->text().toStdString()));
}

void					CreateAccountWindow::displayCreateAccountResponse(const QString &response)
{
	ui.serverResponseLabel->setText(response);
}