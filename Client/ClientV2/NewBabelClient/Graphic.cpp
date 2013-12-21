#include "Graphic.h"

#include	<QDebug>


void					Graphic::init()
{
	// Connect Window Triggered
	connect(ui.actionConnect, SIGNAL(triggered()), this, SLOT(on_connect_window_triggered()));
	// Connection try triggered
	connect(&_connectWindow, SIGNAL(connect_try(const std::string &, unsigned short int)), this, SLOT(on_try_connect(const std::string &, unsigned short int)));
}

void					Graphic::on_connection_error(enum ANetwork::SocketState state)
{
  qDebug() << "CONNECTION error : " << (int)state;
}

void					Graphic::on_connection_success()
{
	qDebug() << "CONNECTION SUCCESS";
}

void					Graphic::run()
{
  show();
}

void					Graphic::on_connect_window_triggered()
{
	_connectWindow.show();
}

void					Graphic::on_try_connect(const std::string &ipAddress, unsigned short int port)
{
	qDebug() << "LA GROS CON " << ipAddress.c_str() << port;
	_tryConnectHandler(port, ipAddress);
}

Graphic::Graphic(QWidget *parent) : QMainWindow(parent), _connectWindow(this)
{
	ui.setupUi(this);
}

Graphic::~Graphic()
{

}
