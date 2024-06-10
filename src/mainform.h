#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include"contactmassage.h"
#include"contactmanager.h"
#include"groupmassage.h"
#include"contactform.h"
#include"groupform.h"
#include"user.h"
#include"messagelistform.h"
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

    void on_massageButton_clicked();

private:
     Ui::MainForm *ui;

    contactMassage *current_c;
    groupMassage *current_g;
    messageListForm *msgList;


};

#endif // MAINFORM_H
