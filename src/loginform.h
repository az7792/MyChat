#ifndef LOGINFORM_H
#define LOGINFORM_H

#include "userinfomanager.h"

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    LoginForm(QWidget *parent = nullptr);
    ~LoginForm();
    UserInfoManager &userInfoManager = UserInfoManager::getInstance();

signals:
    void showRegisterForm(); // 显示注册窗口
    void loggedIn(); // 用户登录成功
    void showResetPasswordForm();// 显示忘记密码窗口

private slots:
    void on_showPasswordCheckBox_stateChanged(int state);
    void on_loginPushButton_clicked();
    void on_accountLineEdit_editingFinished();
    void on_passwordLineEdit_editingFinished();
    void on_registerPushButton_clicked();
    void on_retrievePasswordPushButton_clicked();

private:
    Ui::LoginForm *ui;
};
#endif // LOGINFORM_H
