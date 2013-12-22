#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include "ui_LoginWindow.h"

class LoginWindow : public QDialog
{
	Q_OBJECT

private:
	Ui::LoginWindow ui;

public:
	void						displayLoginResponse(QString &response);

public:
	LoginWindow(QWidget *parent = 0);
	~LoginWindow() {}

public slots:
   void							on_close_button_clicked();
   void							on_login_button_clicked();

signals:
    void						login_try(const std::string &login, std::string &password);


};

#endif // LOGINWINDOW_H
