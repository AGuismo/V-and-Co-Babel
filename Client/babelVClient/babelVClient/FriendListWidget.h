#ifndef FRIENDLISTWIDGET_H
#define FRIENDLISTWIDGET_H

#include <QtWidgets/QListWidget>


class FriendListWidget : public QListWidget
{
	Q_OBJECT

public:
	FriendListWidget(QWidget *parent = 0);
	~FriendListWidget();
};

#endif // FRIENDLISTWIDGET_H
