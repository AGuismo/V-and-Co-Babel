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
    QWidget *layoutWidget_13;
    QGridLayout *gridLayout_37;
    QGridLayout *gridLayout_38;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_9;
    QSpacerItem *horizontalSpacer_28;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QFrame *line_27;
    QGridLayout *gridLayout_41;
    QFrame *line_26;
    QSpacerItem *horizontalSpacer_27;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *deleteSelectedFriendPushButton_7;
    QSpacerItem *horizontalSpacer_26;
    QFrame *line_25;
    QGridLayout *gridLayout_39;
    QTabWidget *FriendTabWidget_7;
    QWidget *Friends_7;
    QGridLayout *gridLayout_40;
    FriendListWidget *listWidget_7;
    QWidget *Nothing_7;
    QWidget *layoutWidget_14;
    QVBoxLayout *verticalLayout_21;
    QVBoxLayout *verticalLayout_22;
    QGridLayout *gridLayout_42;
    QVBoxLayout *verticalLayout_23;
    QGridLayout *gridLayout_43;
    QLabel *selectedFriendNameLabel_8;
    QLabel *selectedFriendIconStatusLabel_8;
    QSpacerItem *horizontalSpacer_29;
    QGridLayout *gridLayout_2;
    QLabel *selectedFriendPersonalMsgLabel_8;
    QSpacerItem *horizontalSpacer_30;
    QPushButton *activeFriendCallPushButton_8;
    QFrame *line_29;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QTextBrowser *friendMsgBox_8;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *sendBoxTextEdit_8;
    QPushButton *sendBoxPushButton_8;
    QSpacerItem *horizontalSpacer_2;
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
        GraphicClass->resize(942, 637);
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
"}"));
        actionConnect = new QAction(GraphicClass);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        QFont font;
        font.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font.setBold(true);
        font.setWeight(75);
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
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setChildrenCollapsible(false);
        layoutWidget_13 = new QWidget(splitter);
        layoutWidget_13->setObjectName(QStringLiteral("layoutWidget_13"));
        gridLayout_37 = new QGridLayout(layoutWidget_13);
        gridLayout_37->setSpacing(6);
        gridLayout_37->setContentsMargins(11, 11, 11, 11);
        gridLayout_37->setObjectName(QStringLiteral("gridLayout_37"));
        gridLayout_37->setContentsMargins(0, 0, 0, 0);
        gridLayout_38 = new QGridLayout();
        gridLayout_38->setSpacing(6);
        gridLayout_38->setObjectName(QStringLiteral("gridLayout_38"));
        gridLayout_38->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget_13);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);
        QFont font2;
        font2.setFamily(QStringLiteral("Dimitri Swank"));
        font2.setPointSize(14);
        label->setFont(font2);
        label->setStyleSheet(QLatin1String("background-color: rgba(156, 156, 156, 200);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"padding: 2px;"));

        horizontalLayout->addWidget(label);

        comboBox_9 = new QComboBox(layoutWidget_13);
        comboBox_9->setObjectName(QStringLiteral("comboBox_9"));
        comboBox_9->setEnabled(true);

        horizontalLayout->addWidget(comboBox_9);

        horizontalSpacer_28 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_28);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit = new QLineEdit(layoutWidget_13);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setMaximumSize(QSize(16777215, 16777215));
        QFont font3;
        font3.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        lineEdit->setFont(font3);
        lineEdit->setStyleSheet(QLatin1String("background-color: rgba(156, 156, 156, 200);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"padding: 2px;"));

        horizontalLayout_2->addWidget(lineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout_3->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        gridLayout_38->addLayout(gridLayout_3, 0, 0, 1, 1);


        gridLayout_37->addLayout(gridLayout_38, 0, 0, 1, 1);

        line_27 = new QFrame(layoutWidget_13);
        line_27->setObjectName(QStringLiteral("line_27"));
        line_27->setFrameShape(QFrame::VLine);
        line_27->setFrameShadow(QFrame::Sunken);

        gridLayout_37->addWidget(line_27, 0, 1, 4, 1);

        gridLayout_41 = new QGridLayout();
        gridLayout_41->setSpacing(6);
        gridLayout_41->setObjectName(QStringLiteral("gridLayout_41"));
        line_26 = new QFrame(layoutWidget_13);
        line_26->setObjectName(QStringLiteral("line_26"));
        line_26->setFrameShape(QFrame::HLine);
        line_26->setFrameShadow(QFrame::Sunken);

        gridLayout_41->addWidget(line_26, 0, 0, 1, 5);

        horizontalSpacer_27 = new QSpacerItem(35, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_41->addItem(horizontalSpacer_27, 1, 0, 1, 1);

        pushButton_13 = new QPushButton(layoutWidget_13);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setEnabled(true);

        gridLayout_41->addWidget(pushButton_13, 1, 1, 1, 1);

        pushButton_14 = new QPushButton(layoutWidget_13);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setEnabled(true);

        gridLayout_41->addWidget(pushButton_14, 1, 2, 1, 1);

        deleteSelectedFriendPushButton_7 = new QPushButton(layoutWidget_13);
        deleteSelectedFriendPushButton_7->setObjectName(QStringLiteral("deleteSelectedFriendPushButton_7"));
        deleteSelectedFriendPushButton_7->setEnabled(true);

        gridLayout_41->addWidget(deleteSelectedFriendPushButton_7, 1, 3, 1, 1);

        horizontalSpacer_26 = new QSpacerItem(36, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_41->addItem(horizontalSpacer_26, 1, 4, 1, 1);

        line_25 = new QFrame(layoutWidget_13);
        line_25->setObjectName(QStringLiteral("line_25"));
        line_25->setFrameShape(QFrame::HLine);
        line_25->setFrameShadow(QFrame::Sunken);

        gridLayout_41->addWidget(line_25, 2, 0, 1, 5);


        gridLayout_37->addLayout(gridLayout_41, 1, 0, 1, 1);

        gridLayout_39 = new QGridLayout();
        gridLayout_39->setSpacing(6);
        gridLayout_39->setObjectName(QStringLiteral("gridLayout_39"));
        FriendTabWidget_7 = new QTabWidget(layoutWidget_13);
        FriendTabWidget_7->setObjectName(QStringLiteral("FriendTabWidget_7"));
        FriendTabWidget_7->setStyleSheet(QStringLiteral(""));
        Friends_7 = new QWidget();
        Friends_7->setObjectName(QStringLiteral("Friends_7"));
        gridLayout_40 = new QGridLayout(Friends_7);
        gridLayout_40->setSpacing(6);
        gridLayout_40->setContentsMargins(11, 11, 11, 11);
        gridLayout_40->setObjectName(QStringLiteral("gridLayout_40"));
        listWidget_7 = new FriendListWidget(Friends_7);
        listWidget_7->setObjectName(QStringLiteral("listWidget_7"));
        listWidget_7->setStyleSheet(QLatin1String("background-image: url(./Img/wallpaper-14461.jpg);\n"
""));

        gridLayout_40->addWidget(listWidget_7, 0, 0, 1, 2);

        FriendTabWidget_7->addTab(Friends_7, QString());
        Nothing_7 = new QWidget();
        Nothing_7->setObjectName(QStringLiteral("Nothing_7"));
        FriendTabWidget_7->addTab(Nothing_7, QString());

        gridLayout_39->addWidget(FriendTabWidget_7, 0, 0, 1, 1);


        gridLayout_37->addLayout(gridLayout_39, 2, 0, 1, 1);

        splitter->addWidget(layoutWidget_13);
        layoutWidget_14 = new QWidget(splitter);
        layoutWidget_14->setObjectName(QStringLiteral("layoutWidget_14"));
        verticalLayout_21 = new QVBoxLayout(layoutWidget_14);
        verticalLayout_21->setSpacing(6);
        verticalLayout_21->setContentsMargins(11, 11, 11, 11);
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        verticalLayout_21->setContentsMargins(0, 0, 0, 0);
        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setSpacing(6);
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        gridLayout_42 = new QGridLayout();
        gridLayout_42->setSpacing(6);
        gridLayout_42->setObjectName(QStringLiteral("gridLayout_42"));
        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setSpacing(6);
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        gridLayout_43 = new QGridLayout();
        gridLayout_43->setSpacing(6);
        gridLayout_43->setObjectName(QStringLiteral("gridLayout_43"));
        selectedFriendNameLabel_8 = new QLabel(layoutWidget_14);
        selectedFriendNameLabel_8->setObjectName(QStringLiteral("selectedFriendNameLabel_8"));
        selectedFriendNameLabel_8->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(selectedFriendNameLabel_8->sizePolicy().hasHeightForWidth());
        selectedFriendNameLabel_8->setSizePolicy(sizePolicy);
        QFont font4;
        font4.setFamily(QStringLiteral("Dimitri Swank"));
        font4.setPointSize(14);
        font4.setBold(false);
        font4.setWeight(50);
        selectedFriendNameLabel_8->setFont(font4);
        selectedFriendNameLabel_8->setLayoutDirection(Qt::LeftToRight);
        selectedFriendNameLabel_8->setAutoFillBackground(false);
        selectedFriendNameLabel_8->setStyleSheet(QLatin1String("background-color: rgba(156, 156, 156, 200);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"min-width: 10em;\n"
"padding: 2px;"));

        gridLayout_43->addWidget(selectedFriendNameLabel_8, 0, 0, 1, 1);

        selectedFriendIconStatusLabel_8 = new QLabel(layoutWidget_14);
        selectedFriendIconStatusLabel_8->setObjectName(QStringLiteral("selectedFriendIconStatusLabel_8"));
        QFont font5;
        font5.setPointSize(14);
        selectedFriendIconStatusLabel_8->setFont(font5);
        selectedFriendIconStatusLabel_8->setStyleSheet(QStringLiteral(""));

        gridLayout_43->addWidget(selectedFriendIconStatusLabel_8, 0, 1, 1, 1);

        horizontalSpacer_29 = new QSpacerItem(34, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_43->addItem(horizontalSpacer_29, 0, 2, 1, 1);


        verticalLayout_23->addLayout(gridLayout_43);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        selectedFriendPersonalMsgLabel_8 = new QLabel(layoutWidget_14);
        selectedFriendPersonalMsgLabel_8->setObjectName(QStringLiteral("selectedFriendPersonalMsgLabel_8"));
        selectedFriendPersonalMsgLabel_8->setFont(font3);
        selectedFriendPersonalMsgLabel_8->setStyleSheet(QLatin1String("background-color: rgba(156, 156, 156, 200);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"min-width: 10em;\n"
"padding: 2px;"));

        gridLayout_2->addWidget(selectedFriendPersonalMsgLabel_8, 0, 0, 1, 1);

        horizontalSpacer_30 = new QSpacerItem(34, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_30, 0, 2, 1, 1);

        activeFriendCallPushButton_8 = new QPushButton(layoutWidget_14);
        activeFriendCallPushButton_8->setObjectName(QStringLiteral("activeFriendCallPushButton_8"));

        gridLayout_2->addWidget(activeFriendCallPushButton_8, 0, 1, 1, 1);


        verticalLayout_23->addLayout(gridLayout_2);


        gridLayout_42->addLayout(verticalLayout_23, 0, 0, 1, 1);


        verticalLayout_22->addLayout(gridLayout_42);


        verticalLayout_21->addLayout(verticalLayout_22);

        line_29 = new QFrame(layoutWidget_14);
        line_29->setObjectName(QStringLiteral("line_29"));
        line_29->setFrameShape(QFrame::HLine);
        line_29->setFrameShadow(QFrame::Sunken);

        verticalLayout_21->addWidget(line_29);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        friendMsgBox_8 = new QTextBrowser(layoutWidget_14);
        friendMsgBox_8->setObjectName(QStringLiteral("friendMsgBox_8"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(3);
        sizePolicy1.setHeightForWidth(friendMsgBox_8->sizePolicy().hasHeightForWidth());
        friendMsgBox_8->setSizePolicy(sizePolicy1);
        friendMsgBox_8->setMaximumSize(QSize(800, 16777215));
        QFont font6;
        font6.setPointSize(10);
        friendMsgBox_8->setFont(font6);
        friendMsgBox_8->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 200);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"min-width: 10em;\n"
"padding: 2px;"));

        verticalLayout->addWidget(friendMsgBox_8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        sendBoxTextEdit_8 = new QLineEdit(layoutWidget_14);
        sendBoxTextEdit_8->setObjectName(QStringLiteral("sendBoxTextEdit_8"));
        sendBoxTextEdit_8->setMaximumSize(QSize(700, 16777215));
        sendBoxTextEdit_8->setFont(font6);
        sendBoxTextEdit_8->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 230);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"min-width: 10em;\n"
"padding: 2px;"));

        horizontalLayout_3->addWidget(sendBoxTextEdit_8);

        sendBoxPushButton_8 = new QPushButton(layoutWidget_14);
        sendBoxPushButton_8->setObjectName(QStringLiteral("sendBoxPushButton_8"));

        horizontalLayout_3->addWidget(sendBoxPushButton_8);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_13->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_2);


        verticalLayout_21->addLayout(horizontalLayout_13);

        splitter->addWidget(layoutWidget_14);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        GraphicClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GraphicClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 942, 26));
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
        QObject::connect(sendBoxTextEdit_8, SIGNAL(textEdited(QString)), friendMsgBox_8, SLOT(setText(QString)));

        FriendTabWidget_7->setCurrentIndex(0);


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
        label->setText(QApplication::translate("GraphicClass", "User", 0));
        lineEdit->setText(QApplication::translate("GraphicClass", "Personnal message...", 0));
        pushButton_13->setText(QApplication::translate("GraphicClass", "Call", 0));
        pushButton_14->setText(QApplication::translate("GraphicClass", "Add", 0));
        deleteSelectedFriendPushButton_7->setText(QApplication::translate("GraphicClass", "Delete", 0));
        FriendTabWidget_7->setTabText(FriendTabWidget_7->indexOf(Friends_7), QApplication::translate("GraphicClass", "Friends", 0));
        FriendTabWidget_7->setTabText(FriendTabWidget_7->indexOf(Nothing_7), QApplication::translate("GraphicClass", "Nothing", 0));
        selectedFriendNameLabel_8->setText(QApplication::translate("GraphicClass", "Selected Friend", 0));
        selectedFriendIconStatusLabel_8->setText(QApplication::translate("GraphicClass", "Icon", 0));
        selectedFriendPersonalMsgLabel_8->setText(QApplication::translate("GraphicClass", "Selected Friend Personal Message", 0));
        activeFriendCallPushButton_8->setText(QApplication::translate("GraphicClass", "Call", 0));
        sendBoxPushButton_8->setText(QApplication::translate("GraphicClass", "Send", 0));
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
