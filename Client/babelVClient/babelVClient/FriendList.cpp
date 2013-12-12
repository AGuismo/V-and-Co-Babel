#include					"FriendList.h"

void						FriendList::insertFriend(QString &friendName, QString &friendMsgPerso, size_t status)
{
	_friendList.insert(friendName, new Friend(friendName, friendMsgPerso, status));
}


Friend						*FriendList::getClient(QString &friendName)
{
	friend_type::iterator	it = _friendList.find(friendName);

	if (it != _friendList.end())
	{
		return it.value();
	}
	return NULL;
}

bool								FriendList::removeFriend(QString &friendName)
{
	friend_type::iterator	it = _friendList.find(friendName);

	if (it != _friendList.end())
	{
		delete *it;
		return true;
	}
	return false;
}

bool								FriendList::updateFriendStatus(QString &friendName, size_t newStatus)
{
	friend_type::iterator	it = _friendList.find(friendName);

	if (it != _friendList.end())
	{
		(*it)->setStatus(newStatus);
		return true;
	}
	return false;
}

bool								FriendList::updateFriendPersonalMsg(QString &friendName, QString &newPersonalMsg)
{
	friend_type::iterator	it = _friendList.find(friendName);

	if (it != _friendList.end())
	{
		(*it)->setFriendPersonalMessage(newPersonalMsg);
		return true;
	}
	return false;
}

bool								FriendList::updateFriendCallStatus(QString &friendName, bool newCallStatus)
{
	friend_type::iterator	it = _friendList.find(friendName);

	if (it != _friendList.end())
	{
		(*it)->setCallStatus(newCallStatus);
		return true;
	}
	return false;
}


FriendList							&FriendList::getInstance()
{
	static FriendList				FriendList;

	return (FriendList);
}

FriendList::~FriendList()
{
	for (friend_type::iterator	it = _friendList.begin(); it != _friendList.end(); ++it)
	    delete *it;
}