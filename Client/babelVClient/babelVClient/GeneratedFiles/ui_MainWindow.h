/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "friendlistwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QLabel *label_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *friendListLabel;
    FriendListWidget *friendListWidget;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *notificationListLabel;
    QListWidget *notificationListWidget;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QTextEdit *sendBoxTextEdit;
    QPushButton *sendBoxPushButton;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QPushButton *activeFriendCallPushButton;
    QLabel *label;
    QLabel *activeFriendLabel;
    QTextBrowser *textBrowser;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(677, 580);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 20, 291, 21));
        QFont font;
        font.setPointSize(14);
        label_3->setFont(font);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 80, 161, 421));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        friendListLabel = new QLabel(layoutWidget);
        friendListLabel->setObjectName(QStringLiteral("friendListLabel"));
        QFont font1;
        font1.setFamily(QStringLiteral("MS PGothic"));
        font1.setPointSize(20);
        friendListLabel->setFont(font1);

        verticalLayout->addWidget(friendListLabel);

        friendListWidget = new FriendListWidget(layoutWidget);
        friendListWidget->setObjectName(QStringLiteral("friendListWidget"));

        verticalLayout->addWidget(friendListWidget);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(190, 80, 151, 421));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        notificationListLabel = new QLabel(layoutWidget1);
        notificationListLabel->setObjectName(QStringLiteral("notificationListLabel"));
        QFont font2;
        font2.setFamily(QStringLiteral("MS UI Gothic"));
        font2.setPointSize(20);
        notificationListLabel->setFont(font2);

        verticalLayout_2->addWidget(notificationListLabel);

        notificationListWidget = new QListWidget(layoutWidget1);
        notificationListWidget->setObjectName(QStringLiteral("notificationListWidget"));

        verticalLayout_2->addWidget(notificationListWidget);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(360, 470, 291, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sendBoxTextEdit = new QTextEdit(layoutWidget2);
        sendBoxTextEdit->setObjectName(QStringLiteral("sendBoxTextEdit"));
        QFont font3;
        font3.setFamily(QStringLiteral("MS UI Gothic"));
        font3.setPointSize(10);
        sendBoxTextEdit->setFont(font3);

        horizontalLayout->addWidget(sendBoxTextEdit);

        sendBoxPushButton = new QPushButton(layoutWidget2);
        sendBoxPushButton->setObjectName(QStringLiteral("sendBoxPushButton"));

        horizontalLayout->addWidget(sendBoxPushButton);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(361, 10, 291, 441));
        verticalLayout_3 = new QVBoxLayout(layoutWidget3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        activeFriendCallPushButton = new QPushButton(layoutWidget3);
        activeFriendCallPushButton->setObjectName(QStringLiteral("activeFriendCallPushButton"));

        gridLayout->addWidget(activeFriendCallPushButton, 1, 1, 1, 1);

        label = new QLabel(layoutWidget3);
        label->setObjectName(QStringLiteral("label"));
        QFont font4;
        font4.setFamily(QStringLiteral("MS PGothic"));
        font4.setPointSize(10);
        label->setFont(font4);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        activeFriendLabel = new QLabel(layoutWidget3);
        activeFriendLabel->setObjectName(QStringLiteral("activeFriendLabel"));
        QFont font5;
        font5.setPointSize(16);
        activeFriendLabel->setFont(font5);
        activeFriendLabel->setAutoFillBackground(false);

        gridLayout->addWidget(activeFriendLabel, 0, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        textBrowser = new QTextBrowser(layoutWidget3);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout_3->addWidget(textBrowser);

        MainWindowClass->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        label_3->raise();
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 677, 21));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0));
        label_3->setText(QApplication::translate("MainWindowClass", "Guismo : Status", 0));
        friendListLabel->setText(QApplication::translate("MainWindowClass", "Friends", 0));
        notificationListLabel->setText(QApplication::translate("MainWindowClass", "Notifications", 0));
        sendBoxPushButton->setText(QApplication::translate("MainWindowClass", "Send", 0));
        activeFriendCallPushButton->setText(QApplication::translate("MainWindowClass", "Call", 0));
        label->setText(QApplication::translate("MainWindowClass", "Active User Personal Message", 0));
        activeFriendLabel->setText(QApplication::translate("MainWindowClass", "ActiveUser : Status", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
