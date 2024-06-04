#ifndef LOGINFORM_H
#define LOGINFORM_H

#include "userinfomanager.h"

#include <QWidget>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    LoginForm(QWidget *parent = nullptr);
    ~LoginForm();
    UserInfoManager *userInfoManager;

signals:
    void showRegisterForm(); // 显示注册窗口
    void loggedIn(); // 用户登录成功

private slots:
    void on_showPasswordCheckBox_stateChanged(int state);
    void on_loginPushButton_clicked();
    void on_accountLineEdit_editingFinished();
    void on_passwordLineEdit_editingFinished();
    void on_registerPushButton_clicked();
    void on_retrievePasswordPushButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // LOGINFORM_H
