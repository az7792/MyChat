#ifndef USERINFOMANAGER_H
#define USERINFOMANAGER_H

#include <QObject>
#include <QString>
#include "UserInfo.h"

class UserInfoManager
{
public:
    UserInfoManager * userInfoManager = nullptr;

    UserInfoManager* getUserInfoManager();

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
    UserInfoManager();
};

#endif // USERINFOMANAGER_H
