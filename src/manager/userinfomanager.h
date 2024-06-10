#ifndef USERINFOMANAGER_H
#define USERINFOMANAGER_H

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonObject>
#include<QJsonArray>
#include "entity/User.h"
#include "entity/group.h"

class UserInfoManager : public QObject
{
    Q_OBJECT

public:
    static UserInfoManager& getInstance() {
        static UserInfoManager instance;
        return instance;
    }

    ~UserInfoManager() = default;

    // 定义主机名和端口号常量
    const QString HOST_NAME = "localhost";
    const int PORT = 8080;
    const QString BASE_URL = "http://" + HOST_NAME + ":" + QString::number(PORT) + "/";

    bool login(QString email, QString password);
    bool login(int UID, QString password);

    bool registerUser(QString username, QString email, QString password,QPixmap pixmap);
    bool matchCaptcha(QString email, QString code);
    bool getCaptchaByEmail(QString email);
    bool deleteUser(int UID);

    bool isUserExist(int UID);
    bool isGroupExist(int UID);
    bool isEmailExist(QString email);

    bool isUsernameValid(QString username);
    bool isEmailValid(QString email);
    bool isPasswordValid(QString password);

    QString encryptPassword(QString password);  // 加密密码

    bool changeUsername(int UID, QString newUsername);
    bool changeEmail(int UID, QString newEmail);
    bool changePassword(QString email, QString newPassword);

    User getUser(int UID);
    User getUser(QString email);

    Group getGroupByGid(int Gid);

    QVector<User> getContactList(int Uid);
    QVector<Group> getGroupList(int Uid);

private:
    explicit UserInfoManager(QObject *parent = nullptr) : QObject(parent) {
        networkManager = new QNetworkAccessManager(this);
    }

    UserInfoManager(const UserInfoManager&) = delete;            // 禁用拷贝构造函数
    UserInfoManager& operator=(const UserInfoManager&) = delete; // 禁用拷贝赋值运算符

    QNetworkAccessManager *networkManager;

    QJsonDocument sendPostRequest(QString endpoint, QUrlQuery postData);

};

#endif // USERINFOMANAGER_H
