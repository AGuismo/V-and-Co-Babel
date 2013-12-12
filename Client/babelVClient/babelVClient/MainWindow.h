#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>


#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

private:
	Ui::MainWindowClass ui;

private:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

public:
	Ui::MainWindowClass			&getUi();

public:
	static MainWindow &getInstance();
};

#endif // MAINWINDOW_H
