#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QWidget>
#include "entity/message.h"
#include <QVector>
#include <QMouseEvent>
namespace Ui {
class MessageBox;
}

class MessageBox : public QWidget
{
    Q_OBJECT

public:
    explicit MessageBox(QWidget *parent = nullptr);
    ~MessageBox();
    void mousePressEvent(QMouseEvent *event) override;//鼠标单击
    QVector<Message>messages;
    QDateTime time;
    int numUnread;
    QString newMessage;
    QString name;
    QString chatType;
    QPixmap avatar;
    int id;
    void addMessage(Message message);
    void setTime(const QDateTime &newTime);
    void setNumUnread(int newNumUnread);
    void setNewMessage(const QString &newNewMessage);
    void setName(const QString &newName);
    void setChatType(const QString &newChatType);
    void setAvatar(const QPixmap &newAvatar);
    void setId(int newId);
    void setBackgroundColor(const QColor& backgroundcolor);
    void setStyleSheet(const QString& style);
signals:
    void clicked(MessageBox *messageBox);
private:
    Ui::MessageBox *ui;

};

#endif // MESSAGEBOX_H
