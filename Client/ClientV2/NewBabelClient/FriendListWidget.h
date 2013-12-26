#ifndef FRIENDLISTWIDGET_H
#define FRIENDLISTWIDGET_H

#include <QListWidget>

class FriendListWidget : public QListWidget
{
	Q_OBJECT

public:
	FriendListWidget(QWidget *parent);
	~FriendListWidget();
};

#endif // FRIENDLISTWIDGET_H
