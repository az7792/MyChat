#include "userinfo.h"

UserInfo::UserInfo(int UID, QString username, QString email)
    : UID(UID), username(username), email(email)
{

}

int UserInfo::getUID()
{
    return UID;
}

QString UserInfo::getUsername()
{
    return username;
}

QString UserInfo::getEmail()
{
    return email;
}
