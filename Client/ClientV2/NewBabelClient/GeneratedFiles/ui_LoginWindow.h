/********************************************************************************
** Form generated from reading UI file 'LoginWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

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

class Ui_LoginWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *loginTitleLabel;
    QLabel *passwordLabel;
    QLabel *loginLabel;
    QPushButton *loginPushButton;
    QLabel *serverResponseLabel;
    QLineEdit *passwordLineEdit;
    QLineEdit *loginLineEdit;
    QPushButton *closePushButton;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QStringLiteral("LoginWindow"));
        LoginWindow->resize(378, 145);
        LoginWindow->setStyleSheet(QLatin1String("LoginWindow \n"
"{\n"
"	border-image: url(./Img/dialog-background.jpg);\n"
"}"));
        gridLayout = new QGridLayout(LoginWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        loginTitleLabel = new QLabel(LoginWindow);
        loginTitleLabel->setObjectName(QStringLiteral("loginTitleLabel"));
        QFont font;
        font.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        loginTitleLabel->setFont(font);
        loginTitleLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        loginTitleLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(loginTitleLabel, 0, 0, 1, 3);

        passwordLabel = new QLabel(LoginWindow);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font1.setPointSize(10);
        passwordLabel->setFont(font1);
        passwordLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(passwordLabel, 2, 0, 1, 1);

        loginLabel = new QLabel(LoginWindow);
        loginLabel->setObjectName(QStringLiteral("loginLabel"));
        loginLabel->setFont(font1);
        loginLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(loginLabel, 1, 0, 1, 1);

        loginPushButton = new QPushButton(LoginWindow);
        loginPushButton->setObjectName(QStringLiteral("loginPushButton"));
        QFont font2;
        font2.setFamily(QStringLiteral("MS Reference Sans Serif"));
        loginPushButton->setFont(font2);
        loginPushButton->setStyleSheet(QLatin1String("QPushButton#loginPushButton\n"
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
"QPushButton#loginPushButton:hover\n"
"{\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 148, 255, 255), stop:1 rgba(0, 8, 84, 255));\n"
"	border-style: inset;\n"
"}\n"
"\n"
" QPushButton#loginPushButton:pressed \n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 56, 183, 255), stop:1 rgba(135, 172, 255, 255));\n"
"     border-style: inset;\n"
" }\n"
"\n"
""));

        gridLayout->addWidget(loginPushButton, 3, 2, 1, 1);

        serverResponseLabel = new QLabel(LoginWindow);
        serverResponseLabel->setObjectName(QStringLiteral("serverResponseLabel"));
        serverResponseLabel->setMinimumSize(QSize(185, 0));
        QFont font3;
        font3.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        serverResponseLabel->setFont(font3);
        serverResponseLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(serverResponseLabel, 3, 0, 1, 1);

        passwordLineEdit = new QLineEdit(LoginWindow);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 230);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"min-width: 10em;\n"
"padding: 2px;"));
        passwordLineEdit->setMaxLength(42);
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordLineEdit, 2, 1, 1, 2);

        loginLineEdit = new QLineEdit(LoginWindow);
        loginLineEdit->setObjectName(QStringLiteral("loginLineEdit"));
        loginLineEdit->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 230);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"min-width: 10em;\n"
"padding: 2px;"));
        loginLineEdit->setMaxLength(42);

        gridLayout->addWidget(loginLineEdit, 1, 1, 1, 2);

        closePushButton = new QPushButton(LoginWindow);
        closePushButton->setObjectName(QStringLiteral("closePushButton"));
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

        gridLayout->addWidget(closePushButton, 3, 1, 1, 1);

        QWidget::setTabOrder(loginLineEdit, passwordLineEdit);
        QWidget::setTabOrder(passwordLineEdit, loginPushButton);
        QWidget::setTabOrder(loginPushButton, closePushButton);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "Login", 0));
        loginTitleLabel->setText(QApplication::translate("LoginWindow", "Login", 0));
        passwordLabel->setText(QApplication::translate("LoginWindow", "Password :", 0));
        loginLabel->setText(QApplication::translate("LoginWindow", "Login :", 0));
        loginPushButton->setText(QApplication::translate("LoginWindow", "Log in", 0));
        serverResponseLabel->setText(QString());
        passwordLineEdit->setInputMask(QString());
        passwordLineEdit->setText(QApplication::translate("LoginWindow", "poil", 0));
        loginLineEdit->setText(QApplication::translate("LoginWindow", "toto", 0));
        closePushButton->setText(QApplication::translate("LoginWindow", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
