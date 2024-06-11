#include "friendnotificationwindow.h"
#include <QIcon>
#include <QApplication>
#include <QScreen>
#include <QListWidgetItem>
#include <QDebug>

FriendNotificationWindow::FriendNotificationWindow(QWidget *parent)
    : QWidget(parent)
{
    setupUI();

    // 示例数据
    for (int i = 1; i <= 5; ++i) {
        QListWidgetItem *item = new QListWidgetItem(notificationList);
        QWidget *widget = createNotificationWidget(QString("好友请求 %1").arg(i), item);
        item->setSizeHint(widget->sizeHint());
        notificationList->setItemWidget(item, widget);
    }

    // 连接按钮信号与槽函数
    connect(minimizeButton, &QPushButton::clicked, this, &FriendNotificationWindow::onMinimizeButtonClicked);
    connect(maximizeButton, &QPushButton::clicked, this, &FriendNotificationWindow::toggleMaximizeRestore);
    connect(closeButton, &QPushButton::clicked, this, &FriendNotificationWindow::onCloseButtonClicked);
    //connect(filterButton, &QPushButton::clicked, this, &FriendNotificationWindow::onFilterButtonClicked);
    connect(deleteAllButton, &QPushButton::clicked, this, &FriendNotificationWindow::onDeleteAllButtonClicked);
}

void FriendNotificationWindow::setupUI()
{
    // 设置窗口属性
    setWindowTitle("好友通知");
    //setWindowFlags(Qt::FramelessWindowHint);  // 去掉窗口框架
    resize(600, 400);
    this->setStyleSheet("QWidget { background-color: #f8f8f8; }");

    // 创建标题栏按钮
    minimizeButton = new QPushButton("-");
    maximizeButton = new QPushButton("□");
    closeButton = new QPushButton("X");

    // 创建过滤按钮
    //filterButton = new QPushButton("筛选");

    // 创建删除全部按钮
    deleteAllButton = new QPushButton("删除全部");

    // 创建通知列表
    notificationList = new QListWidget(this);

    // 设置按钮样式
    minimizeButton->setStyleSheet("QPushButton { background-color: #dcdcdc; border: none; }");
    maximizeButton->setStyleSheet("QPushButton { background-color: #dcdcdc; border: none; }");
    closeButton->setStyleSheet("QPushButton { background-color: #dcdcdc; border: none; }");
    //filterButton->setStyleSheet("QPushButton { background-color: #ffffff; border: 1px solid #dcdcdc; }");
    deleteAllButton->setStyleSheet("QPushButton { background-color: #ffffff; border: 1px solid #dcdcdc; }");

    // 创建布局
    titleLayout = new QHBoxLayout;
    titleLayout->addStretch();  // 增加弹性空间
    //titleLayout->addWidget(filterButton);
    titleLayout->addWidget(deleteAllButton);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(titleLayout);
    mainLayout->addWidget(notificationList);

    setLayout(mainLayout);
}

QWidget* FriendNotificationWindow::createNotificationWidget(const QString &text, QListWidgetItem *item)
{
    // 创建通知条目小部件
    QWidget *widget = new QWidget(this);
    QLabel *label = new QLabel(text, widget);

    QPushButton *acceptButton = new QPushButton("接受", widget);
    QPushButton *rejectButton = new QPushButton("拒绝", widget);

    QHBoxLayout *layout = new QHBoxLayout(widget);
    layout->addWidget(label);
    layout->addStretch();  // 增加弹性空间
    layout->addWidget(acceptButton);
    layout->addWidget(rejectButton);

    widget->setLayout(layout);

    // 连接按钮信号到对应槽函数
    connect(acceptButton, &QPushButton::clicked, [this, item]() { onAcceptButtonClicked(item); });
    connect(rejectButton, &QPushButton::clicked, [this, item]() { onRejectButtonClicked(item); });

    return widget;
}

void FriendNotificationWindow::toggleMaximizeRestore()
{
    if (isMaximized()) {
        showNormal();
        maximizeButton->setText("□");
    } else {
        showMaximized();
        maximizeButton->setText("❐");
    }
}

void FriendNotificationWindow::onMinimizeButtonClicked()
{
    showMinimized();
}

void FriendNotificationWindow::onCloseButtonClicked()
{
    close();
}

void FriendNotificationWindow::onFilterButtonClicked()
{
    qDebug() << "筛选功能点击";
    // 这里可以添加筛选逻辑
}

void FriendNotificationWindow::onDeleteButtonClicked()
{
    // 获取当前选中的条目
    QListWidgetItem *item = notificationList->currentItem();
    if (item) {
        delete item;
    }
}

void FriendNotificationWindow::onAcceptButtonClicked(QListWidgetItem *item)
{
    qDebug() << "接受好友请求: " << item->text();
    // 在这里添加接受好友请求的逻辑
    delete item;  // 移除通知条目
}

void FriendNotificationWindow::onRejectButtonClicked(QListWidgetItem *item)
{
    qDebug() << "拒绝好友请求: " << item->text();
    // 在这里添加拒绝好友请求的逻辑
    delete item;  // 移除通知条目
}

void FriendNotificationWindow::onDeleteAllButtonClicked()
{
    notificationList->clear();  // 清空所有通知
}
