#include "addform.h"
#include <QPixmap>
#include <QDebug>
#include "entity/user.h"
#include "smallWidget/contactmassage.h"
#include "entity/group.h" // 假设有一个Group类
#include "manager/userinfomanager.h"

AddForm::AddForm(QWidget *parent) : QWidget(parent)
{
    // 基本设置
    setWindowTitle("搜索联系人");
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

    if (status == 1) {
        // 按照用户uid来搜索
        int userID = searchText.toInt();
        if (userinfomanage.isUserExist(userID)) {
            User user = userinfomanage.getUser(userID);
            contactMassage *contactMassageWidget = new contactMassage(this);
            contactMassageWidget->setImg(user.getAvatar());
            contactMassageWidget->setName(user.getUsername());
            contactMassageWidget->setUid(user.getUID());
            contentStack->addWidget(contactMassageWidget);
            contentStack->setCurrentWidget(contactMassageWidget);
            currentContactWidget = contactMassageWidget;
        } else {
            qDebug() << "User not found.";
            QLabel *notFoundLabel = new QLabel("User not found", this);
            notFoundLabel->setAlignment(Qt::AlignCenter);
            contentStack->addWidget(notFoundLabel);
            contentStack->setCurrentWidget(notFoundLabel);
        }
    }
    else if (status == 2)
    {
        int groupID = searchText.toInt();
        if(userinfomanage.isGroupExist(groupID))
        {
            Group group = userinfomanage.getGroupByGid(searchText.toInt());
            contactMassage *contactMassageWidget = new contactMassage(this);
            contactMassageWidget->setImg(group.getAvatar());
            contactMassageWidget->setName(group.getGroupname());
            contactMassageWidget->setUid(group.getGroupid());
            QPushButton *button  = new QPushButton;
            contentStack->addWidget(contactMassageWidget);
            contentStack->addWidget(button);
            contentStack->setCurrentWidget(contactMassageWidget);
            currentContactWidget = contactMassageWidget;
        }
        else
        {
            qDebug() << "User not found.";
            QLabel *notFoundLabel = new QLabel("User not found", this);
            notFoundLabel->setAlignment(Qt::AlignCenter);
            contentStack->addWidget(notFoundLabel);
            contentStack->setCurrentWidget(notFoundLabel);
        }
    }
    else
    {
        int userID = searchText.toInt();
        int groupID = searchText.toInt();
        bool isUserExist = userinfomanage.isUserExist(userID);
        bool isGroupExist = userinfomanage.isGroupExist(groupID);

        if (!isUserExist && !isGroupExist) {
            qDebug() << "User and group not found.";
            QLabel *notFoundLabel = new QLabel("User or Group not found", this);
            notFoundLabel->setAlignment(Qt::AlignCenter);
            contentStack->addWidget(notFoundLabel);
            contentStack->setCurrentWidget(notFoundLabel);
        } else {
            clearPreviousSearchResult();
            QWidget *resultWidget = new QWidget(this); // 创建一个新的 QWidget 作为容器
            QVBoxLayout *layout = new QVBoxLayout(resultWidget); // 使用垂直布局

            if (isUserExist) {
                User user = userinfomanage.getUser(userID);
                contactMassage *userContactWidget = new contactMassage(this);
                userContactWidget->setImg(user.getAvatar());
                userContactWidget->setName(user.getUsername());
                userContactWidget->setUid(user.getUID());
                layout->addWidget(userContactWidget); // 将用户信息添加到布局
            }
            if (isGroupExist) {
                Group group = userinfomanage.getGroupByGid(groupID);
                contactMassage *groupContactWidget = new contactMassage(this);
                groupContactWidget->setImg(group.getAvatar());
                groupContactWidget->setName(group.getGroupname());
                groupContactWidget->setUid(group.getGroupid());
                layout->addWidget(groupContactWidget); // 将群组信息添加到布局
            }
            resultWidget->setLayout(layout);
            contentStack->addWidget(resultWidget);
            contentStack->setCurrentWidget(resultWidget);
            //currentContactWidget = resultWidget; // 更新 currentContactWidget 为 resultWidget
        }

    }

    // 隐藏搜索提示图标和文字
    searchIconLabel->hide();
    searchHintLabel->hide();
}

void AddForm::updatePlaceholderText() {
    if (status == 0) {
        searchLineEdit->setPlaceholderText("输入搜索关键词");
    } else if (status == 1) {
        searchLineEdit->setPlaceholderText("UserId");
    } else if (status == 2) {
        searchLineEdit->setPlaceholderText("GroupId");
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
    } else {
        // 如果没有 currentContactWidget 需要清除，直接切换回默认视图
        contentStack->setCurrentIndex(0);
        searchIconLabel->show();
        searchHintLabel->show();
    }
}
