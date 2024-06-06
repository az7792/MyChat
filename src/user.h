#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>

class User
{
public:
    User(int UID,QString username,QString email);
    int getUID();
    QString getUsername();
    QString getEmail();
private:
    int UID;
    QString username;
    QString email;
};

#endif // USER_H
