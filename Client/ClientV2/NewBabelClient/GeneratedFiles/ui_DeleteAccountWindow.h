/********************************************************************************
** Form generated from reading UI file 'DeleteAccountWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
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
        DeleteAccountWindow->resize(298, 145);
        DeleteAccountWindow->setStyleSheet(QLatin1String("DeleteAccountWindow \n"
"{\n"
"	border-image: url(./Img/dialog-background.jpg);\n"
"}"));
        gridLayout = new QGridLayout(DeleteAccountWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        loginLabel = new QLabel(DeleteAccountWindow);
        loginLabel->setObjectName(QStringLiteral("loginLabel"));
        QFont font;
        font.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font.setPointSize(10);
        loginLabel->setFont(font);
        loginLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(loginLabel, 1, 0, 1, 1);

        passwordLabel = new QLabel(DeleteAccountWindow);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        passwordLabel->setFont(font);
        passwordLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(passwordLabel, 2, 0, 1, 1);

        loginLineEdit = new QLineEdit(DeleteAccountWindow);
        loginLineEdit->setObjectName(QStringLiteral("loginLineEdit"));
        loginLineEdit->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 230);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"min-width: 10em;\n"
"padding: 2px;"));
        loginLineEdit->setMaxLength(42);

        gridLayout->addWidget(loginLineEdit, 1, 1, 1, 2);

        passwordLineEdit = new QLineEdit(DeleteAccountWindow);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 230);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"min-width: 10em;\n"
"padding: 2px;"));
        passwordLineEdit->setMaxLength(42);
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordLineEdit, 2, 1, 1, 2);

        serverResponseLabel = new QLabel(DeleteAccountWindow);
        serverResponseLabel->setObjectName(QStringLiteral("serverResponseLabel"));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        serverResponseLabel->setFont(font1);

        gridLayout->addWidget(serverResponseLabel, 3, 0, 1, 1);

        closePushButton = new QPushButton(DeleteAccountWindow);
        closePushButton->setObjectName(QStringLiteral("closePushButton"));
        QFont font2;
        font2.setFamily(QStringLiteral("MS Reference Sans Serif"));
        closePushButton->setFont(font2);
        closePushButton->setStyleSheet(QLatin1String("QPushButton#closePushButton\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(0, 24, 185, 255), stop:1 rgba(163, 175, 255, 255));\n"
"	border-style: outset;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	border-color: rgb(255, 255, 255);\n"
"	min-width: 4em;\n"
"	padding: 6px;\n"
"}\n"
"\n"
"QPushButton#closePushButton:hover\n"
"{\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 148, 255, 255), stop:1 rgba(0, 8, 84, 255));\n"
"	border-style: inset;\n"
"}\n"
"\n"
" QPushButton#closePushButton:pressed \n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 56, 183, 255), stop:1 rgba(135, 172, 255, 255));\n"
"     border-style: inset;\n"
" }\n"
"\n"
""));

        gridLayout->addWidget(closePushButton, 3, 1, 1, 1);

        deletePushButton = new QPushButton(DeleteAccountWindow);
        deletePushButton->setObjectName(QStringLiteral("deletePushButton"));
        deletePushButton->setFont(font2);
        deletePushButton->setStyleSheet(QLatin1String("QPushButton#deletePushButton\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(0, 24, 185, 255), stop:1 rgba(163, 175, 255, 255));\n"
"	border-style: outset;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	border-color: rgb(255, 255, 255);\n"
"	min-width: 4em;\n"
"	padding: 6px;\n"
"}\n"
"\n"
"QPushButton#deletePushButton:hover\n"
"{\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 148, 255, 255), stop:1 rgba(0, 8, 84, 255));\n"
"	border-style: inset;\n"
"}\n"
"\n"
" QPushButton#deletePushButton:pressed \n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 56, 183, 255), stop:1 rgba(135, 172, 255, 255));\n"
"     border-style: inset;\n"
" }\n"
"\n"
""));

        gridLayout->addWidget(deletePushButton, 3, 2, 1, 1);

        loginTitleLabel = new QLabel(DeleteAccountWindow);
        loginTitleLabel->setObjectName(QStringLiteral("loginTitleLabel"));
        QFont font3;
        font3.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        loginTitleLabel->setFont(font3);
        loginTitleLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
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
