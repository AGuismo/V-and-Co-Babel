#ifndef FRIENDLIST_H
# define	FRIENDLIST_H

#include	<QString>
#include	<QList>
#include	<QMap>

#include	"Friend.h"

class FriendList
{
private:
	typedef	QMap<QString , Friend *>	friend_type;

private:
	friend_type							_friendList;

private:
	Friend								*getFriend(QString &friendName);

public:
	void								insertFriend(QString &friendName, QString &friendMsgPerso, size_t status);
	bool								removeFriend(QString &friendName);

public:
	bool								updateFriendStatus(QString &friendName, size_t newStatus);
	bool								updateFriendPersonalMsg(QString &friendName, QString &newPersonalMsg);
	bool								updateFriendCallStatus(QString &friendName, bool newCallStatus);

public:
	bool								insertTxtMsg(QString &friendName, QString &msg);
	bool								insertCurrentTxtMsg(QString &friendName, QString &msg);

public:
	QList<QString>						*getClientConversation(QString &friendName);
	QString								*getClientCurrentMsg(QString &friendName);

public:
	FriendList() {}
	~FriendList();

private:
	 FriendList(const FriendList &);
	 FriendList							operator=(const FriendList &);
};



#endif // !FRIENDLIST_H
