#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include"contactmassage.h"
#include"contactmanager.h"
#include"groupmassage.h"
#include"contactform.h"
#include"groupform.h"
#include "ui_mainwindow.h"
#include"user.h"

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

private:
     Ui::MainForm *ui;

    contactMassage *current_c;
    groupMassage *current_g;


};

#endif // MAINFORM_H
