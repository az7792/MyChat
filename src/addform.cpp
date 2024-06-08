#include "addform.h"
#include <QIcon>
#include <QPixmap>
#include <QDebug>

AddForm::AddForm(QWidget *parent) : QWidget(parent) {

    // 窗口的简单设置
    setWindowTitle("添加联系人");
    this->setStyleSheet("QWidget { background-color: white; }");

    // 设置窗口大小
    resize(550, 700);

    // 创建按钮
    findAllButton = new QPushButton("全部", this);
    findUserButton = new QPushButton("用户", this);
    findGroupButton = new QPushButton("群聊", this);

    // 设置按钮的初始样式
    findAllButton->setStyleSheet("QPushButton { background-color: black; color: white; border: 1px solid black; }");
    findUserButton->setStyleSheet("QPushButton { background-color: white; color: black; border: 1px solid black; }");
    findGroupButton->setStyleSheet("QPushButton { background-color: white; color: black; border: 1px solid black; }");

    // 创建搜索框
    searchLineEdit = new QLineEdit(this);
    searchLineEdit->setPlaceholderText("输入搜索关键词"); // 默认占位符
    searchLineEdit->setClearButtonEnabled(true);

    // 设置搜索框的固定大小（宽度400，高度25）
    searchLineEdit->setFixedSize(400, 25);

    // 创建搜索按钮
    searchButton = new QPushButton("搜索", this);
    searchButton->setStyleSheet("QPushButton { background-color: white; color: black; border: 1px solid black; }");

    // 创建搜索提示图片和文字
    searchIconLabel = new QLabel(this);
    QPixmap pixmap(":/new/prefix1/resources/1.png"); // 替换为你的搜索图标路径
    if (pixmap.isNull()) {
        qDebug() << "Failed to load image: :/new/prefix1/resources/1.png";
    } else {
        searchIconLabel->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
    }

    searchHintLabel = new QLabel("输入关键词搜索", this);
    searchHintLabel->setAlignment(Qt::AlignCenter);

    // 设置顶部按钮布局
    QHBoxLayout *topButtonLayout = new QHBoxLayout;
    topButtonLayout->addWidget(findAllButton);
    topButtonLayout->addWidget(findUserButton);
    topButtonLayout->addWidget(findGroupButton);

    // 设置搜索框和按钮布局
    QHBoxLayout *searchLayout = new QHBoxLayout;
    searchLayout->addWidget(searchLineEdit);
    searchLayout->addWidget(searchButton);

    // 设置中心内容布局
    QVBoxLayout *centerLayout = new QVBoxLayout;
    centerLayout->addWidget(searchIconLabel);
    centerLayout->addWidget(searchHintLabel);
    centerLayout->setAlignment(Qt::AlignCenter);

    QWidget *centerWidget = new QWidget(this);
    centerWidget->setLayout(centerLayout);

    contentStack = new QStackedWidget(this);
    contentStack->addWidget(centerWidget);

    // 设置主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(searchLayout);
    mainLayout->addLayout(topButtonLayout);
    mainLayout->addWidget(contentStack);

    setLayout(mainLayout);

    // 连接按钮点击事件
    connect(findAllButton, &QPushButton::clicked, this, &AddForm::onFindAllButtonClicked);
    connect(findUserButton, &QPushButton::clicked, this, &AddForm::onFindUserButtonClicked);
    connect(findGroupButton, &QPushButton::clicked, this, &AddForm::onFindGroupButtonClicked);
    connect(searchButton, &QPushButton::clicked, this, &AddForm::onSearchButtonClicked);
}

void AddForm::onFindAllButtonClicked() {
    findAllButton->setStyleSheet("QPushButton { background-color: black; color: white; border: 1px solid black; }");
    findUserButton->setStyleSheet("QPushButton { background-color: white; color: black; border: 1px solid black; }");
    findGroupButton->setStyleSheet("QPushButton { background-color: white; color: black; border: 1px solid black; }");
    searchLineEdit->setPlaceholderText("输入搜索关键词"); // 设置为 "输入搜索关键词"

    // 显示搜索提示图标和文字
    searchIconLabel->setVisible(true);
    searchHintLabel->setVisible(true);
}

void AddForm::onFindUserButtonClicked() {
    findUserButton->setStyleSheet("QPushButton { background-color: black; color: white; border: 1px solid black; }");
    findAllButton->setStyleSheet("QPushButton { background-color: white; color: black; border: 1px solid black; }");
    findGroupButton->setStyleSheet("QPushButton { background-color: white; color: black; border: 1px solid black; }");
    searchLineEdit->setPlaceholderText("UserId/Username"); // 设置为 "UserId/Username"

    // 显示搜索提示图标和文字
    searchIconLabel->setVisible(true);
    searchHintLabel->setVisible(true);
}

void AddForm::onFindGroupButtonClicked() {
    findGroupButton->setStyleSheet("QPushButton { background-color: black; color: white; border: 1px solid black; }");
    findUserButton->setStyleSheet("QPushButton { background-color: white; color: black; border: 1px solid black; }");
    findAllButton->setStyleSheet("QPushButton { background-color: white; color: black; border: 1px solid black; }");
    searchLineEdit->setPlaceholderText("GroupId/Groupname"); // 设置为 "GroupId/Groupname"

    // 显示搜索提示图标和文字
    searchIconLabel->setVisible(true);
    searchHintLabel->setVisible(true);
}

void AddForm::onSearchButtonClicked() {
    QString searchText = searchLineEdit->text();
    qDebug() << "搜索: " << searchText;

    // 隐藏搜索提示图标和文字
    searchIconLabel->setVisible(false);
    searchHintLabel->setVisible(false);

    // 这里可以添加你实际的搜索逻辑
}
