#include "FriendNotificationWindow.h"
#include <QIcon>
#include <QSize>
#include <QDebug>
#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QPushButton>

FriendNotificationWindow::FriendNotificationWindow(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void FriendNotificationWindow::setupUI() {
    this->setStyleSheet("QWidget { background-color: white; }");
    setWindowTitle("好友通知");
    resize(600, 400); // 设置窗口大小
    //this->setStyleSheet("background-color: #F5F5F5;"); // 设置背景颜色为浅灰色

    // 标题栏布局
    titleLayout = new QHBoxLayout;

    // 移除好友通知的标题
    // titleLabel = new QLabel("好友通知", this);
    // titleLabel->setStyleSheet("font-size: 20px; font-weight: bold;");
    // titleLayout->addWidget(titleLabel);

    titleLayout->addStretch(); // 添加弹性空间使得按钮靠右

    // 右侧功能按钮
    minimizeButton = new QPushButton(this);
    minimizeButton->setIcon(QIcon(":/icons/minimize.png"));
    minimizeButton->setIconSize(QSize(20, 20));
    minimizeButton->setFlat(true); // 去掉按钮边框
    titleLayout->addWidget(minimizeButton);

    maximizeButton = new QPushButton(this);
    maximizeButton->setIcon(QIcon(":/icons/maximize.png"));
    maximizeButton->setIconSize(QSize(20, 20));
    maximizeButton->setFlat(true);
    titleLayout->addWidget(maximizeButton);

    closeButton = new QPushButton(this);
    closeButton->setIcon(QIcon(":/icons/close.png"));
    closeButton->setIconSize(QSize(20, 20));
    closeButton->setFlat(true);
    titleLayout->addWidget(closeButton);

    filterButton = new QPushButton(this);
    filterButton->setIcon(QIcon(":/icons/filter.png"));
    filterButton->setIconSize(QSize(20, 20));
    filterButton->setFlat(true);
    titleLayout->addWidget(filterButton);

    deleteAllButton = new QPushButton("一键删除", this);
    deleteAllButton->setFlat(true);
    titleLayout->addWidget(deleteAllButton);

    // 好友通知区域
    notificationList = new QListWidget(this);

    // 添加好友通知项
    QStringList friendRequests = {
        "test1 请求加为好友",
        "test2 请求加为好友",
        "test3 请求加为好友"
    };

    for (const QString &request : friendRequests) {
        QListWidgetItem *item = new QListWidgetItem;
        QWidget *widget = createNotificationWidget(request, item);
        item->setSizeHint(widget->sizeHint());
        notificationList->addItem(item);
        notificationList->setItemWidget(item, widget);
    }

    // 设置好友通知项的样式
    notificationList->setStyleSheet("QListWidget { border: none; } "
                                    "QListWidget::item { padding: 10px; margin-bottom: 5px; border-radius: 5px; } "
                                    "QListWidget::item:hover { background-color: white; }");

    // 主布局
    mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(titleLayout);
    mainLayout->addWidget(notificationList); // 确保添加到布局中

    setLayout(mainLayout);

    // 连接信号和槽
    connect(minimizeButton, &QPushButton::clicked, this, &FriendNotificationWindow::onMinimizeButtonClicked);
    connect(maximizeButton, &QPushButton::clicked, this, &FriendNotificationWindow::toggleMaximizeRestore);
    connect(closeButton, &QPushButton::clicked, this, &FriendNotificationWindow::onCloseButtonClicked);
    connect(filterButton, &QPushButton::clicked, this, &FriendNotificationWindow::onFilterButtonClicked);
    connect(deleteAllButton, &QPushButton::clicked, this, &FriendNotificationWindow::onDeleteAllButtonClicked);
}

QWidget* FriendNotificationWindow::createNotificationWidget(const QString &text, QListWidgetItem *item) {
    QWidget *widget = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout;

    // 创建并设置好友信息的标签
    QLabel *label = new QLabel(text, widget);
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred); // 设置标签扩展以填充可用空间

    // 设置接收和拒绝按钮
    QPushButton *acceptButton = new QPushButton("同意", widget);
    QPushButton *rejectButton = new QPushButton("拒绝", widget);

    // 连接按钮点击事件
    connect(acceptButton, &QPushButton::clicked, this, [=](){ onAcceptButtonClicked(item); });
    connect(rejectButton, &QPushButton::clicked, this, [=](){ onRejectButtonClicked(item); });

    // 将控件添加到布局
    layout->addWidget(label);
    layout->addStretch();
    layout->addWidget(acceptButton);
    layout->addWidget(rejectButton);

    // 设置布局到widget
    widget->setLayout(layout);

    // 设置样式
    widget->setStyleSheet(
        "QLabel { font-size: 14px; } " // 设置标签字体大小
        "QPushButton { margin-left: 10px; }" // 设置按钮的间距
        "QPushButton { padding: 5px 10px; }" // 设置按钮的填充
        );

    // 调整控件的最小高度以适应内容
    widget->setMinimumHeight(50);

    return widget;
}


void FriendNotificationWindow::toggleMaximizeRestore() {
    if (isMaximized()) {
        showNormal();
    } else {
        showMaximized();
    }
}

void FriendNotificationWindow::onMinimizeButtonClicked() {
    showMinimized();
}

void FriendNotificationWindow::onCloseButtonClicked() {
    close();
}

void FriendNotificationWindow::onFilterButtonClicked() {
    // 实现你的过滤逻辑
    qDebug() << "Filter button clicked!";
}

void FriendNotificationWindow::onDeleteButtonClicked() {
    // 实现你的删除逻辑
    qDebug() << "Delete button clicked!";
}

void FriendNotificationWindow::onAcceptButtonClicked(QListWidgetItem *item) {
    // 处理同意逻辑
    qDebug() << "Accepted: " << item->text();
    delete notificationList->takeItem(notificationList->row(item));
}

void FriendNotificationWindow::onRejectButtonClicked(QListWidgetItem *item) {
    // 处理拒绝逻辑
    qDebug() << "Rejected: " << item->text();
    delete notificationList->takeItem(notificationList->row(item));
}

void FriendNotificationWindow::onDeleteAllButtonClicked() {
    // 清空所有好友请求
    notificationList->clear();
    qDebug() << "All notifications deleted!";
}
