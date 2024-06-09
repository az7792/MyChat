#ifndef GROUPFORM_H
#define GROUPFORM_H

#include <QWidget>
#include<QVBoxLayout>
#include<groupmassage.h>

namespace Ui {
class groupForm;
}

class groupForm : public QWidget
{
    Q_OBJECT

public:
    explicit groupForm(QWidget *parent = nullptr);
    ~groupForm();



private:
    Ui::groupForm *ui;

signals:
    void passContactGid(int Gid);
};

#endif // GROUPFORM_H
