#include		"FriendListWidget.h"
#include		<qicon.h>
#include		<QSize>
#include		<QAbstractItemView>

void				FriendListWidget::addFriendItem(QIcon &iconStatus, QString &name, QString &personalMsg)
{
	QListWidgetItem	*tmp = new QListWidgetItem(iconStatus, name + "\n\"" + personalMsg + "\""); 
	//tmp->setIconSize(QSize(32, 39));
	addItem(tmp);
}

FriendListWidget::FriendListWidget(QWidget *parent)	: QListWidget(parent)
{
}

FriendListWidget::~FriendListWidget()
{

}