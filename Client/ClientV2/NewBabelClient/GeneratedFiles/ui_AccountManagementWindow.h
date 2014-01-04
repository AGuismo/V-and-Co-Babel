/********************************************************************************
** Form generated from reading UI file 'AccountManagementWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTMANAGEMENTWINDOW_H
#define UI_ACCOUNTMANAGEMENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_AccountManagementWindow
{
public:
    QGridLayout *gridLayout;
    QPushButton *changePasswordPushButton;
    QPushButton *changePrivacyPushButton;
    QLineEdit *newPasswordLineEdit;
    QLabel *passwordLabel;
    QLineEdit *currentPasswordLineEdit;
    QFrame *line;
    QLabel *loginLabel;
    QLabel *loginTitleLabel;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QRadioButton *publicRadioButton;
    QRadioButton *privateRadioButton;
    QLabel *serverResponseLabel;

    void setupUi(QDialog *AccountManagementWindow)
    {
        if (AccountManagementWindow->objectName().isEmpty())
            AccountManagementWindow->setObjectName(QStringLiteral("AccountManagementWindow"));
        AccountManagementWindow->resize(283, 238);
        QFont font;
        font.setFamily(QStringLiteral("MS Reference Sans Serif"));
        AccountManagementWindow->setFont(font);
        AccountManagementWindow->setStyleSheet(QLatin1String("AccountManagementWindow \n"
"{\n"
"	border-image: url(./Img/dialog-background.jpg);\n"
"}"));
        gridLayout = new QGridLayout(AccountManagementWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        changePasswordPushButton = new QPushButton(AccountManagementWindow);
        changePasswordPushButton->setObjectName(QStringLiteral("changePasswordPushButton"));
        changePasswordPushButton->setMinimumSize(QSize(78, 30));
        changePasswordPushButton->setMaximumSize(QSize(100, 16777215));
        changePasswordPushButton->setFont(font);
        changePasswordPushButton->setStyleSheet(QLatin1String("QPushButton#changePasswordPushButton\n"
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
"QPushButton#changePasswordPushButton:hover\n"
"{\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 148, 255, 255), stop:1 rgba(0, 8, 84, 255));\n"
"	border-style: inset;\n"
"}\n"
"\n"
" QPushButton#changePasswordPushButton:pressed \n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 56, 183, 255), stop:1 rgba(135, 172, 255, 255));\n"
"     border-style: inset;\n"
" }\n"
"\n"
""));

        gridLayout->addWidget(changePasswordPushButton, 6, 0, 1, 1);

        changePrivacyPushButton = new QPushButton(AccountManagementWindow);
        changePrivacyPushButton->setObjectName(QStringLiteral("changePrivacyPushButton"));
        changePrivacyPushButton->setMinimumSize(QSize(78, 30));
        changePrivacyPushButton->setMaximumSize(QSize(100, 100));
        changePrivacyPushButton->setFont(font);
        changePrivacyPushButton->setStyleSheet(QLatin1String("QPushButton#changePrivacyPushButton\n"
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
"QPushButton#changePrivacyPushButton:hover\n"
"{\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 148, 255, 255), stop:1 rgba(0, 8, 84, 255));\n"
"	border-style: inset;\n"
"}\n"
"\n"
" QPushButton#changePrivacyPushButton:pressed \n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 56, 183, 255), stop:1 rgba(135, 172, 255, 255));\n"
"     border-style: inset;\n"
" }\n"
"\n"
""));
        changePrivacyPushButton->setIconSize(QSize(20, 20));

        gridLayout->addWidget(changePrivacyPushButton, 6, 1, 1, 1);

        newPasswordLineEdit = new QLineEdit(AccountManagementWindow);
        newPasswordLineEdit->setObjectName(QStringLiteral("newPasswordLineEdit"));
        newPasswordLineEdit->setMaximumSize(QSize(100, 20));
        newPasswordLineEdit->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 230);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"min-width: 10em;\n"
"padding: 2px;"));
        newPasswordLineEdit->setMaxLength(256);
        newPasswordLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(newPasswordLineEdit, 5, 0, 1, 1);

        passwordLabel = new QLabel(AccountManagementWindow);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        passwordLabel->setEnabled(true);
        QFont font1;
        font1.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font1.setPointSize(10);
        passwordLabel->setFont(font1);
        passwordLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(passwordLabel, 4, 0, 1, 1);

        currentPasswordLineEdit = new QLineEdit(AccountManagementWindow);
        currentPasswordLineEdit->setObjectName(QStringLiteral("currentPasswordLineEdit"));
        currentPasswordLineEdit->setMinimumSize(QSize(164, 0));
        currentPasswordLineEdit->setMaximumSize(QSize(100, 16777215));
        currentPasswordLineEdit->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 230);\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"min-width: 10em;\n"
"padding: 2px;"));
        currentPasswordLineEdit->setMaxLength(256);
        currentPasswordLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(currentPasswordLineEdit, 3, 0, 1, 1);

        line = new QFrame(AccountManagementWindow);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 2);

        loginLabel = new QLabel(AccountManagementWindow);
        loginLabel->setObjectName(QStringLiteral("loginLabel"));
        loginLabel->setFont(font1);
        loginLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(loginLabel, 2, 0, 1, 1);

        loginTitleLabel = new QLabel(AccountManagementWindow);
        loginTitleLabel->setObjectName(QStringLiteral("loginTitleLabel"));
        QFont font2;
        font2.setFamily(QStringLiteral("MS Reference Sans Serif"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        loginTitleLabel->setFont(font2);
        loginTitleLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        loginTitleLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(loginTitleLabel, 0, 0, 1, 2);

        groupBox = new QGroupBox(AccountManagementWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        publicRadioButton = new QRadioButton(groupBox);
        publicRadioButton->setObjectName(QStringLiteral("publicRadioButton"));
        publicRadioButton->setChecked(true);

        gridLayout_2->addWidget(publicRadioButton, 0, 0, 1, 1);

        privateRadioButton = new QRadioButton(groupBox);
        privateRadioButton->setObjectName(QStringLiteral("privateRadioButton"));
        privateRadioButton->setChecked(false);

        gridLayout_2->addWidget(privateRadioButton, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox, 2, 1, 4, 1);

        serverResponseLabel = new QLabel(AccountManagementWindow);
        serverResponseLabel->setObjectName(QStringLiteral("serverResponseLabel"));
        QFont font3;
        font3.setFamily(QStringLiteral("MS UI Gothic"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        serverResponseLabel->setFont(font3);
        serverResponseLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(serverResponseLabel, 7, 0, 1, 2);

        QWidget::setTabOrder(currentPasswordLineEdit, newPasswordLineEdit);
        QWidget::setTabOrder(newPasswordLineEdit, changePasswordPushButton);

        retranslateUi(AccountManagementWindow);

        QMetaObject::connectSlotsByName(AccountManagementWindow);
    } // setupUi

    void retranslateUi(QDialog *AccountManagementWindow)
    {
        AccountManagementWindow->setWindowTitle(QApplication::translate("AccountManagementWindow", "LoginWindow", 0));
        changePasswordPushButton->setText(QApplication::translate("AccountManagementWindow", "Change", 0));
        changePrivacyPushButton->setText(QApplication::translate("AccountManagementWindow", "Change", 0));
        newPasswordLineEdit->setInputMask(QString());
        newPasswordLineEdit->setText(QApplication::translate("AccountManagementWindow", "poil2cul", 0));
        passwordLabel->setText(QApplication::translate("AccountManagementWindow", "New Password :", 0));
        currentPasswordLineEdit->setText(QApplication::translate("AccountManagementWindow", "poil", 0));
        loginLabel->setText(QApplication::translate("AccountManagementWindow", "Current Password :", 0));
        loginTitleLabel->setText(QApplication::translate("AccountManagementWindow", "Account options", 0));
        groupBox->setTitle(QApplication::translate("AccountManagementWindow", "Privacy", 0));
        publicRadioButton->setText(QApplication::translate("AccountManagementWindow", "Public", 0));
        privateRadioButton->setText(QApplication::translate("AccountManagementWindow", "Private", 0));
        serverResponseLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AccountManagementWindow: public Ui_AccountManagementWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTMANAGEMENTWINDOW_H
