#include "formmanager.h"

#include <QApplication>
#include <QPushButton>
#include "chatwebsocket.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FormManager widgetManager;
    widgetManager.show();

    ChatWebSocket &web = ChatWebSocket::getInstance();
    web.connectToServer(QUrl("ws://localhost:8080/chat/1"));
    //web.sendMessage("abc");
    //web.disconnectFromServer();
    return a.exec();
}
