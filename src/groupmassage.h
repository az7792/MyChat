#ifndef GROUPMASSAGE_H
#define GROUPMASSAGE_H

#include <QWidget>
#include<QEvent>
#include<QMouseEvent>
#include<QDebug>
#include<QString>

namespace Ui {
class groupMassage;
}

class groupMassage : public QWidget
{
    Q_OBJECT

public:
    explicit groupMassage(QWidget *parent = nullptr);
    ~groupMassage();

    //重写父类的两个虚函数
    virtual void mouseDoubleClickEvent(QMouseEvent *event);

    void setName(QString newName);
    QString getName();
    void setGid(int newUid);
    int getGid();



private:
    Ui::groupMassage *ui;

signals:
    void doubleClicked(int uid);
    void mousePress();

};

#endif // GROUPMASSAGE_H
