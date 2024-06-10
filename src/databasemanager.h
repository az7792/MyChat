#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql>
#include <QDebug>
#include "message.h"

class DatabaseManager {
public:
    static void initializeDatabase(const QString &dbPath);
    static void saveMessageToDatabase(const Message &msg);
    static QVector<Message> loadMessagesFromDatabase();
    static void setMessageReadStatus(int messageId, bool isRead);
};

#endif // DATABASEMANAGER_H
