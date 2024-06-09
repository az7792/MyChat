#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainForm)
{
    ui->setupUi(this);


    //以下为测试用，将来删去
    user.setUsername("user1");
    user.setUID(1);
    user.setEmail("1460014874@qq.com");
    //以上为测试用，将来删去

    //current_c = new contactMassage();
    //ui->massageWidget->layout()->addWidget(current_c);
    //current_g = new groupMassage();
    //ui->massageWidget->layout()->addWidget(current_g);

    contactForm *cform = new contactForm(ui->conatctWidget);
    cform->formInit(user);

    groupForm *gform=new groupForm(ui->conatctWidget);
    gform->formInit(user);

    ui->ContactStackedWidget->layout()->addWidget(cform);
    ui->ContactStackedWidget->layout()->addWidget(gform);
    ui->ContactStackedWidget->setCurrentIndex(2);



    connect(ui->contactButton,&QPushButton::clicked,this,&MainForm::on_contactButton_clicked);
    connect(ui->groupButton,&QPushButton::clicked,this,&MainForm::on_groupButton_clicked);
    connect(cform,&contactForm::passContactUid,this,&MainForm::open_the_chatWindow);
    connect(gform,&groupForm::passContactGid,this,&MainForm::open_the_groupWindow);
}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::on_contactButton_clicked()
{
    ui->ContactStackedWidget->setCurrentIndex(2);

}


void MainForm::on_groupButton_clicked()
{
    ui->ContactStackedWidget->setCurrentIndex(3);
}



void MainForm::open_the_chatWindow(int Uid)
{
    ui->massageWidget->initChat(user,Uid,"user");
}


//待修改
void MainForm::open_the_groupWindow(int Gid)
{
    //以下暂用用户聊天界面代替
    ui->massageWidget->initChat(user,Gid,"Group");


}

