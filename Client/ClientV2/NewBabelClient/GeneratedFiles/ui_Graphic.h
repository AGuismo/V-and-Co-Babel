/********************************************************************************
** Form generated from reading UI file 'Graphic.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <friendlistwidget.h>

QT_BEGIN_NAMESPACE

class Ui_GraphicClass
{
public:
    QAction *actionConnect;
    QAction *actionCreateAccount;
    QAction *actionLogin;
    QAction *actionExit;
    QAction *actionSetVoicemail;
    QAction *actionUnsetVoicemail;
    QAction *actionCall;
    QAction *actionDeleteAccount;
    QAction *actionAddFriend;
    QAction *actionDeleteFriend;
    QAction *actionLogout;
    QAction *actionAccountOptions;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QWidget *widget;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_47;
    QGridLayout *gridLayout_49;
    QFrame *line_33;
    QSpacerItem *horizontalSpacer_35;
    QPushButton *callFriendLeftPushButton;
    QPushButton *addFriendPushButton;
    QPushButton *deleteFriendPushButton;
    QSpacerItem *horizontalSpacer_36;
    QFrame *line_34;
    QGridLayout *gridLayout_50;
    QSpacerItem *horizontalSpacer_2;
    FriendListWidget *friendListWidget;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout_48;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *userNameLabel;
    QComboBox *statusComboBox;
    QSpacerItem *horizontalSpacer_34;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *statusLineEdit;
    QSpacerItem *horizontalSpacer_5;
    QWidget *layoutWidget_15;
    QVBoxLayout *verticalLayout_24;
    QVBoxLayout *verticalLayout_25;
    QGridLayout *gridLayout_51;
    QVBoxLayout *verticalLayout_26;
    QGridLayout *gridLayout_52;
    QLabel *selectedFriendNameLabel;
    QLabel *selectedFriendIconStatusLabel;
    QSpacerItem *horizontalSpacer_37;
    QGridLayout *gridLayout_9;
    QSpacerItem *horizontalSpacer_38;
    QPushButton *callFriendRightPushButton;
    QLabel *selectedFriendPersonalMsgLabel;
    QPushButton *hangUpPushButton;
    QFrame *line_35;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_2;
    QLabel *callLabel;
    QTextBrowser *friendMsgBox;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *sendBoxTextEdit;
    QPushButton *sendBoxPushButton;
    QSpacerItem *horizontalSpacer_7;
    QMenuBar *menuBar;
    QMenu *menuConnection;
    QMenu *menuManage_account;
    QMenu *menuVoicemail;
    QMenu *menuFriends_list;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GraphicClass)
    {
        if (GraphicClass->objectName().isEmpty())
            GraphicClass->setObjectName(QStringLiteral("GraphicClass"));
        GraphicClass->resize(860, 542);
        GraphicClass->setStyleSheet(QLatin1String("QMainWindow \n"
"{\n"
"	border-image: url(./Img/main-background.jpg);\n"
"}\n"
"\n"
"QStatusBar\n"
"{\n"
"	background-color: rgba(156, 156, 156, 200);\n"
"	border-width: 2px;\n"
"	border-radius: 8px;\n"
"	border-color: rgb(0, 0, 0);\n"
"	min-width: 10em;\n"
"	padding: 2px;\n"
"}\n"
"\n"
"QMenuBar\n"
"{\n"
"     background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 lightgray, stop:1 darkgray);\n"
"}\n"
"\n"
"QMenuBar::item\n"
"{\n"
"     spacing: 3px; /* spacing between menu bar items */\n"
"     padding: 1px 4px;\n"
"     background: transparent;\n"
"     border-radius: 4px;\n"
"}\n"
"\n"
"QMenuBar::item:selected\n"
"{ /* when selected using mouse or keyboard */\n"
"	background: #a8a8a8;\n"
"}\n"
"\n"
"QMenuBar::item:pressed\n"
"{\n"
"	background: #888888;\n"
"}"));
        GraphicClass->setTabShape(QTabWidget::Rounded);
        actionConnect = new QAction(GraphicClass);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        QFont font;
        font.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font.setBold(false);
        font.setWeight(50);
        actionConnect->setFont(font);
        actionCreateAccount = new QAction(GraphicClass);
        actionCreateAccount->setObjectName(QStringLiteral("actionCreateAccount"));
        actionCreateAccount->setEnabled(true);
        QFont font1;
        font1.setFamily(QStringLiteral("MS Reference Sans Serif"));
        actionCreateAccount->setFont(font1);
        actionLogin = new QAction(GraphicClass);
        actionLogin->setObjectName(QStringLiteral("actionLogin"));
        actionLogin->setEnabled(true);
        actionLogin->setFont(font1);
        actionExit = new QAction(GraphicClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionExit->setFont(font1);
        actionSetVoicemail = new QAction(GraphicClass);
        actionSetVoicemail->setObjectName(QStringLiteral("actionSetVoicemail"));
        actionSetVoicemail->setEnabled(false);
        actionSetVoicemail->setFont(font1);
        actionUnsetVoicemail = new QAction(GraphicClass);
        actionUnsetVoicemail->setObjectName(QStringLiteral("actionUnsetVoicemail"));
        actionUnsetVoicemail->setEnabled(false);
        actionUnsetVoicemail->setFont(font1);
        actionCall = new QAction(GraphicClass);
        actionCall->setObjectName(QStringLiteral("actionCall"));
        actionCall->setEnabled(false);
        actionCall->setFont(font1);
        actionDeleteAccount = new QAction(GraphicClass);
        actionDeleteAccount->setObjectName(QStringLiteral("actionDeleteAccount"));
        actionDeleteAccount->setEnabled(true);
        actionDeleteAccount->setFont(font1);
        actionAddFriend = new QAction(GraphicClass);
        actionAddFriend->setObjectName(QStringLiteral("actionAddFriend"));
        actionAddFriend->setEnabled(true);
        actionAddFriend->setFont(font1);
        actionDeleteFriend = new QAction(GraphicClass);
        actionDeleteFriend->setObjectName(QStringLiteral("actionDeleteFriend"));
        actionDeleteFriend->setEnabled(true);
        actionDeleteFriend->setFont(font1);
        actionLogout = new QAction(GraphicClass);
        actionLogout->setObjectName(QStringLiteral("actionLogout"));
        actionLogout->setEnabled(false);
        actionLogout->setFont(font1);
        actionAccountOptions = new QAction(GraphicClass);
        actionAccountOptions->setObjectName(QStringLiteral("actionAccountOptions"));
        actionAccountOptions->setEnabled(true);
        actionAccountOptions->setFont(font1);
        centralWidget = new QWidget(GraphicClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("QMenuBar\n"
"{\n"
"     background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 lightgray, stop:1 darkgray);\n"
"}\n"
"\n"
"QMenuBar::item\n"
"{\n"
"     spacing: 3px; /* spacing between menu bar items */\n"
"     padding: 1px 4px;\n"
"     background: transparent;\n"
"     border-radius: 4px;\n"
"}\n"
"\n"
"QMenuBar::item:selected\n"
"{ /* when selected using mouse or keyboard */\n"
"	background: #a8a8a8;\n"
"}\n"
"\n"
"QMenuBar::item:pressed\n"
"{\n"
"	background: #888888;\n"
"}"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setMaximumSize(QSize(16777215, 16777215));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setChildrenCollapsible(false);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(542, 16777215));
        gridLayout_7 = new QGridLayout(widget);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_47 = new QGridLayout();
        gridLayout_47->setSpacing(6);
        gridLayout_47->setObjectName(QStringLiteral("gridLayout_47"));
        gridLayout_47->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_49 = new QGridLayout();
        gridLayout_49->setSpacing(6);
        gridLayout_49->setObjectName(QStringLiteral("gridLayout_49"));
        line_33 = new QFrame(widget);
        line_33->setObjectName(QStringLiteral("line_33"));
        line_33->setFrameShape(QFrame::HLine);
        line_33->setFrameShadow(QFrame::Sunken);

        gridLayout_49->addWidget(line_33, 0, 0, 1, 5);

        horizontalSpacer_35 = new QSpacerItem(35, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_49->addItem(horizontalSpacer_35, 1, 0, 1, 1);

        callFriendLeftPushButton = new QPushButton(widget);
        callFriendLeftPushButton->setObjectName(QStringLiteral("callFriendLeftPushButton"));
        callFriendLeftPushButton->setEnabled(true);
        callFriendLeftPushButton->setFont(font1);
        callFriendLeftPushButton->setStyleSheet(QLatin1String("QPushButton#callFriendLeftPushButton\n"
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
"QPushButton#callFriendLeftPushButton:hover\n"
"{\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 148, 255, 255), stop:1 rgba(0, 8, 84, 255));\n"
"	border-style: inset;\n"
"}\n"
"\n"
"QPushButton#callFriendLeftPushButton:pressed \n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 56, 183, 255), stop:1 rgba(135, 172, 255, 255));\n"
"     border-style: inset;\n"
"}"));

        gridLayout_49->addWidget(callFriendLeftPushButton, 1, 1, 1, 1);

        addFriendPushButton = new QPushButton(widget);
        addFriendPushButton->setObjectName(QStringLiteral("addFriendPushButton"));
        addFriendPushButton->setEnabled(true);
        addFriendPushButton->setFont(font1);
        addFriendPushButton->setStyleSheet(QLatin1String("QPushButton#addFriendPushButton\n"
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
"QPushButton#addFriendPushButton:hover\n"
"{\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 148, 255, 255), stop:1 rgba(0, 8, 84, 255));\n"
"	border-style: inset;\n"
"}\n"
"\n"
"QPushButton#addFriendPushButton:pressed \n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 56, 183, 255), stop:1 rgba(135, 172, 255, 255));\n"
"     border-style: inset;\n"
" }"));

        gridLayout_49->addWidget(addFriendPushButton, 1, 2, 1, 1);

        deleteFriendPushButton = new QPushButton(widget);
        deleteFriendPushButton->setObjectName(QStringLiteral("deleteFriendPushButton"));
        deleteFriendPushButton->setEnabled(true);
        deleteFriendPushButton->setFont(font1);
        deleteFriendPushButton->setStyleSheet(QLatin1String("QPushButton#deleteFriendPushButton\n"
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
"QPushButton#deleteFriendPushButton:hover\n"
"{\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 148, 255, 255), stop:1 rgba(0, 8, 84, 255));\n"
"	border-style: inset;\n"
"}\n"
"\n"
"QPushButton#deleteFriendPushButton:pressed \n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 56, 183, 255), stop:1 rgba(135, 172, 255, 255));\n"
"     border-style: inset;\n"
" }"));

        gridLayout_49->addWidget(deleteFriendPushButton, 1, 3, 1, 1);

        horizontalSpacer_36 = new QSpacerItem(36, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_49->addItem(horizontalSpacer_36, 1, 4, 1, 1);

        line_34 = new QFrame(widget);
        line_34->setObjectName(QStringLiteral("line_34"));
        line_34->setFrameShape(QFrame::HLine);
        line_34->setFrameShadow(QFrame::Sunken);

        gridLayout_49->addWidget(line_34, 2, 0, 1, 5);


        gridLayout_47->addLayout(gridLayout_49, 1, 0, 1, 1);

        gridLayout_50 = new QGridLayout();
        gridLayout_50->setSpacing(6);
        gridLayout_50->setObjectName(QStringLiteral("gridLayout_50"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_50->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        friendListWidget = new FriendListWidget(widget);
        friendListWidget->setObjectName(QStringLiteral("friendListWidget"));
        friendListWidget->setMaximumSize(QSize(260, 16777215));
        friendListWidget->setFont(font);
        friendListWidget->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 200);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"min-width: 10em;\n"
"padding: 2px;"));
        friendListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        friendListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout_50->addWidget(friendListWidget, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_50->addItem(horizontalSpacer_3, 0, 0, 1, 1);


        gridLayout_47->addLayout(gridLayout_50, 2, 0, 1, 1);

        gridLayout_48 = new QGridLayout();
        gridLayout_48->setSpacing(6);
        gridLayout_48->setObjectName(QStringLiteral("gridLayout_48"));
        gridLayout_48->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        userNameLabel = new QLabel(widget);
        userNameLabel->setObjectName(QStringLiteral("userNameLabel"));
        userNameLabel->setEnabled(true);
        QFont font2;
        font2.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        userNameLabel->setFont(font2);
        userNameLabel->setStyleSheet(QLatin1String("background-color: rgba(190, 190, 190, 200);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"padding: 2px;"));

        horizontalLayout_6->addWidget(userNameLabel);

        statusComboBox = new QComboBox(widget);
        statusComboBox->setObjectName(QStringLiteral("statusComboBox"));
        statusComboBox->setEnabled(true);
        statusComboBox->setMinimumSize(QSize(110, 0));
        statusComboBox->setFont(font1);
        statusComboBox->setStyleSheet(QLatin1String("QComboBox#statusComboBox\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(0, 24, 185, 255), stop:1 rgba(163, 175, 255, 255));\n"
"	border-style: outset;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	border-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QComboBox#statusComboBox:hover\n"
"{\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 148, 255, 255), stop:1 rgba(0, 8, 84, 255));\n"
"	border-style: inset;\n"
"}\n"
"\n"
"QComboBox#statusComboBox:pressed \n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 56, 183, 255), stop:1 rgba(135, 172, 255, 255));\n"
"     border-style: inset;\n"
" }\n"
"\n"
"QComboBox::drop-down\n"
"{\n"
"	border-width: 0px;\n"
"}\n"
"QComboBox::down-arrow \n"
"{\n"
"	image: url(noimg);\n"
"	border-width: 0px;\n"
"}"));

        horizontalLayout_6->addWidget(statusComboBox);

        horizontalSpacer_34 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_34);


        gridLayout_8->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        statusLineEdit = new QLineEdit(widget);
        statusLineEdit->setObjectName(QStringLiteral("statusLineEdit"));
        statusLineEdit->setEnabled(true);
        statusLineEdit->setMaximumSize(QSize(400, 16777215));
        QFont font3;
        font3.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        statusLineEdit->setFont(font3);
        statusLineEdit->setStyleSheet(QLatin1String("background-color: rgba(190, 190, 190, 200);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"padding: 2px;"));
        statusLineEdit->setMaxLength(86);

        horizontalLayout_7->addWidget(statusLineEdit);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);


        gridLayout_8->addLayout(horizontalLayout_7, 1, 0, 1, 1);


        gridLayout_48->addLayout(gridLayout_8, 0, 0, 1, 1);


        gridLayout_47->addLayout(gridLayout_48, 0, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_47, 0, 0, 1, 1);

        splitter->addWidget(widget);
        layoutWidget_15 = new QWidget(splitter);
        layoutWidget_15->setObjectName(QStringLiteral("layoutWidget_15"));
        verticalLayout_24 = new QVBoxLayout(layoutWidget_15);
        verticalLayout_24->setSpacing(6);
        verticalLayout_24->setContentsMargins(11, 11, 11, 11);
        verticalLayout_24->setObjectName(QStringLiteral("verticalLayout_24"));
        verticalLayout_24->setContentsMargins(0, 0, 0, 0);
        verticalLayout_25 = new QVBoxLayout();
        verticalLayout_25->setSpacing(6);
        verticalLayout_25->setObjectName(QStringLiteral("verticalLayout_25"));
        gridLayout_51 = new QGridLayout();
        gridLayout_51->setSpacing(6);
        gridLayout_51->setObjectName(QStringLiteral("gridLayout_51"));
        verticalLayout_26 = new QVBoxLayout();
        verticalLayout_26->setSpacing(6);
        verticalLayout_26->setObjectName(QStringLiteral("verticalLayout_26"));
        gridLayout_52 = new QGridLayout();
        gridLayout_52->setSpacing(6);
        gridLayout_52->setObjectName(QStringLiteral("gridLayout_52"));
        selectedFriendNameLabel = new QLabel(layoutWidget_15);
        selectedFriendNameLabel->setObjectName(QStringLiteral("selectedFriendNameLabel"));
        selectedFriendNameLabel->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(selectedFriendNameLabel->sizePolicy().hasHeightForWidth());
        selectedFriendNameLabel->setSizePolicy(sizePolicy);
        selectedFriendNameLabel->setFont(font2);
        selectedFriendNameLabel->setLayoutDirection(Qt::LeftToRight);
        selectedFriendNameLabel->setAutoFillBackground(false);
        selectedFriendNameLabel->setStyleSheet(QLatin1String("background-color: rgba(190, 190, 190, 200);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"min-width: 10em;\n"
"padding: 2px;"));

        gridLayout_52->addWidget(selectedFriendNameLabel, 0, 0, 1, 1);

        selectedFriendIconStatusLabel = new QLabel(layoutWidget_15);
        selectedFriendIconStatusLabel->setObjectName(QStringLiteral("selectedFriendIconStatusLabel"));
        selectedFriendIconStatusLabel->setMaximumSize(QSize(300, 55));
        QFont font4;
        font4.setPointSize(14);
        selectedFriendIconStatusLabel->setFont(font4);
        selectedFriendIconStatusLabel->setStyleSheet(QStringLiteral(""));

        gridLayout_52->addWidget(selectedFriendIconStatusLabel, 0, 1, 1, 1);

        horizontalSpacer_37 = new QSpacerItem(34, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_52->addItem(horizontalSpacer_37, 0, 2, 1, 1);


        verticalLayout_26->addLayout(gridLayout_52);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        horizontalSpacer_38 = new QSpacerItem(34, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_38, 0, 3, 1, 1);

        callFriendRightPushButton = new QPushButton(layoutWidget_15);
        callFriendRightPushButton->setObjectName(QStringLiteral("callFriendRightPushButton"));
        QFont font5;
        font5.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font5.setPointSize(8);
        callFriendRightPushButton->setFont(font5);
        callFriendRightPushButton->setStyleSheet(QLatin1String("QPushButton#callFriendRightPushButton\n"
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
"QPushButton#callFriendRightPushButton:hover\n"
"{\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 148, 255, 255), stop:1 rgba(0, 8, 84, 255));\n"
"	border-style: inset;\n"
"}\n"
"\n"
" QPushButton#callFriendRightPushButton:pressed \n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 56, 183, 255), stop:1 rgba(135, 172, 255, 255));\n"
"     border-style: inset;\n"
" }\n"
"\n"
""));

        gridLayout_9->addWidget(callFriendRightPushButton, 0, 1, 1, 1);

        selectedFriendPersonalMsgLabel = new QLabel(layoutWidget_15);
        selectedFriendPersonalMsgLabel->setObjectName(QStringLiteral("selectedFriendPersonalMsgLabel"));
        selectedFriendPersonalMsgLabel->setMinimumSize(QSize(134, 0));
        selectedFriendPersonalMsgLabel->setFont(font3);
        selectedFriendPersonalMsgLabel->setStyleSheet(QLatin1String("background-color: rgba(190, 190, 190, 200);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"min-width: 10em;\n"
"padding: 2px;"));

        gridLayout_9->addWidget(selectedFriendPersonalMsgLabel, 0, 0, 1, 1);

        hangUpPushButton = new QPushButton(layoutWidget_15);
        hangUpPushButton->setObjectName(QStringLiteral("hangUpPushButton"));
        hangUpPushButton->setEnabled(true);
        hangUpPushButton->setFont(font5);
        hangUpPushButton->setStyleSheet(QLatin1String("QPushButton#hangUpPushButton\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(0, 24, 185, 255), stop:1 rgba(163, 175, 255, 255));\n"
"	border-style: outset;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	border-color: rgb(255, 255, 255);\n"
"	min-width: 5em;\n"
"	padding: 6px;\n"
"}\n"
"\n"
"QPushButton#hangUpPushButton:hover\n"
"{\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 148, 255, 255), stop:1 rgba(0, 8, 84, 255));\n"
"	border-style: inset;\n"
"}\n"
"\n"
" QPushButton#hangUpPushButton:pressed \n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 56, 183, 255), stop:1 rgba(135, 172, 255, 255));\n"
"     border-style: inset;\n"
" }\n"
"\n"
""));

        gridLayout_9->addWidget(hangUpPushButton, 0, 2, 1, 1);


        verticalLayout_26->addLayout(gridLayout_9);


        gridLayout_51->addLayout(verticalLayout_26, 0, 0, 1, 1);


        verticalLayout_25->addLayout(gridLayout_51);


        verticalLayout_24->addLayout(verticalLayout_25);

        line_35 = new QFrame(layoutWidget_15);
        line_35->setObjectName(QStringLiteral("line_35"));
        line_35->setFrameShape(QFrame::HLine);
        line_35->setFrameShadow(QFrame::Sunken);

        verticalLayout_24->addWidget(line_35);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_6);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        callLabel = new QLabel(layoutWidget_15);
        callLabel->setObjectName(QStringLiteral("callLabel"));
        callLabel->setFont(font3);
        callLabel->setStyleSheet(QStringLiteral(""));
        callLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(callLabel);

        friendMsgBox = new QTextBrowser(layoutWidget_15);
        friendMsgBox->setObjectName(QStringLiteral("friendMsgBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(3);
        sizePolicy1.setHeightForWidth(friendMsgBox->sizePolicy().hasHeightForWidth());
        friendMsgBox->setSizePolicy(sizePolicy1);
        friendMsgBox->setMinimumSize(QSize(134, 0));
        friendMsgBox->setMaximumSize(QSize(800, 16777215));
        friendMsgBox->setSizeIncrement(QSize(3, 0));
        QFont font6;
        font6.setPointSize(10);
        friendMsgBox->setFont(font6);
        friendMsgBox->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 200);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"min-width: 10em;\n"
"padding: 2px;"));
        friendMsgBox->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        friendMsgBox->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_2->addWidget(friendMsgBox);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        sendBoxTextEdit = new QLineEdit(layoutWidget_15);
        sendBoxTextEdit->setObjectName(QStringLiteral("sendBoxTextEdit"));
        sendBoxTextEdit->setMaximumSize(QSize(700, 16777215));
        sendBoxTextEdit->setFont(font6);
        sendBoxTextEdit->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 230);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"min-width: 10em;\n"
"padding: 2px;"));
        sendBoxTextEdit->setMaxLength(256);

        horizontalLayout_8->addWidget(sendBoxTextEdit);

        sendBoxPushButton = new QPushButton(layoutWidget_15);
        sendBoxPushButton->setObjectName(QStringLiteral("sendBoxPushButton"));
        sendBoxPushButton->setFont(font1);
        sendBoxPushButton->setStyleSheet(QLatin1String("QPushButton#sendBoxPushButton\n"
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
"QPushButton#sendBoxPushButton:hover\n"
"{\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 148, 255, 255), stop:1 rgba(0, 8, 84, 255));\n"
"	border-style: inset;\n"
"}\n"
"\n"
" QPushButton#sendBoxPushButton:pressed \n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 56, 183, 255), stop:1 rgba(135, 172, 255, 255));\n"
"     border-style: inset;\n"
" }\n"
"\n"
""));

        horizontalLayout_8->addWidget(sendBoxPushButton);


        verticalLayout_2->addLayout(horizontalLayout_8);


        horizontalLayout_14->addLayout(verticalLayout_2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_7);


        verticalLayout_24->addLayout(horizontalLayout_14);

        splitter->addWidget(layoutWidget_15);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        GraphicClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GraphicClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 860, 18));
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

        menuBar->addAction(menuConnection->menuAction());
        menuBar->addAction(menuManage_account->menuAction());
        menuBar->addAction(menuFriends_list->menuAction());
        menuBar->addAction(menuVoicemail->menuAction());
        menuConnection->addAction(actionConnect);
        menuConnection->addAction(actionLogin);
        menuConnection->addAction(actionLogout);
        menuManage_account->addAction(actionCreateAccount);
        menuManage_account->addAction(actionDeleteAccount);
        menuManage_account->addAction(actionAccountOptions);
        menuVoicemail->addAction(actionSetVoicemail);
        menuVoicemail->addAction(actionUnsetVoicemail);
        menuFriends_list->addAction(actionAddFriend);
        menuFriends_list->addAction(actionDeleteFriend);

        retranslateUi(GraphicClass);

        QMetaObject::connectSlotsByName(GraphicClass);
    } // setupUi

    void retranslateUi(QMainWindow *GraphicClass)
    {
        GraphicClass->setWindowTitle(QApplication::translate("GraphicClass", "V & Co - Babel", 0));
        actionConnect->setText(QApplication::translate("GraphicClass", "Connect", 0));
        actionCreateAccount->setText(QApplication::translate("GraphicClass", "Create account", 0));
        actionLogin->setText(QApplication::translate("GraphicClass", "Log in", 0));
        actionExit->setText(QApplication::translate("GraphicClass", "Exit", 0));
        actionSetVoicemail->setText(QApplication::translate("GraphicClass", "Set voicemail", 0));
        actionUnsetVoicemail->setText(QApplication::translate("GraphicClass", "Unset voicemail", 0));
        actionCall->setText(QApplication::translate("GraphicClass", "Call", 0));
        actionDeleteAccount->setText(QApplication::translate("GraphicClass", "Delete account", 0));
        actionAddFriend->setText(QApplication::translate("GraphicClass", "Add friend", 0));
        actionDeleteFriend->setText(QApplication::translate("GraphicClass", "Delete friend", 0));
        actionLogout->setText(QApplication::translate("GraphicClass", "Log out", 0));
        actionAccountOptions->setText(QApplication::translate("GraphicClass", "Account options", 0));
        callFriendLeftPushButton->setText(QApplication::translate("GraphicClass", "Call", 0));
        addFriendPushButton->setText(QApplication::translate("GraphicClass", "Add", 0));
        deleteFriendPushButton->setText(QApplication::translate("GraphicClass", "Delete", 0));
        userNameLabel->setText(QApplication::translate("GraphicClass", "User", 0));
        statusLineEdit->setText(QApplication::translate("GraphicClass", "Personnal message...", 0));
        selectedFriendNameLabel->setText(QApplication::translate("GraphicClass", "Selected Friend", 0));
        selectedFriendIconStatusLabel->setText(QString());
        callFriendRightPushButton->setText(QApplication::translate("GraphicClass", "Call", 0));
        selectedFriendPersonalMsgLabel->setText(QApplication::translate("GraphicClass", "Selected Friend Personal Message", 0));
        hangUpPushButton->setText(QApplication::translate("GraphicClass", "Hang-up", 0));
        callLabel->setText(QApplication::translate("GraphicClass", "Call Status", 0));
        sendBoxPushButton->setText(QApplication::translate("GraphicClass", "Send", 0));
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
