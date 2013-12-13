#include		"FriendList.h"
#include		"MainWindow.h"

MainWindow::MainWindow(QWidget *parent)	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowTitle("VBabel");


	connect(ui.friendListW, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(on_friend_clicked(QListWidgetItem *)));
}

void						MainWindow::on_friend_clicked(QListWidgetItem *friendClicked)
{
	QString					friendGlobal(friendClicked->text());


	ui.selectedFriendNameLabel->setText(friendGlobal.left(friendGlobal.indexOf("\n")));
	ui.selectedFriendPersonalMsgLabel->setText(friendGlobal.mid(friendGlobal.indexOf("\n") + 1));
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
