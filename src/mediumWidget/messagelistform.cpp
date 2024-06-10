#include "messagelistform.h"
#include "ui_messagelistform.h"

messageListForm::messageListForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::messageListForm)
{
    ui->setupUi(this);
}

messageListForm::~messageListForm()
{
    delete ui;
}

void messageListForm::addMessageBox(MessageBox *messageBox)
{
    if(messageBoxMap.find(qMakePair(messageBox->id,messageBox->chatType)) != messageBoxMap.end())
        return;
    messageBoxMap.insert(qMakePair(messageBox->id,messageBox->chatType),messageBox);
    connect(messageBox,&MessageBox::clicked,this,&messageListForm::passMessageBox);
    ui->scrollAreaWidgetContents->layout()->addWidget(messageBox);
}

void messageListForm::updataMessageBox(Message message)
{
    if(message.fromUserUid == sendUser.getUID()){//我发给别人
        auto it = messageBoxMap.find(qMakePair(message.toReceiver,message.receiverType));
        if(it == messageBoxMap.end()){
            //新建一个
            MessageBox *newMessageBox = new MessageBox();
            if(message.receiverType=="user")
                newMessageBox->avatar = userInfoManager.getUser(message.toReceiver).getAvatar();
            newMessageBox->setNumUnread(0);
            newMessageBox->id = message.toReceiver;
            newMessageBox->uid = sendUser.getUID();
            newMessageBox->addMessage(message);
            addMessageBox(newMessageBox);
        }else{
            (*it)->addMessage(message);
        }
    }else{
        if(message.receiverType=="user"){
            auto it = messageBoxMap.find(qMakePair(message.fromUserUid,message.receiverType));
            if(it == messageBoxMap.end()){
                //新建一个
                MessageBox *newMessageBox = new MessageBox();
                User tmp = userInfoManager.getUser(message.fromUserUid);
                newMessageBox->setAvatar(tmp.getAvatar());
                newMessageBox->setName(tmp.getUsername());
                newMessageBox->setNumUnread(0);
                newMessageBox->id = message.fromUserUid;
                newMessageBox->chatType = message.receiverType;
                newMessageBox->uid = sendUser.getUID();
                newMessageBox->addMessage(message);
                addMessageBox(newMessageBox);
            }else{
                (*it)->addMessage(message);
            }
        }else{
            auto it = messageBoxMap.find(qMakePair(message.toReceiver,message.receiverType));
            if(it == messageBoxMap.end()){
                //新建一个
                MessageBox *newMessageBox = new MessageBox();
                newMessageBox->setName(userInfoManager.getGroupByGid(message.toReceiver).getGroupname());
                newMessageBox->setNumUnread(0);
                newMessageBox->id = message.toReceiver;
                newMessageBox->chatType = message.receiverType;
                newMessageBox->uid = sendUser.getUID();
                newMessageBox->addMessage(message);
                addMessageBox(newMessageBox);
            }else{
                (*it)->addMessage(message);
            }
        }
    }




}


