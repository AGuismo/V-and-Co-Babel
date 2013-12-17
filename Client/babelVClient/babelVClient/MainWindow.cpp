#include		"FriendList.h"
#include		"MainWindow.h"
#include		"Env.h"

#include		<QDebug>

MainWindow::MainWindow(QWidget *parent)	: QMainWindow(parent), _connectWindow(this)
{
	ui.setupUi(this);
	setWindowTitle("VBabel");
	_tcpSocket = new QTcpSocket(this);

	// Friend List Widget
	connect(ui.friendListW, SIGNAL(itemActivated(QListWidgetItem *)), this, SLOT(on_friend_clicked(QListWidgetItem *)));
	connect(ui.friendListW, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(on_friend_clicked(QListWidgetItem *)));
	connect(ui.deleteSelectedFriendPushButton, SIGNAL(clicked()), this, SLOT(on_delete_friend_clicked()));
	// SendBox buttoon
	connect(ui.sendBoxPushButton, SIGNAL(clicked()), this, SLOT(on_send_txt_msg()));
	connect(ui.sendBoxTextEdit, SIGNAL(returnPressed()), this, SLOT(on_send_txt_msg()));
	// Connect Window
	connect(ui.actionExit, SIGNAL(triggered()), this, SLOT(on_exit_action()));
	// Connect Window
	connect(ui.actionConnect, SIGNAL(triggered()), this, SLOT(on_connect_window_triggered()));
	// Create account Window
	connect(ui.actionCreate_account, SIGNAL(triggered()), this, SLOT(on_create_account_window_triggered()));
}

void						MainWindow::send_request(ARequest *req)
{
    std::vector<Protocol::Byte>					bytes;
	std::vector<Protocol::Byte>::const_iterator	it;
	QByteArray									datagram;

    std::cout << "Send request code: " << req->code() << std::endl;
    bytes = Protocol::product(*req);
	for (it = bytes.begin(); it != bytes.end(); ++it)
		datagram.push_back(*it);
	_tcpSocket->write(datagram.data(), datagram.size());
}

void						MainWindow::on_call_clicked()
{
	exit(1); // disgusting !
}

void						MainWindow::on_exit_action()
{
	exit(1); // disgusting !
}

void						MainWindow::on_connect_window_triggered()
{
	_connectWindow.show();
}

void						MainWindow::on_create_account_window_triggered()
{
	_createAccountWindow.show();
}


void						MainWindow::on_connection_try()
{
	qDebug() << Env::getInstance().authenticateInfo.addressIp << " : " << Env::getInstance().authenticateInfo.portTCP;
	_tcpSocket->connectToHost(Env::getInstance().authenticateInfo.addressIp, Env::getInstance().authenticateInfo.portTCP);
	if (_tcpSocket->waitForConnected(300))
	{
		Env::getInstance().userInfo.connected = true;
	}
	else
	{
		Env::getInstance().userInfo.connected = false;
		_tcpSocket->close();
	}
}

void						MainWindow::on_authentification_try()
{
	qDebug() << "authentification mtf : " << Env::getInstance().authenticateInfo.login << " : " << Env::getInstance().authenticateInfo.password;
	//send_request(new request::auth::client::NewClient(Env::getInstance().authenticateInfo.login, md5(Env::getInstance().authenticateInfo.password.toStdString()), false));
}





void						MainWindow::on_send_txt_msg()
{
	if (Env::getInstance().selectedFriend.friendName.size() != 0)
	{
		QList<QString>		*conversationList;

		Env::getInstance().friendList.insertTxtMsg(Env::getInstance().selectedFriend.friendName, ui.sendBoxTextEdit->text());
		ui.sendBoxTextEdit->clear();
		ui.friendMsgBox->clear();
		
		if ( (conversationList = Env::getInstance().friendList.getClientConversation(Env::getInstance().selectedFriend.friendName)) != NULL)
		{
			 for (int i = 0; i < conversationList->size(); ++i)
			 {
	 			ui.friendMsgBox->append(conversationList->at(i));
			}
		}
	}
}

void						MainWindow::on_friend_clicked(QListWidgetItem *friendClicked) // à faire plus beau !
{
	QString					friendGlobal(friendClicked->text());
	QList<QString>			*conversationList;



	if (Env::getInstance().selectedFriend.friendName.size() != 0)
		Env::getInstance().friendList.insertCurrentTxtMsg(Env::getInstance().selectedFriend.friendName, ui.sendBoxTextEdit->text());

	Env::getInstance().selectedFriend.friendName = friendGlobal.left(friendGlobal.indexOf("\n"));
	qDebug() << Env::getInstance().selectedFriend.friendName;
	ui.selectedFriendNameLabel->setText(friendGlobal.left(friendGlobal.indexOf("\n")));
	ui.selectedFriendPersonalMsgLabel->setText(friendGlobal.mid(friendGlobal.indexOf("\n") + 1));
	ui.friendMsgBox->clear();
	ui.sendBoxTextEdit->clear();
	if ((conversationList = Env::getInstance().friendList.getClientConversation(Env::getInstance().selectedFriend.friendName)) != NULL)
	{
		ui.sendBoxTextEdit->setText(*Env::getInstance().friendList.getClientCurrentMsg(Env::getInstance().selectedFriend.friendName));
		for (int i = 0; i < conversationList->size(); ++i)
		{
	 		ui.friendMsgBox->append(conversationList->at(i));
		}
	}
}

void						MainWindow::on_delete_friend_clicked()
{
	if (Env::getInstance().selectedFriend.friendName.size() != 0)
	{
		Env::getInstance().friendList.removeFriend(Env::getInstance().selectedFriend.friendName);
		ui.friendMsgBox->clear();
		ui.sendBoxTextEdit->clear();
	}
}

Ui::MainWindowClass			&MainWindow::getUi()
{
	return (ui);
}

MainWindow					&MainWindow::getInstance()
{
	static MainWindow		MainWindow;

	return (MainWindow);
}

MainWindow::~MainWindow()
{
}
