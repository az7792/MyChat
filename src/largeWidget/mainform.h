#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include"smallWidget/contactmassage.h"
#include"smallWidget/groupmassage.h"
#include"mediumWidget/contactform.h"
#include"mediumWidget//groupform.h"
#include"entity/user.h"
#include "mediumWidget/addform.h""
#include "mediumWidget/FriendNotificationWindow.h""
#include"mediumWidget/messagelistform.h"
namespace Ui {
class MainForm;
}

class MainForm : public QWidget
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = nullptr);
    ~MainForm();
    User user;

private slots:
    void on_contactButton_clicked();

    void on_groupButton_clicked();

    void open_the_chatWindow(int Uid);

    void open_the_groupWindow(int Uid);
    void on_applyButton_clicked();

    void on_searchButton_clicked();
    void on_massageButton_clicked();

private:
     Ui::MainForm *ui;

    contactMassage *current_c;
    groupMassage *current_g;
    messageListForm *msgList;

    AddForm *addForm; // 保存 AddForm 的指针
    FriendNotificationWindow *notificationWindow; // 保存 FriendNotificationWindow 的指针


};

#endif // MAINFORM_H
