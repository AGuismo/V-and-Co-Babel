#ifndef FRIENDLIST_H
# define	FRIENDLIST_H

#include	<QString>
#include	<QMap>

#include	"Friend.h"

class FriendList
{
private:
	typedef	QMap<QString &, Friend *>	friend_type;

private:
	friend_type							_friendList;

public:
	void								insertFriend(QString &friendName, QString &friendStatus);

public:
	Friend								*getClient(QString &friendName);

public:
	FriendList();
	~FriendList();
};



#endif // !FRIENDLIST_H
