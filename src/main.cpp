#include "formmanager.h"
#include "addform.h"
#include "FriendNotificationWindow.h""
#include <QApplication>
#include <QPushButton>
#include "chatwebsocket.h"
#include "chatform.h"
#include "mainform.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //FormManager widgetManager;
    //widgetManager.show();
    //MainForm ttt;
    //ttt.show();

    ChatWebSocket &web = ChatWebSocket::getInstance();
    web.connectToServer(QUrl("ws://localhost:8080/chat/1"));
    ChatForm tmp;
    tmp.fromId=1,tmp.toId=2,tmp.chatType="user";
    tmp.show();
    //web.sendMessage("abc");
    //web.disconnectFromServer();
    return a.exec();
}
