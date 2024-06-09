#ifndef CHATFORM_H
#define CHATFORM_H

#include <QWidget>
#include "user.h"
#include "message.h"
#include "chatwebsocket.h"
#include "sendbox.h"
#include "recvbox.h"
#include<QScrollBar>
namespace Ui {
class ChatForm;
}

class ChatForm : public QWidget
{
    Q_OBJECT

public:
    explicit ChatForm(QWidget *parent = nullptr);
    ~ChatForm();
    ChatWebSocket &chatWebsocket = ChatWebSocket::getInstance();
    int fromId,toId;
    QString chatType;

private slots:
    void on_SendPushButton_clicked();
    void onTextMessageReceived(const QString &message);

private:
    Ui::ChatForm *ui;
};

#endif // CHATFORM_H
