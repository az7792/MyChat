#include "contactform.h"
#include "ui_contactform.h"

contactForm::contactForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::contactForm)
{
    ui->setupUi(this);
}

contactForm::~contactForm()
{
    delete ui;
}

void contactForm::formInit(User user)
{

    QLayout *layout = ui->conatctScrollAreaWidgetContents->layout();
    if (layout) {
        QLayoutItem *item;
        while ((item = layout->takeAt(0))) {
            delete item->widget();
            delete item;
        }
    }
    QVector<User> cList=useIfo.getContactList(user.getUID());

    for(User it:cList)
    {
        contactMassage *tempcon=new contactMassage(ui->contactScrollArea);
        tempcon->setUid(it.getUID());
        tempcon->setName(it.getUsername());
        tempcon->setImg(it.getAvatar());
        qDebug()<<"用户id:"<<it.getUID();
        connect(tempcon,&contactMassage::doubleClicked,this,&contactForm::passContactUid);
        ui->conatctScrollAreaWidgetContents->layout()->addWidget(tempcon);
    }
}

