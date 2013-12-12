/********************************************************************************
** Form generated from reading UI file 'servertester.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERTESTER_H
#define UI_SERVERTESTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerTester
{
public:
    QWidget *centralWidget;
    QPushButton *ButtonQuit;
    QLineEdit *lineAdress;
    QLabel *labelAdress;
    QLabel *labelPort;
    QLineEdit *linePort;
    QLabel *labelStatus;
    QLabel *connectStatus;
    QPushButton *ButtonConnect;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QLabel *labelEditCmd;
    QLineEdit *lineEditCmd;
    QPushButton *ButtonSend;
    QFrame *line_2;
    QLabel *labelTitre;
    QTextBrowser *ServerBrowser;
    QLabel *labelServerBrowser;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;

    void setupUi(QMainWindow *ServerTester)
    {
        if (ServerTester->objectName().isEmpty())
            ServerTester->setObjectName(QStringLiteral("ServerTester"));
        ServerTester->resize(685, 442);
        centralWidget = new QWidget(ServerTester);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ButtonQuit = new QPushButton(centralWidget);
        ButtonQuit->setObjectName(QStringLiteral("ButtonQuit"));
        ButtonQuit->setGeometry(QRect(332, 390, 331, 41));
        lineAdress = new QLineEdit(centralWidget);
        lineAdress->setObjectName(QStringLiteral("lineAdress"));
        lineAdress->setGeometry(QRect(130, 50, 111, 22));
        labelAdress = new QLabel(centralWidget);
        labelAdress->setObjectName(QStringLiteral("labelAdress"));
        labelAdress->setGeometry(QRect(30, 50, 101, 16));
        labelPort = new QLabel(centralWidget);
        labelPort->setObjectName(QStringLiteral("labelPort"));
        labelPort->setGeometry(QRect(40, 80, 81, 16));
        linePort = new QLineEdit(centralWidget);
        linePort->setObjectName(QStringLiteral("linePort"));
        linePort->setGeometry(QRect(130, 80, 51, 22));
        labelStatus = new QLabel(centralWidget);
        labelStatus->setObjectName(QStringLiteral("labelStatus"));
        labelStatus->setGeometry(QRect(70, 110, 51, 16));
        connectStatus = new QLabel(centralWidget);
        connectStatus->setObjectName(QStringLiteral("connectStatus"));
        connectStatus->setGeometry(QRect(130, 110, 161, 16));
        ButtonConnect = new QPushButton(centralWidget);
        ButtonConnect->setObjectName(QStringLiteral("ButtonConnect"));
        ButtonConnect->setGeometry(QRect(90, 130, 91, 41));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(340, 130, 93, 28));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 170, 93, 28));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(340, 210, 93, 28));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(340, 250, 93, 28));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(340, 290, 93, 28));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(450, 130, 93, 28));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(450, 170, 93, 28));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(450, 210, 93, 28));
        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(450, 250, 93, 28));
        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(450, 290, 93, 28));
        pushButton_11 = new QPushButton(centralWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(560, 130, 93, 28));
        pushButton_12 = new QPushButton(centralWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(560, 170, 93, 28));
        pushButton_13 = new QPushButton(centralWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(560, 210, 93, 28));
        pushButton_14 = new QPushButton(centralWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(560, 250, 93, 28));
        pushButton_15 = new QPushButton(centralWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(560, 290, 93, 28));
        pushButton_16 = new QPushButton(centralWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(340, 330, 93, 28));
        pushButton_17 = new QPushButton(centralWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(450, 330, 93, 28));
        pushButton_18 = new QPushButton(centralWidget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setGeometry(QRect(560, 330, 93, 28));
        labelEditCmd = new QLabel(centralWidget);
        labelEditCmd->setObjectName(QStringLiteral("labelEditCmd"));
        labelEditCmd->setGeometry(QRect(340, 40, 161, 16));
        lineEditCmd = new QLineEdit(centralWidget);
        lineEditCmd->setObjectName(QStringLiteral("lineEditCmd"));
        lineEditCmd->setGeometry(QRect(340, 60, 231, 22));
        ButtonSend = new QPushButton(centralWidget);
        ButtonSend->setObjectName(QStringLiteral("ButtonSend"));
        ButtonSend->setGeometry(QRect(580, 60, 81, 28));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(320, 110, 361, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        labelTitre = new QLabel(centralWidget);
        labelTitre->setObjectName(QStringLiteral("labelTitre"));
        labelTitre->setGeometry(QRect(70, 20, 141, 21));
        QFont font;
        font.setPointSize(12);
        labelTitre->setFont(font);
        ServerBrowser = new QTextBrowser(centralWidget);
        ServerBrowser->setObjectName(QStringLiteral("ServerBrowser"));
        ServerBrowser->setGeometry(QRect(20, 220, 271, 201));
        labelServerBrowser = new QLabel(centralWidget);
        labelServerBrowser->setObjectName(QStringLiteral("labelServerBrowser"));
        labelServerBrowser->setGeometry(QRect(30, 190, 201, 16));
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(320, 370, 361, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(300, 10, 20, 421));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(10, 170, 291, 16));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        ServerTester->setCentralWidget(centralWidget);

        retranslateUi(ServerTester);
        QObject::connect(lineAdress, SIGNAL(returnPressed()), ButtonConnect, SLOT(click()));
        QObject::connect(linePort, SIGNAL(returnPressed()), ButtonConnect, SLOT(click()));
        QObject::connect(lineEditCmd, SIGNAL(returnPressed()), ButtonSend, SLOT(click()));

        QMetaObject::connectSlotsByName(ServerTester);
    } // setupUi

    void retranslateUi(QMainWindow *ServerTester)
    {
        ServerTester->setWindowTitle(QApplication::translate("ServerTester", "ServerTester", 0));
        ButtonQuit->setText(QApplication::translate("ServerTester", "Close", 0));
        lineAdress->setText(QString());
        labelAdress->setText(QApplication::translate("ServerTester", "Server Adress :", 0));
        labelPort->setText(QApplication::translate("ServerTester", "Server Port :", 0));
        linePort->setText(QString());
        labelStatus->setText(QApplication::translate("ServerTester", "Status :", 0));
        connectStatus->setText(QApplication::translate("ServerTester", "Disconnected", 0));
        ButtonConnect->setText(QApplication::translate("ServerTester", "Connect !", 0));
        pushButton->setText(QApplication::translate("ServerTester", "Connect", 0));
        pushButton_2->setText(QApplication::translate("ServerTester", "Call", 0));
        pushButton_3->setText(QApplication::translate("ServerTester", "Status Afk", 0));
        pushButton_4->setText(QApplication::translate("ServerTester", "PushButton", 0));
        pushButton_5->setText(QApplication::translate("ServerTester", "PushButton", 0));
        pushButton_6->setText(QApplication::translate("ServerTester", "Create Acc", 0));
        pushButton_7->setText(QApplication::translate("ServerTester", "Chat", 0));
        pushButton_8->setText(QApplication::translate("ServerTester", "Status Online", 0));
        pushButton_9->setText(QApplication::translate("ServerTester", "PushButton", 0));
        pushButton_10->setText(QApplication::translate("ServerTester", "PushButton", 0));
        pushButton_11->setText(QApplication::translate("ServerTester", "add Friend", 0));
        pushButton_12->setText(QApplication::translate("ServerTester", "Disconnect", 0));
        pushButton_13->setText(QApplication::translate("ServerTester", "Status Offline", 0));
        pushButton_14->setText(QApplication::translate("ServerTester", "PushButton", 0));
        pushButton_15->setText(QApplication::translate("ServerTester", "PushButton", 0));
        pushButton_16->setText(QApplication::translate("ServerTester", "PushButton", 0));
        pushButton_17->setText(QApplication::translate("ServerTester", "PushButton", 0));
        pushButton_18->setText(QApplication::translate("ServerTester", "PushButton", 0));
        labelEditCmd->setText(QApplication::translate("ServerTester", "Test your own command :", 0));
        ButtonSend->setText(QApplication::translate("ServerTester", "Send", 0));
        labelTitre->setText(QApplication::translate("ServerTester", "BABEL TESTER", 0));
        labelServerBrowser->setText(QApplication::translate("ServerTester", "Server answer browser :", 0));
    } // retranslateUi

};

namespace Ui {
    class ServerTester: public Ui_ServerTester {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERTESTER_H
