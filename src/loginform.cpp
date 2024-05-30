#include "loginform.h"
#include "ui_loginform.h"

#include <registerform.h>

LoginForm::LoginForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    userInfoManager = UserInfoManager::getUserInfoManager();
}

LoginForm::~LoginForm()
{
    delete ui;
}

// 控制是否显示密码
void LoginForm::on_showPasswordCheckBox_stateChanged(int state)
{
    if(state == Qt::Checked) {
        ui->passwordLineEdit->setEchoMode(QLineEdit::Normal);
    } else {
        ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
    }
}

// 账号编辑框输入完毕后判断格式
void LoginForm::on_accountLineEdit_editingFinished()
{
    QString text = ui->accountLineEdit->text();
    if (text.contains('@')) { // 输入的为邮箱
        ui->accountdTipLabel->setText(userInfoManager->isEmailValid(text) ? "" : "邮箱格式错误");
    } else { // 输入的为UID
        bool ok;
        int value = text.toInt(&ok); // 尝试将文本转换为整数
        ui->accountdTipLabel->setText((ok && value >= 1) ? "" : "UID格式错误");
    }
}

// 密码编辑框输入完毕后判断格式
void LoginForm::on_passwordLineEdit_editingFinished()
{
    QString text = ui->passwordLineEdit->text();
    ui->passwordTipLabel->setText(userInfoManager->isPasswordValid(text) ? "" : "密码长度应为6-20个字符，并且必须包含以下四种类型中的至少两种：大写字母、小写字母、数字、特殊符号");
}

// 登录按钮被按下
void LoginForm::on_loginPushButton_clicked()
{
    bool success = false;
    QString text = ui->accountLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    if (text.contains('@')) { // 使用邮箱登录
        success = userInfoManager->login(text,password);
    } else { // 使用UID登录
        int UID = text.toInt();
        success = userInfoManager->login(UID,password);
    }
    if(success){
        //打开主页面
        qDebug()<<"登录成功";
    }else{
        QMessageBox::warning(this, "登录失败", "账号或密码错误，请重新输入。");
    }
}

// 注册按钮被按下
void LoginForm::on_registerPushButton_clicked()
{

}

// 忘记密码按钮被按下
void LoginForm::on_retrievePasswordPushButton_clicked()
{

}

