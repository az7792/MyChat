#include "userinfomanager.h"
UserInfoManager* UserInfoManager::userInfoManager = nullptr;

UserInfoManager::UserInfoManager(QObject *parent) : QObject(parent)
{
    networkManager = new QNetworkAccessManager(this);
}

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
    QNetworkRequest request;
    request.setUrl(QUrl("http://" + HOST_NAME + ":" + QString::number(PORT) + "/exists/uid?uid=" + QString::number(UID)));
    QNetworkReply * reply = networkManager->get(request); // 发送 GET 请求，并获取返回的响应

    QEventLoop loop;
    // 当请求完成时，中断事件循环
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec(); // 等待请求完成或超时

    bool userExists = false; // 默认用户不存在
    if (reply->isFinished()) {
        if (reply->error() == QNetworkReply::NoError) { // 无错误发生
            // 读取响应数据
            QByteArray responseData = reply->readAll();
            if(QString::fromUtf8(responseData.constData())=="true")
                userExists = true;
        } else {
            // 发生错误时处理错误信息
            qDebug() << "Error: " << reply->errorString();
        }
    } else {
        // 超时处理
        qDebug() << "请求失败";
    }

    reply->deleteLater();
    return userExists;
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
