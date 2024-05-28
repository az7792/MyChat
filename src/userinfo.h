#ifndef USERINFO_H
#define USERINFO_H

#include <QObject>
#include <QString>

class UserInfo
{
public:
    UserInfo(int UID,QString username,QString email);
    int getUID();
    QString getUsername();
    QString getEmail();
private:
    int UID;
    QString username;
    QString email;
};

#endif // USERINFO_H
