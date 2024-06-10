#include "addform.h"
#include <QPixmap>
#include <QDebug>
#include "entity/user.h"
#include "smallWidget/contactmassage.h"
#include "entity/group.h" // 假设有一个Group类

AddForm::AddForm(QWidget *parent) : QWidget(parent)
{
    // 基本设置
    setWindowTitle("添加联系人");
    this->setStyleSheet("QWidget { background-color: white; }");
    resize(550, 700);

    // 创建按钮
    findAllButton = new QPushButton("全部", this);
    findUserButton = new QPushButton("用户", this);
    findGroupButton = new QPushButton("群聊", this);

    // 设置按钮样式
    findAllButton->setStyleSheet("QPushButton { background-color: black; color: white; border: 1px solid black; }");
    findUserButton->setStyleSheet("QPushButton { background-color: white; color: black; border: 1px solid black; }");
    findGroupButton->setStyleSheet("QPushButton { background-color: white; color: black; border: 1px solid black; }");

    // 创建搜索框
    searchLineEdit = new QLineEdit(this);
    searchLineEdit->setPlaceholderText("输入搜索关键词");
    searchLineEdit->setClearButtonEnabled(true);
    searchLineEdit->setFixedSize(400, 25);

    // 创建搜索按钮
    searchButton = new QPushButton("搜索", this);
    searchButton->setStyleSheet("QPushButton { background-color: white; color: black; border: 1px solid black; }");

    // 创建搜索提示图片和文字
    searchIconLabel = new QLabel(this);
    QPixmap pixmap(":/img/resources/1.png"); // 确保图像路径正确
    searchIconLabel->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
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

    // 初始化指针为 nullptr
    currentContactWidget = nullptr;
}

void AddForm::onFindAllButtonClicked() {
    status = 0;
    updatePlaceholderText();
    findAllButton->setStyleSheet("QPushButton { background-color: black; color: white; border: 1px solid black; }");
    findUserButton->setStyleSheet("QPushButton { background-color: white; color: black; border: 1px solid black; }");
    findGroupButton->setStyleSheet("QPushButton { background-color: white; color: black; border: 1px solid black; }");

    // 重新显示搜索提示图标和文字
    searchIconLabel->show();
    searchHintLabel->show();

    // 清除上次搜索结果
    clearPreviousSearchResult();

    // 清空搜索框的内容
    searchLineEdit->clear();
}

void AddForm::onFindUserButtonClicked() {
    status = 1;
    updatePlaceholderText();
    findUserButton->setStyleSheet("QPushButton { background-color: black; color: white; border: 1px solid black; }");
    findAllButton->setStyleSheet("QPushButton { background-color: white; color: black; border: 1px solid black; }");
    findGroupButton->setStyleSheet("QPushButton { background-color: white; color: black; border: 1px solid black; }");

    // 重新显示搜索提示图标和文字
    searchIconLabel->show();
    searchHintLabel->show();

    // 清除上次搜索结果
    clearPreviousSearchResult();

    // 清空搜索框的内容
    searchLineEdit->clear();
}

void AddForm::onFindGroupButtonClicked() {
    status = 2;
    updatePlaceholderText();
    findGroupButton->setStyleSheet("QPushButton { background-color: black; color: white; border: 1px solid black; }");
    findUserButton->setStyleSheet("QPushButton { background-color: white; color: black; border: 1px solid黑; }");
    findAllButton->setStyleSheet("QPushButton { background-color: white; color: black; border: 1px solid黑; }");

    // 重新显示搜索提示图标和文字
    searchIconLabel->show();
    searchHintLabel->show();

    // 清除上次搜索结果
    clearPreviousSearchResult();

    // 清空搜索框的内容
    searchLineEdit->clear();
}

void AddForm::onSearchButtonClicked() {
    QString searchText = searchLineEdit->text();
    qDebug() << "搜索: " << searchText;

    // 清除上次搜索结果
    clearPreviousSearchResult();

    contactMassage *contactMassageWidget = new contactMassage(this);

    if (status == 1) {
        // 按照用户来搜索
        User user = userinfomanage.getUser(searchText.toInt());
        contactMassageWidget->setImg(user.getAvatar());
        contactMassageWidget->setName(user.getUsername());
        contactMassageWidget->setUid(user.getUID());
    } else if (status == 2) {
        // 按照群聊来搜索
        //Group group = groupinfomanage.getGroup(searchText.toInt());
        //contactMassageWidget->setImg(group.getAvatar());
        //contactMassageWidget->setName(group.getGroupname());
        //contactMassageWidget->setUid(group.getGroupID());
    } else {
        // 其他搜索逻辑
        //contactMassageWidget->setName("Search in all categories not implemented");
    }

    // 将 contactMassageWidget 添加到 contentStack 中
    contentStack->addWidget(contactMassageWidget);

    // 切换到显示 contactMassageWidget
    contentStack->setCurrentWidget(contactMassageWidget);
    currentContactWidget = contactMassageWidget;

    // 隐藏搜索提示图标和文字
    searchIconLabel->hide();
    searchHintLabel->hide();
}

void AddForm::updatePlaceholderText() {
    if (status == 0) {
        searchLineEdit->setPlaceholderText("输入搜索关键词");
    } else if (status == 1) {
        searchLineEdit->setPlaceholderText("UserId/Username");
    } else if (status == 2) {
        searchLineEdit->setPlaceholderText("GroupId/Groupname");
    }
}

void AddForm::clearPreviousSearchResult() {
    if (currentContactWidget != nullptr) {
        contentStack->removeWidget(currentContactWidget);
        currentContactWidget->deleteLater(); // 释放内存
        currentContactWidget = nullptr;

        // 切换回默认的搜索提示视图
        contentStack->setCurrentIndex(0);
        searchIconLabel->show();
        searchHintLabel->show();
    }
}
