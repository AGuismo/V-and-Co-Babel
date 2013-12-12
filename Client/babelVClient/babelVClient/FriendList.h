#ifndef FRIENDLIST_H
# define	FRIENDLIST_H

#include	<QString>
#include	<QMap>

#include	"Friend.h"

class FriendList
{
private:
	typedef	QMap<QString , Friend *>	friend_type;

private:
	friend_type							_friendList;

public:
	void								insertFriend(QString &friendName, QString &friendMsgPerso, size_t status);
	bool								removeFriend(QString &friendName);
	bool								updateFriendStatus(QString &friendName, size_t newStatus);
	bool								updateFriendPersonalMsg(QString &friendName, QString &newPersonalMsg);
	bool								updateFriendCallStatus(QString &friendName, bool newCallStatus);

public:
	Friend								*getClient(QString &friendName);

private:
	FriendList() {}
	~FriendList();

public:
	static FriendList					&getInstance(void);

private:
	 FriendList(const FriendList &);
	 FriendList							operator=(const FriendList &);
};



#endif // !FRIENDLIST_H
