#include "chatform.h"
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
    this->chatType = chatType;
    this->toId=toId;
    if(chatType == "user"){
        User recvUser = userInfoManager.getUser(toId);
        recvUsers.insert(recvUser.getUID(),recvUser);
        ui->nameLabel->setText(recvUser.getUsername());
    }else{
        //加载群成员
    }
    //加载消息
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
    ui->ShowMessageLayout->addWidget(recvBox);
}

