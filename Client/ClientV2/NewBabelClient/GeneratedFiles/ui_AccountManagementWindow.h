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
        AccountManagementWindow->resize(232, 186);
        gridLayout = new QGridLayout(AccountManagementWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        changePasswordPushButton = new QPushButton(AccountManagementWindow);
        changePasswordPushButton->setObjectName(QStringLiteral("changePasswordPushButton"));
        changePasswordPushButton->setMinimumSize(QSize(100, 22));
        changePasswordPushButton->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(changePasswordPushButton, 6, 0, 1, 1);

        changePrivacyPushButton = new QPushButton(AccountManagementWindow);
        changePrivacyPushButton->setObjectName(QStringLiteral("changePrivacyPushButton"));
        changePrivacyPushButton->setMinimumSize(QSize(100, 22));
        changePrivacyPushButton->setMaximumSize(QSize(100, 20));

        gridLayout->addWidget(changePrivacyPushButton, 6, 1, 1, 1);

        newPasswordLineEdit = new QLineEdit(AccountManagementWindow);
        newPasswordLineEdit->setObjectName(QStringLiteral("newPasswordLineEdit"));
        newPasswordLineEdit->setMaximumSize(QSize(100, 20));
        newPasswordLineEdit->setMaxLength(256);
        newPasswordLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(newPasswordLineEdit, 5, 0, 1, 1);

        passwordLabel = new QLabel(AccountManagementWindow);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        passwordLabel->setEnabled(true);
        QFont font;
        font.setFamily(QStringLiteral("MS UI Gothic"));
        font.setPointSize(10);
        passwordLabel->setFont(font);

        gridLayout->addWidget(passwordLabel, 4, 0, 1, 1);

        currentPasswordLineEdit = new QLineEdit(AccountManagementWindow);
        currentPasswordLineEdit->setObjectName(QStringLiteral("currentPasswordLineEdit"));
        currentPasswordLineEdit->setMinimumSize(QSize(100, 0));
        currentPasswordLineEdit->setMaximumSize(QSize(100, 16777215));
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
        loginLabel->setFont(font);

        gridLayout->addWidget(loginLabel, 2, 0, 1, 1);

        loginTitleLabel = new QLabel(AccountManagementWindow);
        loginTitleLabel->setObjectName(QStringLiteral("loginTitleLabel"));
        QFont font1;
        font1.setFamily(QStringLiteral("MS UI Gothic"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        loginTitleLabel->setFont(font1);
        loginTitleLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(loginTitleLabel, 0, 0, 1, 2);

        groupBox = new QGroupBox(AccountManagementWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
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
        QFont font2;
        font2.setFamily(QStringLiteral("MS UI Gothic"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        serverResponseLabel->setFont(font2);
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
