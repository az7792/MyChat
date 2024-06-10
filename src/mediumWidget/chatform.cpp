#include "mediumWidget/chatform.h"
#include "ui_chatform.h"

#include <QTimer>

ChatForm::ChatForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatForm)
{
    ui->setupUi(this);
    ui->scrollAreaWidgetContents->layout()->setSpacing(25);
    connect(&chatWebsocket,&ChatWebSocket::textMessageReceived,this,&ChatForm::onTextMessageReceived);
}

ChatForm::~ChatForm()
{
    delete ui;
}

void ChatForm::initChat(User fromUser, int toId, QString chatType)
{
    //加载用户
    sendUser = fromUser;
    addRecvUsers(toId,chatType);
    //加载消息
}

void ChatForm::addRecvUsers(int toId, QString chatType)
{
    this->chatType = chatType;
    this->toId=toId;
    recvUsers.clear();
    if(chatType == "user"){
        User recvUser = userInfoManager.getUser(toId);
        recvUsers.insert(recvUser.getUID(),recvUser);
        ui->nameLabel->setText(recvUser.getUsername());
    }else{
        //加载群成员
        QVector<User>Users = userInfoManager.getGroupMembers(toId);
        ui->nameLabel->setText(userInfoManager.getGroupByGid(toId).getGroupname());
        for(auto v:Users){
            recvUsers.insert(v.getUID(),v);
        }
    }
}

void ChatForm::on_SendPushButton_clicked()//发送
{
    if(ui->plainTextEdit->toPlainText()=="" && toId==-1)
        return;
    QString text = ui->plainTextEdit->toPlainText();
    Message message(sendUser.getUID(),toId,chatType,text,"text");
    chatWebsocket.sendMessage(message);
    ui->plainTextEdit->setPlainText("");
    //显示聊天
    SendBox *sendBox = new SendBox(ui->scrollArea);
    sendBox->setBackgroundColor(QColor(0,153,255));
    sendBox->setBordetRadius(10);
    sendBox->setTextColor(Qt::white);
    sendBox->setText(text);
    sendBox->setAvatar(sendUser.getAvatar());
    ui->scrollAreaWidgetContents->layout()->addWidget(sendBox);
    QTimer::singleShot(100, this, [this]() {
        ui->scrollArea->verticalScrollBar()->setValue(ui->scrollArea->verticalScrollBar()->maximum());
    });
    //存储聊天
}

void ChatForm::onTextMessageReceived(const QString &messageString)
{
    if(toId == -1){//还未选择聊天对象
        //存消息
        return;
    }
    RecvBox *recvBox = new RecvBox(ui->scrollArea);
    recvBox->setBackgroundColor(QColor(0,153,255));
    recvBox->setBordetRadius(10);
    recvBox->setTextColor(Qt::white);
    Message message = Message::toMessage(messageString);
    recvBox->setText(message.text);
    recvBox->setAvatar(recvUsers[message.fromUserUid].getAvatar());
    ui->scrollAreaWidgetContents->layout()->addWidget(recvBox);
    QTimer::singleShot(100, this, [this]() {
        ui->scrollArea->verticalScrollBar()->setValue(ui->scrollArea->verticalScrollBar()->maximum());
    });
}

void ChatForm::onMessageBoxPass(MessageBox *messageBox)
{
    ui->nameLabel->setText(messageBox->name);
    toId = messageBox->id;
    chatType = messageBox->chatType;
    addRecvUsers(toId,chatType);
    for(auto v:messageBox->messages){
        if(v.fromUserUid == sendUser.getUID())
        {
            SendBox *sendBox = new SendBox(ui->scrollArea);
            sendBox->setBackgroundColor(QColor(0,153,255));
            sendBox->setBordetRadius(10);
            sendBox->setTextColor(Qt::white);
            sendBox->setText(v.text);
            sendBox->setAvatar(sendUser.getAvatar());
            ui->scrollAreaWidgetContents->layout()->addWidget(sendBox);
            QTimer::singleShot(100, this, [this]() {
                ui->scrollArea->verticalScrollBar()->setValue(ui->scrollArea->verticalScrollBar()->maximum());
            });
        }else{
            RecvBox *recvBox = new RecvBox(ui->scrollArea);
            recvBox->setBackgroundColor(QColor(0,153,255));
            recvBox->setBordetRadius(10);
            recvBox->setTextColor(Qt::white);
            recvBox->setText(v.text);
            recvBox->setAvatar(recvUsers[v.fromUserUid].getAvatar());
            ui->scrollAreaWidgetContents->layout()->addWidget(recvBox);
            QTimer::singleShot(100, this, [this]() {
                ui->scrollArea->verticalScrollBar()->setValue(ui->scrollArea->verticalScrollBar()->maximum());
            });
        }
    }
}

