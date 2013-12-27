/********************************************************************************
** Form generated from reading UI file 'ManageFriendWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEFRIENDWINDOW_H
#define UI_MANAGEFRIENDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_ManageFriendWindow
{
public:

    void setupUi(QDialog *ManageFriendWindow)
    {
        if (ManageFriendWindow->objectName().isEmpty())
            ManageFriendWindow->setObjectName(QStringLiteral("ManageFriendWindow"));
        ManageFriendWindow->resize(400, 300);

        retranslateUi(ManageFriendWindow);

        QMetaObject::connectSlotsByName(ManageFriendWindow);
    } // setupUi

    void retranslateUi(QDialog *ManageFriendWindow)
    {
        ManageFriendWindow->setWindowTitle(QApplication::translate("ManageFriendWindow", "ManageFriendWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class ManageFriendWindow: public Ui_ManageFriendWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEFRIENDWINDOW_H
