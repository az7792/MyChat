#ifndef FORMMANAGER_H
#define FORMMANAGER_H

#include <QVector>
#include <QStackedLayout>
#include "smallWidget/loginform.h"
#include "smallWidget/registerform.h"
#include"largeWidget/mainform.h"
#include "smallWidget/resetpasswordform.h"
#include "entity/user.h"
#include"webSocket/chatwebsocket.h"
class FormManager : public QWidget
{
    Q_OBJECT
public:
    explicit FormManager(QWidget *parent = nullptr);
    ~FormManager();

    ChatWebSocket &web = ChatWebSocket::getInstance();
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
    MainForm *mainForm=nullptr;
};

#endif // FORMMANAGER_H
