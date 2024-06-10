#ifndef MESSAGELISTFORM_H
#define MESSAGELISTFORM_H

#include <QWidget>
#include "smallWidget/messagebox.h"
#include "entity/user.h"
#include <QMap>
#include <QPair>
#include "manager/userinfomanager.h"
namespace Ui {
class messageListForm;
}

class messageListForm : public QWidget
{
    Q_OBJECT

public:
    explicit messageListForm(QWidget *parent = nullptr);
    ~messageListForm();
    UserInfoManager &userInfoManager = UserInfoManager::getInstance();
    QMap<QPair<int,QString>,MessageBox*> messageBoxMap;
    void addMessageBox(MessageBox *messageBox);
    User sendUser;
public slots:
    void updataMessageBox(Message message);
signals:
    void passMessageBox(MessageBox *messageBox);
private:
    Ui::messageListForm *ui;
};

#endif // MESSAGELISTFORM_H
