#include "FriendListWidget.h"

FriendListWidget::FriendListWidget(QWidget *parent)	: QListWidget(parent)
{
	addItem(new QListWidgetItem("0"));
	addItem(new QListWidgetItem("1"));
	addItem(new QListWidgetItem("2"));
	addItem(new QListWidgetItem("3"));
	addItem(new QListWidgetItem("4"));
	addItem(new QListWidgetItem("5"));
	addItem(new QListWidgetItem("6"));
	addItem(new QListWidgetItem("Poil"));

}

FriendListWidget::~FriendListWidget()
{

}