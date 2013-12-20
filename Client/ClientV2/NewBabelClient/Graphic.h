#ifndef GRAPHIC_H
#define GRAPHIC_H

#include		<QtWidgets/QMainWindow>
#include		"ui_Graphic.h"
#include		"AGraphic.hh"
#include		"ConnectWindow.h"

class Graphic : public QMainWindow, public AGraphic
{
	Q_OBJECT

private:
	ConnectWindow	_connectWindow;

public:
	Graphic(QWidget *parent = 0);
	~Graphic();

public slots:
	void			on_connect_window_triggered();
	void			on_try_connect(const std::string &ipAddress, unsigned short int port);

public:
	void	init();
	void	run();

private:
	Ui::GraphicClass ui;
};

#endif // GRAPHIC_H
