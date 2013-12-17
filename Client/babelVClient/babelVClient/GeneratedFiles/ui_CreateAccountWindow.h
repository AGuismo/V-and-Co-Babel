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
    QLabel *passwordLineEdit;
    QPushButton *createPushButton;
    QLineEdit *passwordLineEdit_2;
    QLineEdit *loginLineEdit;
    QLabel *serverResponseLabel;
    QPushButton *closePushButton;
    QLabel *titleLabel;

    void setupUi(QDialog *CreateAccountWindow)
    {
        if (CreateAccountWindow->objectName().isEmpty())
            CreateAccountWindow->setObjectName(QStringLiteral("CreateAccountWindow"));
        CreateAccountWindow->resize(235, 118);
        gridLayout = new QGridLayout(CreateAccountWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        loginLabel = new QLabel(CreateAccountWindow);
        loginLabel->setObjectName(QStringLiteral("loginLabel"));
        QFont font;
        font.setPointSize(10);
        loginLabel->setFont(font);

        gridLayout->addWidget(loginLabel, 1, 0, 1, 1);

        passwordLineEdit = new QLabel(CreateAccountWindow);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setFont(font);

        gridLayout->addWidget(passwordLineEdit, 2, 0, 1, 1);

        createPushButton = new QPushButton(CreateAccountWindow);
        createPushButton->setObjectName(QStringLiteral("createPushButton"));

        gridLayout->addWidget(createPushButton, 3, 2, 1, 1);

        passwordLineEdit_2 = new QLineEdit(CreateAccountWindow);
        passwordLineEdit_2->setObjectName(QStringLiteral("passwordLineEdit_2"));

        gridLayout->addWidget(passwordLineEdit_2, 2, 1, 1, 2);

        loginLineEdit = new QLineEdit(CreateAccountWindow);
        loginLineEdit->setObjectName(QStringLiteral("loginLineEdit"));

        gridLayout->addWidget(loginLineEdit, 1, 1, 1, 2);

        serverResponseLabel = new QLabel(CreateAccountWindow);
        serverResponseLabel->setObjectName(QStringLiteral("serverResponseLabel"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        serverResponseLabel->setFont(font1);

        gridLayout->addWidget(serverResponseLabel, 3, 0, 1, 1);

        closePushButton = new QPushButton(CreateAccountWindow);
        closePushButton->setObjectName(QStringLiteral("closePushButton"));

        gridLayout->addWidget(closePushButton, 3, 1, 1, 1);

        titleLabel = new QLabel(CreateAccountWindow);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        QFont font2;
        font2.setFamily(QStringLiteral("MS UI Gothic"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        titleLabel->setFont(font2);
        titleLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(titleLabel, 0, 0, 1, 3);


        retranslateUi(CreateAccountWindow);

        QMetaObject::connectSlotsByName(CreateAccountWindow);
    } // setupUi

    void retranslateUi(QDialog *CreateAccountWindow)
    {
        CreateAccountWindow->setWindowTitle(QApplication::translate("CreateAccountWindow", "CreateAccountWindow", 0));
        loginLabel->setText(QApplication::translate("CreateAccountWindow", "Login :", 0));
        passwordLineEdit->setText(QApplication::translate("CreateAccountWindow", "Password", 0));
        createPushButton->setText(QApplication::translate("CreateAccountWindow", "Create", 0));
        serverResponseLabel->setText(QString());
        closePushButton->setText(QApplication::translate("CreateAccountWindow", "Close", 0));
        titleLabel->setText(QApplication::translate("CreateAccountWindow", "New account", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateAccountWindow: public Ui_CreateAccountWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEACCOUNTWINDOW_H
