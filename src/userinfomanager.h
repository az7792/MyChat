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
#include "UserInfo.h"

class UserInfoManager: public QObject
{
    Q_OBJECT

public:
    static UserInfoManager* getUserInfoManager();
    ~UserInfoManager();
    // 定义主机名和端口号常量
    const QString HOST_NAME = "localhost";
    const int PORT = 8080;

    bool login(QString email, QString password);
    bool login(int UID, QString password);

    bool registerUser(QString username, QString email, QString password);
    bool deleteUser(int UID);

    bool isUserExist(int UID);
    bool isEmailExist(QString email);
    bool isUsernameValid(QString username);
    bool isEmailValid(QString email);
    bool isPasswordValid(QString password);

    QString encryptPassword(QString password);  // 加密密码

    bool changeUsername(int UID, QString newUsername);
    bool changeEmail(int UID, QString newEmail);
    bool changePassword(int UID, QString newPassword);

    UserInfo getUserInfo(int UID);
    UserInfo getUserInfo(QString email);    
private:
    explicit UserInfoManager(QObject *parent = nullptr);

    UserInfoManager(const UserInfoManager&) = delete; // 禁用拷贝构造函数
    UserInfoManager& operator=(const UserInfoManager&) = delete; // 禁用拷贝赋值运算符
    static QScopedPointer<UserInfoManager> userInfoManager;
    QNetworkAccessManager *networkManager;
};

#endif // USERINFOMANAGER_H
