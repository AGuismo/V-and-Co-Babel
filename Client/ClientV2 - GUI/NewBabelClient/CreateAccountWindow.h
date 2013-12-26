#ifndef CREATEACCOUNTWINDOW_H
#define CREATEACCOUNTWINDOW_H

#include <QDialog>
#include "ui_CreateAccountWindow.h"

class CreateAccountWindow : public QDialog
{
	Q_OBJECT

public:
	void						displayCreateAccountResponse(const QString &response);
	void						clearServerResponse();

private:
	Ui::CreateAccountWindow		ui;

public:
	CreateAccountWindow(QWidget *parent = 0);
	~CreateAccountWindow() {}

public slots:
   void							on_close_button_clicked();
   void							on_create_account_button_clicked();

signals:
    void						create_account_try(const std::string &login, const std::string &password);

};

#endif // CREATEACCOUNTWINDOW_H
