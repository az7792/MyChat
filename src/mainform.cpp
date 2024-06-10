#include "mainform.h"
#include "ui_mainform.h"
#include "addform.h"
#include "friendnotificationwindow.h"

MainForm::MainForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainForm)
    , addForm(nullptr) // 初始化指针为 nullptr
    , notificationWindow(nullptr) // 初始化指针为 nullptr
{
    ui->setupUi(this);

    // 以下为测试用，将来删去
    user.setUsername("user1");
    user.setUID(1);
    user.setEmail("1460014874@qq.com");
    // 以上为测试用，将来删去

    // 创建 Contact 和 Group 界面
    contactForm *cform = new contactForm(ui->conatctWidget);
    cform->formInit(user);

    groupForm *gform=new groupForm(ui->conatctWidget);

    ui->ContactStackedWidget->layout()->addWidget(cform);
    ui->ContactStackedWidget->layout()->addWidget(gform);
    ui->ContactStackedWidget->setCurrentIndex(2);
    connect(ui->contactButton, &QPushButton::clicked, this, &MainForm::on_contactButton_clicked);
    connect(ui->groupButton, &QPushButton::clicked, this, &MainForm::on_groupButton_clicked);
    connect(cform, &contactForm::passContactUid, this, &MainForm::open_the_chatWindow);
    connect(gform, &groupForm::passContactGid, this, &MainForm::open_the_groupWindow);
    connect(ui->addButton, &QPushButton::clicked, this, &MainForm::on_addButton_clicked);
    connect(ui->applyButton, &QPushButton::clicked, this, &MainForm::on_applyButton_clicked);
}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::on_contactButton_clicked()
{
    ui->ContactStackedWidget->setCurrentIndex(2);

}

void MainForm::on_groupButton_clicked()
{
    ui->ContactStackedWidget->setCurrentIndex(3);
}

void MainForm::open_the_chatWindow(int Uid)
{
    ui->massageWidget->initChat(user, Uid, "user");
}

void MainForm::open_the_groupWindow(int Gid)
{
    ui->massageWidget->layout()->removeWidget(current_g);
    ui->massageWidget->layout()->removeWidget(current_c);
    ui->massageWidget->layout()->update();
    current_g->setName(QString::number(100 + Gid));
    current_g->setGid(Gid);
    ui->massageWidget->layout()->addWidget(current_g);
}

void MainForm::on_addButton_clicked()
{
    // 如果窗口已存在，先关闭它
    if (addForm) {
        addForm->close();
    }

    // 创建新的 AddForm 窗口
    addForm = new AddForm(); // 创建独立窗口，不指定父窗口
    addForm->setAttribute(Qt::WA_DeleteOnClose); // 窗口关闭时自动删除对象

    // 显示添加联系人窗口
    addForm->show();

    // 连接新窗口的关闭事件，关闭时将指针设为 nullptr
    connect(addForm, &AddForm::destroyed, [this]() {
        addForm = nullptr; // 重置指针
    });
}

void MainForm::on_applyButton_clicked()
{
    // 如果窗口已存在，先关闭它
    if (notificationWindow) {
        notificationWindow->close();
    }

    // 创建新的 FriendNotificationWindow 窗口
    notificationWindow = new FriendNotificationWindow(); // 创建独立窗口，不指定父窗口
    notificationWindow->setAttribute(Qt::WA_DeleteOnClose); // 窗口关闭时自动删除对象

    // 显示好友通知窗口
    notificationWindow->show();

    // 连接新窗口的关闭事件，关闭时将指针设为 nullptr
    connect(notificationWindow, &FriendNotificationWindow::destroyed, [this]() {
        notificationWindow = nullptr; // 重置指针
    });
}
