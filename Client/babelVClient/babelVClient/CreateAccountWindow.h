#ifndef CREATEACCOUNTWINDOW_H
#define CREATEACCOUNTWINDOW_H

#include <QDialog>
#include "ui_CreateAccountWindow.h"

class CreateAccountWindow : public QDialog
{
	Q_OBJECT

private:
	Ui::CreateAccountWindow ui;


public:
	CreateAccountWindow(QWidget *parent = 0);
	~CreateAccountWindow();


public slots:
   void								on_close_button_clicked();
   void								on_create_button_clicked();
};

#endif // CREATEACCOUNTWINDOW_H
