#include				"Friend.h"


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

Friend::Friend(QString &friendName, QString &friendStatus)
{
	_name = friendName;
	_personalMsg = friendStatus;
}

Friend::~Friend()
{
}