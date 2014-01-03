/********************************************************************************
** Form generated from reading UI file 'Graphic.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHIC_H
#define UI_GRAPHIC_H

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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "FriendListWidget.h"

QT_BEGIN_NAMESPACE

class Ui_GraphicClass
{
public:
    QAction *actionConnect;
    QAction *actionCreateAccount;
    QAction *actionLogin;
    QAction *actionExit;
    QAction *actionSetAnswer;
    QAction *actionUnSetAnswer;
    QAction *actionCall;
    QAction *actionDeleteAccount;
    QAction *actionAddFriend;
    QAction *actionDelete_friend;
    QAction *actionLogout;
    QAction *actionAccountOptions;
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QComboBox *statusComboBox;
    QLabel *label_4;
    QLineEdit *statusLineEdit;
    QLabel *label_3;
    QGridLayout *gridLayout_6;
    QTabWidget *FriendTabWidget;
    QWidget *Friends;
    QGridLayout *gridLayout_9;
    FriendListWidget *listWidget;
    QWidget *Nothing;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_3;
    QFrame *line_2;
    QPushButton *callFriendLeftPushButton;
    QPushButton *addFriendPushButton;
    QPushButton *deleteFriendPushButton;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QFrame *line_3;
    QFrame *line;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *selectedFriendNameLabel;
    QLabel *selectedFriendPersonalMsgLabel;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line_4;
    QPushButton *hangUpPushButton;
    QPushButton *callFriendRightPushButton;
    QLabel *selectedFriendIconStatusLabel;
    QHBoxLayout *horizontalLayout_2;
    QTextBrowser *friendMsgBox;
    QHBoxLayout *horizontalLayout;
    QLineEdit *sendBoxTextEdit;
    QPushButton *sendBoxPushButton;
    QMenuBar *menuBar;
    QMenu *menuVBabel;
    QMenu *menuConnection;
    QMenu *menuManage_account;
    QMenu *menuVoicemail;
    QMenu *menuFriends_list;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GraphicClass)
    {
        if (GraphicClass->objectName().isEmpty())
            GraphicClass->setObjectName(QStringLiteral("GraphicClass"));
        GraphicClass->resize(670, 389);
        actionConnect = new QAction(GraphicClass);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionCreateAccount = new QAction(GraphicClass);
        actionCreateAccount->setObjectName(QStringLiteral("actionCreateAccount"));
        actionCreateAccount->setEnabled(false);
        actionLogin = new QAction(GraphicClass);
        actionLogin->setObjectName(QStringLiteral("actionLogin"));
        actionLogin->setEnabled(false);
        actionExit = new QAction(GraphicClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionSetAnswer = new QAction(GraphicClass);
        actionSetAnswer->setObjectName(QStringLiteral("actionSetAnswer"));
        actionSetAnswer->setEnabled(true);
        actionUnSetAnswer = new QAction(GraphicClass);
        actionUnSetAnswer->setObjectName(QStringLiteral("actionUnSetAnswer"));
        actionUnSetAnswer->setEnabled(true);
        actionCall = new QAction(GraphicClass);
        actionCall->setObjectName(QStringLiteral("actionCall"));
        actionCall->setEnabled(false);
        actionDeleteAccount = new QAction(GraphicClass);
        actionDeleteAccount->setObjectName(QStringLiteral("actionDeleteAccount"));
        actionDeleteAccount->setEnabled(false);
        actionAddFriend = new QAction(GraphicClass);
        actionAddFriend->setObjectName(QStringLiteral("actionAddFriend"));
        actionAddFriend->setEnabled(true);
        actionDelete_friend = new QAction(GraphicClass);
        actionDelete_friend->setObjectName(QStringLiteral("actionDelete_friend"));
        actionDelete_friend->setEnabled(false);
        actionLogout = new QAction(GraphicClass);
        actionLogout->setObjectName(QStringLiteral("actionLogout"));
        actionLogout->setEnabled(false);
        actionAccountOptions = new QAction(GraphicClass);
        actionAccountOptions->setObjectName(QStringLiteral("actionAccountOptions"));
        actionAccountOptions->setEnabled(false);
        centralWidget = new QWidget(GraphicClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setChildrenCollapsible(false);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        gridLayout_5 = new QGridLayout(layoutWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 3, 1, 1);

        statusComboBox = new QComboBox(layoutWidget);
        statusComboBox->setObjectName(QStringLiteral("statusComboBox"));
        statusComboBox->setEnabled(true);

        gridLayout_2->addWidget(statusComboBox, 1, 2, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setEnabled(true);
        QFont font;
        font.setPointSize(14);
        label_4->setFont(font);

        gridLayout_2->addWidget(label_4, 0, 2, 1, 1);

        statusLineEdit = new QLineEdit(layoutWidget);
        statusLineEdit->setObjectName(QStringLiteral("statusLineEdit"));

        gridLayout_2->addWidget(statusLineEdit, 1, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font);

        gridLayout_2->addWidget(label_3, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        FriendTabWidget = new QTabWidget(layoutWidget);
        FriendTabWidget->setObjectName(QStringLiteral("FriendTabWidget"));
        Friends = new QWidget();
        Friends->setObjectName(QStringLiteral("Friends"));
        gridLayout_9 = new QGridLayout(Friends);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        listWidget = new FriendListWidget(Friends);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout_9->addWidget(listWidget, 0, 0, 1, 2);

        FriendTabWidget->addTab(Friends, QString());
        Nothing = new QWidget();
        Nothing->setObjectName(QStringLiteral("Nothing"));
        FriendTabWidget->addTab(Nothing, QString());

        gridLayout_6->addWidget(FriendTabWidget, 0, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_6, 2, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));

        gridLayout_5->addLayout(verticalLayout_2, 3, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_2, 2, 0, 1, 5);

        callFriendLeftPushButton = new QPushButton(layoutWidget);
        callFriendLeftPushButton->setObjectName(QStringLiteral("callFriendLeftPushButton"));
        callFriendLeftPushButton->setEnabled(true);

        gridLayout_3->addWidget(callFriendLeftPushButton, 1, 1, 1, 1);

        addFriendPushButton = new QPushButton(layoutWidget);
        addFriendPushButton->setObjectName(QStringLiteral("addFriendPushButton"));
        addFriendPushButton->setEnabled(true);

        gridLayout_3->addWidget(addFriendPushButton, 1, 2, 1, 1);

        deleteFriendPushButton = new QPushButton(layoutWidget);
        deleteFriendPushButton->setObjectName(QStringLiteral("deleteFriendPushButton"));
        deleteFriendPushButton->setEnabled(true);

        gridLayout_3->addWidget(deleteFriendPushButton, 1, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 1, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        line_3 = new QFrame(layoutWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_3, 0, 0, 1, 5);


        gridLayout_5->addLayout(gridLayout_3, 1, 0, 1, 1);

        line = new QFrame(layoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line, 0, 1, 4, 1);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        selectedFriendNameLabel = new QLabel(layoutWidget1);
        selectedFriendNameLabel->setObjectName(QStringLiteral("selectedFriendNameLabel"));
        selectedFriendNameLabel->setEnabled(true);
        sizePolicy.setHeightForWidth(selectedFriendNameLabel->sizePolicy().hasHeightForWidth());
        selectedFriendNameLabel->setSizePolicy(sizePolicy);
        selectedFriendNameLabel->setFont(font);
        selectedFriendNameLabel->setAutoFillBackground(false);

        gridLayout->addWidget(selectedFriendNameLabel, 0, 0, 1, 1);

        selectedFriendPersonalMsgLabel = new QLabel(layoutWidget1);
        selectedFriendPersonalMsgLabel->setObjectName(QStringLiteral("selectedFriendPersonalMsgLabel"));
        QFont font1;
        font1.setFamily(QStringLiteral("MS PGothic"));
        font1.setPointSize(10);
        selectedFriendPersonalMsgLabel->setFont(font1);

        gridLayout->addWidget(selectedFriendPersonalMsgLabel, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        line_4 = new QFrame(layoutWidget1);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 2, 0, 1, 5);

        hangUpPushButton = new QPushButton(layoutWidget1);
        hangUpPushButton->setObjectName(QStringLiteral("hangUpPushButton"));

        gridLayout->addWidget(hangUpPushButton, 1, 2, 1, 1);

        callFriendRightPushButton = new QPushButton(layoutWidget1);
        callFriendRightPushButton->setObjectName(QStringLiteral("callFriendRightPushButton"));

        gridLayout->addWidget(callFriendRightPushButton, 1, 1, 1, 1);

        selectedFriendIconStatusLabel = new QLabel(layoutWidget1);
        selectedFriendIconStatusLabel->setObjectName(QStringLiteral("selectedFriendIconStatusLabel"));
        selectedFriendIconStatusLabel->setFont(font);

        gridLayout->addWidget(selectedFriendIconStatusLabel, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        friendMsgBox = new QTextBrowser(layoutWidget1);
        friendMsgBox->setObjectName(QStringLiteral("friendMsgBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(3);
        sizePolicy1.setHeightForWidth(friendMsgBox->sizePolicy().hasHeightForWidth());
        friendMsgBox->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(friendMsgBox);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        sendBoxTextEdit = new QLineEdit(layoutWidget1);
        sendBoxTextEdit->setObjectName(QStringLiteral("sendBoxTextEdit"));

        horizontalLayout->addWidget(sendBoxTextEdit);

        sendBoxPushButton = new QPushButton(layoutWidget1);
        sendBoxPushButton->setObjectName(QStringLiteral("sendBoxPushButton"));

        horizontalLayout->addWidget(sendBoxPushButton);


        verticalLayout_4->addLayout(horizontalLayout);

        splitter->addWidget(layoutWidget1);

        gridLayout_4->addWidget(splitter, 0, 0, 1, 1);

        GraphicClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GraphicClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 670, 21));
        menuVBabel = new QMenu(menuBar);
        menuVBabel->setObjectName(QStringLiteral("menuVBabel"));
        menuConnection = new QMenu(menuBar);
        menuConnection->setObjectName(QStringLiteral("menuConnection"));
        menuManage_account = new QMenu(menuBar);
        menuManage_account->setObjectName(QStringLiteral("menuManage_account"));
        menuVoicemail = new QMenu(menuBar);
        menuVoicemail->setObjectName(QStringLiteral("menuVoicemail"));
        menuFriends_list = new QMenu(menuBar);
        menuFriends_list->setObjectName(QStringLiteral("menuFriends_list"));
        menuFriends_list->setEnabled(true);
        GraphicClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(GraphicClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GraphicClass->setStatusBar(statusBar);

        menuBar->addAction(menuVBabel->menuAction());
        menuBar->addAction(menuConnection->menuAction());
        menuBar->addAction(menuManage_account->menuAction());
        menuBar->addAction(menuFriends_list->menuAction());
        menuBar->addAction(menuVoicemail->menuAction());
        menuVBabel->addAction(actionExit);
        menuConnection->addAction(actionConnect);
        menuConnection->addAction(actionLogin);
        menuConnection->addAction(actionLogout);
        menuManage_account->addAction(actionCreateAccount);
        menuManage_account->addAction(actionDeleteAccount);
        menuManage_account->addAction(actionAccountOptions);
        menuVoicemail->addAction(actionSetAnswer);
        menuVoicemail->addAction(actionUnSetAnswer);
        menuFriends_list->addAction(actionAddFriend);

        retranslateUi(GraphicClass);

        FriendTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GraphicClass);
    } // setupUi

    void retranslateUi(QMainWindow *GraphicClass)
    {
        GraphicClass->setWindowTitle(QApplication::translate("GraphicClass", "MainWindow", 0));
        actionConnect->setText(QApplication::translate("GraphicClass", "Connect", 0));
        actionCreateAccount->setText(QApplication::translate("GraphicClass", "Create account", 0));
        actionLogin->setText(QApplication::translate("GraphicClass", "Log in", 0));
        actionExit->setText(QApplication::translate("GraphicClass", "Exit", 0));
        actionSetAnswer->setText(QApplication::translate("GraphicClass", "Set voicemail", 0));
        actionUnSetAnswer->setText(QApplication::translate("GraphicClass", "Unset voicemail", 0));
        actionCall->setText(QApplication::translate("GraphicClass", "Call", 0));
        actionDeleteAccount->setText(QApplication::translate("GraphicClass", "Delete account", 0));
        actionAddFriend->setText(QApplication::translate("GraphicClass", "Add friend", 0));
        actionDelete_friend->setText(QApplication::translate("GraphicClass", "Delete friend", 0));
        actionLogout->setText(QApplication::translate("GraphicClass", "Log out", 0));
        actionAccountOptions->setText(QApplication::translate("GraphicClass", "Account options", 0));
        label_4->setText(QApplication::translate("GraphicClass", "Icon", 0));
        statusLineEdit->setText(QApplication::translate("GraphicClass", "Status here", 0));
        label_3->setText(QApplication::translate("GraphicClass", "User", 0));
        FriendTabWidget->setTabText(FriendTabWidget->indexOf(Friends), QApplication::translate("GraphicClass", "Friends", 0));
        FriendTabWidget->setTabText(FriendTabWidget->indexOf(Nothing), QApplication::translate("GraphicClass", "Nothing", 0));
        callFriendLeftPushButton->setText(QApplication::translate("GraphicClass", "Call", 0));
        addFriendPushButton->setText(QApplication::translate("GraphicClass", "Add", 0));
        deleteFriendPushButton->setText(QApplication::translate("GraphicClass", "Delete", 0));
        selectedFriendNameLabel->setText(QApplication::translate("GraphicClass", "Selected Friend", 0));
        selectedFriendPersonalMsgLabel->setText(QApplication::translate("GraphicClass", "Selected Friend Personal Message", 0));
        hangUpPushButton->setText(QApplication::translate("GraphicClass", "Hang Up", 0));
        callFriendRightPushButton->setText(QApplication::translate("GraphicClass", "Call", 0));
        selectedFriendIconStatusLabel->setText(QApplication::translate("GraphicClass", "Icon", 0));
        sendBoxPushButton->setText(QApplication::translate("GraphicClass", "Send", 0));
        menuVBabel->setTitle(QApplication::translate("GraphicClass", "VBabel", 0));
        menuConnection->setTitle(QApplication::translate("GraphicClass", "Connection", 0));
        menuManage_account->setTitle(QApplication::translate("GraphicClass", "Manage account", 0));
        menuVoicemail->setTitle(QApplication::translate("GraphicClass", "Voicemail", 0));
        menuFriends_list->setTitle(QApplication::translate("GraphicClass", "Friends list", 0));
    } // retranslateUi

};

namespace Ui {
    class GraphicClass: public Ui_GraphicClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHIC_H
