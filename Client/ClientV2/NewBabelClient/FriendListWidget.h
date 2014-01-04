#ifndef FRIENDLISTWIDGET_H
#define FRIENDLISTWIDGET_H

#include	<QListWidget>
#include	"FriendList.hh"

class FriendListWidget : public QListWidget
{
	Q_OBJECT

private:
	void		insertFriend(const std::string &name, const Status status);

public:
	void		updateFriendListWidget(const friend_list_type &friendList);

public:
	FriendListWidget(QWidget *parent);
	~FriendListWidget();
};

#endif // FRIENDLISTWIDGET_H
