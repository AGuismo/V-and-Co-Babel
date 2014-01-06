/********************************************************************************
** Form generated from reading UI file 'FakeMenu.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAKEMENU_H
#define UI_FAKEMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FakeMenu
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLineEdit *ServerPort;
    QLabel *label_3;
    QLineEdit *ClientIP;
    QLabel *label;
    QLabel *label_2;
    QPushButton *Disconnect;
    QLineEdit *ClientPort;
    QTextBrowser *Display;
    QPushButton *Connect;
    QLabel *label_4;
    QTextBrowser *Display_2;

    void setupUi(QMainWindow *FakeMenu)
    {
        if (FakeMenu->objectName().isEmpty())
            FakeMenu->setObjectName(QStringLiteral("FakeMenu"));
        FakeMenu->resize(800, 600);
        centralwidget = new QWidget(FakeMenu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        ServerPort = new QLineEdit(centralwidget);
        ServerPort->setObjectName(QStringLiteral("ServerPort"));

        gridLayout->addWidget(ServerPort, 1, 2, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        ClientIP = new QLineEdit(centralwidget);
        ClientIP->setObjectName(QStringLiteral("ClientIP"));

        gridLayout->addWidget(ClientIP, 1, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        Disconnect = new QPushButton(centralwidget);
        Disconnect->setObjectName(QStringLiteral("Disconnect"));
        Disconnect->setEnabled(false);

        gridLayout->addWidget(Disconnect, 1, 4, 1, 1);

        ClientPort = new QLineEdit(centralwidget);
        ClientPort->setObjectName(QStringLiteral("ClientPort"));

        gridLayout->addWidget(ClientPort, 1, 1, 1, 1);

        Display = new QTextBrowser(centralwidget);
        Display->setObjectName(QStringLiteral("Display"));

        gridLayout->addWidget(Display, 2, 0, 1, 5);

        Connect = new QPushButton(centralwidget);
        Connect->setObjectName(QStringLiteral("Connect"));

        gridLayout->addWidget(Connect, 1, 3, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 3, 1, 2);

        Display_2 = new QTextBrowser(centralwidget);
        Display_2->setObjectName(QStringLiteral("Display_2"));
        Display_2->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(Display_2, 3, 0, 1, 5);

        FakeMenu->setCentralWidget(centralwidget);
#ifndef QT_NO_SHORTCUT
        label_3->setBuddy(ServerPort);
        label->setBuddy(ClientIP);
        label_2->setBuddy(ClientPort);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(ClientIP, ClientPort);
        QWidget::setTabOrder(ClientPort, ServerPort);
        QWidget::setTabOrder(ServerPort, Connect);
        QWidget::setTabOrder(Connect, Disconnect);
        QWidget::setTabOrder(Disconnect, Display);
        QWidget::setTabOrder(Display, Display_2);

        retranslateUi(FakeMenu);

        QMetaObject::connectSlotsByName(FakeMenu);
    } // setupUi

    void retranslateUi(QMainWindow *FakeMenu)
    {
        FakeMenu->setWindowTitle(QApplication::translate("FakeMenu", "MainWindow", 0));
        label_3->setText(QApplication::translate("FakeMenu", "ServerPort", 0));
        label->setText(QApplication::translate("FakeMenu", "ClientIP", 0));
        label_2->setText(QApplication::translate("FakeMenu", "ClientPort", 0));
        Disconnect->setText(QApplication::translate("FakeMenu", "Disconnect", 0));
        Connect->setText(QApplication::translate("FakeMenu", "Connect", 0));
        label_4->setText(QApplication::translate("FakeMenu", "Actions", 0));
    } // retranslateUi

};

namespace Ui {
    class FakeMenu: public Ui_FakeMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAKEMENU_H
