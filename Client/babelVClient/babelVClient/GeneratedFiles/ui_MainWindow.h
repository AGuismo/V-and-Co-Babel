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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <friendlistwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QPushButton *activeFriendCallPushButton;
    QLabel *label;
    QLabel *activeFriendLabel;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *sendBoxPushButton;
    QVBoxLayout *verticalLayout;
    QLabel *friendListLabel;
    FriendListWidget *friendListW;
    QVBoxLayout *verticalLayout_2;
    QLabel *notificationListLabel;
    QListWidget *notificationListWidget;
    QMenuBar *menuBar;
    QMenu *menuVBabel;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(717, 388);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_3->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_3->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_3->addWidget(pushButton_3, 0, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 2, 0, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setPointSize(14);
        label_3->setFont(font);

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setFamily(QStringLiteral("MS PGothic"));
        font1.setPointSize(10);
        label_2->setFont(font1);

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout_2->addWidget(comboBox_2, 2, 1, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout_2->addWidget(label_4, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 1, 0, 1, 2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        activeFriendCallPushButton = new QPushButton(centralWidget);
        activeFriendCallPushButton->setObjectName(QStringLiteral("activeFriendCallPushButton"));

        gridLayout->addWidget(activeFriendCallPushButton, 2, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        activeFriendLabel = new QLabel(centralWidget);
        activeFriendLabel->setObjectName(QStringLiteral("activeFriendLabel"));
        QFont font2;
        font2.setPointSize(16);
        activeFriendLabel->setFont(font2);
        activeFriendLabel->setAutoFillBackground(false);

        gridLayout->addWidget(activeFriendLabel, 1, 0, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout);


        gridLayout_4->addLayout(verticalLayout_3, 1, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        horizontalLayout_2->addWidget(textBrowser);


        gridLayout_4->addLayout(horizontalLayout_2, 2, 2, 2, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        sendBoxPushButton = new QPushButton(centralWidget);
        sendBoxPushButton->setObjectName(QStringLiteral("sendBoxPushButton"));

        horizontalLayout->addWidget(sendBoxPushButton);


        gridLayout_4->addLayout(horizontalLayout, 4, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        friendListLabel = new QLabel(centralWidget);
        friendListLabel->setObjectName(QStringLiteral("friendListLabel"));
        QFont font3;
        font3.setFamily(QStringLiteral("MS PGothic"));
        font3.setPointSize(20);
        friendListLabel->setFont(font3);

        verticalLayout->addWidget(friendListLabel);

        friendListW = new FriendListWidget(centralWidget);
        friendListW->setObjectName(QStringLiteral("friendListW"));

        verticalLayout->addWidget(friendListW);


        gridLayout_4->addLayout(verticalLayout, 3, 0, 2, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        notificationListLabel = new QLabel(centralWidget);
        notificationListLabel->setObjectName(QStringLiteral("notificationListLabel"));
        QFont font4;
        font4.setFamily(QStringLiteral("MS UI Gothic"));
        font4.setPointSize(20);
        notificationListLabel->setFont(font4);

        verticalLayout_2->addWidget(notificationListLabel);

        notificationListWidget = new QListWidget(centralWidget);
        notificationListWidget->setObjectName(QStringLiteral("notificationListWidget"));

        verticalLayout_2->addWidget(notificationListWidget);


        gridLayout_4->addLayout(verticalLayout_2, 3, 1, 2, 1);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 717, 21));
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
        pushButton->setText(QApplication::translate("MainWindowClass", "Call", 0));
        pushButton_2->setText(QApplication::translate("MainWindowClass", "Add", 0));
        pushButton_3->setText(QApplication::translate("MainWindowClass", "Delete", 0));
        label_3->setText(QApplication::translate("MainWindowClass", "User", 0));
        label_2->setText(QApplication::translate("MainWindowClass", "User Personal Message................", 0));
        label_4->setText(QApplication::translate("MainWindowClass", "Icone", 0));
        activeFriendCallPushButton->setText(QApplication::translate("MainWindowClass", "Call", 0));
        label->setText(QApplication::translate("MainWindowClass", "Selected Friend Personal Message", 0));
        activeFriendLabel->setText(QApplication::translate("MainWindowClass", "Selected Friend", 0));
        label_5->setText(QApplication::translate("MainWindowClass", "Icone", 0));
        sendBoxPushButton->setText(QApplication::translate("MainWindowClass", "Send", 0));
        friendListLabel->setText(QApplication::translate("MainWindowClass", "Friends", 0));
        notificationListLabel->setText(QApplication::translate("MainWindowClass", "Notifications", 0));
        menuVBabel->setTitle(QApplication::translate("MainWindowClass", "VBabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
