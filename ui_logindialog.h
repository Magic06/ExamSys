/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *userPassWord;
    QLineEdit *lineEditPassWord;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *imgLabel;
    QLineEdit *lineEditUserName;
    QLabel *userName;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(686, 416);
        userPassWord = new QLabel(LoginDialog);
        userPassWord->setObjectName(QString::fromUtf8("userPassWord"));
        userPassWord->setGeometry(QRect(180, 210, 91, 20));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        userPassWord->setFont(font);
        lineEditPassWord = new QLineEdit(LoginDialog);
        lineEditPassWord->setObjectName(QString::fromUtf8("lineEditPassWord"));
        lineEditPassWord->setGeometry(QRect(270, 210, 200, 23));
        lineEditPassWord->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(LoginDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 300, 150, 30));
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(LoginDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(430, 300, 150, 30));
        pushButton_2->setFont(font);
        imgLabel = new QLabel(LoginDialog);
        imgLabel->setObjectName(QString::fromUtf8("imgLabel"));
        imgLabel->setGeometry(QRect(0, 0, 641, 361));
        imgLabel->setPixmap(QPixmap(QString::fromUtf8(":/login.png")));
        imgLabel->setScaledContents(true);
        lineEditUserName = new QLineEdit(LoginDialog);
        lineEditUserName->setObjectName(QString::fromUtf8("lineEditUserName"));
        lineEditUserName->setGeometry(QRect(270, 160, 200, 23));
        userName = new QLabel(LoginDialog);
        userName->setObjectName(QString::fromUtf8("userName"));
        userName->setGeometry(QRect(180, 160, 81, 20));
        userName->setFont(font);
        imgLabel->raise();
        userPassWord->raise();
        lineEditPassWord->raise();
        pushButton->raise();
        pushButton_2->raise();
        lineEditUserName->raise();
        userName->raise();

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "LoginDialog", nullptr));
        userPassWord->setText(QCoreApplication::translate("LoginDialog", "\345\257\206  \347\240\201\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LoginDialog", "\346\263\250\345\206\214", nullptr));
        imgLabel->setText(QString());
        userName->setText(QCoreApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
