#ifndef FRIENDLISTWIDGET_H
#define FRIENDLISTWIDGET_H

#include <QtWidgets/QListWidget>


class FriendListWidget : public QListWidget
{
	Q_OBJECT

public:
	void				addFriendItem(QIcon &iconStatus, QString &name, QString &personalMsg);

public:
	FriendListWidget(QWidget *parent = 0);
	~FriendListWidget();
};

#endif // FRIENDLISTWIDGET_H
