/********************************************************************************
** Form generated from reading UI file 'ConnectWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
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
    QLineEdit *portTcpLineEdit;
    QLabel *passwordLabel;
    QPushButton *connectPushButton;
    QLineEdit *ipLineEdit;
    QLabel *serverResponseLabel;
    QPushButton *closePushButton;
    QLabel *loginLabel;
    QLabel *label;

    void setupUi(QDialog *ConnectWindow)
    {
        if (ConnectWindow->objectName().isEmpty())
            ConnectWindow->setObjectName(QStringLiteral("ConnectWindow"));
        ConnectWindow->resize(378, 145);
        ConnectWindow->setStyleSheet(QLatin1String("ConnectWindow \n"
"{\n"
"	border-image: url(./Img/dialog-background.jpg);\n"
"}"));
        gridLayout = new QGridLayout(ConnectWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        portTcpLineEdit = new QLineEdit(ConnectWindow);
        portTcpLineEdit->setObjectName(QStringLiteral("portTcpLineEdit"));
        portTcpLineEdit->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 230);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"min-width: 10em;\n"
"padding: 2px;"));
        portTcpLineEdit->setMaxLength(42);

        gridLayout->addWidget(portTcpLineEdit, 2, 1, 1, 2);

        passwordLabel = new QLabel(ConnectWindow);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        QFont font;
        font.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font.setPointSize(10);
        passwordLabel->setFont(font);
        passwordLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(passwordLabel, 2, 0, 1, 1);

        connectPushButton = new QPushButton(ConnectWindow);
        connectPushButton->setObjectName(QStringLiteral("connectPushButton"));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Reference Sans Serif"));
        connectPushButton->setFont(font1);
        connectPushButton->setStyleSheet(QLatin1String("QPushButton#connectPushButton\n"
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
"QPushButton#connectPushButton:hover\n"
"{\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 148, 255, 255), stop:1 rgba(0, 8, 84, 255));\n"
"	border-style: inset;\n"
"}\n"
"\n"
" QPushButton#connectPushButton:pressed \n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 56, 183, 255), stop:1 rgba(135, 172, 255, 255));\n"
"     border-style: inset;\n"
" }\n"
"\n"
""));

        gridLayout->addWidget(connectPushButton, 3, 2, 1, 1);

        ipLineEdit = new QLineEdit(ConnectWindow);
        ipLineEdit->setObjectName(QStringLiteral("ipLineEdit"));
        ipLineEdit->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 230);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"min-width: 10em;\n"
"padding: 2px;"));
        ipLineEdit->setMaxLength(42);

        gridLayout->addWidget(ipLineEdit, 1, 1, 1, 2);

        serverResponseLabel = new QLabel(ConnectWindow);
        serverResponseLabel->setObjectName(QStringLiteral("serverResponseLabel"));
        serverResponseLabel->setMinimumSize(QSize(185, 0));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        serverResponseLabel->setFont(font2);
        serverResponseLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(serverResponseLabel, 3, 0, 1, 1);

        closePushButton = new QPushButton(ConnectWindow);
        closePushButton->setObjectName(QStringLiteral("closePushButton"));
        closePushButton->setFont(font1);
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

        loginLabel = new QLabel(ConnectWindow);
        loginLabel->setObjectName(QStringLiteral("loginLabel"));
        loginLabel->setFont(font);
        loginLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(loginLabel, 1, 0, 1, 1);

        label = new QLabel(ConnectWindow);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 3);

        QWidget::setTabOrder(ipLineEdit, portTcpLineEdit);
        QWidget::setTabOrder(portTcpLineEdit, connectPushButton);
        QWidget::setTabOrder(connectPushButton, closePushButton);

        retranslateUi(ConnectWindow);

        QMetaObject::connectSlotsByName(ConnectWindow);
    } // setupUi

    void retranslateUi(QDialog *ConnectWindow)
    {
        ConnectWindow->setWindowTitle(QApplication::translate("ConnectWindow", "Connect", 0));
        portTcpLineEdit->setText(QApplication::translate("ConnectWindow", "40202", 0));
        passwordLabel->setText(QApplication::translate("ConnectWindow", "TCP Port :", 0));
        connectPushButton->setText(QApplication::translate("ConnectWindow", "Connect", 0));
        ipLineEdit->setText(QApplication::translate("ConnectWindow", "78.230.102.179", 0));
        serverResponseLabel->setText(QApplication::translate("ConnectWindow", "Disconnected", 0));
        closePushButton->setText(QApplication::translate("ConnectWindow", "Close", 0));
        loginLabel->setText(QApplication::translate("ConnectWindow", "Ip Address :", 0));
        label->setText(QApplication::translate("ConnectWindow", "Connect", 0));
    } // retranslateUi

};

namespace Ui {
    class ConnectWindow: public Ui_ConnectWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTWINDOW_H
