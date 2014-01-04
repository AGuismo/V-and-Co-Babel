/********************************************************************************
** Form generated from reading UI file 'AddFriendWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIENDWINDOW_H
#define UI_ADDFRIENDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddFriendWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *loginLabel;
    QLineEdit *loginLineEdit;
    QLabel *serverResponseLabel;
    QPushButton *closePushButton;
    QPushButton *addPushButton;
    QLabel *loginTitleLabel;

    void setupUi(QDialog *AddFriendWindow)
    {
        if (AddFriendWindow->objectName().isEmpty())
            AddFriendWindow->setObjectName(QStringLiteral("AddFriendWindow"));
        AddFriendWindow->resize(337, 109);
        AddFriendWindow->setStyleSheet(QLatin1String("AddFriendWindow \n"
"{\n"
"	border-image: url(./Img/dialog-background.jpg);\n"
"}"));
        gridLayout = new QGridLayout(AddFriendWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        loginLabel = new QLabel(AddFriendWindow);
        loginLabel->setObjectName(QStringLiteral("loginLabel"));
        QFont font;
        font.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font.setPointSize(10);
        loginLabel->setFont(font);
        loginLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(loginLabel, 1, 0, 1, 1);

        loginLineEdit = new QLineEdit(AddFriendWindow);
        loginLineEdit->setObjectName(QStringLiteral("loginLineEdit"));
        loginLineEdit->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 230);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"min-width: 10em;\n"
"padding: 2px;"));
        loginLineEdit->setMaxLength(42);

        gridLayout->addWidget(loginLineEdit, 1, 1, 1, 2);

        serverResponseLabel = new QLabel(AddFriendWindow);
        serverResponseLabel->setObjectName(QStringLiteral("serverResponseLabel"));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        serverResponseLabel->setFont(font1);

        gridLayout->addWidget(serverResponseLabel, 2, 0, 1, 1);

        closePushButton = new QPushButton(AddFriendWindow);
        closePushButton->setObjectName(QStringLiteral("closePushButton"));
        QFont font2;
        font2.setFamily(QStringLiteral("MS Reference Sans Serif"));
        closePushButton->setFont(font2);
        closePushButton->setStyleSheet(QLatin1String("QPushButton#closePushButton\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(0, 24, 185, 255), stop:1 rgba(163, 175, 255, 255));\n"
"	border-style: outset;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	border-color: rgb(255, 255, 255);\n"
"	min-width: 4em;\n"
"	padding: 6px;\n"
"}\n"
"\n"
"QPushButton#closePushButton:hover\n"
"{\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 148, 255, 255), stop:1 rgba(0, 8, 84, 255));\n"
"	border-style: inset;\n"
"}\n"
"\n"
" QPushButton#closePushButton:pressed \n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 56, 183, 255), stop:1 rgba(135, 172, 255, 255));\n"
"     border-style: inset;\n"
" }\n"
"\n"
""));

        gridLayout->addWidget(closePushButton, 2, 1, 1, 1);

        addPushButton = new QPushButton(AddFriendWindow);
        addPushButton->setObjectName(QStringLiteral("addPushButton"));
        addPushButton->setFont(font2);
        addPushButton->setStyleSheet(QLatin1String("QPushButton#addPushButton\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(0, 24, 185, 255), stop:1 rgba(163, 175, 255, 255));\n"
"	border-style: outset;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	border-color: rgb(255, 255, 255);\n"
"	min-width: 4em;\n"
"	padding: 6px;\n"
"}\n"
"\n"
"QPushButton#addPushButton:hover\n"
"{\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 148, 255, 255), stop:1 rgba(0, 8, 84, 255));\n"
"	border-style: inset;\n"
"}\n"
"\n"
" QPushButton#addPushButton:pressed \n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 56, 183, 255), stop:1 rgba(135, 172, 255, 255));\n"
"     border-style: inset;\n"
" }\n"
"\n"
""));

        gridLayout->addWidget(addPushButton, 2, 2, 1, 1);

        loginTitleLabel = new QLabel(AddFriendWindow);
        loginTitleLabel->setObjectName(QStringLiteral("loginTitleLabel"));
        QFont font3;
        font3.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        loginTitleLabel->setFont(font3);
        loginTitleLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        loginTitleLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(loginTitleLabel, 0, 0, 1, 3);

        QWidget::setTabOrder(loginLineEdit, addPushButton);
        QWidget::setTabOrder(addPushButton, closePushButton);

        retranslateUi(AddFriendWindow);

        QMetaObject::connectSlotsByName(AddFriendWindow);
    } // setupUi

    void retranslateUi(QDialog *AddFriendWindow)
    {
        AddFriendWindow->setWindowTitle(QApplication::translate("AddFriendWindow", "LoginWindow", 0));
        loginLabel->setText(QApplication::translate("AddFriendWindow", "Friend pseudo :", 0));
        loginLineEdit->setText(QApplication::translate("AddFriendWindow", "tata", 0));
        serverResponseLabel->setText(QString());
        closePushButton->setText(QApplication::translate("AddFriendWindow", "Close", 0));
        addPushButton->setText(QApplication::translate("AddFriendWindow", "Add", 0));
        loginTitleLabel->setText(QApplication::translate("AddFriendWindow", "Add friend", 0));
    } // retranslateUi

};

namespace Ui {
    class AddFriendWindow: public Ui_AddFriendWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIENDWINDOW_H
