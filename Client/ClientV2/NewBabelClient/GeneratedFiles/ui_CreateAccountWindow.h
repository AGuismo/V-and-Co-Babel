/********************************************************************************
** Form generated from reading UI file 'CreateAccountWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEACCOUNTWINDOW_H
#define UI_CREATEACCOUNTWINDOW_H

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

class Ui_CreateAccountWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *loginLabel;
    QLabel *passwordLabel;
    QLineEdit *loginLineEdit;
    QLineEdit *passwordLineEdit;
    QLabel *serverResponseLabel;
    QPushButton *closePushButton;
    QPushButton *createPushButton;
    QLabel *loginTitleLabel;

    void setupUi(QDialog *CreateAccountWindow)
    {
        if (CreateAccountWindow->objectName().isEmpty())
            CreateAccountWindow->setObjectName(QStringLiteral("CreateAccountWindow"));
        CreateAccountWindow->resize(378, 145);
        CreateAccountWindow->setStyleSheet(QLatin1String("CreateAccountWindow \n"
"{\n"
"	border-image: url(./Img/dialog-background.jpg);\n"
"}"));
        gridLayout = new QGridLayout(CreateAccountWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        loginLabel = new QLabel(CreateAccountWindow);
        loginLabel->setObjectName(QStringLiteral("loginLabel"));
        QFont font;
        font.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font.setPointSize(10);
        loginLabel->setFont(font);
        loginLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(loginLabel, 1, 0, 1, 1);

        passwordLabel = new QLabel(CreateAccountWindow);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        passwordLabel->setFont(font);
        passwordLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(passwordLabel, 2, 0, 1, 1);

        loginLineEdit = new QLineEdit(CreateAccountWindow);
        loginLineEdit->setObjectName(QStringLiteral("loginLineEdit"));
        loginLineEdit->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 230);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"min-width: 10em;\n"
"padding: 2px;"));
        loginLineEdit->setMaxLength(42);

        gridLayout->addWidget(loginLineEdit, 1, 1, 1, 2);

        passwordLineEdit = new QLineEdit(CreateAccountWindow);
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

        serverResponseLabel = new QLabel(CreateAccountWindow);
        serverResponseLabel->setObjectName(QStringLiteral("serverResponseLabel"));
        serverResponseLabel->setMinimumSize(QSize(185, 0));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        serverResponseLabel->setFont(font1);
        serverResponseLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(serverResponseLabel, 3, 0, 1, 1);

        closePushButton = new QPushButton(CreateAccountWindow);
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

        createPushButton = new QPushButton(CreateAccountWindow);
        createPushButton->setObjectName(QStringLiteral("createPushButton"));
        createPushButton->setFont(font2);
        createPushButton->setStyleSheet(QLatin1String("QPushButton#createPushButton\n"
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
"QPushButton#createPushButton:hover\n"
"{\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 148, 255, 255), stop:1 rgba(0, 8, 84, 255));\n"
"	border-style: inset;\n"
"}\n"
"\n"
" QPushButton#createPushButton:pressed \n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 56, 183, 255), stop:1 rgba(135, 172, 255, 255));\n"
"     border-style: inset;\n"
" }\n"
"\n"
""));

        gridLayout->addWidget(createPushButton, 3, 2, 1, 1);

        loginTitleLabel = new QLabel(CreateAccountWindow);
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
        QWidget::setTabOrder(passwordLineEdit, createPushButton);
        QWidget::setTabOrder(createPushButton, closePushButton);

        retranslateUi(CreateAccountWindow);

        QMetaObject::connectSlotsByName(CreateAccountWindow);
    } // setupUi

    void retranslateUi(QDialog *CreateAccountWindow)
    {
        CreateAccountWindow->setWindowTitle(QApplication::translate("CreateAccountWindow", "Login", 0));
        loginLabel->setText(QApplication::translate("CreateAccountWindow", "Login :", 0));
        passwordLabel->setText(QApplication::translate("CreateAccountWindow", "Password :", 0));
        loginLineEdit->setText(QApplication::translate("CreateAccountWindow", "toto", 0));
        passwordLineEdit->setInputMask(QString());
        passwordLineEdit->setText(QApplication::translate("CreateAccountWindow", "poil", 0));
        serverResponseLabel->setText(QString());
        closePushButton->setText(QApplication::translate("CreateAccountWindow", "Close", 0));
        createPushButton->setText(QApplication::translate("CreateAccountWindow", "Create", 0));
        loginTitleLabel->setText(QApplication::translate("CreateAccountWindow", "Create account", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateAccountWindow: public Ui_CreateAccountWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEACCOUNTWINDOW_H
