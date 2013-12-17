#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include	<QtWidgets/QMainWindow>
#include	<QtNetwork>

#include	"types.hh"
#include	"RequestCode.hh"
#include	"AuthRequest.hh"
#include	"CallRequest.hh"
#include	"Protocol.hpp"


#include	"ConnectWindow.h"
#include	"CreateAccountWindow.h"
#include	"ui_MainWindow.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

private:
	Ui::MainWindowClass			ui;

private:
	QTcpSocket					*_tcpSocket;

private:
	ConnectWindow				_connectWindow;
	CreateAccountWindow			_createAccountWindow;

public slots:
   void							on_friend_clicked(QListWidgetItem *);
   void							on_delete_friend_clicked();
   void							on_send_txt_msg();
   void							on_connect_window_triggered();
   void							on_create_account_window_triggered();
   void							on_connection_try();
   void							on_exit_action();
   void							on_call_clicked();
   void							on_authentification_try();
   void							send_request(ARequest *req);

public:
	Ui::MainWindowClass			&getUi();

public:
	static MainWindow			&getInstance();

private:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
};

#endif // MAINWINDOW_H
