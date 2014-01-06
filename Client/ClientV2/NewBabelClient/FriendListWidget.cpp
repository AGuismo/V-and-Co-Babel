#include	"friendlistwidget.h"


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
		tmp = new QIcon(QPixmap("./Img/Invisible.png"));
		break;
	case 1:
		tmp = new QIcon(QPixmap("./Img/Online.png"));
		break;
	case 2:
		tmp = new QIcon(QPixmap("./Img/Away.png"));
		break;
	case 3:
		tmp = new QIcon(QPixmap("./Img/Occuped.png"));
		break;
	case 4:
		return;
		break;
	default:
		tmp = new QIcon(QPixmap("./Img/Invisible.png"));
		break;
	}
	this->setIconSize(QSize(37, 44));
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

