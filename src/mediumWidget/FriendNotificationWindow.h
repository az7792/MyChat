#ifndef FRIENDNOTIFICATIONWINDOW_H
#define FRIENDNOTIFICATIONWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QListWidgetItem>

class FriendNotificationWindow : public QWidget {
    Q_OBJECT

public:
    explicit FriendNotificationWindow(QWidget *parent = nullptr);

private slots:
    void toggleMaximizeRestore();
    void onMinimizeButtonClicked();
    void onCloseButtonClicked();
    void onFilterButtonClicked();
    void onDeleteButtonClicked();
    void onAcceptButtonClicked(QListWidgetItem *item);
    void onRejectButtonClicked(QListWidgetItem *item);
    void onDeleteAllButtonClicked();

private:
    void setupUI();
    QWidget* createNotificationWidget(const QString &text, QListWidgetItem *item);

    // UI elements
    QPushButton *minimizeButton;
    QPushButton *maximizeButton;
    QPushButton *closeButton;
    QPushButton *deleteAllButton;
    QListWidget *notificationList;

    // Layouts
    QVBoxLayout *mainLayout;
    QHBoxLayout *titleLayout;
};

#endif // FRIENDNOTIFICATIONWINDOW_H
