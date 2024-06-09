#include "user.h"

User::User(int UID, QString username, QString email,QPixmap avatar)
    : UID(UID), username(username), email(email),avatar(avatar)
{

}

User::User()
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

QPixmap User::getAvatar()
{
    return avatar;
}

// 设置UID
void User::setUID(int UID) {
    this->UID = UID;
}

// 设置用户名
void User::setUsername(QString username) {
    this->username = username;
}

// 设置邮箱
void User::setEmail(QString email) {
    this->email = email;
}

void User::setAvatar(QPixmap avatar)
{
    this->avatar = avatar;
}
