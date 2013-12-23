#include "Graphic.h"

#include	<QDebug>


void					Graphic::init()
{
	// Connect Window Triggered
	connect(ui.actionConnect, SIGNAL(triggered()), this, SLOT(on_connect_window_triggered()));
	// Login Window Triggered
	connect(ui.actionLogin, SIGNAL(triggered()), this, SLOT(on_login_window_triggered()));
	// Connection try triggered
	connect(&_connectWindow, SIGNAL(connect_try(const std::string &, unsigned short int)), this, SLOT(on_try_connect(const std::string &, unsigned short int)));
	// Login try triggered
	connect(&_loginWindow, SIGNAL(login_try(const std::string &, const std::string &)), this, SLOT(on_try_login(const std::string &, const std::string &)));
}

void					Graphic::on_connection_error(enum ANetwork::SocketState state)
{
  switch (state)
  {
        case ANetwork::ERRCONNREFUSED:
		_connectWindow.displayConnectResponse(QString("Connection refused"));
		break;
	case ANetwork::ERRTIMEDOUT:
		_connectWindow.displayConnectResponse(QString("Connection timed out"));
		break;
	case ANetwork::ERRHANDSHAKE:
		_connectWindow.displayConnectResponse(QString("Handshake error"));
		break;
	default:
		  _connectWindow.displayConnectResponse(QString("Unknown error.."));
		break;
  }
  ui.actionLogin->setEnabled(true); // to remove only for debuggind purpose
}

void					Graphic::on_connection_success()
{
  _connectWindow.displayConnectResponse(QString("Connected"));
  ui.actionLogin->setEnabled(true);
  ui.actionConnect->setEnabled(false);
}

void					Graphic::on_login_success()
{
  _loginWindow.displayLoginResponse(QString("Logged in"));
  ui.actionLog_out->setEnabled(true);
  ui.actionLogin->setEnabled(false);
}

void                                    Graphic::on_login_error(const std::string &error)
{
  _loginWindow.displayLoginResponse(QString(error.c_str()));
}

void					Graphic::run()
{
  show();
}

void					Graphic::on_connect_window_triggered()
{
	_connectWindow.show();
}

void					Graphic::on_login_window_triggered()
{
	_loginWindow.show();
}

void					Graphic::on_try_connect(const std::string &ipAddress, unsigned short int port)
{
	_tryConnectHandler(port, ipAddress);
}

void					Graphic::on_try_login(const std::string &login, const std::string &password)
{
	qDebug() << login.c_str() << password.c_str();
	_tryAuthentificationHandler(login, password);
}

Graphic::Graphic(QWidget *parent) : QMainWindow(parent), _connectWindow(this), _loginWindow(this)
{
	ui.setupUi(this);
}

Graphic::~Graphic()
{

}
