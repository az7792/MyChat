#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>

class User
{
public:
    User(int UID,QString username,QString email);
    User();
    int getUID();
    QString getUsername();
    QString getEmail();
    void setUID(int UID);
    void setUsername(QString username);
    void setEmail(QString email);
private:
    int UID=-1;
    QString username;
    QString email;
};

#endif // USER_H
