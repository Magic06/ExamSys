#include "examdialog.h"
#include <QDebug>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QLabel>
#include <QVector>

ExamDialog::ExamDialog(QWidget *parent):QDialog(parent),m_question_num(0)
{
    //设置字体和大小
    QFont font;
    font.setPointSize(12);
    this->setFont(font);

    //设置窗体的background
    setPalette(QPalette(QColor(209,215,255)));
    resize(800,900);

    //显示关闭,最大化和最小化按钮
    setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMinMaxButtonsHint );
    initTimer();
    initLayout();
    initTextEdit();
    initButtons();
}

void ExamDialog::updateTime()
{

    m_timeGo++;
    QString title;//考试已用时: x分x秒
    title=QString::asprintf("考试已用时: %lu分%lu秒",m_timeGo/60,m_timeGo%60);
//    qDebug()<<title;
    setWindowTitle(title);
}

ExamDialog::~ExamDialog(){
    m_timer->stop();
    delete m_timer;

    //清理标签
    QVector<QLabel*>::iterator it = m_title_labels.begin();
    while(it != m_title_labels.end()){
        QLabel *temp = *it;
        it = m_title_labels.erase(it);
        delete temp;
    }
}

void ExamDialog::initTimer()
{
    m_timeGo = 0;
    m_timer = new QTimer(this);//定时器对象
    m_timer->setInterval(1000);
    connect(m_timer,SIGNAL(timeout()),this,SLOT(updateTime()));
    m_timer->start();
}

void ExamDialog::initLayout()
{

    m_layout = new QGridLayout(this);
    m_layout->setMargin(10);//设置窗体与控件的间隔
    m_layout->setSpacing(10);//设置控件间的间距
}

//考试题目显示
bool ExamDialog::initTextEdit()
{
    QString strLine;
    QString strText;
    bool isFirstReq = true;

    QString fileName = "exam.txt";
    QFile file(fileName);
    QTextStream textStream(&file);

    textStream.setCodec("UTF-8");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        m_textEdit = new QTextEdit(this);
        m_textEdit->setReadOnly(true);
        while(!textStream.atEnd()){
            strLine = textStream.readLine();
//            qDebug()<<"read line:"<<strLine;
            strLine = strLine.trimmed();
            if(strLine.length() < 1) continue;
            if(strLine.at(0) == '#') continue;
            if(strLine.at(0) == '!') continue;
            if(strLine.at(0) == 'Q'){//问题
                m_question_num++;
                if(isFirstReq){
                    isFirstReq = false;
                }else{
                    strText.append("\n");
                }

                strText.append(strLine.remove(0,1));
                strText.append("\n");
                continue;
            }
            if(strLine.at(0) == '.'){//答案
                strText.append(strLine.remove(0,1));
                strText.append("\n");
                continue;
            }

        }
        m_textEdit->setText(strText);
        m_layout->addWidget(m_textEdit,0,0,1,10);
        return true;
    }else{
        QMessageBox::information(this,"提示","打开失败");
        return false;
    }
}

void ExamDialog::initButtons()
{
//    for(int i=0; i<10; i++){
//        m_titleLabels[i] = new QLabel(this);
//        m_titleLabels[i]->setText("第"+QString::number(i+1)+"题");
//        m_layout->addWidget(m_titleLabels[i],1,i);
//    }
    QStringList strList = {"A","B","C","D"};
//    QString str = "ABCD";
    for(unsigned i = 0; i < m_question_num; i++){
        //生成标签
        QLabel *item = new QLabel(this);
        item->setText("第"+QString::number(i+1)+"题");
        m_layout->addWidget(item,1,i);
        m_title_labels.append(item);
        //生成按钮(组)
        if(i < 8){
            m_btnGroups[i] = new QButtonGroup(this);
            for(int j = 0; j < 4; j++){
                m_radioBtns[i * 4 + j] = new QRadioButton(this);
                m_radioBtns[i * 4 + j]->setText(strList[j]);
                m_btnGroups[i]->addButton(m_radioBtns[i * 4 + j]);
                m_layout->addWidget(m_radioBtns[i * 4 + j], 2 + j, i);
            }

        }
    }

}
