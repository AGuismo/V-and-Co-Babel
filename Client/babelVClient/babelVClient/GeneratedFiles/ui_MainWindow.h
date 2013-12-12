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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "friendlistwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
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
    QLineEdit *lineEdit;
    QPushButton *sendBoxPushButton;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QPushButton *activeFriendCallPushButton;
    QLabel *label;
    QLabel *activeFriendLabel;
    QLabel *label_5;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QTextBrowser *textBrowser;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QWidget *widget1;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QMenu *menuVBabel;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(652, 560);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 140, 161, 361));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        friendListLabel = new QLabel(layoutWidget);
        friendListLabel->setObjectName(QStringLiteral("friendListLabel"));
        QFont font;
        font.setFamily(QStringLiteral("MS PGothic"));
        font.setPointSize(20);
        friendListLabel->setFont(font);

        verticalLayout->addWidget(friendListLabel);

        friendListWidget = new FriendListWidget(layoutWidget);
        friendListWidget->setObjectName(QStringLiteral("friendListWidget"));

        verticalLayout->addWidget(friendListWidget);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(190, 140, 151, 361));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        notificationListLabel = new QLabel(layoutWidget1);
        notificationListLabel->setObjectName(QStringLiteral("notificationListLabel"));
        QFont font1;
        font1.setFamily(QStringLiteral("MS UI Gothic"));
        font1.setPointSize(20);
        notificationListLabel->setFont(font1);

        verticalLayout_2->addWidget(notificationListLabel);

        notificationListWidget = new QListWidget(layoutWidget1);
        notificationListWidget->setObjectName(QStringLiteral("notificationListWidget"));

        verticalLayout_2->addWidget(notificationListWidget);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(360, 480, 281, 20));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(layoutWidget2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        sendBoxPushButton = new QPushButton(layoutWidget2);
        sendBoxPushButton->setObjectName(QStringLiteral("sendBoxPushButton"));

        horizontalLayout->addWidget(sendBoxPushButton);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(360, 10, 281, 61));
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
        QFont font2;
        font2.setFamily(QStringLiteral("MS PGothic"));
        font2.setPointSize(10);
        label->setFont(font2);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        activeFriendLabel = new QLabel(layoutWidget3);
        activeFriendLabel->setObjectName(QStringLiteral("activeFriendLabel"));
        QFont font3;
        font3.setPointSize(16);
        activeFriendLabel->setFont(font3);
        activeFriendLabel->setAutoFillBackground(false);

        gridLayout->addWidget(activeFriendLabel, 0, 0, 1, 1);

        label_5 = new QLabel(layoutWidget3);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font4;
        font4.setPointSize(14);
        label_5->setFont(font4);

        gridLayout->addWidget(label_5, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(360, 90, 281, 371));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(horizontalLayoutWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        horizontalLayout_2->addWidget(textBrowser);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 331, 61));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font4);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font4);

        gridLayout_2->addWidget(label_4, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font2);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        comboBox_2 = new QComboBox(widget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout_2->addWidget(comboBox_2, 1, 1, 1, 1);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 90, 331, 25));
        gridLayout_3 = new QGridLayout(widget1);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_3->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(widget1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_3->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(widget1);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_3->addWidget(pushButton_3, 0, 2, 1, 1);

        MainWindowClass->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        label_3->raise();
        textBrowser->raise();
        textBrowser->raise();
        textBrowser->raise();
        label_2->raise();
        comboBox_2->raise();
        label_4->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        horizontalLayoutWidget->raise();
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 652, 21));
        menuVBabel = new QMenu(menuBar);
        menuVBabel->setObjectName(QStringLiteral("menuVBabel"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuVBabel->menuAction());

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0));
        friendListLabel->setText(QApplication::translate("MainWindowClass", "Friends", 0));
        notificationListLabel->setText(QApplication::translate("MainWindowClass", "Notifications", 0));
        sendBoxPushButton->setText(QApplication::translate("MainWindowClass", "Send", 0));
        activeFriendCallPushButton->setText(QApplication::translate("MainWindowClass", "Call", 0));
        label->setText(QApplication::translate("MainWindowClass", "Selected Friend Personal Message", 0));
        activeFriendLabel->setText(QApplication::translate("MainWindowClass", "Selected Friend", 0));
        label_5->setText(QApplication::translate("MainWindowClass", "Icone", 0));
        label_3->setText(QApplication::translate("MainWindowClass", "User", 0));
        label_4->setText(QApplication::translate("MainWindowClass", "Icone", 0));
        label_2->setText(QApplication::translate("MainWindowClass", "User Personal Message................", 0));
        pushButton->setText(QApplication::translate("MainWindowClass", "Call", 0));
        pushButton_2->setText(QApplication::translate("MainWindowClass", "Add", 0));
        pushButton_3->setText(QApplication::translate("MainWindowClass", "Delete", 0));
        menuVBabel->setTitle(QApplication::translate("MainWindowClass", "VBabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
