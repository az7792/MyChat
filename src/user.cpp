#include "user.h"

User::User(int UID, QString username, QString email)
    : UID(UID), username(username), email(email)
{

}

int User::getUID()
{
    return UID;
}

QString User::getUsername()
{
    return username;
}

QString User::getEmail()
{
    return email;
}
