#include "contactmassage.h"
#include "ui_contactmassage.h"

contactMassage::contactMassage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::contactMassage)
{
    ui->setupUi(this);
}

contactMassage::~contactMassage()
{
    delete ui;
}



void contactMassage::setName(QString newName)
{
    ui->nameLabel->setText(newName);
}


QString contactMassage::getName()
{
    return ui->nameLabel->text();
}

void contactMassage::setUid(int newUid){
    ui->uidLabel->setText(QString::number(newUid));
}

int contactMassage::getUid(){
    bool ok;
    int Uid=ui->uidLabel->text().toInt(&ok);
    return Uid;
}

void contactMassage::mouseDoubleClickEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        qDebug()<<"鼠标双击了: "<<this->getName();
        emit doubleClicked(this->getUid());
    }
}

