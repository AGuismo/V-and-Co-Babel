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
    QAction *actionSet_voicemail;
    QAction *actionUnset_voicemail;
    QAction *actionCall;
    QAction *actionDelete_account;
    QAction *actionAdd_friend;
    QAction *actionDelete_friend;
    QAction *actionLogout;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QWidget *widget;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_47;
    QGridLayout *gridLayout_49;
    QFrame *line_33;
    QSpacerItem *horizontalSpacer_35;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *deleteSelectedFriendPushButton_9;
    QSpacerItem *horizontalSpacer_36;
    QFrame *line_34;
    QGridLayout *gridLayout_50;
    QSpacerItem *horizontalSpacer_2;
    FriendListWidget *listWidget_9;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout_48;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QComboBox *comboBox_11;
    QSpacerItem *horizontalSpacer_34;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *lineEdit_3;
    QSpacerItem *horizontalSpacer_5;
    QWidget *layoutWidget_15;
    QVBoxLayout *verticalLayout_24;
    QVBoxLayout *verticalLayout_25;
    QGridLayout *gridLayout_51;
    QVBoxLayout *verticalLayout_26;
    QGridLayout *gridLayout_52;
    QLabel *selectedFriendNameLabel_9;
    QLabel *selectedFriendIconStatusLabel_9;
    QSpacerItem *horizontalSpacer_37;
    QGridLayout *gridLayout_9;
    QSpacerItem *horizontalSpacer_38;
    QPushButton *activeFriendCallPushButton_9;
    QLabel *selectedFriendPersonalMsgLabel_9;
    QPushButton *HangUpPushButton;
    QFrame *line_35;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *friendMsgBox_9;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *sendBoxTextEdit_9;
    QPushButton *sendBoxPushButton_9;
    QSpacerItem *horizontalSpacer_7;
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
        GraphicClass->resize(984, 529);
        GraphicClass->setStyleSheet(QLatin1String("QMainWindow \n"
"{\n"
"	border-image: url(./Img/wallpaper-14461.jpg);\n"
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
        actionConnect = new QAction(GraphicClass);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        QFont font;
        font.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font.setBold(false);
        font.setWeight(50);
        actionConnect->setFont(font);
        actionCreateAccount = new QAction(GraphicClass);
        actionCreateAccount->setObjectName(QStringLiteral("actionCreateAccount"));
        actionCreateAccount->setEnabled(false);
        QFont font1;
        font1.setFamily(QStringLiteral("MS Reference Sans Serif"));
        actionCreateAccount->setFont(font1);
        actionLogin = new QAction(GraphicClass);
        actionLogin->setObjectName(QStringLiteral("actionLogin"));
        actionLogin->setEnabled(false);
        actionExit = new QAction(GraphicClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionSet_voicemail = new QAction(GraphicClass);
        actionSet_voicemail->setObjectName(QStringLiteral("actionSet_voicemail"));
        actionSet_voicemail->setEnabled(false);
        actionUnset_voicemail = new QAction(GraphicClass);
        actionUnset_voicemail->setObjectName(QStringLiteral("actionUnset_voicemail"));
        actionUnset_voicemail->setEnabled(false);
        actionCall = new QAction(GraphicClass);
        actionCall->setObjectName(QStringLiteral("actionCall"));
        actionCall->setEnabled(false);
        actionCall->setFont(font1);
        actionDelete_account = new QAction(GraphicClass);
        actionDelete_account->setObjectName(QStringLiteral("actionDelete_account"));
        actionDelete_account->setEnabled(false);
        actionAdd_friend = new QAction(GraphicClass);
        actionAdd_friend->setObjectName(QStringLiteral("actionAdd_friend"));
        actionAdd_friend->setEnabled(false);
        actionDelete_friend = new QAction(GraphicClass);
        actionDelete_friend->setObjectName(QStringLiteral("actionDelete_friend"));
        actionDelete_friend->setEnabled(false);
        actionLogout = new QAction(GraphicClass);
        actionLogout->setObjectName(QStringLiteral("actionLogout"));
        actionLogout->setEnabled(false);
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

        pushButton_17 = new QPushButton(widget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setEnabled(true);
        pushButton_17->setStyleSheet(QLatin1String("QPushButton#pushButton_17\n"
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
" QPushButton#pushButton_17:pressed \n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 56, 183, 255), stop:1 rgba(135, 172, 255, 255));\n"
"     border-style: inset;\n"
" }"));

        gridLayout_49->addWidget(pushButton_17, 1, 1, 1, 1);

        pushButton_18 = new QPushButton(widget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setEnabled(true);
        pushButton_18->setStyleSheet(QLatin1String("QPushButton#pushButton_18\n"
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
" QPushButton#pushButton_18:pressed \n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 56, 183, 255), stop:1 rgba(135, 172, 255, 255));\n"
"     border-style: inset;\n"
" }"));

        gridLayout_49->addWidget(pushButton_18, 1, 2, 1, 1);

        deleteSelectedFriendPushButton_9 = new QPushButton(widget);
        deleteSelectedFriendPushButton_9->setObjectName(QStringLiteral("deleteSelectedFriendPushButton_9"));
        deleteSelectedFriendPushButton_9->setEnabled(true);
        deleteSelectedFriendPushButton_9->setStyleSheet(QLatin1String("QPushButton#deleteSelectedFriendPushButton_9\n"
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
" QPushButton#deleteSelectedFriendPushButton_9:pressed \n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 56, 183, 255), stop:1 rgba(135, 172, 255, 255));\n"
"     border-style: inset;\n"
" }"));

        gridLayout_49->addWidget(deleteSelectedFriendPushButton_9, 1, 3, 1, 1);

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

        listWidget_9 = new FriendListWidget(widget);
        listWidget_9->setObjectName(QStringLiteral("listWidget_9"));
        listWidget_9->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 200);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"min-width: 10em;\n"
"padding: 2px;"));

        gridLayout_50->addWidget(listWidget_9, 0, 1, 1, 1);

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
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setEnabled(true);
        QFont font2;
        font2.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        label_3->setFont(font2);
        label_3->setStyleSheet(QLatin1String("background-color: rgba(156, 156, 156, 200);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"padding: 2px;"));

        horizontalLayout_6->addWidget(label_3);

        comboBox_11 = new QComboBox(widget);
        comboBox_11->setObjectName(QStringLiteral("comboBox_11"));
        comboBox_11->setEnabled(true);
        comboBox_11->setMinimumSize(QSize(110, 0));
        comboBox_11->setStyleSheet(QLatin1String("QComboBox#comboBox_11\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(0, 24, 185, 255), stop:1 rgba(163, 175, 255, 255));\n"
"	border-style: outset;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	border-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
" QComboBox#comboBox_11:pressed \n"
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

        horizontalLayout_6->addWidget(comboBox_11);

        horizontalSpacer_34 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_34);


        gridLayout_8->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setEnabled(true);
        lineEdit_3->setMaximumSize(QSize(400, 16777215));
        QFont font3;
        font3.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        lineEdit_3->setFont(font3);
        lineEdit_3->setStyleSheet(QLatin1String("background-color: rgba(156, 156, 156, 200);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"padding: 2px;"));

        horizontalLayout_7->addWidget(lineEdit_3);

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
        selectedFriendNameLabel_9 = new QLabel(layoutWidget_15);
        selectedFriendNameLabel_9->setObjectName(QStringLiteral("selectedFriendNameLabel_9"));
        selectedFriendNameLabel_9->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(selectedFriendNameLabel_9->sizePolicy().hasHeightForWidth());
        selectedFriendNameLabel_9->setSizePolicy(sizePolicy);
        selectedFriendNameLabel_9->setFont(font2);
        selectedFriendNameLabel_9->setLayoutDirection(Qt::LeftToRight);
        selectedFriendNameLabel_9->setAutoFillBackground(false);
        selectedFriendNameLabel_9->setStyleSheet(QLatin1String("background-color: rgba(156, 156, 156, 200);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"min-width: 10em;\n"
"padding: 2px;"));

        gridLayout_52->addWidget(selectedFriendNameLabel_9, 0, 0, 1, 1);

        selectedFriendIconStatusLabel_9 = new QLabel(layoutWidget_15);
        selectedFriendIconStatusLabel_9->setObjectName(QStringLiteral("selectedFriendIconStatusLabel_9"));
        selectedFriendIconStatusLabel_9->setMaximumSize(QSize(300, 42));
        QFont font4;
        font4.setPointSize(14);
        selectedFriendIconStatusLabel_9->setFont(font4);
        selectedFriendIconStatusLabel_9->setStyleSheet(QStringLiteral(""));

        gridLayout_52->addWidget(selectedFriendIconStatusLabel_9, 0, 1, 1, 1);

        horizontalSpacer_37 = new QSpacerItem(34, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_52->addItem(horizontalSpacer_37, 0, 2, 1, 1);


        verticalLayout_26->addLayout(gridLayout_52);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        horizontalSpacer_38 = new QSpacerItem(34, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_38, 0, 3, 1, 1);

        activeFriendCallPushButton_9 = new QPushButton(layoutWidget_15);
        activeFriendCallPushButton_9->setObjectName(QStringLiteral("activeFriendCallPushButton_9"));
        QFont font5;
        font5.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font5.setPointSize(8);
        activeFriendCallPushButton_9->setFont(font5);
        activeFriendCallPushButton_9->setStyleSheet(QLatin1String("QPushButton#activeFriendCallPushButton_9\n"
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
" QPushButton#activeFriendCallPushButton_9:pressed \n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 56, 183, 255), stop:1 rgba(135, 172, 255, 255));\n"
"     border-style: inset;\n"
" }"));

        gridLayout_9->addWidget(activeFriendCallPushButton_9, 0, 1, 1, 1);

        selectedFriendPersonalMsgLabel_9 = new QLabel(layoutWidget_15);
        selectedFriendPersonalMsgLabel_9->setObjectName(QStringLiteral("selectedFriendPersonalMsgLabel_9"));
        selectedFriendPersonalMsgLabel_9->setMinimumSize(QSize(164, 0));
        selectedFriendPersonalMsgLabel_9->setFont(font3);
        selectedFriendPersonalMsgLabel_9->setStyleSheet(QLatin1String("background-color: rgba(156, 156, 156, 200);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"min-width: 10em;\n"
"padding: 2px;"));

        gridLayout_9->addWidget(selectedFriendPersonalMsgLabel_9, 0, 0, 1, 1);

        HangUpPushButton = new QPushButton(layoutWidget_15);
        HangUpPushButton->setObjectName(QStringLiteral("HangUpPushButton"));
        HangUpPushButton->setEnabled(true);
        HangUpPushButton->setFont(font5);
        HangUpPushButton->setStyleSheet(QLatin1String("QPushButton#HangUpPushButton\n"
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
" QPushButton#HangUpPushButton:pressed \n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 56, 183, 255), stop:1 rgba(135, 172, 255, 255));\n"
"     border-style: inset;\n"
" }"));

        gridLayout_9->addWidget(HangUpPushButton, 0, 2, 1, 1);


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
        friendMsgBox_9 = new QTextBrowser(layoutWidget_15);
        friendMsgBox_9->setObjectName(QStringLiteral("friendMsgBox_9"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(3);
        sizePolicy1.setHeightForWidth(friendMsgBox_9->sizePolicy().hasHeightForWidth());
        friendMsgBox_9->setSizePolicy(sizePolicy1);
        friendMsgBox_9->setMinimumSize(QSize(164, 0));
        friendMsgBox_9->setMaximumSize(QSize(800, 16777215));
        friendMsgBox_9->setSizeIncrement(QSize(3, 0));
        QFont font6;
        font6.setPointSize(10);
        friendMsgBox_9->setFont(font6);
        friendMsgBox_9->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 200);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"min-width: 10em;\n"
"padding: 2px;"));

        verticalLayout_2->addWidget(friendMsgBox_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        sendBoxTextEdit_9 = new QLineEdit(layoutWidget_15);
        sendBoxTextEdit_9->setObjectName(QStringLiteral("sendBoxTextEdit_9"));
        sendBoxTextEdit_9->setMaximumSize(QSize(700, 16777215));
        sendBoxTextEdit_9->setFont(font6);
        sendBoxTextEdit_9->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 230);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"min-width: 10em;\n"
"padding: 2px;"));

        horizontalLayout_8->addWidget(sendBoxTextEdit_9);

        sendBoxPushButton_9 = new QPushButton(layoutWidget_15);
        sendBoxPushButton_9->setObjectName(QStringLiteral("sendBoxPushButton_9"));
        sendBoxPushButton_9->setStyleSheet(QLatin1String("QPushButton#sendBoxPushButton_9\n"
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
" QPushButton#sendBoxPushButton_9:pressed \n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 56, 183, 255), stop:1 rgba(135, 172, 255, 255));\n"
"     border-style: inset;\n"
" }"));

        horizontalLayout_8->addWidget(sendBoxPushButton_9);


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
        menuBar->setGeometry(QRect(0, 0, 984, 23));
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
        menuVBabel->addAction(actionCall);
        menuVBabel->addAction(actionExit);
        menuConnection->addAction(actionConnect);
        menuConnection->addAction(actionLogin);
        menuConnection->addAction(actionLogout);
        menuManage_account->addAction(actionCreateAccount);
        menuManage_account->addAction(actionDelete_account);
        menuVoicemail->addAction(actionSet_voicemail);
        menuVoicemail->addAction(actionUnset_voicemail);
        menuFriends_list->addAction(actionAdd_friend);
        menuFriends_list->addAction(actionDelete_friend);

        retranslateUi(GraphicClass);

        QMetaObject::connectSlotsByName(GraphicClass);
    } // setupUi

    void retranslateUi(QMainWindow *GraphicClass)
    {
        GraphicClass->setWindowTitle(QApplication::translate("GraphicClass", "MainWindow", 0));
        actionConnect->setText(QApplication::translate("GraphicClass", "Connect", 0));
        actionCreateAccount->setText(QApplication::translate("GraphicClass", "Create account", 0));
        actionLogin->setText(QApplication::translate("GraphicClass", "Log in", 0));
        actionExit->setText(QApplication::translate("GraphicClass", "Exit", 0));
        actionSet_voicemail->setText(QApplication::translate("GraphicClass", "Set voicemail", 0));
        actionUnset_voicemail->setText(QApplication::translate("GraphicClass", "Unset voicemail", 0));
        actionCall->setText(QApplication::translate("GraphicClass", "Call", 0));
        actionDelete_account->setText(QApplication::translate("GraphicClass", "Delete account", 0));
        actionAdd_friend->setText(QApplication::translate("GraphicClass", "Add friend", 0));
        actionDelete_friend->setText(QApplication::translate("GraphicClass", "Delete friend", 0));
        actionLogout->setText(QApplication::translate("GraphicClass", "Log out", 0));
        pushButton_17->setText(QApplication::translate("GraphicClass", "Call", 0));
        pushButton_18->setText(QApplication::translate("GraphicClass", "Add", 0));
        deleteSelectedFriendPushButton_9->setText(QApplication::translate("GraphicClass", "Delete", 0));
        label_3->setText(QApplication::translate("GraphicClass", "User", 0));
        lineEdit_3->setText(QApplication::translate("GraphicClass", "Personnal message...", 0));
        selectedFriendNameLabel_9->setText(QApplication::translate("GraphicClass", "Selected Friend", 0));
        selectedFriendIconStatusLabel_9->setText(QApplication::translate("GraphicClass", "Icon", 0));
        activeFriendCallPushButton_9->setText(QApplication::translate("GraphicClass", "Call", 0));
        selectedFriendPersonalMsgLabel_9->setText(QApplication::translate("GraphicClass", "Selected Friend Personal Message", 0));
        HangUpPushButton->setText(QApplication::translate("GraphicClass", "Hang-up", 0));
        sendBoxPushButton_9->setText(QApplication::translate("GraphicClass", "Send", 0));
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
