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
    QLabel *label_20;
    QComboBox *comboBox_8;
    QSpacerItem *horizontalSpacer_25;
    QLabel *label_22;
    QLabel *label_21;
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
    QVBoxLayout *verticalLayout_20;
    QWidget *layoutWidget_14;
    QVBoxLayout *verticalLayout_21;
    QVBoxLayout *verticalLayout_22;
    QGridLayout *gridLayout_42;
    QFrame *line_28;
    QPushButton *activeFriendCallPushButton_7;
    QLabel *selectedFriendIconStatusLabel_7;
    QLabel *selectedFriendPersonalMsgLabel_7;
    QLabel *selectedFriendNameLabel_7;
    QSpacerItem *horizontalSpacer_28;
    QHBoxLayout *horizontalLayout_13;
    QTextBrowser *friendMsgBox_7;
    QHBoxLayout *horizontalLayout_14;
    QLineEdit *sendBoxTextEdit_7;
    QPushButton *sendBoxPushButton_7;
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
        GraphicClass->setStyleSheet(QLatin1String("QMainWindow {border-image: url(./Img/530035-1920x1080.jpg);}\n"
""));
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
        actionSet_voicemail = new QAction(GraphicClass);
        actionSet_voicemail->setObjectName(QStringLiteral("actionSet_voicemail"));
        actionSet_voicemail->setEnabled(false);
        actionUnset_voicemail = new QAction(GraphicClass);
        actionUnset_voicemail->setObjectName(QStringLiteral("actionUnset_voicemail"));
        actionUnset_voicemail->setEnabled(false);
        actionCall = new QAction(GraphicClass);
        actionCall->setObjectName(QStringLiteral("actionCall"));
        actionCall->setEnabled(false);
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
        label_20 = new QLabel(layoutWidget_13);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setEnabled(false);
        QFont font;
        font.setFamily(QStringLiteral("MS PGothic"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        label_20->setFont(font);
        label_20->setStyleSheet(QStringLiteral(""));

        gridLayout_38->addWidget(label_20, 1, 0, 1, 1);

        comboBox_8 = new QComboBox(layoutWidget_13);
        comboBox_8->setObjectName(QStringLiteral("comboBox_8"));
        comboBox_8->setEnabled(false);

        gridLayout_38->addWidget(comboBox_8, 1, 1, 1, 1);

        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_38->addItem(horizontalSpacer_25, 0, 2, 1, 1);

        label_22 = new QLabel(layoutWidget_13);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setEnabled(false);
        QFont font1;
        font1.setPointSize(14);
        label_22->setFont(font1);
        label_22->setStyleSheet(QStringLiteral(""));

        gridLayout_38->addWidget(label_22, 0, 1, 1, 1);

        label_21 = new QLabel(layoutWidget_13);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setWeight(50);
        label_21->setFont(font2);
        label_21->setStyleSheet(QStringLiteral(""));

        gridLayout_38->addWidget(label_21, 0, 0, 1, 1);


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
        FriendTabWidget_7->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:0, y2:0.534, stop:0.0847458 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        Friends_7 = new QWidget();
        Friends_7->setObjectName(QStringLiteral("Friends_7"));
        gridLayout_40 = new QGridLayout(Friends_7);
        gridLayout_40->setSpacing(6);
        gridLayout_40->setContentsMargins(11, 11, 11, 11);
        gridLayout_40->setObjectName(QStringLiteral("gridLayout_40"));
        listWidget_7 = new FriendListWidget(Friends_7);
        listWidget_7->setObjectName(QStringLiteral("listWidget_7"));
        listWidget_7->setStyleSheet(QStringLiteral("background-image: url(./Img/530035-1920x1080.jpg);"));

        gridLayout_40->addWidget(listWidget_7, 0, 0, 1, 2);

        FriendTabWidget_7->addTab(Friends_7, QString());
        Nothing_7 = new QWidget();
        Nothing_7->setObjectName(QStringLiteral("Nothing_7"));
        FriendTabWidget_7->addTab(Nothing_7, QString());

        gridLayout_39->addWidget(FriendTabWidget_7, 0, 0, 1, 1);


        gridLayout_37->addLayout(gridLayout_39, 2, 0, 1, 1);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setSpacing(6);
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));

        gridLayout_37->addLayout(verticalLayout_20, 3, 0, 1, 1);

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
        line_28 = new QFrame(layoutWidget_14);
        line_28->setObjectName(QStringLiteral("line_28"));
        line_28->setFrameShape(QFrame::HLine);
        line_28->setFrameShadow(QFrame::Sunken);

        gridLayout_42->addWidget(line_28, 2, 0, 1, 3);

        activeFriendCallPushButton_7 = new QPushButton(layoutWidget_14);
        activeFriendCallPushButton_7->setObjectName(QStringLiteral("activeFriendCallPushButton_7"));

        gridLayout_42->addWidget(activeFriendCallPushButton_7, 1, 1, 1, 1);

        selectedFriendIconStatusLabel_7 = new QLabel(layoutWidget_14);
        selectedFriendIconStatusLabel_7->setObjectName(QStringLiteral("selectedFriendIconStatusLabel_7"));
        selectedFriendIconStatusLabel_7->setFont(font1);
        selectedFriendIconStatusLabel_7->setStyleSheet(QStringLiteral(""));

        gridLayout_42->addWidget(selectedFriendIconStatusLabel_7, 0, 1, 1, 1);

        selectedFriendPersonalMsgLabel_7 = new QLabel(layoutWidget_14);
        selectedFriendPersonalMsgLabel_7->setObjectName(QStringLiteral("selectedFriendPersonalMsgLabel_7"));
        selectedFriendPersonalMsgLabel_7->setFont(font);
        selectedFriendPersonalMsgLabel_7->setStyleSheet(QStringLiteral(""));

        gridLayout_42->addWidget(selectedFriendPersonalMsgLabel_7, 1, 0, 1, 1);

        selectedFriendNameLabel_7 = new QLabel(layoutWidget_14);
        selectedFriendNameLabel_7->setObjectName(QStringLiteral("selectedFriendNameLabel_7"));
        selectedFriendNameLabel_7->setEnabled(true);
        sizePolicy.setHeightForWidth(selectedFriendNameLabel_7->sizePolicy().hasHeightForWidth());
        selectedFriendNameLabel_7->setSizePolicy(sizePolicy);
        selectedFriendNameLabel_7->setFont(font2);
        selectedFriendNameLabel_7->setLayoutDirection(Qt::LeftToRight);
        selectedFriendNameLabel_7->setAutoFillBackground(false);
        selectedFriendNameLabel_7->setStyleSheet(QStringLiteral(""));

        gridLayout_42->addWidget(selectedFriendNameLabel_7, 0, 0, 1, 1);

        horizontalSpacer_28 = new QSpacerItem(34, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_42->addItem(horizontalSpacer_28, 0, 2, 1, 1);


        verticalLayout_22->addLayout(gridLayout_42);


        verticalLayout_21->addLayout(verticalLayout_22);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        friendMsgBox_7 = new QTextBrowser(layoutWidget_14);
        friendMsgBox_7->setObjectName(QStringLiteral("friendMsgBox_7"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(3);
        sizePolicy1.setHeightForWidth(friendMsgBox_7->sizePolicy().hasHeightForWidth());
        friendMsgBox_7->setSizePolicy(sizePolicy1);
        friendMsgBox_7->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 218);"));

        horizontalLayout_13->addWidget(friendMsgBox_7);


        verticalLayout_21->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        sendBoxTextEdit_7 = new QLineEdit(layoutWidget_14);
        sendBoxTextEdit_7->setObjectName(QStringLiteral("sendBoxTextEdit_7"));
        sendBoxTextEdit_7->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 255);"));

        horizontalLayout_14->addWidget(sendBoxTextEdit_7);

        sendBoxPushButton_7 = new QPushButton(layoutWidget_14);
        sendBoxPushButton_7->setObjectName(QStringLiteral("sendBoxPushButton_7"));

        horizontalLayout_14->addWidget(sendBoxPushButton_7);


        verticalLayout_21->addLayout(horizontalLayout_14);

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
        label_20->setText(QApplication::translate("GraphicClass", "User Personal Message................", 0));
        label_22->setText(QApplication::translate("GraphicClass", "Icon", 0));
        label_21->setText(QApplication::translate("GraphicClass", "User", 0));
        pushButton_13->setText(QApplication::translate("GraphicClass", "Call", 0));
        pushButton_14->setText(QApplication::translate("GraphicClass", "Add", 0));
        deleteSelectedFriendPushButton_7->setText(QApplication::translate("GraphicClass", "Delete", 0));
        FriendTabWidget_7->setTabText(FriendTabWidget_7->indexOf(Friends_7), QApplication::translate("GraphicClass", "Friends", 0));
        FriendTabWidget_7->setTabText(FriendTabWidget_7->indexOf(Nothing_7), QApplication::translate("GraphicClass", "Nothing", 0));
        activeFriendCallPushButton_7->setText(QApplication::translate("GraphicClass", "Call", 0));
        selectedFriendIconStatusLabel_7->setText(QApplication::translate("GraphicClass", "Icon", 0));
        selectedFriendPersonalMsgLabel_7->setText(QApplication::translate("GraphicClass", "Selected Friend Personal Message", 0));
        selectedFriendNameLabel_7->setText(QApplication::translate("GraphicClass", "Selected Friend", 0));
        sendBoxPushButton_7->setText(QApplication::translate("GraphicClass", "Send", 0));
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
