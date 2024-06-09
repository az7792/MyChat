#include "groupform.h"
#include "ui_groupform.h"

groupForm::groupForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::groupForm)
{
    ui->setupUi(this);

    for(int i=10;i<=20;i++){
        groupMassage *tempcon=new groupMassage(ui->groupScrollArea);
        tempcon->setName(QString::number(i));
        tempcon->setGid(i+1000);
        connect(tempcon,&groupMassage::doubleClicked,this,&groupForm::passContactGid);
        ui->groupScrollAreaWidgetContents->layout()->addWidget(tempcon);
    }
}

groupForm::~groupForm()
{
    delete ui;
}


