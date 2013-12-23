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
    QLabel *loginLabel;
    QLabel *passwordLabel;
    QLineEdit *loginLineEdit;
    QLineEdit *passwordLineEdit;
    QLabel *serverResponseLabel;
    QPushButton *closePushButton;
    QPushButton *loginPushButton;
    QLabel *loginTitleLabel;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QStringLiteral("LoginWindow"));
        LoginWindow->resize(298, 138);
        gridLayout = new QGridLayout(LoginWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        loginLabel = new QLabel(LoginWindow);
        loginLabel->setObjectName(QStringLiteral("loginLabel"));
        QFont font;
        font.setPointSize(10);
        loginLabel->setFont(font);

        gridLayout->addWidget(loginLabel, 1, 0, 1, 1);

        passwordLabel = new QLabel(LoginWindow);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        QFont font1;
        font1.setFamily(QStringLiteral("MS UI Gothic"));
        font1.setPointSize(10);
        passwordLabel->setFont(font1);

        gridLayout->addWidget(passwordLabel, 2, 0, 1, 1);

        loginLineEdit = new QLineEdit(LoginWindow);
        loginLineEdit->setObjectName(QStringLiteral("loginLineEdit"));
        loginLineEdit->setMaxLength(256);

        gridLayout->addWidget(loginLineEdit, 1, 1, 1, 2);

        passwordLineEdit = new QLineEdit(LoginWindow);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setMaxLength(256);

        gridLayout->addWidget(passwordLineEdit, 2, 1, 1, 2);

        serverResponseLabel = new QLabel(LoginWindow);
        serverResponseLabel->setObjectName(QStringLiteral("serverResponseLabel"));
        QFont font2;
        font2.setFamily(QStringLiteral("MS UI Gothic"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        serverResponseLabel->setFont(font2);

        gridLayout->addWidget(serverResponseLabel, 3, 0, 1, 1);

        closePushButton = new QPushButton(LoginWindow);
        closePushButton->setObjectName(QStringLiteral("closePushButton"));

        gridLayout->addWidget(closePushButton, 3, 1, 1, 1);

        loginPushButton = new QPushButton(LoginWindow);
        loginPushButton->setObjectName(QStringLiteral("loginPushButton"));

        gridLayout->addWidget(loginPushButton, 3, 2, 1, 1);

        loginTitleLabel = new QLabel(LoginWindow);
        loginTitleLabel->setObjectName(QStringLiteral("loginTitleLabel"));
        QFont font3;
        font3.setFamily(QStringLiteral("MS UI Gothic"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        loginTitleLabel->setFont(font3);
        loginTitleLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(loginTitleLabel, 0, 0, 1, 3);

        QWidget::setTabOrder(loginLineEdit, passwordLineEdit);
        QWidget::setTabOrder(passwordLineEdit, loginPushButton);
        QWidget::setTabOrder(loginPushButton, closePushButton);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "LoginWindow", 0));
        loginLabel->setText(QApplication::translate("LoginWindow", "Login :", 0));
        passwordLabel->setText(QApplication::translate("LoginWindow", "Password :", 0));
        serverResponseLabel->setText(QString());
        closePushButton->setText(QApplication::translate("LoginWindow", "Close", 0));
        loginPushButton->setText(QApplication::translate("LoginWindow", "Log in", 0));
        loginTitleLabel->setText(QApplication::translate("LoginWindow", "Login", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
