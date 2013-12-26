#ifndef ACCOUNTMANAGEMENTWINDOW_H
#define ACCOUNTMANAGEMENTWINDOW_H

#include <QDialog>
#include "ui_AccountManagementWindow.h"

class AccountManagementWindow : public QDialog
{
	Q_OBJECT

public:
	AccountManagementWindow(QWidget *parent = 0);
	~AccountManagementWindow();

private:
	Ui::AccountManagementWindow ui;
};

#endif // ACCOUNTMANAGEMENTWINDOW_H
