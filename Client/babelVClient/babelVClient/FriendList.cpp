#include					"FriendList.h"
#include					"MainWindow.h"

#include					"Env.h" //à virer
#include					<qdebug.h>
#include					<QPixmap>
#include					<QSize>

void						FriendList::insertFriend(QString &friendName, QString &friendMsgPerso, size_t status)
{
	_friendList.insert(friendName, new Friend(friendName, friendMsgPerso, status));
	//MainWindow::getInstance().getUi().friendListW->addFriendItem(QIcon("./Img/Online.png"), friendName, friendMsgPerso); //à modifier

	QIcon	img(QPixmap("./Img/Guyman-Helmet-Smiley-icon2.png"));
	//img.setIconSize(QSize(32, 39));

	MainWindow::getInstance().getUi().friendListW->addFriendItem(img, friendName, friendMsgPerso);
	MainWindow::getInstance().getUi().friendListW->setIconSize(QSize(32, 39));
}

Friend						*FriendList::getFriend(QString &friendName)
{
	friend_type::iterator	it = _friendList.find(friendName);

	if (it != _friendList.end())
	{
		return it.value();
	}
	return NULL;
}

QList<QString>						*FriendList::getClientConversation(QString &friendName)
{
	Friend							*tmpFriend;

	if ((tmpFriend = getFriend(friendName)) != NULL)
		return tmpFriend->getConversation();
	return NULL;
}

QString								*FriendList::getClientCurrentMsg(QString &friendName)
{
	Friend							*tmpFriend;

	if ((tmpFriend = getFriend(friendName)) != NULL)
		return tmpFriend->getCurrentMsg();
	return NULL;
}

bool								FriendList::insertCurrentTxtMsg(QString &friendName, QString &msg)
{
	Friend							*tmpFriend;

	if ((tmpFriend = getFriend(friendName)) != NULL)
	{
		tmpFriend->setCurrentMsg(msg);
		return true;
	}
	return false;
}

bool								FriendList::removeFriend(QString &friendName)
{
	QList<QListWidgetItem *>				tmpList;
	QListWidgetItem							*tmpItem;
	Friend									*tmpFriend;

	if ((tmpFriend = getFriend(friendName)) != NULL)
	{
//		qDebug() << ":" << friendName.size() << ":" << Env::getInstance().selectedFriend.friendName.size() << ":";
		tmpList = MainWindow::getInstance().getUi().friendListW->findItems(friendName, Qt::MatchStartsWith); // à check
		if (tmpList.isEmpty())
		{
//			qDebug() << "NOTOK";
			return false;
		}
		while (!tmpList.isEmpty())
		{
			tmpItem = tmpList.takeFirst();
			MainWindow::getInstance().getUi().friendListW->removeItemWidget(tmpItem);		
			delete tmpItem;
		}
		_friendList.remove(friendName);
		return true;
	}
	return false;
}

bool								FriendList::updateFriendStatus(QString &friendName, size_t newStatus)
{
	Friend							*tmpFriend;

	if ((tmpFriend = getFriend(friendName)) != NULL)
	{
		tmpFriend->setStatus(newStatus);
		return true;
	}
	return false;
}

bool								FriendList::updateFriendPersonalMsg(QString &friendName, QString &newPersonalMsg)
{
	Friend							*tmpFriend;

	if ((tmpFriend = getFriend(friendName)) != NULL)
	{
		tmpFriend->setFriendPersonalMessage(newPersonalMsg);
		return true;
	}
	return false;
}

bool								FriendList::updateFriendCallStatus(QString &friendName, bool newCallStatus)
{
	Friend							*tmpFriend;

	if ((tmpFriend = getFriend(friendName)) != NULL)
	{
		tmpFriend->setCallStatus(newCallStatus);
		return true;
	}
	return false;
}

bool								FriendList::insertTxtMsg(QString &friendName, QString &msg)
{
	Friend							*tmpFriend;

	if ((tmpFriend = getFriend(friendName)) != NULL)
	{
		tmpFriend->insertMsg(msg);
		return true;
	}
	return false;
}

FriendList::~FriendList()
{
	for (friend_type::iterator	it = _friendList.begin(); it != _friendList.end(); ++it)
	    delete *it;
}