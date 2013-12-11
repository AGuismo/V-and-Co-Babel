#include					"FriendList.h"

void						FriendList::insertFriend(QString &friendName, QString &friendStatus)
{
	_friendList.insert(friendName, new Friend(friendName, friendStatus));
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