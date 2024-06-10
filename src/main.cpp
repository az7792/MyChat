#include "manager/formmanager.h"
#include <QApplication>
#include <QBuffer>
#include <QPushButton>
#include <mediumWidget/messagelistform.h>
#include <smallWidget/messagebox.h>
#include <QColor>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // DatabaseManager::initializeDatabase("messages.db");
    // Message msg(1,1,2,"user","message","text",QDateTime::currentDateTime());
    // //DatabaseManager::saveMessageToDatabase(msg);
    // DatabaseManager::setMessageReadStatus(1,0);
    // QVector<Message> ms = DatabaseManager::loadMessagesFromDatabase();
    // for(auto v:ms)
    // {
    //     qDebug()<<v.messageId<<" "<<v.sentTime<<v.isRead;
    // }
    FormManager widgetManager;
    widgetManager.show();
    // MainForm ttt;
    // ttt.show();

    // messageListForm tmp;
    // MessageBox *box1 = new MessageBox();
    // box1->setTime(QDateTime::currentDateTime());
    // box1->setNewMessage("nihao");
    // box1->setName("abc");
    // box1->setNumUnread(5);
    // box1->show();
    // tmp.addMessageBox(box1);
    // tmp.show();

    // ChatWebSocket &web = ChatWebSocket::getInstance();
    // web.connectToServer(QUrl("ws://localhost:8080/chat/1"));
    // ChatForm tmp;
    // tmp.fromId=1,tmp.toId=2,tmp.chatType="user";
    // tmp.show();
    // web.sendMessage("abc");
    // web.disconnectFromServer();
    // MainWindow w;
    // w.show();
    // ChatWebSocket &web = ChatWebSocket::getInstance();
    // web.connectToServer(QUrl("ws://localhost:8080/chat/1"));

    // UserInfoManager &us = UserInfoManager::getInstance();
    // ChatForm tmp;
    // User sendUser = us.getUser(1);
    // tmp.initChat(sendUser, 19, "user");
    // tmp.show();
    // QPixmap ttt = sendUser.getAvatar();
    // 指定输出目录
    // ttt.save("C:/Users/li'qi/Desktop/convertedImage13.jpg", "JPG");
    // return a.exec();
    // tmp.initChat(sendUser,12,"user");

    // tmp.show();

    // web.sendMessage("abc");
    // web.disconnectFromServer();
    //  RegisterForm tmp;
    //  tmp.show();

    return a.exec();
}

//   az77927792
