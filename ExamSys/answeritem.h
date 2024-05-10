#ifndef ANSWERITEM_H
#define ANSWERITEM_H

#include <QString>
#include <QMap>
#include <QVector>
#include <QPair>
#include <QStringList>

class answeritem
{
public:
    answeritem(const QString label);
    ~answeritem();

    unsigned int get_num() const{
        return m_num;
    }

    bool add_item(QString item){
        //防御性编程 在增加选项时，要判断选项是否存在
        for(int i = 0;i < m_itmes.count();i++){
            if(m_itmes[i].first == item){
                return false;
            }
        }
        m_itmes.append(QPair<QString,int> (item,0));
        return true;

    }

private:
    QString m_label;        //题目标签
    unsigned int m_num;     //选项的个数
    bool is_single_type;    //如果有多个类型，使用枚举  单选-false  多选-true
    QVector<QPair<QString,int>> m_itmes;  //题目选项 0-表示没选 1-表示已选
    QStringList m_answers;  //答案列表

    int m_begin_row;        //显示的行号,
    int m_begin_column;     //显示的列号

    int m_total_score;      //题目总分
    int m_score;            //题目分值

};

#endif // ANSWERITEM_H
