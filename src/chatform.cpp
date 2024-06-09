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

void ChatForm::on_SendPushButton_clicked()//发送
{
    if(ui->plainTextEdit->toPlainText()=="")
        return;
    QString text = ui->plainTextEdit->toPlainText();
    Message message(fromId,toId,chatType,text,"text");
    chatWebsocket.sendMessage(message);
    ui->plainTextEdit->setPlainText("");
    //显示聊天
    SendBox *sendBox = new SendBox(ui->scrollArea);
    sendBox->setBackgroundColor(QColor(0,153,255));
    sendBox->setBordetRadius(10);
    sendBox->setTextColor(Qt::white);
    sendBox->setText(text);
    ui->scrollAreaWidgetContents->layout()->addWidget(sendBox);
    QTimer::singleShot(100, this, [this]() {
        ui->scrollArea->verticalScrollBar()->setValue(ui->scrollArea->verticalScrollBar()->maximum());
    });
    //存储聊天
}

void ChatForm::onTextMessageReceived(const QString &messageString)
{
    RecvBox *recvBox = new RecvBox(ui->scrollArea);
    recvBox->setBackgroundColor(QColor(0,153,255));
    recvBox->setBordetRadius(10);
    recvBox->setTextColor(Qt::white);
    Message message = Message::toMessage(messageString);
    recvBox->setText(message.text);
    ui->ShowMessageLayout->addWidget(recvBox);
}

