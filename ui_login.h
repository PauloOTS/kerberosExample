/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QAction *actionreleaseLoginButton;
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QPushButton *loginButton;
    QLineEdit *userText;
    QLineEdit *passTextField;
    QPushButton *cadastroButton;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(266, 134);
        actionreleaseLoginButton = new QAction(Login);
        actionreleaseLoginButton->setObjectName(QStringLiteral("actionreleaseLoginButton"));
        usernameLabel = new QLabel(Login);
        usernameLabel->setObjectName(QStringLiteral("usernameLabel"));
        usernameLabel->setGeometry(QRect(10, 10, 81, 20));
        passwordLabel = new QLabel(Login);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        passwordLabel->setGeometry(QRect(10, 60, 67, 17));
        loginButton = new QPushButton(Login);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(160, 100, 89, 25));
        userText = new QLineEdit(Login);
        userText->setObjectName(QStringLiteral("userText"));
        userText->setGeometry(QRect(100, 10, 151, 25));
        passTextField = new QLineEdit(Login);
        passTextField->setObjectName(QStringLiteral("passTextField"));
        passTextField->setGeometry(QRect(100, 60, 151, 25));
        passTextField->setEchoMode(QLineEdit::Password);
        cadastroButton = new QPushButton(Login);
        cadastroButton->setObjectName(QStringLiteral("cadastroButton"));
        cadastroButton->setGeometry(QRect(40, 100, 89, 25));
        usernameLabel->raise();
        passwordLabel->raise();
        userText->raise();
        passTextField->raise();
        loginButton->raise();
        cadastroButton->raise();

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Dialog", Q_NULLPTR));
        actionreleaseLoginButton->setText(QApplication::translate("Login", "Login", Q_NULLPTR));
        actionreleaseLoginButton->setShortcut(QApplication::translate("Login", "Ctrl+L", Q_NULLPTR));
        usernameLabel->setText(QApplication::translate("Login", "Username", Q_NULLPTR));
        passwordLabel->setText(QApplication::translate("Login", "Password", Q_NULLPTR));
        loginButton->setText(QApplication::translate("Login", "Login", Q_NULLPTR));
        cadastroButton->setText(QApplication::translate("Login", "Cadastrar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
