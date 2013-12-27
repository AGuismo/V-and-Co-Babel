/********************************************************************************
** Form generated from reading UI file 'audio.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDIO_H
#define UI_AUDIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Audio
{
public:
    QGridLayout *gridLayout;
    QTextBrowser *Display;
    QPushButton *inputWrite;
    QLineEdit *inputWriteLine;

    void setupUi(QWidget *Audio)
    {
        if (Audio->objectName().isEmpty())
            Audio->setObjectName(QStringLiteral("Audio"));
        Audio->resize(480, 640);
        gridLayout = new QGridLayout(Audio);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Display = new QTextBrowser(Audio);
        Display->setObjectName(QStringLiteral("Display"));

        gridLayout->addWidget(Display, 2, 0, 1, 1);

        inputWrite = new QPushButton(Audio);
        inputWrite->setObjectName(QStringLiteral("inputWrite"));

        gridLayout->addWidget(inputWrite, 0, 0, 1, 1);

        inputWriteLine = new QLineEdit(Audio);
        inputWriteLine->setObjectName(QStringLiteral("inputWriteLine"));

        gridLayout->addWidget(inputWriteLine, 1, 0, 1, 1);


        retranslateUi(Audio);

        QMetaObject::connectSlotsByName(Audio);
    } // setupUi

    void retranslateUi(QWidget *Audio)
    {
        Audio->setWindowTitle(QApplication::translate("Audio", "Form", 0));
        inputWrite->setText(QApplication::translate("Audio", "InputWrite", 0));
    } // retranslateUi

};

namespace Ui {
    class Audio: public Ui_Audio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIO_H
