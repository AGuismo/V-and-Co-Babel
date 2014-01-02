#include	"AddFriendWindow.h"


AddFriendWindow::AddFriendWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setModal(true);
	connect(ui.closePushButton, SIGNAL(clicked()), this, SLOT(on_close_button_clicked()));
	connect(ui.addPushButton, SIGNAL(clicked()), this, SLOT(on_add_button_clicked()));
}

void				AddFriendWindow::on_close_button_clicked()
{
	close();
}

void				AddFriendWindow::on_add_button_clicked()
{
	emit(add_try(ui.loginLineEdit->text().toStdString()));

}

void				AddFriendWindow::displayAddResponse(const QString &response)
{
	ui.serverResponseLabel->setText(response);
}

void				AddFriendWindow::clearServerResponse()
{
	ui.serverResponseLabel->clear();
}