#ifndef MESSAGE_H
#define MESSAGE_H

#include <QDateTime>

class Message{
public:
    Message();
    Message(int form,int to,QString receiverType,QString text,QString type);
    Message(int messageId,int form,int to,QString receiverType,QString text,QString type,QDateTime sentTime);
    ~Message();
    int messageId;
    int fromUserUid;
    int toReceiver;
    QString receiverType;
    QString text;
    QString type;
    QDateTime sentTime;

    QString toJsonString();

    static Message toMessage(QString jsonString);
signals:
};

#endif // MESSAGE_H
