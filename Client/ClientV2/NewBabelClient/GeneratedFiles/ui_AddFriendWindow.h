/********************************************************************************
** Form generated from reading UI file 'AddFriendWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIENDWINDOW_H
#define UI_ADDFRIENDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddFriendWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *loginLabel;
    QLineEdit *loginLineEdit;
    QLabel *serverResponseLabel;
    QPushButton *closePushButton;
    QPushButton *addPushButton;
    QLabel *loginTitleLabel;

    void setupUi(QDialog *AddFriendWindow)
    {
        if (AddFriendWindow->objectName().isEmpty())
            AddFriendWindow->setObjectName(QStringLiteral("AddFriendWindow"));
        AddFriendWindow->resize(270, 92);
        gridLayout = new QGridLayout(AddFriendWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        loginLabel = new QLabel(AddFriendWindow);
        loginLabel->setObjectName(QStringLiteral("loginLabel"));
        QFont font;
        font.setPointSize(10);
        loginLabel->setFont(font);

        gridLayout->addWidget(loginLabel, 1, 0, 1, 1);

        loginLineEdit = new QLineEdit(AddFriendWindow);
        loginLineEdit->setObjectName(QStringLiteral("loginLineEdit"));
        loginLineEdit->setMaxLength(256);

        gridLayout->addWidget(loginLineEdit, 1, 1, 1, 2);

        serverResponseLabel = new QLabel(AddFriendWindow);
        serverResponseLabel->setObjectName(QStringLiteral("serverResponseLabel"));
        QFont font1;
        font1.setFamily(QStringLiteral("MS UI Gothic"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        serverResponseLabel->setFont(font1);

        gridLayout->addWidget(serverResponseLabel, 2, 0, 1, 1);

        closePushButton = new QPushButton(AddFriendWindow);
        closePushButton->setObjectName(QStringLiteral("closePushButton"));

        gridLayout->addWidget(closePushButton, 2, 1, 1, 1);

        addPushButton = new QPushButton(AddFriendWindow);
        addPushButton->setObjectName(QStringLiteral("addPushButton"));

        gridLayout->addWidget(addPushButton, 2, 2, 1, 1);

        loginTitleLabel = new QLabel(AddFriendWindow);
        loginTitleLabel->setObjectName(QStringLiteral("loginTitleLabel"));
        QFont font2;
        font2.setFamily(QStringLiteral("MS UI Gothic"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        loginTitleLabel->setFont(font2);
        loginTitleLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(loginTitleLabel, 0, 0, 1, 3);

        QWidget::setTabOrder(loginLineEdit, addPushButton);
        QWidget::setTabOrder(addPushButton, closePushButton);

        retranslateUi(AddFriendWindow);

        QMetaObject::connectSlotsByName(AddFriendWindow);
    } // setupUi

    void retranslateUi(QDialog *AddFriendWindow)
    {
        AddFriendWindow->setWindowTitle(QApplication::translate("AddFriendWindow", "LoginWindow", 0));
        loginLabel->setText(QApplication::translate("AddFriendWindow", "Friend pseudo :", 0));
        loginLineEdit->setText(QApplication::translate("AddFriendWindow", "tata", 0));
        serverResponseLabel->setText(QString());
        closePushButton->setText(QApplication::translate("AddFriendWindow", "Close", 0));
        addPushButton->setText(QApplication::translate("AddFriendWindow", "Add", 0));
        loginTitleLabel->setText(QApplication::translate("AddFriendWindow", "Add friend", 0));
    } // retranslateUi

};

namespace Ui {
    class AddFriendWindow: public Ui_AddFriendWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIENDWINDOW_H
