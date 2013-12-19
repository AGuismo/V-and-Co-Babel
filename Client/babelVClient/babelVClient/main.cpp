#include		<QtWidgets/QApplication>
#include		"MainWindow.h"
#include		"Salt.hpp"
#include		"Env.h"
#include		"FriendList.h"

Salt::size_type	Salt::SALT = 42;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//MainWindow::getInstance().show();
	Env::getInstance();


	Env::getInstance().friendList.insertFriend(QString("Albator"), QString("Mange des nems..."), 1);
	Env::getInstance().friendList.insertFriend(QString("Goldorak"), QString("Aime les aristochats"), 2);
	Env::getInstance().friendList.insertFriend(QString("Capitaine Flam"), QString("J'aime les bisounours !"), 1);
	Env::getInstance().friendList.insertFriend(QString("Poil"), QString("Se gratte le cul"), 1);
//	Env::getInstance().friendList.removeFriend(QString("Goldorak"));
//	Env::getInstance().friendList.removeFriend(QString("Goldorak"));
	return a.exec();
}
