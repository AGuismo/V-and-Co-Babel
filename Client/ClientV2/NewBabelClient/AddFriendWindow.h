#ifndef ADDFRIENDWINDOW_H
#define ADDFRIENDWINDOW_H

#include <QDialog>
#include "ui_AddFriendWindow.h"

class AddFriendWindow : public QDialog
{
	Q_OBJECT

private:
	Ui::AddFriendWindow ui;

public:
	void						displayAddResponse(const QString &response);
	void						clearServerResponse();

public:
	AddFriendWindow(QWidget *parent = 0);
	~AddFriendWindow() {}

public slots:
   void							on_close_button_clicked();
   void							on_add_button_clicked();

signals:
    void						add_try(const std::string &friendLogin);

};

#endif // ADDFRIENDWINDOW_H
