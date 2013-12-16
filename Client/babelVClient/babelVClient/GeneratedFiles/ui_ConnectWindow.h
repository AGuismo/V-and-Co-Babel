/********************************************************************************
** Form generated from reading UI file 'ConnectWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTWINDOW_H
#define UI_CONNECTWINDOW_H

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

class Ui_ConnectWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *serverResponseLabel;
    QPushButton *closePushButton;
    QLabel *loginLabel;
    QLineEdit *loginLineEdit;
    QPushButton *connectPushButton;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;

    void setupUi(QDialog *ConnectWindow)
    {
        if (ConnectWindow->objectName().isEmpty())
            ConnectWindow->setObjectName(QStringLiteral("ConnectWindow"));
        ConnectWindow->resize(272, 99);
        gridLayout = new QGridLayout(ConnectWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        serverResponseLabel = new QLabel(ConnectWindow);
        serverResponseLabel->setObjectName(QStringLiteral("serverResponseLabel"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        serverResponseLabel->setFont(font);

        gridLayout->addWidget(serverResponseLabel, 2, 0, 1, 1);

        closePushButton = new QPushButton(ConnectWindow);
        closePushButton->setObjectName(QStringLiteral("closePushButton"));

        gridLayout->addWidget(closePushButton, 2, 1, 1, 1);

        loginLabel = new QLabel(ConnectWindow);
        loginLabel->setObjectName(QStringLiteral("loginLabel"));
        QFont font1;
        font1.setPointSize(10);
        loginLabel->setFont(font1);

        gridLayout->addWidget(loginLabel, 0, 0, 1, 1);

        loginLineEdit = new QLineEdit(ConnectWindow);
        loginLineEdit->setObjectName(QStringLiteral("loginLineEdit"));

        gridLayout->addWidget(loginLineEdit, 0, 1, 1, 2);

        connectPushButton = new QPushButton(ConnectWindow);
        connectPushButton->setObjectName(QStringLiteral("connectPushButton"));

        gridLayout->addWidget(connectPushButton, 2, 2, 1, 1);

        passwordLabel = new QLabel(ConnectWindow);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        passwordLabel->setFont(font1);

        gridLayout->addWidget(passwordLabel, 1, 0, 1, 1);

        passwordLineEdit = new QLineEdit(ConnectWindow);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));

        gridLayout->addWidget(passwordLineEdit, 1, 1, 1, 2);


        retranslateUi(ConnectWindow);

        QMetaObject::connectSlotsByName(ConnectWindow);
    } // setupUi

    void retranslateUi(QDialog *ConnectWindow)
    {
        ConnectWindow->setWindowTitle(QApplication::translate("ConnectWindow", "ConnectWindow", 0));
        serverResponseLabel->setText(QApplication::translate("ConnectWindow", "Disconnected", 0));
        closePushButton->setText(QApplication::translate("ConnectWindow", "Close", 0));
        loginLabel->setText(QApplication::translate("ConnectWindow", "Login :", 0));
        connectPushButton->setText(QApplication::translate("ConnectWindow", "Connect", 0));
        passwordLabel->setText(QApplication::translate("ConnectWindow", "Password :", 0));
    } // retranslateUi

};

namespace Ui {
    class ConnectWindow: public Ui_ConnectWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTWINDOW_H
