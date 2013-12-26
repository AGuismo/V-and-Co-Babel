#ifndef ACCOUNTMANAGEMENTWINDOW_H
#define ACCOUNTMANAGEMENTWINDOW_H

#include <QDialog>
#include "ui_AccountManagementWindow.h"

class AccountManagementWindow : public QDialog
{
	Q_OBJECT

public:
	void							displayAccountManagementResponse(const QString &response);
	void							clearServerResponse();

private:
	Ui::AccountManagementWindow		ui;

public:
	AccountManagementWindow(QWidget *parent = 0);
	~AccountManagementWindow() {}

public slots:
   void								on_close_button_clicked();
   void								on_change_password_button_clicked();
   void								on_change_privacy_button_clicked();

signals:
    void							change_password_try(const std::string &curentPassword, const std::string &newPassword);
    void							change_privacy_try(bool newPrivacy);
};

#endif // ACCOUNTMANAGEMENTWINDOW_H
