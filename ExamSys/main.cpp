#include "logindialog.h"
#include "examdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    LoginDialog w;
//    w.show();
    ExamDialog ed;
    ed.show();
    return a.exec();
}
