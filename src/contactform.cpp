#include "contactform.h"
#include "ui_contactform.h"

contactForm::contactForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::contactForm)
{
    ui->setupUi(this);


    for(int i=1;i<=10;i++){
        contactMassage *tempcon=new contactMassage(ui->contactScrollArea);
        tempcon->setName(QString::number(i));
        tempcon->setUid(i+1000);
        connect(tempcon,&contactMassage::doubleClicked,this,&contactForm::passContactUid);
        ui->conatctScrollAreaWidgetContents->layout()->addWidget(tempcon);
    }




}

contactForm::~contactForm()
{
    delete ui;
}

