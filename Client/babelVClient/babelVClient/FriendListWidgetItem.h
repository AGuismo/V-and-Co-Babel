#ifndef FRIENDLISTWIDGETITEM_H
#define FRIENDLISTWIDGETITEM_H

#include <QtWidgets/QListWidget>
#include <QtWidgets/QListWidgetItem>


class FriendListWidgetItem : public QListWidgetItem
{
	Q_OBJECT

public:
	FriendListWidgetItem(QListWidget *parent, int type);
	~FriendListWidgetItem();
};

#endif // FRIENDLISTWIDGETITEM_H
