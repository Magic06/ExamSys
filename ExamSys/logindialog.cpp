#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <qmessagebox.h>
#include <QFile>
#include <QTextStream>
#include <QThread>
#include <QDebug>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->imgLabel->setScaledContents(true);
    ui->imgLabel->move(0, 0);


    this->resize(ui->imgLabel->width(),ui->imgLabel->height());
    setWindowTitle("驾校科目一考试登录");
    setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
    ui->lineEditUserName->setFocus();

//    //实现标题时间自增
//    while(true){
//        static int second = 0;
//        QString title = "科目一考试 已用时:";
//        title.append(QString::number(second++)+"秒");
//        setWindowTitle(title);
//        QThread::msleep(1000);
//        qDebug()<<title;
//    }
}
LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_clicked()
{
//    QMessageBox::information(this,"测试","");
    //邮箱格式验证   123456789@qq.com
    QRegExp mail_user("^[a-zA-Z][\\w]{5,17}@([A-Z0-9a-z\\-]+\\.)+[A-Za-z]{2,6}$");
//    QRegExp user_rx2("^[0-9][0-9]*");
    ui->lineEditUserName->setFocus();

    bool res = mail_user.exactMatch(ui->lineEditUserName->text());
    if(!res){
//        QMessageBox::information(this,"检测结果","匹配");
        QMessageBox::information(this,"提示","非法的邮箱地址，请重新输入！");
        ui->lineEditUserName->clear();
        ui->lineEditPassWord->clear();
        ui->lineEditUserName->setFocus();
        return ;
    }else{
        //验证用户身份的合法性
        QString filename = "account.txt";//账号密码文件
        QString username;
        QString passwrd;
        QString strline;
        QStringList strList;

        username = ui->lineEditUserName->text();
        passwrd = ui->lineEditPassWord->text();

        if(passwrd.isEmpty()){
            QMessageBox::information(this,"提示","密码为空，请重新输入!");
            ui->lineEditPassWord->setFocus();
            return ;
        }else{
            //到账号文件中读取用户名和密码
            QFile file(filename);
            QTextStream stream(&file);

            if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
                while (!stream.atEnd()) {
                    strline = stream.readLine();
                    strList = strline.split(",");
                    if(strList.count()!=2){
                        //记录错误日志
                        continue;
                    }
                    if(username==strList[0]){
                        if(passwrd == strList[1]){
                            QMessageBox::information(this,"提示","登录成功");
                            file.close();
                            return ;
                        }else{
                            QMessageBox::information(this,"提示","密码错误，请重新输入!");
                            ui->lineEditPassWord->setFocus();
                            ui->lineEditPassWord->clear();
                            file.close();
                            return ;
                        }
                    }else{
                        continue;
                    }
                }
                QMessageBox::information(this,"提示","账户号或密码错误，请重新输入!");
                ui->lineEditUserName->clear();
                ui->lineEditPassWord->clear();
                ui->lineEditUserName->setFocus();
                file.close();
                return ;
            }else{
                QMessageBox::information(this,"提示","读取账号数据失败！");
                return ;
            }
        }
    }
//    else{
//        QMessageBox::information(this,"检测结果","不匹配");
//    }

}
