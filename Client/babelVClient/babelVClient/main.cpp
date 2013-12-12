#include		"MainWindow.h"
#include		"FriendList.h"
#include		<QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
//	MainWindow w;

	MainWindow::getInstance().show();

	FriendList::getInstance().insertFriend(QString("Albator"), QString("Mange des nems..."), 1);
	FriendList::getInstance().insertFriend(QString("Goldorak"), QString("Aime les aristochats"), 2);
	FriendList::getInstance().insertFriend(QString("Capitaine Flam"), QString("J'aime les bisounours !"), 1);
	FriendList::getInstance().insertFriend(QString("Poil"), QString("Se gratte le cul"), 1);


//	w.show();
	
/*	FriendList::getInstance().insertFriend(QString("Albator"), QString("Mange des nems..."), 1);
	FriendList::getInstance().insertFriend(QString("Goldorak"), QString("Aime les aristochats"), 2);
	FriendList::getInstance().insertFriend(QString("Capitaine Flam"), QString("J'aime les bisounours !"), 1);
	FriendList::getInstance().insertFriend(QString("Poil"), QString("Se gratte le cul"), 1);*/
	return a.exec();
}
