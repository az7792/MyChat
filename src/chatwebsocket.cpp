#include "chatwebsocket.h"

#include <QJsonDocument>
#include <QJsonObject>

ChatWebSocket::ChatWebSocket(QObject *parent)
    : QObject{parent}
{
    webSocket = new QWebSocket();
    connect(webSocket, &QWebSocket::connected, this, &ChatWebSocket::onConnected);
    connect(webSocket, &QWebSocket::disconnected, this, &ChatWebSocket::onDisconnected);
    connect(webSocket, &QWebSocket::textMessageReceived, this, &ChatWebSocket::onTextMessageReceived);
}

ChatWebSocket::~ChatWebSocket()
{
    if (webSocket) {
        webSocket->deleteLater();
    }
}

void ChatWebSocket::connectToServer(const QUrl &url)
{
    webSocket->open(url);
}

void ChatWebSocket::disconnectFromServer()
{
    webSocket->close();
}

void ChatWebSocket::sendMessage(int from,int to,const QString &message)
{
    QJsonObject json;
    json["from"] = from;
    json["to"] = to;
    json["message"] = message;

    QJsonDocument doc(json);
    QString jsonString = QString::fromUtf8(doc.toJson(QJsonDocument::Compact));
    qDebug()<<jsonString;
    webSocket->sendTextMessage(jsonString);
}

void ChatWebSocket::onConnected()
{
    qDebug()<<"连接成功";
    //this->sendMessage(1,1,"abbb");
}

void ChatWebSocket::onDisconnected()
{
    qDebug()<<"断开连接";
}

void ChatWebSocket::onTextMessageReceived(const QString &message)
{
    qDebug()<<"收到消息："+message;
}
