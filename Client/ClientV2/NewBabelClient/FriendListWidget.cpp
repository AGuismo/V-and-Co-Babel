#include "FriendListWidget.h"

FriendListWidget::FriendListWidget(QWidget *parent)
	: QListWidget(parent)
{

}

void						FriendListWidget::insertFriend(const std::string &name, const Status status)
{
	QIcon					*tmp;

	if (status == DELETED)
		return;

	switch (status)
	{
	case 0:
		tmp = new QIcon(QPixmap("./Img/Guyman-Helmet-Smiley-icon.png"));
		break;
	case 1:
		tmp = new QIcon(QPixmap("./Img/Guyman-Helmet-On-icon.png"));
		break;
	case 2:
		tmp = new QIcon(QPixmap("./Img/Guyman-Helmet-Music-icon.png"));
		break;
	case 3:
		tmp = new QIcon(QPixmap("./Img/Guyman-Helmet-icon.png"));
		break;
	default:
		tmp = new QIcon(QPixmap("./Img/Guyman-Helmet-Smiley-icon.png"));
		break;
	}
	this->setIconSize(QSize(32, 39));
	addItem(new QListWidgetItem(*tmp, QString(name.c_str())));
}

void					FriendListWidget::updateFriendListWidget(const friend_list_type &friendList)
{
	this->clear();
	for (friend_list_type::const_iterator	it = friendList.begin(); it != friendList.end(); ++it)
		insertFriend( it->first, it->second.status);
}


FriendListWidget::~FriendListWidget()
{

}

