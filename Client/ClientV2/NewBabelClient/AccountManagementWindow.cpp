#include "AccountManagementWindow.h"

AccountManagementWindow::AccountManagementWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setModal(true);
	connect(ui.changePasswordPushButton, SIGNAL(clicked()), this, SLOT(on_change_password_button_clicked()));
	connect(ui.changePrivacyPushButton, SIGNAL(clicked()), this, SLOT(on_change_privacy_button_clicked()));
}

void					AccountManagementWindow::clearServerResponse()
{
	ui.serverResponseLabel->clear();
}

void					AccountManagementWindow::on_close_button_clicked()
{
	close();
}

void					AccountManagementWindow::on_change_password_button_clicked()
{
	emit(change_password_try(ui.currentPasswordLineEdit->text().toStdString(), ui.newPasswordLineEdit->text().toStdString()));
}

void					AccountManagementWindow::on_change_privacy_button_clicked()
{
	if (ui.publicRadioButton->isChecked())
		emit(change_privacy_try(false));
	else
		emit(change_privacy_try(true));
}

void					AccountManagementWindow::displayAccountManagementResponse(const QString &response)
{
	ui.serverResponseLabel->setText(response);
}