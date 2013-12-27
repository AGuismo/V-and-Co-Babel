#ifndef MANAGEFRIENDWINDOW_H
#define MANAGEFRIENDWINDOW_H

#include <QDialog>
#include "ui_ManageFriendWindow.h"

class ManageFriendWindow : public QDialog
{
	Q_OBJECT

public:
	ManageFriendWindow(QWidget *parent = 0);
	~ManageFriendWindow();

private:
	Ui::ManageFriendWindow ui;
};

#endif // MANAGEFRIENDWINDOW_H
