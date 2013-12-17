#ifndef CONNECTWINDOW_H
#define CONNECTWINDOW_H

#include <QDialog>
#include "ui_ConnectWindow.h"

class	MainWindow;

class ConnectWindow : public QDialog
{
	Q_OBJECT

private:
	Ui::ConnectWindow				ui;
	MainWindow						*_poop;

public:
	ConnectWindow(QWidget *parent = 0);
	~ConnectWindow();

public slots:
   void								on_close_button_clicked();
   void								on_connect_button_clicked();
};

#endif // CONNECTWINDOW_H
