/********************************************************************************
** Form generated from reading UI file 'LoginWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
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
    QLabel *label;
    QLabel *label_2;
    QLineEdit *loginLineEdit;
    QLineEdit *passwordLineEdit;
    QLabel *serverResponseLabel;
    QPushButton *closePushButton;
    QPushButton *loginPushButton;
    QLabel *label_4;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QStringLiteral("LoginWindow"));
        LoginWindow->resize(235, 118);
        gridLayout = new QGridLayout(LoginWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(LoginWindow);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(LoginWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setFamily(QStringLiteral("MS UI Gothic"));
        font1.setPointSize(10);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        loginLineEdit = new QLineEdit(LoginWindow);
        loginLineEdit->setObjectName(QStringLiteral("loginLineEdit"));

        gridLayout->addWidget(loginLineEdit, 1, 1, 1, 2);

        passwordLineEdit = new QLineEdit(LoginWindow);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));

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

        label_4 = new QLabel(LoginWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font3;
        font3.setFamily(QStringLiteral("MS UI Gothic"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        label_4->setFont(font3);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 0, 1, 3);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "LoginWindow", 0));
        label->setText(QApplication::translate("LoginWindow", "Login :", 0));
        label_2->setText(QApplication::translate("LoginWindow", "Password :", 0));
        serverResponseLabel->setText(QString());
        closePushButton->setText(QApplication::translate("LoginWindow", "Close", 0));
        loginPushButton->setText(QApplication::translate("LoginWindow", "Log in", 0));
        label_4->setText(QApplication::translate("LoginWindow", "Login", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H