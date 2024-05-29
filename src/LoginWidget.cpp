#include "LoginWidget.h"
#include "ui_LoginWidget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    userInfoManager = UserInfoManager::getUserInfoManager();
    connect(ui->loginPushButton,&QPushButton::clicked,this,&Widget::handleLoginPushButtonClicked);
    connect(ui->registerPushButton,&QPushButton::clicked,this,[](){
        qDebug()<<1;
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleLoginPushButtonClicked()
{
    qDebug()<<userInfoManager->isUserExist(1);
    qDebug()<<userInfoManager->isEmailExist("1460014874@qq.com1");
}
