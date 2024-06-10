#include "mainform.h"
#include "ui_mainform.h"
#include "mediumWidget/addform.h"
#include "mediumWidget/friendnotificationwindow.h"

MainForm::MainForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainForm)
    , addForm(nullptr) // 初始化指针为 nullptr
    , notificationWindow(nullptr) // 初始化指针为 nullptr
{
    ui->setupUi(this);

    // 以下为测试用，将来删去
    // user.setUsername("user1");
    // user.setUID(1);
    // user.setEmail("1460014874@qq.com");
    // 以上为测试用，将来删去

    // 创建 Contact 和 Group 界面
    cform = new contactForm(ui->conatctWidget);
    gform=new groupForm(ui->conatctWidget);


    msgList = new messageListForm(ui->conatctWidget);
    ui->ContactStackedWidget->layout()->addWidget(msgList);
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
    cform->formInit(user);
    ui->ContactStackedWidget->setCurrentIndex(3);

}

void MainForm::on_groupButton_clicked()
{
    gform->formInit(user);
    ui->ContactStackedWidget->setCurrentIndex(4);
}

void MainForm::open_the_chatWindow(int Uid)
{
    ui->massageWidget->initChat(user, Uid, "user");
    User tuser=info.getUser(Uid);
    MessageBox *newBox=new MessageBox;
    newBox->setAvatar(tuser.getAvatar());
    newBox->setId(tuser.getUID());
    newBox->setName(tuser.getUsername());
    newBox->setChatType("user");
    msgList->addMessageBox(newBox);
    ui->ContactStackedWidget->setCurrentIndex(2);
}

void MainForm::open_the_groupWindow(int Gid)
{
    //以下暂用用户聊天界面代替
    ui->massageWidget->initChat(user,Gid,"group");
    Group tgroup=info.getGroupByGid(Gid);
    MessageBox *newBox=new MessageBox;
    newBox->setId(tgroup.getGroupid());
    newBox->setName(tgroup.getGroupname());
    newBox->setChatType("group");
    msgList->addMessageBox(newBox);
    ui->ContactStackedWidget->setCurrentIndex(2);
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

void MainForm::on_massageButton_clicked()
{
    ui->ContactStackedWidget->setCurrentIndex(2);
}

void MainForm::formInit(User newUser)
{
    user=newUser;
    gform->formInit(user);
    cform->formInit(user);
}
