#include "userinfomanager.h"

UserInfoManager::UserInfoManager() {}

UserInfoManager* UserInfoManager::getUserInfoManager() {
    if (userInfoManager == nullptr) {
        userInfoManager = new UserInfoManager();
    }
    return userInfoManager;
}

//登录请求
bool UserInfoManager::login(QString email, QString password) {

}
//登录请求
bool UserInfoManager::login(int UID, QString password) {

}
//注册请求
bool UserInfoManager::registerUser(QString username, QString email, QString password) {

}
//注销用户
bool UserInfoManager::deleteUser(int UID) {

}
//用户是否存在
bool UserInfoManager::isUserExist(int UID) {

}
//邮箱是否存在
bool UserInfoManager::isEmailExist(QString email) {

}
//用户名是否合法
bool UserInfoManager::isUsernameValid(QString username) {

}
//邮箱是否合法
bool UserInfoManager::isEmailValid(QString email) {

}
//密码是否合法
bool UserInfoManager::isPasswordValid(QString password) {

}
//加密密码
QString UserInfoManager::encryptPassword(QString password) {

}
//修改用户名
bool UserInfoManager::changeUsername(int UID, QString newUsername) {

}
//修改邮箱
bool UserInfoManager::changeEmail(int UID, QString newEmail) {

}
//修改密码
bool UserInfoManager::changePassword(int UID, QString newPassword) {

}
//获取用户信息
UserInfo UserInfoManager::getUserInfo(int UID) {

}
//获取用户信息
UserInfo UserInfoManager::getUserInfo(QString email) {

}
