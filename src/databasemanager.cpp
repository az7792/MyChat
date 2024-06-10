#include "databaseManager.h"
#include <QVector>
void DatabaseManager::initializeDatabase(const QString &dbPath) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);

    if (!db.open()) {
        qDebug() << "Error: Unable to open database" << db.lastError();
        return;
    }

    QSqlQuery query;
    QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS messages (
            messageId INTEGER PRIMARY KEY AUTOINCREMENT,
            fromUserUid INTEGER,
            toReceiver INTEGER,
            receiverType TEXT,
            text TEXT,
            type TEXT,
            sentTime TEXT,
            isread INTEGER DEFAULT 0
        )
    )";

    if (!query.exec(createTableQuery)) {
        qDebug() << "Error: Failed to create table" << query.lastError();
    }
}

void DatabaseManager::saveMessageToDatabase(const Message &msg) {
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Error: Database is not open";
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO messages (fromUserUid, toReceiver, receiverType, text, type, sentTime) VALUES (?, ?, ?, ?, ?, ?)");
    query.addBindValue(msg.fromUserUid);
    query.addBindValue(msg.toReceiver);
    query.addBindValue(msg.receiverType);
    query.addBindValue(msg.text);
    query.addBindValue(msg.type);
    query.addBindValue(msg.sentTime.toString(Qt::ISODate)); // 将 QDateTime 转换为字符串

    if (!query.exec()) {
        qDebug() << "Error: Failed to insert message" << query.lastError();
    }
}



QVector<Message> DatabaseManager::loadMessagesFromDatabase() {
    QVector<Message> messages;

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Error: Database is not open";
        return messages;
    }

    QSqlQuery query("SELECT messageId, fromUserUid, toReceiver, receiverType, text, type, sentTime, isread FROM messages");
    while (query.next()) {
        Message msg;
        msg.messageId = query.value(0).toInt();
        msg.fromUserUid = query.value(1).toInt();
        msg.toReceiver = query.value(2).toInt();
        msg.receiverType = query.value(3).toString();
        msg.text = query.value(4).toString();
        msg.type = query.value(5).toString();
        msg.sentTime = QDateTime::fromString(query.value(6).toString(), Qt::ISODate);
        msg.isRead = query.value(7).toInt();

        messages.append(msg);
    }

    return messages;
}

void DatabaseManager::setMessageReadStatus(int messageId, bool isRead) {
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Error: Database is not open";
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE messages SET isread = ? WHERE messageId = ?");
    query.addBindValue(isRead ? 1 : 0); // 转换为整数值（1 表示已读，0 表示未读）
    query.addBindValue(messageId);

    if (!query.exec()) {
        qDebug() << "Error: Failed to update message read status" << query.lastError();
    }
}
