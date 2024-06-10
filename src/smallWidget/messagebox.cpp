#include "messagebox.h"
#include "ui_messagebox.h"
MessageBox::MessageBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MessageBox)
{
    ui->setupUi(this);    
}

MessageBox::~MessageBox()
{
    delete ui;
}

void MessageBox::setTime(const QDateTime &newTime)
{
    time = newTime;
    int hours = newTime.time().hour();
    int minutes = newTime.time().minute();

    // 将小时和分钟格式化为hh:mm
    QString formattedTime = QString("%1:%2")
                                .arg(hours, 2, 10, QChar('0'))   // 保证小时是两位数，不足两位补零
                                .arg(minutes, 2, 10, QChar('0'));// 保证分钟是两位数，不足两位补零
    ui->timeLabel->setText(formattedTime);
}

void MessageBox::setNumUnread(int newNumUnread)
{
    numUnread = newNumUnread;
    if(numUnread==0)
        ui->unReadLabel->setText("");
    else
        ui->unReadLabel->setNum(newNumUnread);
}

void MessageBox::setNewMessage(const QString &newMessage)
{
    this->newMessage = newMessage;
    ui->messageLabel->setText(newMessage);
}

void MessageBox::setName(const QString &newName)
{
    name = newName;
    ui->nameLabel->setText(newName);
}

void MessageBox::setChatType(const QString &newChatType)
{
    chatType = newChatType;
}

void MessageBox::setAvatar(const QPixmap &newAvatar)
{
    avatar = newAvatar;
    ui->avatarLabel->setPixmap(newAvatar);
}

void MessageBox::setId(int newId)
{
    id = newId;
}

void MessageBox::setBackgroundColor(const QColor &backgroundcolor)
{
    setStyleSheet(QString("#BGwidget{background-color: %1;}").arg(backgroundcolor.name()));
}

void MessageBox::setStyleSheet(const QString &style)
{
    QWidget::setStyleSheet(styleSheet()+style);
}