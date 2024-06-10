#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include"contactmassage.h"
#include"contactmanager.h"
#include"groupmassage.h"
#include"contactform.h"
#include"groupform.h"
<<<<<<< HEAD
//#include "ui_mainwindow.h"
#include"user.h"
#include "addform.h""
#include "FriendNotificationWindow.h""

=======
#include"user.h"
#include"messagelistform.h"
>>>>>>> feature3
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
    contactmanager cmarger;

private slots:
    void on_contactButton_clicked();

    void on_groupButton_clicked();

    void open_the_chatWindow(int Uid);

    void open_the_groupWindow(int Uid);

<<<<<<< HEAD
    void on_applyButton_clicked();

    void on_addButton_clicked();
=======
    void on_massageButton_clicked();
>>>>>>> feature3

private:
     Ui::MainForm *ui;

    contactMassage *current_c;
    groupMassage *current_g;
    messageListForm *msgList;

    AddForm *addForm; // 保存 AddForm 的指针
    FriendNotificationWindow *notificationWindow; // 保存 FriendNotificationWindow 的指针


};

#endif // MAINFORM_H
