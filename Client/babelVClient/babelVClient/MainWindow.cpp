#include		"FriendList.h"
#include		"MainWindow.h"
#include		"Env.h"

#include		<QDebug>

MainWindow::MainWindow(QWidget *parent)	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowTitle("VBabel");

	connect(ui.friendListW, SIGNAL(itemActivated(QListWidgetItem *)), this, SLOT(on_friend_clicked(QListWidgetItem *)));
	connect(ui.friendListW, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(on_friend_clicked(QListWidgetItem *)));
	connect(ui.deleteSelectedFriendPushButton, SIGNAL(clicked()), this, SLOT(on_delete_friend_clicked()));
	connect(ui.sendBoxPushButton, SIGNAL(clicked()), this, SLOT(on_send_txt_msg()));
}

void						MainWindow::on_send_txt_msg()
{
	if (Env::getInstance().selectedFriend.friendName.size() != 0)
	{
		QList<QString>		*conversationList;

		Env::getInstance().friendList.insertTxtMsg(Env::getInstance().selectedFriend.friendName, ui.sendBoxTextEdit->toPlainText());
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

void						MainWindow::on_friend_clicked(QListWidgetItem *friendClicked)
{
	QString					friendGlobal(friendClicked->text());
	QList<QString>			*conversationList;



	if (Env::getInstance().selectedFriend.friendName.size() != 0)
		Env::getInstance().friendList.insertCurrentTxtMsg(Env::getInstance().selectedFriend.friendName, ui.sendBoxTextEdit->toPlainText());

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

MainWindow							&MainWindow::getInstance()
{
	static MainWindow				MainWindow;

	return (MainWindow);
}

MainWindow::~MainWindow()
{
}
