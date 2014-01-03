#ifndef FRIENDLISTWIDGET_H
#define FRIENDLISTWIDGET_H

#include	<QListWidget>
#include	"FriendList.hh"

class FriendListWidget : public QListWidget
{
	Q_OBJECT

public:
	void		insertFriend(const std::string &name, Status status);

public:
	FriendListWidget(QWidget *parent);
	~FriendListWidget();
};

#endif // FRIENDLISTWIDGET_H
