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
    QPushButton *outputWrite;
    QTextBrowser *Display;
    QLineEdit *outputWriteLine;

    void setupUi(QMainWindow *FakeMenu)
    {
        if (FakeMenu->objectName().isEmpty())
            FakeMenu->setObjectName(QStringLiteral("FakeMenu"));
        FakeMenu->resize(800, 600);
        centralwidget = new QWidget(FakeMenu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        outputWrite = new QPushButton(centralwidget);
        outputWrite->setObjectName(QStringLiteral("outputWrite"));

        gridLayout->addWidget(outputWrite, 0, 0, 1, 1);

        Display = new QTextBrowser(centralwidget);
        Display->setObjectName(QStringLiteral("Display"));

        gridLayout->addWidget(Display, 2, 0, 1, 1);

        outputWriteLine = new QLineEdit(centralwidget);
        outputWriteLine->setObjectName(QStringLiteral("outputWriteLine"));

        gridLayout->addWidget(outputWriteLine, 1, 0, 1, 1);

        FakeMenu->setCentralWidget(centralwidget);

        retranslateUi(FakeMenu);

        QMetaObject::connectSlotsByName(FakeMenu);
    } // setupUi

    void retranslateUi(QMainWindow *FakeMenu)
    {
        FakeMenu->setWindowTitle(QApplication::translate("FakeMenu", "MainWindow", 0));
        outputWrite->setText(QApplication::translate("FakeMenu", "OutputWrite", 0));
    } // retranslateUi

};

namespace Ui {
    class FakeMenu: public Ui_FakeMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAKEMENU_H
