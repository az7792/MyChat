#ifndef CHATFORM_H
#define CHATFORM_H

#include <QWidget>
#include "entity/user.h"
#include "entity/message.h"
#include "webSocket/chatwebsocket.h"
#include "smallWidget/sendbox.h"
#include "smallWidget/recvbox.h"
#include "smallWidget/messagebox.h"
#include<QScrollBar>
#include <QMap>
#include <manager/userinfomanager.h>
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
    UserInfoManager &userInfoManager = UserInfoManager::getInstance();
    //void initChat(User fromUser,int toId,QString chatType);
    int toId=-1;
    QString chatType;
    User sendUser;
    QMap<int,User> recvUsers;

    void addRecvUsers(int id,QString chatType);
signals:
    void saveToMessageBox(Message message);
public slots:
    void onMessageBoxPass(MessageBox *messageBox);
private slots:
    void on_SendPushButton_clicked();
    void onTextMessageReceived(const QString &message);    

private:
    Ui::ChatForm *ui;
};

#endif // CHATFORM_H
