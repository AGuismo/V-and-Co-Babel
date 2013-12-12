#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>


#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

private:
	Ui::MainWindowClass ui;

public slots:
   void on_friend_clicked(QListWidgetItem *);

public:
	Ui::MainWindowClass			&getUi();

public:
	static MainWindow &getInstance();

private:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
};

#endif // MAINWINDOW_H
