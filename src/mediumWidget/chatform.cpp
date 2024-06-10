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

void ChatForm::addRecvUsers(int toId, QString chatType)
{
    //清除之前的消息
    QLayout *layout = ui->scrollAreaWidgetContents->layout();
    if (layout) {
        QLayoutItem *item;
        while ((item = layout->takeAt(0))) {
            delete item->widget();
            delete item;
        }
    }

    //加载消息
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
    if(ui->plainTextEdit->toPlainText()=="" || toId==-1)
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
    message.sentTime = QDateTime::currentDateTime();
    message.isRead = 1;
    emit saveToMessageBox(message);
}

void ChatForm::onTextMessageReceived(const QString &messageString)
{
    Message message = Message::toMessage(messageString);
    if(toId == -1){
        emit saveToMessageBox(message);
        return;
    }
    if(message.receiverType != chatType){
        emit saveToMessageBox(message);
        return;
    }else if(message.receiverType == "user" && message.fromUserUid != toId){
        emit saveToMessageBox(message);
        return;
    }else if(message.receiverType == "group" && message.toReceiver != toId){
        emit saveToMessageBox(message);
        return;
    }

    RecvBox *recvBox = new RecvBox(ui->scrollArea);
    recvBox->setBackgroundColor(QColor(0,153,255));
    recvBox->setBordetRadius(10);
    recvBox->setTextColor(Qt::white);
    recvBox->setText(message.text);
    recvBox->setAvatar(recvUsers[message.fromUserUid].getAvatar());
    ui->scrollAreaWidgetContents->layout()->addWidget(recvBox);
    QTimer::singleShot(100, this, [this]() {
        ui->scrollArea->verticalScrollBar()->setValue(ui->scrollArea->verticalScrollBar()->maximum());
    });
    message.isRead = 1;
    emit saveToMessageBox(message);
}

void ChatForm::onMessageBoxPass(MessageBox *messageBox)
{
    //加载用户
    sendUser = userInfoManager.getUser(messageBox->uid);
    toId = messageBox->id,chatType = messageBox->chatType;
    //加载消息
    addRecvUsers(toId,chatType);
    ui->nameLabel->setText(messageBox->name);
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
    messageBox->setNumUnread(0);
}

