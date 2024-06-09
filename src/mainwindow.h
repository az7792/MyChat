#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"contactmassage.h"
#include"contactmanager.h"
#include"groupmassage.h"
#include"contactform.h"
#include"groupform.h"
#include"user.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    User user;

private slots:
    void on_contactButton_clicked();

    void on_groupButton_clicked();

    void open_the_chatWindow(int Uid);

    void open_the_groupWindow(int Uid);

private:
    Ui::MainWindow *ui;

    contactMassage *current_c;
    groupMassage *current_g;
};
#endif // MAINWINDOW_H
