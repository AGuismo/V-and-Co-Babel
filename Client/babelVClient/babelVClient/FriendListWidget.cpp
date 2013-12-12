#include		"FriendListWidget.h"
#include		<qicon.h>

void				FriendListWidget::addFriendItem(QIcon &iconStatus, QString &name, QString &personalMsg)
{
	addItem(new QListWidgetItem(iconStatus, name + "\n\"" + personalMsg + "\""));
}

FriendListWidget::FriendListWidget(QWidget *parent)	: QListWidget(parent)
{
}

FriendListWidget::~FriendListWidget()
{

}