#ifndef GROUPFORM_H
#define GROUPFORM_H

#include <QWidget>
#include<QVBoxLayout>
#include<smallWidget/groupmassage.h>
#include"entity/user.h"
#include"entity/group.h"
#include"manager/userinfomanager.h"

namespace Ui {
class groupForm;
}

class groupForm : public QWidget
{
    Q_OBJECT

public:
    explicit groupForm(QWidget *parent = nullptr);
    ~groupForm();

    UserInfoManager &useIfo=UserInfoManager::getInstance();
    User user;
    void formInit(User user);



private:
    Ui::groupForm *ui;

signals:
    void passContactGid(int Gid);
};

#endif // GROUPFORM_H
