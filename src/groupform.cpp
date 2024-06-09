#include "groupform.h"
#include "ui_groupform.h"

groupForm::groupForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::groupForm)
{
    ui->setupUi(this);
}

groupForm::~groupForm()
{
    delete ui;
}

void groupForm::formInit(User user)
{

    QVector<Group> cList=useIfo.getGroupList(user.getUID());

    for(Group it:cList)
    {
        groupMassage *tempcon=new groupMassage(ui->groupScrollArea);
        tempcon->setGid(it.getGroupid());
        tempcon->setName(it.getGroupname());
        qDebug()<<"群组id:"<<it.getGroupid();
        connect(tempcon,&groupMassage::doubleClicked,this,&groupForm::passContactGid);
        ui->groupScrollAreaWidgetContents->layout()->addWidget(tempcon);
    }
}

