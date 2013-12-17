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
#include <QtWidgets/QFrame>
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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <friendlistwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionConnect;
    QAction *actionCreate_account;
    QAction *actionLogin;
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer;
    QFrame *line;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox_2;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QTextBrowser *friendMsgBox;
    QVBoxLayout *verticalLayout;
    QLabel *friendListLabel;
    FriendListWidget *friendListW;
    QVBoxLayout *verticalLayout_2;
    QLabel *notificationListLabel;
    QListWidget *notificationListWidget;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QPushButton *activeFriendCallPushButton;
    QLabel *selectedFriendNameLabel;
    QLabel *selectedFriendPersonalMsgLabel;
    QLabel *selectedFriendIconStatusLabel;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout;
    QLineEdit *sendBoxTextEdit;
    QPushButton *sendBoxPushButton;
    QGridLayout *gridLayout_3;
    QFrame *line_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *deleteSelectedFriendPushButton;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QFrame *line_3;
    QMenuBar *menuBar;
    QMenu *menuVBabel;
    QMenu *menuConnection;
    QMenu *menuManage_account;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(824, 549);
        actionConnect = new QAction(MainWindowClass);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionCreate_account = new QAction(MainWindowClass);
        actionCreate_account->setObjectName(QStringLiteral("actionCreate_account"));
        actionLogin = new QAction(MainWindowClass);
        actionLogin->setObjectName(QStringLiteral("actionLogin"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 1, 0, 1, 1);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line, 2, 2, 4, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(false);
        QFont font;
        font.setFamily(QStringLiteral("MS PGothic"));
        font.setPointSize(10);
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setEnabled(false);
        QFont font1;
        font1.setPointSize(14);
        label_3->setFont(font1);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);

        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setEnabled(false);

        gridLayout_2->addWidget(comboBox_2, 1, 1, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setEnabled(false);
        label_4->setFont(font1);

        gridLayout_2->addWidget(label_4, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 2, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        friendMsgBox = new QTextBrowser(centralWidget);
        friendMsgBox->setObjectName(QStringLiteral("friendMsgBox"));

        horizontalLayout_2->addWidget(friendMsgBox);


        gridLayout_4->addLayout(horizontalLayout_2, 3, 3, 2, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        friendListLabel = new QLabel(centralWidget);
        friendListLabel->setObjectName(QStringLiteral("friendListLabel"));
        QFont font2;
        font2.setFamily(QStringLiteral("MS PGothic"));
        font2.setPointSize(20);
        friendListLabel->setFont(font2);

        verticalLayout->addWidget(friendListLabel);

        friendListW = new FriendListWidget(centralWidget);
        friendListW->setObjectName(QStringLiteral("friendListW"));

        verticalLayout->addWidget(friendListW);


        gridLayout_4->addLayout(verticalLayout, 4, 0, 2, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        notificationListLabel = new QLabel(centralWidget);
        notificationListLabel->setObjectName(QStringLiteral("notificationListLabel"));
        notificationListLabel->setEnabled(false);
        QFont font3;
        font3.setFamily(QStringLiteral("MS UI Gothic"));
        font3.setPointSize(20);
        notificationListLabel->setFont(font3);

        verticalLayout_2->addWidget(notificationListLabel);

        notificationListWidget = new QListWidget(centralWidget);
        notificationListWidget->setObjectName(QStringLiteral("notificationListWidget"));
        notificationListWidget->setEnabled(false);
        notificationListWidget->setMaximumSize(QSize(200, 16777215));

        verticalLayout_2->addWidget(notificationListWidget);


        gridLayout_4->addLayout(verticalLayout_2, 4, 1, 2, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 6, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        activeFriendCallPushButton = new QPushButton(centralWidget);
        activeFriendCallPushButton->setObjectName(QStringLiteral("activeFriendCallPushButton"));

        gridLayout->addWidget(activeFriendCallPushButton, 1, 1, 1, 1);

        selectedFriendNameLabel = new QLabel(centralWidget);
        selectedFriendNameLabel->setObjectName(QStringLiteral("selectedFriendNameLabel"));
        selectedFriendNameLabel->setEnabled(true);
        selectedFriendNameLabel->setFont(font1);
        selectedFriendNameLabel->setAutoFillBackground(false);

        gridLayout->addWidget(selectedFriendNameLabel, 0, 0, 1, 1);

        selectedFriendPersonalMsgLabel = new QLabel(centralWidget);
        selectedFriendPersonalMsgLabel->setObjectName(QStringLiteral("selectedFriendPersonalMsgLabel"));
        selectedFriendPersonalMsgLabel->setFont(font);

        gridLayout->addWidget(selectedFriendPersonalMsgLabel, 1, 0, 1, 1);

        selectedFriendIconStatusLabel = new QLabel(centralWidget);
        selectedFriendIconStatusLabel->setObjectName(QStringLiteral("selectedFriendIconStatusLabel"));
        selectedFriendIconStatusLabel->setFont(font1);

        gridLayout->addWidget(selectedFriendIconStatusLabel, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 2, 0, 1, 2);


        verticalLayout_3->addLayout(gridLayout);


        gridLayout_4->addLayout(verticalLayout_3, 2, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        sendBoxTextEdit = new QLineEdit(centralWidget);
        sendBoxTextEdit->setObjectName(QStringLiteral("sendBoxTextEdit"));

        horizontalLayout->addWidget(sendBoxTextEdit);

        sendBoxPushButton = new QPushButton(centralWidget);
        sendBoxPushButton->setObjectName(QStringLiteral("sendBoxPushButton"));

        horizontalLayout->addWidget(sendBoxPushButton);


        gridLayout_4->addLayout(horizontalLayout, 5, 3, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_2, 2, 0, 1, 5);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(false);

        gridLayout_3->addWidget(pushButton, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(false);

        gridLayout_3->addWidget(pushButton_2, 1, 2, 1, 1);

        deleteSelectedFriendPushButton = new QPushButton(centralWidget);
        deleteSelectedFriendPushButton->setObjectName(QStringLiteral("deleteSelectedFriendPushButton"));
        deleteSelectedFriendPushButton->setEnabled(true);

        gridLayout_3->addWidget(deleteSelectedFriendPushButton, 1, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 1, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_3, 0, 0, 1, 5);


        gridLayout_4->addLayout(gridLayout_3, 3, 0, 1, 2);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 824, 21));
        menuVBabel = new QMenu(menuBar);
        menuVBabel->setObjectName(QStringLiteral("menuVBabel"));
        menuConnection = new QMenu(menuBar);
        menuConnection->setObjectName(QStringLiteral("menuConnection"));
        menuManage_account = new QMenu(menuBar);
        menuManage_account->setObjectName(QStringLiteral("menuManage_account"));
        MainWindowClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuVBabel->menuAction());
        menuBar->addAction(menuConnection->menuAction());
        menuBar->addAction(menuManage_account->menuAction());
        menuConnection->addAction(actionConnect);
        menuConnection->addAction(actionLogin);
        menuManage_account->addAction(actionCreate_account);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0));
        actionConnect->setText(QApplication::translate("MainWindowClass", "Connect", 0));
        actionCreate_account->setText(QApplication::translate("MainWindowClass", "Create account", 0));
        actionLogin->setText(QApplication::translate("MainWindowClass", "Login", 0));
        label_2->setText(QApplication::translate("MainWindowClass", "User Personal Message................", 0));
        label_3->setText(QApplication::translate("MainWindowClass", "User", 0));
        label_4->setText(QApplication::translate("MainWindowClass", "Icon", 0));
        friendListLabel->setText(QApplication::translate("MainWindowClass", "Friends", 0));
        notificationListLabel->setText(QApplication::translate("MainWindowClass", "Notifications", 0));
        activeFriendCallPushButton->setText(QApplication::translate("MainWindowClass", "Call", 0));
        selectedFriendNameLabel->setText(QApplication::translate("MainWindowClass", "Selected Friend", 0));
        selectedFriendPersonalMsgLabel->setText(QApplication::translate("MainWindowClass", "Selected Friend Personal Message", 0));
        selectedFriendIconStatusLabel->setText(QApplication::translate("MainWindowClass", "Icon", 0));
        sendBoxPushButton->setText(QApplication::translate("MainWindowClass", "Send", 0));
        pushButton->setText(QApplication::translate("MainWindowClass", "Call", 0));
        pushButton_2->setText(QApplication::translate("MainWindowClass", "Add", 0));
        deleteSelectedFriendPushButton->setText(QApplication::translate("MainWindowClass", "Delete", 0));
        menuVBabel->setTitle(QApplication::translate("MainWindowClass", "VBabel", 0));
        menuConnection->setTitle(QApplication::translate("MainWindowClass", "Connection", 0));
        menuManage_account->setTitle(QApplication::translate("MainWindowClass", "Manage account", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
