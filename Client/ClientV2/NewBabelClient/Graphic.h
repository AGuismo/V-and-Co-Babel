#ifndef GRAPHIC_H
#define GRAPHIC_H

#include		<QtWidgets/QMainWindow>
#include		<QTime>
#include		"ui_Graphic.h"
#include		"AGraphic.hh"
#include		"ConnectWindow.h"
#include		"CreateAccountWindow.h"
#include		"LoginWindow.h"
#include		"DeleteAccountWindow.h"
#include		"AccountManagementWindow.h"
#include		"AddFriendWindow.h"
#include		"FriendListWidget.h"

class Graphic : public QMainWindow, public AGraphic
{
	Q_OBJECT

private:
	Ui::GraphicClass		ui;

private:
	ConnectWindow			_connectWindow;
	LoginWindow				_loginWindow;
	CreateAccountWindow		_createAccountWindow;
	DeleteAccountWindow		_deleteAccountWindow;
	AccountManagementWindow	_accountManagementWindow;
	AddFriendWindow			_addFriendWindow;

private:
	QLabel					*_timeLabel;
	QTime					_time;

public slots:
	void			on_connect_window_triggered();
	void			on_login_window_triggered();
	void			on_logout_window_triggered();
	void			on_create_account_window_triggered();
	void			on_delete_account_window_triggered();
	void			on_account_management_window_triggered();

	void			on_add_friend_window_triggered();
	void			on_delete_friend_triggered();
	void			on_send_box_push_button_released();
	void			on_call_friend_push_button_released();
	void			on_hang_up_push_button_released();
	void			on_change_status_triggered(int);
	void			on_change_status_txt_triggered();
	void			on_set_auto_answer_triggered();
	void			on_unset_auto_answer_triggered();

	void			on_friend_list_selection_changed();
	void			showTime();

public slots:
	void			on_try_connect(const std::string &ipAddress, unsigned short int port);
	void			on_try_login(const std::string &login, const std::string &password);
	void			on_try_create(const std::string &login, const std::string &password);
	void			on_try_delete(const std::string &login, const std::string &password);
	void			on_try_change_password(const std::string &currentPassword, const std::string &newPassword);
	void			on_try_change_privacy(bool newPrivacy);
	void			enable_status_txt_change();
	void			on_try_add_friend(const std::string &);

private:
	bool			eventFilter(QObject *target, QEvent *event);
public:
	void			on_connection_error(enum ANetwork::SocketState);
	void			on_connection_success();
	void			on_login_success();
	void			on_login_error(const std::string &error);
	void			on_desauthentification_success();
	void			on_desauthentification_error();
	void			on_create_account_success();
	void			on_create_account_error(const std::string &error);
	void			on_delete_account_success();
	void			on_delete_account_error(const std::string &error);
	void			on_change_account_privacy_success();
	void			on_change_account_privacy_error(const std::string &error);
	void			on_change_account_password_success();
	void			on_change_account_password_error(const std::string &error);

	void			on_call_request_success();
	void			on_call_request_error();

	void			on_select_friend();// à coder
	void			on_add_friend_success();
	void			on_add_friend_error(const std::string &error);

	void			askFriendInformation(const std::string &friendName);
	void			receiveFriendInformation(Friend *friendInfo);

public:
	bool			request_server_response(const std::string &title, const std::string &content);
	void			updateFriendList(const friend_list_type	&);

private:
	void			connected();
	void			disconnected();
	void			loggedIn();
	void			loggedOut();

public:
	void			init();
	void			run();

public:
	Graphic(QWidget *parent = 0);
	~Graphic();
};

#endif // GRAPHIC_H
