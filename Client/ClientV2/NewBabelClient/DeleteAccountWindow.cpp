#include "DeleteAccountWindow.h"

DeleteAccountWindow::DeleteAccountWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setModal(true);
	connect(ui.closePushButton, SIGNAL(clicked()), this, SLOT(on_close_button_clicked()));
	connect(ui.deletePushButton, SIGNAL(clicked()), this, SLOT(on_delete_account_button_clicked()));
}

void					DeleteAccountWindow::clearServerResponse()
{
	ui.serverResponseLabel->clear();
}

void					DeleteAccountWindow::on_close_button_clicked()
{
	close();
}

void					DeleteAccountWindow::on_delete_account_button_clicked()
{
	emit(delete_account_try(ui.loginLineEdit->text().toStdString(), ui.passwordLineEdit->text().toStdString()));
}

void					DeleteAccountWindow::displayDeleteAccountResponse(const QString &response)
{
	ui.serverResponseLabel->setText(response);
}