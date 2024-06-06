#ifndef FORMMANAGER_H
#define FORMMANAGER_H

#include <QVector>
#include <QStackedLayout>
#include "loginform.h"
#include "registerform.h"
#include "resetpasswordform.h"
#include "user.h"
class FormManager : public QWidget
{
    Q_OBJECT
public:
    explicit FormManager(QWidget *parent = nullptr);
    ~FormManager();
signals:

private slots:
    void showRegisterForm();
    void showMainForm(User user);
    void showLoginForm();
    void showResetPasswordForm();
private :
    LoginForm *loginForm = nullptr;
    RegisterForm *registerForm = nullptr;
    ResetPasswordForm *resetPasswordForm = nullptr;
    QStackedLayout *stackedLayout=nullptr;
};

#endif // FORMMANAGER_H
