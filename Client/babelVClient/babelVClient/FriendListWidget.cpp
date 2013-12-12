#include		"FriendListWidget.h"
#include		<qicon.h>

void				FriendListWidget::addFriendItem(QIcon &iconStatus, QString &name, QString &personalMsg)
{
	addItem(new QListWidgetItem(iconStatus, name));
}

FriendListWidget::FriendListWidget(QWidget *parent)	: QListWidget(parent)
{
/*	addItem(new QListWidgetItem("0"));
	addItem(new QListWidgetItem("1"));
	addItem(new QListWidgetItem("2"));
	addItem(new QListWidgetItem("3"));
	addItem(new QListWidgetItem("4"));
	addItem(new QListWidgetItem("5"));
	addItem(new QListWidgetItem("6"));
	addItem(new QListWidgetItem(QIcon("./Img/Online.png"), "Poil"));
//	addItem(*/
}

FriendListWidget::~FriendListWidget()
{

}