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
    QPushButton *gButton;
    QPushButton *fButton;
    QPushButton *eButton;
    QPushButton *dButton;
    QPushButton *cButton;
    QPushButton *bButton;
    QPushButton *hButton;
    QPushButton *jButton;
    QPushButton *kButton;
    QPushButton *qButton;
    QPushButton *lButton;
    QPushButton *rButton;
    QPushButton *pButton;
    QPushButton *mButton;
    QPushButton *nButton;
    QPushButton *oButton;
    QPushButton *iButton;
    QPushButton *aButton;
    QVBoxLayout *verticalLayout;
    QLabel *labelTitre;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelServerBrowser;
    QTextBrowser *ServerBrowser;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelAdress;
    QLabel *labelPortTCP;
    QLabel *labelPortUDP;
    QLabel *labelStatus;
    QGridLayout *gridLayout_2;
    QLabel *labelEditCmd;
    QPushButton *ButtonSend;
    QLineEdit *lineEditCmd;
    QPushButton *ButtonQuit;
    QFrame *line_5;
    QLabel *connectStatus;
    QLineEdit *lineAdress;
    QLineEdit *linePortTCP;
    QPushButton *ButtonConnect;
    QFrame *line_2;
    QFrame *line_4;
    QFrame *line_3;
    QLineEdit *linePortUDP;

    void setupUi(QMainWindow *ServerTester)
    {
        if (ServerTester->objectName().isEmpty())
            ServerTester->setObjectName(QStringLiteral("ServerTester"));
        ServerTester->resize(592, 427);
        centralWidget = new QWidget(ServerTester);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gButton = new QPushButton(centralWidget);
        gButton->setObjectName(QStringLiteral("gButton"));
        gButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(gButton, 2, 0, 1, 1);

        fButton = new QPushButton(centralWidget);
        fButton->setObjectName(QStringLiteral("fButton"));
        fButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(fButton, 1, 2, 1, 1);

        eButton = new QPushButton(centralWidget);
        eButton->setObjectName(QStringLiteral("eButton"));
        eButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(eButton, 1, 1, 1, 1);

        dButton = new QPushButton(centralWidget);
        dButton->setObjectName(QStringLiteral("dButton"));
        dButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(dButton, 1, 0, 1, 1);

        cButton = new QPushButton(centralWidget);
        cButton->setObjectName(QStringLiteral("cButton"));
        cButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(cButton, 0, 2, 1, 1);

        bButton = new QPushButton(centralWidget);
        bButton->setObjectName(QStringLiteral("bButton"));
        bButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(bButton, 0, 1, 1, 1);

        hButton = new QPushButton(centralWidget);
        hButton->setObjectName(QStringLiteral("hButton"));
        hButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(hButton, 2, 1, 1, 1);

        jButton = new QPushButton(centralWidget);
        jButton->setObjectName(QStringLiteral("jButton"));
        jButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(jButton, 3, 0, 1, 1);

        kButton = new QPushButton(centralWidget);
        kButton->setObjectName(QStringLiteral("kButton"));
        kButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(kButton, 3, 1, 1, 1);

        qButton = new QPushButton(centralWidget);
        qButton->setObjectName(QStringLiteral("qButton"));
        qButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(qButton, 5, 1, 1, 1);

        lButton = new QPushButton(centralWidget);
        lButton->setObjectName(QStringLiteral("lButton"));
        lButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(lButton, 3, 2, 1, 1);

        rButton = new QPushButton(centralWidget);
        rButton->setObjectName(QStringLiteral("rButton"));
        rButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(rButton, 5, 2, 1, 1);

        pButton = new QPushButton(centralWidget);
        pButton->setObjectName(QStringLiteral("pButton"));
        pButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pButton, 5, 0, 1, 1);

        mButton = new QPushButton(centralWidget);
        mButton->setObjectName(QStringLiteral("mButton"));
        mButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(mButton, 4, 0, 1, 1);

        nButton = new QPushButton(centralWidget);
        nButton->setObjectName(QStringLiteral("nButton"));
        nButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(nButton, 4, 1, 1, 1);

        oButton = new QPushButton(centralWidget);
        oButton->setObjectName(QStringLiteral("oButton"));
        oButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(oButton, 4, 2, 1, 1);

        iButton = new QPushButton(centralWidget);
        iButton->setObjectName(QStringLiteral("iButton"));
        iButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(iButton, 2, 2, 1, 1);

        aButton = new QPushButton(centralWidget);
        aButton->setObjectName(QStringLiteral("aButton"));
        aButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(aButton, 0, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout, 5, 3, 3, 1);

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


        gridLayout_4->addLayout(verticalLayout_3, 7, 0, 3, 2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        labelAdress = new QLabel(centralWidget);
        labelAdress->setObjectName(QStringLiteral("labelAdress"));

        verticalLayout_2->addWidget(labelAdress);

        labelPortTCP = new QLabel(centralWidget);
        labelPortTCP->setObjectName(QStringLiteral("labelPortTCP"));

        verticalLayout_2->addWidget(labelPortTCP);

        labelPortUDP = new QLabel(centralWidget);
        labelPortUDP->setObjectName(QStringLiteral("labelPortUDP"));

        verticalLayout_2->addWidget(labelPortUDP);

        labelStatus = new QLabel(centralWidget);
        labelStatus->setObjectName(QStringLiteral("labelStatus"));

        verticalLayout_2->addWidget(labelStatus);


        gridLayout_4->addLayout(verticalLayout_2, 1, 0, 4, 1);

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

        gridLayout_4->addWidget(ButtonQuit, 9, 3, 1, 1);

        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_5, 6, 0, 1, 2);

        connectStatus = new QLabel(centralWidget);
        connectStatus->setObjectName(QStringLiteral("connectStatus"));

        gridLayout_4->addWidget(connectStatus, 4, 1, 1, 1);

        lineAdress = new QLineEdit(centralWidget);
        lineAdress->setObjectName(QStringLiteral("lineAdress"));

        gridLayout_4->addWidget(lineAdress, 1, 1, 1, 1);

        linePortTCP = new QLineEdit(centralWidget);
        linePortTCP->setObjectName(QStringLiteral("linePortTCP"));

        gridLayout_4->addWidget(linePortTCP, 2, 1, 1, 1);

        ButtonConnect = new QPushButton(centralWidget);
        ButtonConnect->setObjectName(QStringLiteral("ButtonConnect"));
        ButtonConnect->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_4->addWidget(ButtonConnect, 5, 0, 1, 2);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_2, 4, 3, 1, 1);

        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_4, 0, 2, 10, 1);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_3, 8, 3, 1, 1);

        linePortUDP = new QLineEdit(centralWidget);
        linePortUDP->setObjectName(QStringLiteral("linePortUDP"));

        gridLayout_4->addWidget(linePortUDP, 3, 1, 1, 1);

        ServerTester->setCentralWidget(centralWidget);

        retranslateUi(ServerTester);
        QObject::connect(lineAdress, SIGNAL(returnPressed()), ButtonConnect, SLOT(click()));
        QObject::connect(linePortTCP, SIGNAL(returnPressed()), ButtonConnect, SLOT(click()));
        QObject::connect(lineEditCmd, SIGNAL(returnPressed()), ButtonSend, SLOT(click()));
        QObject::connect(linePortUDP, SIGNAL(returnPressed()), ButtonConnect, SLOT(click()));

        QMetaObject::connectSlotsByName(ServerTester);
    } // setupUi

    void retranslateUi(QMainWindow *ServerTester)
    {
        ServerTester->setWindowTitle(QApplication::translate("ServerTester", "ServerTester", 0));
        gButton->setText(QApplication::translate("ServerTester", "accept de toto", 0));
        fButton->setText(QApplication::translate("ServerTester", "appel de tata", 0));
        eButton->setText(QApplication::translate("ServerTester", "appel de toto", 0));
        dButton->setText(QApplication::translate("ServerTester", "connection tata", 0));
        cButton->setText(QApplication::translate("ServerTester", "connection toto", 0));
        bButton->setText(QApplication::translate("ServerTester", "cr\303\251ation tata", 0));
        hButton->setText(QApplication::translate("ServerTester", "accept de tata", 0));
        jButton->setText(QApplication::translate("ServerTester", "denied de tata", 0));
        kButton->setText(QApplication::translate("ServerTester", "Disconnect le client", 0));
        qButton->setText(QApplication::translate("ServerTester", "q", 0));
        lButton->setText(QApplication::translate("ServerTester", "l", 0));
        rButton->setText(QApplication::translate("ServerTester", "r", 0));
        pButton->setText(QApplication::translate("ServerTester", "p", 0));
        mButton->setText(QApplication::translate("ServerTester", "m", 0));
        nButton->setText(QApplication::translate("ServerTester", "n", 0));
        oButton->setText(QApplication::translate("ServerTester", "o", 0));
        iButton->setText(QApplication::translate("ServerTester", "denied de toto", 0));
        aButton->setText(QApplication::translate("ServerTester", "cr\303\251ation toto", 0));
        labelTitre->setText(QApplication::translate("ServerTester", "BABEL TESTER", 0));
        labelServerBrowser->setText(QApplication::translate("ServerTester", "Server answer browser :", 0));
        labelAdress->setText(QApplication::translate("ServerTester", "Server Adress :", 0));
        labelPortTCP->setText(QApplication::translate("ServerTester", "Server Port (TCP) :", 0));
        labelPortUDP->setText(QApplication::translate("ServerTester", "Server Port (UDP) :", 0));
        labelStatus->setText(QApplication::translate("ServerTester", "Status :", 0));
        labelEditCmd->setText(QApplication::translate("ServerTester", "Test your own command :", 0));
        ButtonSend->setText(QApplication::translate("ServerTester", "Send", 0));
        lineEditCmd->setText(QApplication::translate("ServerTester", "Hello World !", 0));
        ButtonQuit->setText(QApplication::translate("ServerTester", "Close", 0));
        connectStatus->setText(QApplication::translate("ServerTester", "Disconnected", 0));
        lineAdress->setText(QApplication::translate("ServerTester", "127.0.0.1", 0));
        linePortTCP->setText(QApplication::translate("ServerTester", "44201", 0));
        ButtonConnect->setText(QApplication::translate("ServerTester", "Connect !", 0));
        linePortUDP->setText(QApplication::translate("ServerTester", "44202", 0));
    } // retranslateUi

};

namespace Ui {
    class ServerTester: public Ui_ServerTester {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERTESTER_H
