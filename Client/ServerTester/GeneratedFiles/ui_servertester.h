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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerTester
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_12;
    QPushButton *pushButton_7;
    QPushButton *pushButton_2;
    QPushButton *pushButton_11;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QPushButton *pushButton_4;
    QPushButton *pushButton_9;
    QPushButton *pushButton_17;
    QPushButton *pushButton_14;
    QPushButton *pushButton_18;
    QPushButton *pushButton_16;
    QPushButton *pushButton_5;
    QPushButton *pushButton_10;
    QPushButton *pushButton_15;
    QPushButton *pushButton_13;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout;
    QLabel *labelTitre;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelServerBrowser;
    QTextBrowser *ServerBrowser;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelAdress;
    QLabel *labelPort;
    QLabel *labelStatus;
    QGridLayout *gridLayout_2;
    QLabel *labelEditCmd;
    QPushButton *ButtonSend;
    QLineEdit *lineEditCmd;
    QPushButton *ButtonQuit;
    QFrame *line_5;
    QLabel *connectStatus;
    QLineEdit *lineAdress;
    QLineEdit *linePort;
    QPushButton *ButtonConnect;
    QFrame *line_2;
    QFrame *line_4;
    QFrame *line_3;

    void setupUi(QMainWindow *ServerTester)
    {
        if (ServerTester->objectName().isEmpty())
            ServerTester->setObjectName(QStringLiteral("ServerTester"));
        ServerTester->resize(592, 398);
        centralWidget = new QWidget(ServerTester);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_3, 2, 0, 1, 1);

        pushButton_12 = new QPushButton(centralWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_12, 1, 2, 1, 1);

        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_7, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_11 = new QPushButton(centralWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_11, 0, 2, 1, 1);

        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_6, 0, 1, 1, 1);

        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_8, 2, 1, 1, 1);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_4, 3, 0, 1, 1);

        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_9, 3, 1, 1, 1);

        pushButton_17 = new QPushButton(centralWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_17, 5, 1, 1, 1);

        pushButton_14 = new QPushButton(centralWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_14, 3, 2, 1, 1);

        pushButton_18 = new QPushButton(centralWidget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_18, 5, 2, 1, 1);

        pushButton_16 = new QPushButton(centralWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_16, 5, 0, 1, 1);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_5, 4, 0, 1, 1);

        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_10, 4, 1, 1, 1);

        pushButton_15 = new QPushButton(centralWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_15, 4, 2, 1, 1);

        pushButton_13 = new QPushButton(centralWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_13, 2, 2, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout, 4, 3, 3, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelTitre = new QLabel(centralWidget);
        labelTitre->setObjectName(QStringLiteral("labelTitre"));
        QFont font;
        font.setPointSize(12);
        labelTitre->setFont(font);

        verticalLayout->addWidget(labelTitre);


        gridLayout_4->addLayout(verticalLayout, 0, 0, 1, 2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        labelServerBrowser = new QLabel(centralWidget);
        labelServerBrowser->setObjectName(QStringLiteral("labelServerBrowser"));

        verticalLayout_3->addWidget(labelServerBrowser);

        ServerBrowser = new QTextBrowser(centralWidget);
        ServerBrowser->setObjectName(QStringLiteral("ServerBrowser"));

        verticalLayout_3->addWidget(ServerBrowser);


        gridLayout_4->addLayout(verticalLayout_3, 6, 0, 3, 2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        labelAdress = new QLabel(centralWidget);
        labelAdress->setObjectName(QStringLiteral("labelAdress"));

        verticalLayout_2->addWidget(labelAdress);

        labelPort = new QLabel(centralWidget);
        labelPort->setObjectName(QStringLiteral("labelPort"));

        verticalLayout_2->addWidget(labelPort);

        labelStatus = new QLabel(centralWidget);
        labelStatus->setObjectName(QStringLiteral("labelStatus"));

        verticalLayout_2->addWidget(labelStatus);


        gridLayout_4->addLayout(verticalLayout_2, 1, 0, 3, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        labelEditCmd = new QLabel(centralWidget);
        labelEditCmd->setObjectName(QStringLiteral("labelEditCmd"));

        gridLayout_2->addWidget(labelEditCmd, 0, 0, 1, 1);

        ButtonSend = new QPushButton(centralWidget);
        ButtonSend->setObjectName(QStringLiteral("ButtonSend"));
        ButtonSend->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_2->addWidget(ButtonSend, 1, 1, 1, 1);

        lineEditCmd = new QLineEdit(centralWidget);
        lineEditCmd->setObjectName(QStringLiteral("lineEditCmd"));

        gridLayout_2->addWidget(lineEditCmd, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 3, 3, 1);

        ButtonQuit = new QPushButton(centralWidget);
        ButtonQuit->setObjectName(QStringLiteral("ButtonQuit"));
        ButtonQuit->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_4->addWidget(ButtonQuit, 8, 3, 1, 1);

        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_5, 5, 0, 1, 2);

        connectStatus = new QLabel(centralWidget);
        connectStatus->setObjectName(QStringLiteral("connectStatus"));

        gridLayout_4->addWidget(connectStatus, 3, 1, 1, 1);

        lineAdress = new QLineEdit(centralWidget);
        lineAdress->setObjectName(QStringLiteral("lineAdress"));

        gridLayout_4->addWidget(lineAdress, 1, 1, 1, 1);

        linePort = new QLineEdit(centralWidget);
        linePort->setObjectName(QStringLiteral("linePort"));

        gridLayout_4->addWidget(linePort, 2, 1, 1, 1);

        ButtonConnect = new QPushButton(centralWidget);
        ButtonConnect->setObjectName(QStringLiteral("ButtonConnect"));
        ButtonConnect->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_4->addWidget(ButtonConnect, 4, 0, 1, 2);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_2, 3, 3, 1, 1);

        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_4, 0, 2, 9, 1);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_3, 7, 3, 1, 1);

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
        pushButton_3->setText(QApplication::translate("ServerTester", "Status Afk", 0));
        pushButton_12->setText(QApplication::translate("ServerTester", "Disconnect", 0));
        pushButton_7->setText(QApplication::translate("ServerTester", "Chat", 0));
        pushButton_2->setText(QApplication::translate("ServerTester", "Call", 0));
        pushButton_11->setText(QApplication::translate("ServerTester", "add Friend", 0));
        pushButton_6->setText(QApplication::translate("ServerTester", "Create Acc", 0));
        pushButton_8->setText(QApplication::translate("ServerTester", "Status Online", 0));
        pushButton_4->setText(QApplication::translate("ServerTester", "PushButton", 0));
        pushButton_9->setText(QApplication::translate("ServerTester", "PushButton", 0));
        pushButton_17->setText(QApplication::translate("ServerTester", "PushButton", 0));
        pushButton_14->setText(QApplication::translate("ServerTester", "PushButton", 0));
        pushButton_18->setText(QApplication::translate("ServerTester", "PushButton", 0));
        pushButton_16->setText(QApplication::translate("ServerTester", "PushButton", 0));
        pushButton_5->setText(QApplication::translate("ServerTester", "PushButton", 0));
        pushButton_10->setText(QApplication::translate("ServerTester", "PushButton", 0));
        pushButton_15->setText(QApplication::translate("ServerTester", "PushButton", 0));
        pushButton_13->setText(QApplication::translate("ServerTester", "Status Offline", 0));
        pushButton->setText(QApplication::translate("ServerTester", "Connect", 0));
        labelTitre->setText(QApplication::translate("ServerTester", "BABEL TESTER", 0));
        labelServerBrowser->setText(QApplication::translate("ServerTester", "Server answer browser :", 0));
        labelAdress->setText(QApplication::translate("ServerTester", "Server Adress :", 0));
        labelPort->setText(QApplication::translate("ServerTester", "Server Port :", 0));
        labelStatus->setText(QApplication::translate("ServerTester", "Status :", 0));
        labelEditCmd->setText(QApplication::translate("ServerTester", "Test your own command :", 0));
        ButtonSend->setText(QApplication::translate("ServerTester", "Send", 0));
        lineEditCmd->setText(QApplication::translate("ServerTester", "Hello World !", 0));
        ButtonQuit->setText(QApplication::translate("ServerTester", "Close", 0));
        connectStatus->setText(QApplication::translate("ServerTester", "Disconnected", 0));
        lineAdress->setText(QApplication::translate("ServerTester", "127.0.0.1", 0));
        linePort->setText(QApplication::translate("ServerTester", "44201", 0));
        ButtonConnect->setText(QApplication::translate("ServerTester", "Connect !", 0));
    } // retranslateUi

};

namespace Ui {
    class ServerTester: public Ui_ServerTester {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERTESTER_H
