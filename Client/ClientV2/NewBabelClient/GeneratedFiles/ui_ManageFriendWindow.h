/********************************************************************************
** Form generated from reading UI file 'ManageFriendWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_ManageFriendWindow
{
public:
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

    void setupUi(QDialog *ManageFriendWindow)
    {
        if (ManageFriendWindow->objectName().isEmpty())
            ManageFriendWindow->setObjectName(QStringLiteral("ManageFriendWindow"));
        ManageFriendWindow->resize(232, 186);
        changePasswordPushButton = new QPushButton(ManageFriendWindow);
        changePasswordPushButton->setObjectName(QStringLiteral("changePasswordPushButton"));
        changePasswordPushButton->setGeometry(QRect(9, 133, 100, 22));
        changePasswordPushButton->setMinimumSize(QSize(100, 22));
        changePasswordPushButton->setMaximumSize(QSize(100, 16777215));
        changePrivacyPushButton = new QPushButton(ManageFriendWindow);
        changePrivacyPushButton->setObjectName(QStringLiteral("changePrivacyPushButton"));
        changePrivacyPushButton->setGeometry(QRect(123, 134, 100, 22));
        changePrivacyPushButton->setMinimumSize(QSize(100, 22));
        changePrivacyPushButton->setMaximumSize(QSize(100, 20));
        newPasswordLineEdit = new QLineEdit(ManageFriendWindow);
        newPasswordLineEdit->setObjectName(QStringLiteral("newPasswordLineEdit"));
        newPasswordLineEdit->setGeometry(QRect(9, 107, 100, 20));
        newPasswordLineEdit->setMaximumSize(QSize(100, 20));
        newPasswordLineEdit->setMaxLength(256);
        newPasswordLineEdit->setEchoMode(QLineEdit::Password);
        passwordLabel = new QLabel(ManageFriendWindow);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        passwordLabel->setEnabled(true);
        passwordLabel->setGeometry(QRect(9, 88, 86, 16));
        QFont font;
        font.setFamily(QStringLiteral("MS UI Gothic"));
        font.setPointSize(10);
        passwordLabel->setFont(font);
        currentPasswordLineEdit = new QLineEdit(ManageFriendWindow);
        currentPasswordLineEdit->setObjectName(QStringLiteral("currentPasswordLineEdit"));
        currentPasswordLineEdit->setGeometry(QRect(9, 62, 100, 20));
        currentPasswordLineEdit->setMinimumSize(QSize(100, 0));
        currentPasswordLineEdit->setMaximumSize(QSize(100, 16777215));
        currentPasswordLineEdit->setMaxLength(256);
        currentPasswordLineEdit->setEchoMode(QLineEdit::Password);
        line = new QFrame(ManageFriendWindow);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(9, 34, 214, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        loginLabel = new QLabel(ManageFriendWindow);
        loginLabel->setObjectName(QStringLiteral("loginLabel"));
        loginLabel->setGeometry(QRect(9, 43, 108, 16));
        loginLabel->setFont(font);
        loginTitleLabel = new QLabel(ManageFriendWindow);
        loginTitleLabel->setObjectName(QStringLiteral("loginTitleLabel"));
        loginTitleLabel->setGeometry(QRect(9, 9, 149, 19));
        QFont font1;
        font1.setFamily(QStringLiteral("MS UI Gothic"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        loginTitleLabel->setFont(font1);
        loginTitleLabel->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(ManageFriendWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(123, 43, 77, 73));
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

        serverResponseLabel = new QLabel(ManageFriendWindow);
        serverResponseLabel->setObjectName(QStringLiteral("serverResponseLabel"));
        serverResponseLabel->setGeometry(QRect(9, 161, 16, 16));
        QFont font2;
        font2.setFamily(QStringLiteral("MS UI Gothic"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        serverResponseLabel->setFont(font2);
        serverResponseLabel->setAlignment(Qt::AlignCenter);
        QWidget::setTabOrder(currentPasswordLineEdit, newPasswordLineEdit);
        QWidget::setTabOrder(newPasswordLineEdit, changePasswordPushButton);

        retranslateUi(ManageFriendWindow);

        QMetaObject::connectSlotsByName(ManageFriendWindow);
    } // setupUi

    void retranslateUi(QDialog *ManageFriendWindow)
    {
        ManageFriendWindow->setWindowTitle(QApplication::translate("ManageFriendWindow", "LoginWindow", 0));
        changePasswordPushButton->setText(QApplication::translate("ManageFriendWindow", "Change", 0));
        changePrivacyPushButton->setText(QApplication::translate("ManageFriendWindow", "Change", 0));
        newPasswordLineEdit->setInputMask(QString());
        newPasswordLineEdit->setText(QApplication::translate("ManageFriendWindow", "poil2cul", 0));
        passwordLabel->setText(QApplication::translate("ManageFriendWindow", "New Password :", 0));
        currentPasswordLineEdit->setText(QApplication::translate("ManageFriendWindow", "poil", 0));
        loginLabel->setText(QApplication::translate("ManageFriendWindow", "Current Password :", 0));
        loginTitleLabel->setText(QApplication::translate("ManageFriendWindow", "Account options", 0));
        groupBox->setTitle(QApplication::translate("ManageFriendWindow", "Privacy", 0));
        publicRadioButton->setText(QApplication::translate("ManageFriendWindow", "Public", 0));
        privateRadioButton->setText(QApplication::translate("ManageFriendWindow", "Private", 0));
        serverResponseLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ManageFriendWindow: public Ui_ManageFriendWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEFRIENDWINDOW_H
