#ifndef GRAPHIC_H
#define GRAPHIC_H

#include		<QtWidgets/QMainWindow>
#include		"ui_Graphic.h"
#include		"AGraphic.hh"
#include		"ConnectWindow.h"
#include		"LoginWindow.h"

class Graphic : public QMainWindow, public AGraphic
{
	Q_OBJECT

private:
	ConnectWindow	_connectWindow;
	LoginWindow	_loginWindow;

public:
	Graphic(QWidget *parent = 0);
	~Graphic();

public slots:
	void			on_connect_window_triggered();
	void			on_login_window_triggered();

public slots:
	void			on_try_connect(const std::string &ipAddress, unsigned short int port);
	void			on_try_login(const std::string &login, const std::string &password);

public:
	void			on_connection_error(enum ANetwork::SocketState);
	void			on_connection_success();
	void			on_login_success();
	void			on_login_error(const std::string &error);

public:
	void	init();
	void	run();

private:
	Ui::GraphicClass ui;
};

#endif // GRAPHIC_H
