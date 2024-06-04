#include "registerform.h"
#include "ui_registerform.h"

#include <QMessageBox>

RegisterForm::RegisterForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegisterForm)
{
    ui->setupUi(this);
    userInfoManager = UserInfoManager::getUserInfoManager();
}

RegisterForm::~RegisterForm()
{
    qDebug()<<1;
    delete ui;
}


// 用户名编辑框输入完毕后判断格式
void RegisterForm::on_userNameLineEdit_editingFinished()
{
    QString text = ui->userNameLineEdit->text();
    ui->userNameTipLabel->setText(userInfoManager->isUsernameValid(text) ? "" : "用户名由1到20个汉字、字母、数字或下划线组成");
}

// 账号(email)编辑框输入完毕后判断格式
void RegisterForm::on_accountLineEdit_editingFinished()
{
    QString text = ui->accountLineEdit->text();
    if(!userInfoManager->isEmailValid(text)){
        ui->accountdTipLabel->setText("邮箱格式错误");
        return;
    }
    if(userInfoManager->isEmailExist(text)){
        ui->accountdTipLabel->setText("此邮箱已注册过");
        return;
    }
    ui->accountdTipLabel->setText("");
}

// 密码1编辑框输入完毕后判断格式
void RegisterForm::on_passwordLineEdit1_editingFinished()
{
    QString text1 = ui->passwordLineEdit1->text();
    if(!userInfoManager->isPasswordValid(text1)){
        ui->passwordTipLabel1->setText("密码长度应为6-20个字符，并且必须包含以下四种类型中的至少两种：大写字母、小写字母、数字、特殊符号");
        return;
    }
    ui->passwordTipLabel1->setText("");
    QString text2 = ui->passwordLineEdit2->text();
    ui->passwordTipLabel2->setText(text1==text2?"":"两次密码不一致");
}

// 切换是否显示密码
void RegisterForm::on_showPasswordCheckBox_stateChanged(int state)
{
    if(state == Qt::Checked) {
        ui->passwordLineEdit1->setEchoMode(QLineEdit::Normal);
        ui->passwordLineEdit2->setEchoMode(QLineEdit::Normal);
    } else {
        ui->passwordLineEdit1->setEchoMode(QLineEdit::Password);
        ui->passwordLineEdit2->setEchoMode(QLineEdit::Password);
    }
}

// 密码2编辑框输入完毕后判断格式
void RegisterForm::on_passwordLineEdit2_editingFinished()
{
    QString text1 = ui->passwordLineEdit1->text();
    QString text2 = ui->passwordLineEdit2->text();
    ui->passwordTipLabel2->setText(text1==text2?"":"两次密码不一致");
}

// 用户注册请求
void RegisterForm::on_registerPushButton_clicked()
{
    bool success = false;
    QString username = ui->userNameLineEdit->text();
    QString email = ui->accountLineEdit->text();
    QString password = ui->passwordLineEdit1->text();
    QString captcha = ui->captchaLineEdit->text();
    if(captcha.size()!=6||!userInfoManager->matchCaptcha(email,captcha)){
        QMessageBox::warning(this,"","注册失败,验证码错误");
        return;
    }
    success = userInfoManager->registerUser(username,email,password);
    if(success){
        emit registered();
    }else{
        QMessageBox::warning(this, "注册失败", "注册失败，请重试");
    }
}

//获取验证码
void RegisterForm::on_getCaptchaPushButton_clicked()
{
    if(!userInfoManager->isEmailValid(ui->accountLineEdit->text())){
        QMessageBox::warning(this,"","邮箱格式错误");
        return;
    }
    if(userInfoManager->isEmailExist(ui->accountLineEdit->text())){
        QMessageBox::warning(this,"","邮箱已注册过");
        return;
    }
    // 禁用按钮并开始60秒倒计时
    ui->getCaptchaPushButton->setEnabled(false); // 禁用按钮
    ui->getCaptchaPushButton->setText("60s"); // 初始化按钮文本为60s

    QTimer *timer = new QTimer(this);
    countdown = 60;

    // lambda函数更新按钮文本
    auto updateButton = [this, timer]() mutable {
        if (countdown > 0) {
            ui->getCaptchaPushButton->setText(QString::number(countdown) + "s");
            (countdown)--;
        } else {
            timer->stop();
            ui->getCaptchaPushButton->setText("获取验证码");
            ui->getCaptchaPushButton->setEnabled(true);
            timer->deleteLater();
        }
    };

    // 连接定时器的timeout信号到lambda函数
    connect(timer, &QTimer::timeout, updateButton);

    // 启动定时器，每秒触发一次timeout信号
    timer->start(1000);

    bool getCaptcha = userInfoManager->getCaptchaByEmail(ui->accountLineEdit->text());
    if(!getCaptcha){
        qDebug()<<"获取验证失败";
        timer->stop();
        ui->getCaptchaPushButton->setText("获取验证码");
        ui->getCaptchaPushButton->setEnabled(true); // 重新启用按钮
        timer->deleteLater(); // 删除QTimer对象
        return;
    }
}


void RegisterForm::on_captchaLineEdit_editingFinished()
{
    QString captcha = ui->captchaLineEdit->text();
    if(captcha.size()!=6)
        ui->captchaTipLabel->setText("验证码长度应为6");
    else
        ui->captchaTipLabel->setText("");
}


void RegisterForm::on_returnPushButton_clicked()
{
    emit showLoginForm();
}

