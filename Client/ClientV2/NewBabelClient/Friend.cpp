#include				"Friend.h"
#include				"MainWindow.h"


void					Friend::setFriendPersonalMessage(QString &newPm)
{
	_personalMsg = newPm;
}

void					Friend::setCallStatus(bool newCallStatus)
{
	_callStatus = newCallStatus;
}

void					Friend::setStatus(int newStatus)
{
	_status = newStatus;
}

void					Friend::insertMsg(QString &msg)
{
	_msgList.push_back(msg);
}

void					Friend::setCurrentMsg(QString &curMsg)
{
	_curgMsg = curMsg;
}

QList<QString>			*Friend::getConversation()
{
	return (&_msgList);
}

QString					*Friend::getCurrentMsg()
{
	return (&_curgMsg);
}

Friend::Friend(QString &friendName, QString &personalMsg, size_t status)
{
	_name = friendName;
	_personalMsg = personalMsg;
	_callStatus = false;
	_status = status;
}

Friend::~Friend()
{
}