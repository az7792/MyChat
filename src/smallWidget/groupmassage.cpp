#include "groupmassage.h"
#include "ui_groupmassage.h"

groupMassage::groupMassage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::groupMassage)
{
    ui->setupUi(this);
}

groupMassage::~groupMassage()
{
    delete ui;
}


void groupMassage::setName(QString newName)
{
    ui->nameLabel->setText(newName);
}


QString groupMassage::getName()
{
    return ui->nameLabel->text();
}

void groupMassage::setGid(int newGid){
    ui->groupidLabel->setText(QString::number(newGid));
}

int groupMassage::getGid(){
    bool ok;
    int Gid=ui->groupidLabel->text().toInt(&ok);
    return Gid;
}

void groupMassage::mouseDoubleClickEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        qDebug()<<"鼠标双击了: "<<this->getName();
        emit doubleClicked(this->getGid());
    }
}

