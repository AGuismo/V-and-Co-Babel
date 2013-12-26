/********************************************************************************
** Form generated from reading UI file 'DeleteAccountWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEACCOUNTWINDOW_H
#define UI_DELETEACCOUNTWINDOW_H

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

class Ui_DeleteAccountWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *loginLabel;
    QLabel *passwordLabel;
    QLineEdit *loginLineEdit;
    QLineEdit *passwordLineEdit;
    QLabel *serverResponseLabel;
    QPushButton *closePushButton;
    QPushButton *deletePushButton;
    QLabel *loginTitleLabel;

    void setupUi(QDialog *DeleteAccountWindow)
    {
        if (DeleteAccountWindow->objectName().isEmpty())
            DeleteAccountWindow->setObjectName(QStringLiteral("DeleteAccountWindow"));
        DeleteAccountWindow->resize(298, 138);
        gridLayout = new QGridLayout(DeleteAccountWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        loginLabel = new QLabel(DeleteAccountWindow);
        loginLabel->setObjectName(QStringLiteral("loginLabel"));
        QFont font;
        font.setPointSize(10);
        loginLabel->setFont(font);

        gridLayout->addWidget(loginLabel, 1, 0, 1, 1);

        passwordLabel = new QLabel(DeleteAccountWindow);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        QFont font1;
        font1.setFamily(QStringLiteral("MS UI Gothic"));
        font1.setPointSize(10);
        passwordLabel->setFont(font1);

        gridLayout->addWidget(passwordLabel, 2, 0, 1, 1);

        loginLineEdit = new QLineEdit(DeleteAccountWindow);
        loginLineEdit->setObjectName(QStringLiteral("loginLineEdit"));
        loginLineEdit->setMaxLength(256);

        gridLayout->addWidget(loginLineEdit, 1, 1, 1, 2);

        passwordLineEdit = new QLineEdit(DeleteAccountWindow);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setMaxLength(256);
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordLineEdit, 2, 1, 1, 2);

        serverResponseLabel = new QLabel(DeleteAccountWindow);
        serverResponseLabel->setObjectName(QStringLiteral("serverResponseLabel"));
        QFont font2;
        font2.setFamily(QStringLiteral("MS UI Gothic"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        serverResponseLabel->setFont(font2);

        gridLayout->addWidget(serverResponseLabel, 3, 0, 1, 1);

        closePushButton = new QPushButton(DeleteAccountWindow);
        closePushButton->setObjectName(QStringLiteral("closePushButton"));

        gridLayout->addWidget(closePushButton, 3, 1, 1, 1);

        deletePushButton = new QPushButton(DeleteAccountWindow);
        deletePushButton->setObjectName(QStringLiteral("deletePushButton"));

        gridLayout->addWidget(deletePushButton, 3, 2, 1, 1);

        loginTitleLabel = new QLabel(DeleteAccountWindow);
        loginTitleLabel->setObjectName(QStringLiteral("loginTitleLabel"));
        QFont font3;
        font3.setFamily(QStringLiteral("MS UI Gothic"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        loginTitleLabel->setFont(font3);
        loginTitleLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(loginTitleLabel, 0, 0, 1, 3);

        QWidget::setTabOrder(loginLineEdit, passwordLineEdit);
        QWidget::setTabOrder(passwordLineEdit, deletePushButton);
        QWidget::setTabOrder(deletePushButton, closePushButton);

        retranslateUi(DeleteAccountWindow);

        QMetaObject::connectSlotsByName(DeleteAccountWindow);
    } // setupUi

    void retranslateUi(QDialog *DeleteAccountWindow)
    {
        DeleteAccountWindow->setWindowTitle(QApplication::translate("DeleteAccountWindow", "LoginWindow", 0));
        loginLabel->setText(QApplication::translate("DeleteAccountWindow", "Login :", 0));
        passwordLabel->setText(QApplication::translate("DeleteAccountWindow", "Password :", 0));
        loginLineEdit->setText(QApplication::translate("DeleteAccountWindow", "toto", 0));
        passwordLineEdit->setInputMask(QString());
        passwordLineEdit->setText(QApplication::translate("DeleteAccountWindow", "poil", 0));
        serverResponseLabel->setText(QString());
        closePushButton->setText(QApplication::translate("DeleteAccountWindow", "Close", 0));
        deletePushButton->setText(QApplication::translate("DeleteAccountWindow", "Delete", 0));
        loginTitleLabel->setText(QApplication::translate("DeleteAccountWindow", "Delete account", 0));
    } // retranslateUi

};

namespace Ui {
    class DeleteAccountWindow: public Ui_DeleteAccountWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEACCOUNTWINDOW_H
