#ifndef FRIEND_H
# define	FRIEND_H

#include	<QString>
#include	<QList>

class Friend
{
private:
	QString					_friendName;
	QString					_friendPersonalMessage;

private:
	int						_status;
	bool					_callStatus;

private:
	typedef	QList<QString>	MSG_LIST;
	typedef	QString			MSG;

private:
	MSG_LIST				_msgList;
	MSG						_curgMsg;

public:
	void					setFriendPersonalMessage(QString &newPm);
	void					setCallStatus(bool newCallStatus);
	void					setStatus(int newStatus);

public:
	void					insertMsg(QString &msg);
	void					setCurrentMsg(QString &curMsg);

public:
	Friend(QString friendName, QString friendStatus);
	~Friend();
};

#endif // !FRIEND_H
