#ifndef CHATWEBSOCKET_H
#define CHATWEBSOCKET_H

#include <QObject>
#include <QWebSocket>
#include <entity/message.h>
class ChatWebSocket : public QObject
{
    Q_OBJECT
public:
    static ChatWebSocket& getInstance() {
        static ChatWebSocket instance;
        return instance;
    }
    void connectToServer(const QUrl &url);
    void disconnectFromServer();
    void sendMessage(Message message);
signals:
    void textMessageReceived(const QString &message);
public slots:
    void onConnected();
    void onDisconnected();
    void onTextMessageReceived(const QString &message);
private:
    explicit ChatWebSocket(QObject *parent = nullptr);
    ~ChatWebSocket();
    QWebSocket *webSocket=nullptr;

    // 禁用拷贝构造和赋值运算符
    ChatWebSocket(const ChatWebSocket&) = delete;
    ChatWebSocket& operator=(const ChatWebSocket&) = delete;
};

#endif // CHATWEBSOCKET_H
