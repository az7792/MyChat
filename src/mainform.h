#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include"contactmassage.h"
#include"contactmanager.h"
#include"groupmassage.h"
#include"contactform.h"
#include"groupform.h"
//#include "ui_mainwindow.h"
#include"user.h"
#include "addform.h""
#include "FriendNotificationWindow.h""

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

    void on_addButton_clicked();

private:
     Ui::MainForm *ui;

    contactMassage *current_c;
    groupMassage *current_g;

    AddForm *addForm; // 保存 AddForm 的指针
    FriendNotificationWindow *notificationWindow; // 保存 FriendNotificationWindow 的指针


};

#endif // MAINFORM_H
