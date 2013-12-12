#ifndef FRIEND_H
# define	FRIEND_H

#include	<QString>
#include	<QList>
#include	<QListWidgetitem>

class Friend
{
private:
	QListWidgetItem *		_friendWidget;

private:
	QString					_name;
	QString					_personalMsg;

private:
	size_t					_status;
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
	Friend(QString &friendName, QString &friendMsgPerso, size_t status);
	~Friend();

private:
	Friend(const Friend &);
	Friend					operator=(const Friend &);
};

#endif // !FRIEND_H
