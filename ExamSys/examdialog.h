#ifndef EXAMDIALOG_H
#define EXAMDIALOG_H
#include <QDialog>
#include <QTimer>
#include <QTextEdit>
#include <QGridLayout>
#include <QLabel>
#include <QVector>
#include <QRadioButton>
#include <QButtonGroup>
#include <QCheckBox>


class ExamDialog : public QDialog
{
    Q_OBJECT
public:
    ExamDialog(QWidget *parent = 0);
    ~ExamDialog();


private:
    void initTimer();
    void initLayout();
    bool initTextEdit();
    void initButtons();//初始化按钮和标签

private slots:
    void updateTime();

private:
    QTimer *m_timer;
    unsigned long m_timeGo;//已用时  单位 秒/s

    QTextEdit *m_textEdit;//显示所有考试试题
    QGridLayout *m_layout;//布局管理器

    unsigned m_question_num;
    QLabel *m_titleLabels[10];//题目标签
    QVector<QLabel*> m_title_labels;//优化后的题目标签

    QRadioButton *m_radioBtns[32];//单选题分组
    QButtonGroup *m_btnGroups[9];//单选按钮分组
    QCheckBox    *m_checkBtns[4];//多选题按钮

    //判断题A，B选项
    QRadioButton *m_radioA,*m_radioB;

};

#endif // EXAMDIALOG_H
