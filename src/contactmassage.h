#ifndef CONTACTMASSAGE_H
#define CONTACTMASSAGE_H

#include <QWidget>
#include<QEvent>
#include<QMouseEvent>
#include<QDebug>
#include<QString>

namespace Ui {
class contactMassage;
}

class contactMassage : public QWidget
{
    Q_OBJECT

public:
    explicit contactMassage(QWidget *parent = nullptr);
    ~contactMassage();

    //重写父类的两个虚函数
    virtual void mouseDoubleClickEvent(QMouseEvent *event);


    void setName(QString newName);
    QString getName();
    void setUid(int newUid);
    int getUid();

private:
    Ui::contactMassage *ui;


signals:
    void doubleClicked(int uid);
    void mousePress();

};

#endif // CONTACTMASSAGE_H
