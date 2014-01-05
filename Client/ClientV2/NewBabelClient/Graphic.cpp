#include				"Graphic.h"
#include				"Env.hh"
#include				<QTimer>
#include				<QMessageBox>
#include				<QMovie>
#include				<QSplashScreen>
#include				<QDebug> // à virer


void					Graphic::init()
{
	ui.statusComboBox->addItem(QIcon("./Img/Online.png"), "Online", QVariant("e"));
	ui.statusComboBox->addItem(QIcon("./Img/Away.png"), "Away", QVariant("e"));
	ui.statusComboBox->addItem(QIcon("./Img/Occuped.png"), "Occuped", QVariant("e"));
	ui.statusComboBox->addItem(QIcon("./Img/Invisible.png"), "Invisible", QVariant("e"));
	ui.statusComboBox->setIconSize(QSize(34, 41));

	// Connect Window Triggered
	connect(ui.actionConnect, SIGNAL(triggered()), this, SLOT(on_connect_window_triggered()));
	// Login Window Triggered
	connect(ui.actionLogin, SIGNAL(triggered()), this, SLOT(on_login_window_triggered()));
	// Logout Window Triggered
	connect(ui.actionLogout, SIGNAL(triggered()), this, SLOT(on_logout_window_triggered()));

	// Add Friend Window Triggered
	connect(ui.actionAddFriend, SIGNAL(triggered()), this, SLOT(on_add_friend_window_triggered()));
	// Add Friend Window Push Button Released
	connect(ui.addFriendPushButton, SIGNAL(released()), this, SLOT(on_add_friend_window_triggered()));
	// Delete Friend Triggered
	connect(ui.deleteFriendPushButton, SIGNAL(released()), this, SLOT(on_delete_friend_triggered()));
	// Send message pushbutton released
	connect(ui.sendBoxPushButton, SIGNAL(released()), this, SLOT(on_send_box_push_button_released()));
	// Send message box return released
	connect(ui.sendBoxTextEdit, SIGNAL(returnPressed()), this, SLOT(on_send_box_push_button_released()));
	// Call friend push button left released
	connect(ui.callFriendLeftPushButton, SIGNAL(released()), this, SLOT(on_call_friend_push_button_released()));
	// Call friend push button right released
	connect(ui.callFriendRightPushButton, SIGNAL(released()), this, SLOT(on_call_friend_push_button_released()));
	// Hang up push button  released
	connect(ui.hangUpPushButton, SIGNAL(released()), this, SLOT(on_hang_up_push_button_released()));
	// Status change line edit
	connect(ui.statusLineEdit, SIGNAL(returnPressed()), this, SLOT(on_change_status_txt_triggered()));
	// Status change comboBox
	connect(ui.statusComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_change_status_triggered(int)));
	// Set answer Triggered
	connect(ui.actionSetVoicemail, SIGNAL(triggered()), this, SLOT(on_set_auto_answer_triggered()));
	// Unset answer Triggered
	connect(ui.actionUnsetVoicemail, SIGNAL(triggered()), this, SLOT(on_unset_auto_answer_triggered()));	
	// Create Account Window Triggered
	connect(ui.actionCreateAccount, SIGNAL(triggered()), this, SLOT(on_create_account_window_triggered()));
	// Delete Account Window Triggered
	connect(ui.actionDeleteAccount, SIGNAL(triggered()), this, SLOT(on_delete_account_window_triggered()));
	// Account Management Window Triggered
	connect(ui.actionAccountOptions, SIGNAL(triggered()), this, SLOT(on_account_management_window_triggered()));
	// Connection try triggered
	connect(&_connectWindow, SIGNAL(connect_try(const std::string &, unsigned short int)), this, SLOT(on_try_connect(const std::string &, unsigned short int)));
	// Change password try triggered
	connect(&_accountManagementWindow, SIGNAL(change_password_try(const std::string &, const std::string &)), this, SLOT(on_try_change_password(const std::string &, const std::string &)));
	// Change privacy try triggered
	connect(&_accountManagementWindow, SIGNAL(change_privacy_try(bool)), this, SLOT(on_try_change_privacy(bool)));
	// Login try triggered
	connect(&_loginWindow, SIGNAL(login_try(const std::string &, const std::string &)), this, SLOT(on_try_login(const std::string &, const std::string &)));
	// Create account try triggered
	connect(&_createAccountWindow, SIGNAL(create_account_try(const std::string &, const std::string &)), this, SLOT(on_try_create(const std::string &, const std::string &)));
	// Delete account try triggered
	connect(&_deleteAccountWindow, SIGNAL(delete_account_try(const std::string &, const std::string &)), this, SLOT(on_try_delete(const std::string &, const std::string &)));

	// Add friend try triggered
	connect(&_addFriendWindow, SIGNAL(add_try(const std::string &)), this, SLOT(on_try_add_friend(const std::string &)));

	// Friend list Item changed
	connect(ui.friendListWidget, SIGNAL(itemSelectionChanged()), this, SLOT(on_friend_list_selection_changed()));
}


void					Graphic::on_friend_list_selection_changed()
{
	if (ui.friendListWidget->currentItem() == NULL)
		return;
	qDebug() << "item changed: " << ui.friendListWidget->currentItem()->text();
	Env::getInstance().selectedFriend.name = ui.friendListWidget->currentItem()->text().toStdString();
	askFriendInformation(ui.friendListWidget->currentItem()->text().toStdString());
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
  connected();
  QTimer::singleShot(800, &_connectWindow, SLOT(on_close_button_clicked()));
}

void					Graphic::on_login_success()
{
  _loginWindow.displayLoginResponse(QString("Logged in"));
  loggedIn();
  Env::getInstance().userInfo.login = Env::getInstance().userInfo.loginTry;
  loggedIn();
  QTimer::singleShot(800, &_loginWindow, SLOT(on_close_button_clicked()));
}

void					Graphic::on_desauthentification_success()
{
  loggedOut();
}

void					Graphic::on_desauthentification_error()
{
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

void					Graphic::on_change_account_privacy_error(const std::string &error)
{
  _accountManagementWindow.displayAccountManagementResponse(QString(error.c_str()));
}

void					Graphic::on_change_account_privacy_success()
{
  _accountManagementWindow.displayAccountManagementResponse(QString("Privacy mode changed"));
  _accountManagementWindow.setEnabled(false);
  QTimer::singleShot(800, &_accountManagementWindow, SLOT(on_close_button_clicked()));
}

void					Graphic::on_change_account_password_error(const std::string &error)
{
  _accountManagementWindow.displayAccountManagementResponse(QString(error.c_str()));
}

void					Graphic::on_change_account_password_success()
{
  _accountManagementWindow.displayAccountManagementResponse(QString("Password changed"));
  _accountManagementWindow.setEnabled(false);
  QTimer::singleShot(800, &_accountManagementWindow, SLOT(on_close_button_clicked()));
}


void					Graphic::on_delete_account_error(const std::string &error)
{
  _deleteAccountWindow.displayDeleteAccountResponse(QString(error.c_str()));
}

void					Graphic::on_delete_account_success()
{
  _deleteAccountWindow.displayDeleteAccountResponse(QString("Account deleted"));
  _deleteAccountWindow.setEnabled(false);
  QTimer::singleShot(800, &_deleteAccountWindow, SLOT(on_close_button_clicked()));
}

bool					Graphic::eventFilter(QObject *target, QEvent *event)
{
	return (true);
}

void					Graphic::run()
{
	QSplashScreen screen;

	screen.setPixmap(QPixmap("./Img/logoBabelSplash.png"));
	screen.show();
	screen.installEventFilter(this);
	
	QEventLoop evtLoop;
	QTimer::singleShot(2000, &evtLoop, SLOT(quit()));
	evtLoop.exec();

	screen.hide();

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

void					Graphic::on_delete_account_window_triggered()
{
	_deleteAccountWindow.show();
	_deleteAccountWindow.setEnabled(true);
	_deleteAccountWindow.clearServerResponse();
}

void					Graphic::on_logout_window_triggered()
{
	_desAuthentificationHandler();
	loggedOut();
}

void					Graphic::on_login_window_triggered()
{
	_loginWindow.show();
	_loginWindow.setEnabled(true);
	_loginWindow.clearServerResponse();
}

void					Graphic::on_account_management_window_triggered()
{
	_accountManagementWindow.show();
	_accountManagementWindow.setEnabled(true);
	_accountManagementWindow.clearServerResponse();
}

void					Graphic::on_add_friend_window_triggered()
{
	_addFriendWindow.show();
	_addFriendWindow.setEnabled(true);
	_addFriendWindow.clearServerResponse();

}










void					Graphic::on_try_add_friend(const std::string &friendName)
{
	qDebug() << "adding friend here mtfk";
	_addFriendHandler(friendName);
}

void					Graphic::on_add_friend_success()
{
  _addFriendWindow.displayAddResponse(QString("Request sended"));
  _addFriendWindow.setEnabled(false);
  QTimer::singleShot(800, &_addFriendWindow, SLOT(on_close_button_clicked()));
}

void					Graphic::on_add_friend_error(const std::string &error)
{
  _addFriendWindow.displayAddResponse(QString(error.c_str()));
}

void					Graphic::on_delete_friend_triggered()
{
	if (ui.friendListWidget->currentItem() == NULL)
		return;

	QString				msg("Are you sure to delete \"");
	msg += 	ui.friendListWidget->currentItem()->text();
	msg += "\", he is really going to miss you..";


	if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, "Delete contact", msg, QMessageBox::Yes|QMessageBox::No).exec()) 
	{
		_delFriendHandler(ui.friendListWidget->currentItem()->text().toStdString());
		qDebug() << "deleting friend here mtfk !";
	}
	else
		qDebug() << "deletion aborted";
}

void					Graphic::on_send_box_push_button_released()
{
	qDebug() << "sending here mtfk !" << ui.sendBoxTextEdit->text(); // warning pseufo
	
	if (ui.friendListWidget->currentItem() != NULL)
		_chatHandler(ui.friendListWidget->currentItem()->text().toStdString(), ui.sendBoxTextEdit->text().toStdString());
	ui.sendBoxTextEdit->clear();
}

void					Graphic::closeEvent(QCloseEvent *ev)
{
	qDebug("Close Event");
	_aboutToCloseHandler();
	QMainWindow::closeEvent(ev);
}

void					Graphic::on_call_friend_push_button_released()
{
	qDebug() << "calling here mtfck !";
	if (ui.friendListWidget->currentItem() != NULL)
		_callHandler(ui.friendListWidget->currentItem()->text().toStdString());
}

void					Graphic::on_hang_up_push_button_released()
{
	qDebug() << "hanging up here mtfck !";
	_hangupHandler();
}

void					Graphic::on_change_status_triggered(int newStatus)
{
	qDebug() << "changing status here mtfk !";
	qDebug() << "[" << newStatus << ui.statusComboBox->currentIndex()  + 1 << "]";
	if (ui.statusComboBox->currentIndex() + 1 == 4)
		_statusHandler(ui.statusComboBox->currentIndex() + 2, ui.statusLineEdit->text().toStdString());		else
		_statusHandler(ui.statusComboBox->currentIndex() + 1, ui.statusLineEdit->text().toStdString());
}

void					Graphic::on_change_status_txt_triggered()
{
	qDebug() << "changing status txt here mtfk !";
	if (ui.statusComboBox->currentIndex() + 1 == 4)
		_statusHandler(ui.statusComboBox->currentIndex() + 2, ui.statusLineEdit->text().toStdString());		else
		_statusHandler(ui.statusComboBox->currentIndex() + 1, ui.statusLineEdit->text().toStdString());
	ui.statusLineEdit->setEnabled(false);
	QTimer::singleShot(800, this, SLOT(enable_status_txt_change()));
}

void					Graphic::on_set_auto_answer_triggered()
{
	qDebug() << "setting auto answer here mtfk !";
}

void					Graphic::on_unset_auto_answer_triggered()
{
	qDebug() << "unsetting auto answer here mtfk !";
}



bool					Graphic::request_server_response(const std::string &title, const std::string &content)
{

	if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, QString(title.c_str()), QString(content.c_str()), QMessageBox::Yes|QMessageBox::No).exec()) 
	{
		qDebug() << "Accepted !";
		return true;
	}
	return false;
	qDebug() << "Decline !";
}



void					Graphic::updateFriendList(const friend_list_type &friendList)
{
	ui.friendListWidget->updateFriendListWidget(friendList);
//	_friendListWidget.updateFriendListWidget(friendList);
}


void					Graphic::askFriendInformation(const std::string &friendName)
{
	_getFriendHandler(friendName);
}

void					Graphic::receiveFriendInformation(Friend *friendInfo)
{
	if (friendInfo != NULL)
	{
		ui.selectedFriendNameLabel->setText(QString(friendInfo->name.c_str()));
		ui.selectedFriendPersonalMsgLabel->setText(QString(friendInfo->personalMsg.c_str()));
		ui.friendMsgBox->clear();

		QPixmap					*tmp;

		switch (friendInfo->status)
		{
		case 0:
			tmp = new QPixmap("./Img/Invisible.png");
			break;
		case 1:
			tmp = new QPixmap("./Img/Online.png");
			break;
		case 2:
			tmp = new QPixmap("./Img/Away.png");
			break;
		case 3:
			tmp = new QPixmap("./Img/Occuped.png");
			break;
		case 4:
			return;
			break;
		default:
			tmp = new QPixmap("./Img/Invisible.png");
			break;
		}
		ui.selectedFriendIconStatusLabel->setPixmap(*tmp);

		for ( convers_type::const_iterator it =	friendInfo->conversation.begin(); it != friendInfo->conversation.end(); ++it)
		{
			ui.friendMsgBox->append(QString(it->header.c_str()));
		//	ui.friendMsgBox->append(QString(it->content.c_str()));
		}
	}
}


void					Graphic::on_try_connect(const std::string &ipAddress, unsigned short int port)
{
	_tryConnectHandler(port, ipAddress);
}

void					Graphic::on_try_login(const std::string &login, const std::string &password)
{
	 Env::getInstance().userInfo.loginTry = login;
	_tryAuthentificationHandler(login, password);
}

void					Graphic::on_try_create(const std::string &login, const std::string &password)
{
	_tryCreateAccountHandler(login, password);
}

void					Graphic::on_try_delete(const std::string &login, const std::string &password)
{
	_tryDeleteAccountHandler(login, password);
}

void					Graphic::on_try_change_password(const std::string &currentPassword, const std::string &newPassword)
{
	_tryChangePasswordHandler(currentPassword, newPassword);
}

void					Graphic::on_try_change_privacy(bool newPrivacy)
{
	_tryChangePrivacyHandler(newPrivacy);
}

void					Graphic::enable_status_txt_change()
{
	ui.statusLineEdit->setEnabled(true);
}

void					Graphic::disconnected()
{
	ui.actionConnect->setEnabled(true);
	// everything else disabled
}

void					Graphic::connected()
{
  ui.actionLogin->setEnabled(true);
  ui.actionCreateAccount->setEnabled(true);
  ui.actionConnect->setEnabled(false);
  ui.actionDeleteAccount->setEnabled(true);
  _connectWindow.setEnabled(false);
}

void					Graphic::loggedIn()
{
	ui.actionLogout->setEnabled(true);
	ui.actionLogin->setEnabled(false);
	ui.actionAccountOptions->setEnabled(true);
	ui.actionDeleteAccount->setEnabled(false);
	ui.actionCreateAccount->setEnabled(false);
	_loginWindow.setEnabled(false);
	ui.userNameLabel->setText(QString(Env::getInstance().userInfo.login.c_str()));
}

void					Graphic::loggedOut()
{
	ui.actionDeleteAccount->setEnabled(true);
	ui.actionCreateAccount->setEnabled(true);
	ui.actionAccountOptions->setEnabled(false);
	ui.actionLogin->setEnabled(true);
	ui.actionLogout->setEnabled(false);
}

void		Graphic::showTime()
{
	_timeLabel->setText(_time.currentTime().toString());
}

Graphic::Graphic(QWidget *parent) : QMainWindow(parent), _connectWindow(this), _loginWindow(this), _createAccountWindow(this), _deleteAccountWindow(this), _accountManagementWindow(this), _addFriendWindow(this)
{
	ui.setupUi(this);

	QPixmap					*tmp;
	tmp = new QPixmap("./Img/Invisible.png");
	ui.selectedFriendIconStatusLabel->setPixmap(*tmp);
	
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
	timer->start(1000);

	_timeLabel = new QLabel(_time.currentTime().toString());
	ui.statusBar->addPermanentWidget(_timeLabel);

	//showTime();
	
	setWindowIcon(QIcon("./Img/logoBabel.png"));
	QMovie *movie = new QMovie("./Img/appel_en_cours.gif", QByteArray(), this);
	//QMovie *movie = new QMovie("./Img/en_communication.gif", QByteArray(), this);
	ui.callLabel->setMovie(movie);
	movie->start();
	//ui.callLabel->setMovie(NULL);
}

void					Graphic::on_call_request_success()
{
	qDebug() << "call request succes here mtf";
}

void					Graphic::on_call_request_error()
{
	qDebug() << "call request error here mtf";
}



Graphic::~Graphic()
{
}
