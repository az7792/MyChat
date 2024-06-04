#include "formmanager.h"

FormManager::FormManager(QWidget *parent)
    : QWidget(parent)
{
    // 创建登录窗体，并设置为 FormManager 的子窗口
    loginForm = new LoginForm(this);

    // 创建注册窗体，并设置为 FormManager 的子窗口
    registerForm = new RegisterForm(this);

    // 创建一个堆叠布局管理器
    stackedLayout = new QStackedLayout(this);
    stackedLayout->addWidget(loginForm); // 将登录窗体添加到布局中
    stackedLayout->addWidget(registerForm); // 将注册窗体添加到布局中

    // 设置堆叠布局到 FormManager 窗口
    setLayout(stackedLayout);

    // 连接信号到相应的槽函数
    connect(loginForm, &LoginForm::loggedIn, this, &FormManager::showMainForm);
    connect(loginForm, &LoginForm::showRegisterForm, this, &FormManager::showRegisterForm);
    connect(registerForm, &RegisterForm::showLoginForm, this, &FormManager::showLoginForm);
    connect(registerForm, &RegisterForm::registered, this, &FormManager::showLoginForm);

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

void FormManager::showMainForm()
{
    qDebug() << "切换主页面";
}

void FormManager::showLoginForm()
{
    stackedLayout->setCurrentWidget(loginForm);
}

