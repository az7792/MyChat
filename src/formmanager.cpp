#include "formmanager.h"

FormManager::FormManager(QWidget *parent)
    : QWidget(parent)
{
    // 创建登录窗体，并设置为 FormManager 的子窗口
    loginForm = new LoginForm(this);

    // 创建注册窗体，并设置为 FormManager 的子窗口
    registerForm = new RegisterForm(this);

    // 创建忘记密码窗体，并设置为 FormManager 的子窗口
    resetPasswordForm = new ResetPasswordForm(this);

    // 创建一个堆叠布局管理器
    stackedLayout = new QStackedLayout(this);
    stackedLayout->addWidget(loginForm); // 将登录窗体添加到布局中
    stackedLayout->addWidget(registerForm); // 将注册窗体添加到布局中
    stackedLayout->addWidget(resetPasswordForm); // 将忘记密码窗体添加到布局中

    // 设置堆叠布局到 FormManager 窗口
    setLayout(stackedLayout);

    // 连接信号到相应的槽函数
    connect(loginForm, &LoginForm::loggedIn, this, &FormManager::showMainForm);//登录成功后显示主页面
    connect(loginForm, &LoginForm::showRegisterForm, this, &FormManager::showRegisterForm);//从 登录界面 返回 注册界面
    connect(loginForm,&LoginForm::showResetPasswordForm,this,&FormManager::showResetPasswordForm);//从 登录界面 返回 找回界面

    connect(registerForm, &RegisterForm::showLoginForm, this, &FormManager::showLoginForm);//从 注册界面 返回 登录界面
    connect(registerForm, &RegisterForm::registered, this, &FormManager::showLoginForm);//注册成功后显示登录界面

    connect(resetPasswordForm,&ResetPasswordForm::showLoginForm,this,&FormManager::showLoginForm);//从 找回界面 返回 登录界面
    // 设置初始显示的窗体为登录窗体
    stackedLayout->setCurrentWidget(loginForm);
}

FormManager::~FormManager()
{

}

void FormManager::showRegisterForm()
{
    stackedLayout->setCurrentWidget(registerForm);
}

void FormManager::showResetPasswordForm()
{
    stackedLayout->setCurrentWidget(resetPasswordForm);
}

void FormManager::showMainForm(User user)
{
    qDebug()<<user.getUsername()<<" "<<user.getEmail()<<" "<<user.getUID();
    qDebug() << "切换主页面";
}

void FormManager::showLoginForm()
{
    stackedLayout->setCurrentWidget(loginForm);
}

