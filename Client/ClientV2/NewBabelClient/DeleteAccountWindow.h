#ifndef DELETEACCOUNTWINDOW_H
#define DELETEACCOUNTWINDOW_H

#include <QDialog>
#include "ui_DeleteAccountWindow.h"

class DeleteAccountWindow : public QDialog
{
	Q_OBJECT

public:
	void						displayDeleteAccountResponse(const QString &response);
	void						clearServerResponse();

private:
	Ui::DeleteAccountWindow		ui;

public:
	DeleteAccountWindow(QWidget *parent = 0);
	~DeleteAccountWindow() {}

public slots:
   void							on_close_button_clicked();
   void							on_delete_account_button_clicked();

signals:
    void						delete_account_try(const std::string &login, const std::string &password);
};

#endif // DELETEACCOUNTWINDOW_H
