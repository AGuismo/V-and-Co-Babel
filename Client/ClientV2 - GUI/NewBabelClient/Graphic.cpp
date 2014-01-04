

#include	"Graphic.h"

#include	<QDebug>

void					Graphic::init()
{
	// Connect Window Triggered
	connect(ui.actionConnect, SIGNAL(triggered()), this, SLOT(on_connect_window_triggered()));
	// Login Window Triggered
	connect(ui.actionLogin, SIGNAL(triggered()), this, SLOT(on_login_window_triggered()));
	// Logout Window Triggered
	connect(ui.actionLogout, SIGNAL(triggered()), this, SLOT(on_logout_window_triggered()));
	// Create Account Window Triggered
	connect(ui.actionCreateAccount, SIGNAL(triggered()), this, SLOT(on_create_account_window_triggered()));
	// Connection try triggered
	connect(&_connectWindow, SIGNAL(connect_try(const std::string &, unsigned short int)), this, SLOT(on_try_connect(const std::string &, unsigned short int)));
	// Login try triggered
	connect(&_loginWindow, SIGNAL(login_try(const std::string &, const std::string &)), this, SLOT(on_try_login(const std::string &, const std::string &)));
	// Createa account try triggered
	connect(&_createAccountWindow, SIGNAL(create_account_try(const std::string &, const std::string &)), this, SLOT(on_try_create(const std::string &, const std::string &)));

	// Combo Box
	connect(ui.comboBox_11, SIGNAL(currentIndexChanged(int)), this, SLOT(changeStatus()));
}

void					Graphic::changeContact(int value)
{
	QPixmap *pixmap_img;

	switch (value)
	{
	case 0:
		pixmap_img = new QPixmap("./Img/Guyman-Helmet-Smiley-icon.png");
		break;
	case 1:
		pixmap_img = new QPixmap("./Img/Guyman-Helmet-On-icon.png");
		break;
	case 2:
		pixmap_img = new QPixmap("./Img/Guyman-Helmet-Music-icon2.png");
		break;
	case 3:
		pixmap_img = new QPixmap("./Img/Guyman-Helmet-icon.png");
		break;
	default:
		pixmap_img = new QPixmap("./Img/Guyman-Helmet-Smiley-icon.png");
		break;
	}
	pixmap_img->scaled(39, 41, Qt::KeepAspectRatio);
	ui.selectedFriendIconStatusLabel_9->setPixmap(*pixmap_img);
}

void					Graphic::changeStatus()
{
	int value = ui.comboBox_11->currentIndex();
	qDebug() << "Status : " << value;

	switch (value)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}
	changeContact(value);
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
}

void					Graphic::on_connection_success()
{
  _connectWindow.displayConnectResponse(QString("Connected"));
  ui.actionLogin->setEnabled(true);
  ui.actionCreateAccount->setEnabled(true);
  ui.actionConnect->setEnabled(false);
  _connectWindow.setEnabled(false);
  QTimer::singleShot(800, &_connectWindow, SLOT(on_close_button_clicked()));
}

void					Graphic::on_login_success()
{
  _loginWindow.displayLoginResponse(QString("Logged in"));
  ui.actionLogout->setEnabled(true);
  ui.actionLogin->setEnabled(false);
  _loginWindow.setEnabled(false);
  QTimer::singleShot(800, &_loginWindow, SLOT(on_close_button_clicked()));
}

void					Graphic::on_desauthentification_success()
{
  ui.actionLogout->setEnabled(false);
  ui.actionLogin->setEnabled(true);
}

void					Graphic::on_desauthentification_error()
{
  ui.actionLogout->setEnabled(true);
  ui.actionLogin->setEnabled(false);
}

void					Graphic::on_login_error(const std::string &error)
{
  _loginWindow.displayLoginResponse(QString(error.c_str()));
}

void					Graphic::on_create_account_error(const std::string &error)
{
  _createAccountWindow.displayCreateAccountResponse(QString(error.c_str()));
}

void					Graphic::on_create_account_success()
{
  _createAccountWindow.displayCreateAccountResponse(QString("Account created"));
  _createAccountWindow.setEnabled(false);
  QTimer::singleShot(800, &_createAccountWindow, SLOT(on_close_button_clicked()));
}

void					Graphic::run()
{
  show();
}

void					Graphic::on_connect_window_triggered()
{
	_connectWindow.show();
	_createAccountWindow.setEnabled(true);
	_connectWindow.clearServerResponse();
}

void					Graphic::on_create_account_window_triggered()
{
	_createAccountWindow.show();
	_createAccountWindow.setEnabled(true);
	_createAccountWindow.clearServerResponse();
}

void					Graphic::on_logout_window_triggered()
{
	_desAuthentificationHandler();
}

void					Graphic::on_login_window_triggered()
{
	_loginWindow.show();
	_loginWindow.setEnabled(true);
	_loginWindow.clearServerResponse();
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

void					Graphic::on_try_create(const std::string &login, const std::string &password)
{
	qDebug() << "creation" << login.c_str() << password.c_str();
	_tryCreateAccountHandler(login, password);
}

void		Graphic::showTime()
{
	TimeLabel->setText(time.currentTime().toString());
}

Graphic::Graphic(QWidget *parent) : QMainWindow(parent), _connectWindow(this), _loginWindow(this), _createAccountWindow(this)
{
	ui.setupUi(this);

	ui.comboBox_11->addItem(QIcon("./Img/Guyman-Helmet-Smiley-icon.png"), "Online", QVariant("e"));
	ui.comboBox_11->addItem(QIcon("./Img/Guyman-Helmet-On-icon.png"), "Away", QVariant("e"));
	ui.comboBox_11->addItem(QIcon("./Img/Guyman-Helmet-Music-icon2.png"), "Occuped", QVariant("e"));
	ui.comboBox_11->addItem(QIcon("./Img/Guyman-Helmet-icon.png"), "Invisible", QVariant("e"));
	ui.comboBox_11->setIconSize(QSize(34, 41));

	ui.lineEdit_3->setMaxLength(84);

	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
	timer->start(1000);

	TimeLabel = new QLabel(time.currentTime().toString());
	ui.statusBar->addPermanentWidget(TimeLabel);

	showTime();
	
	setWindowIcon(QIcon("./Img/logoBabel.png"));
}

Graphic::~Graphic()
{

}
