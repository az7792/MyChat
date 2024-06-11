# API

## entity

### User 类

- **功能**：表示一个用户，包含用户的基本信息和一些操作该信息的方法。
- **构造函数**：
  - `User(int UID, QString username, QString email, QPixmap avatar)`：初始化用户对象。
  - `User()`：默认构造函数。
- **成员函数**：
  - `getUID()`：获取用户ID。
  - `getUsername()`：获取用户名。
  - `getEmail()`：获取邮箱地址。
  - `getAvatar()`：获取用户头像。
  - `setUID(int UID)`：设置用户ID。
  - `setUsername(QString username)`：设置用户名。
  - `setEmail(QString email)`：设置邮箱地址。
  - `setAvatar(QPixmap avatar)`：设置用户头像。
  - `toUser(QJsonObject jsonObject)`：从JSON对象创建用户对象。

### Message 类
- **功能**：表示一条消息，包含消息的详细信息和一些操作该信息的方法。
- **构造函数**：
  - `Message()`：默认构造函数。
  - `Message(int form, int to, QString receiverType, QString text, QString type)`：初始化消息对象。
  - `Message(int messageId, int form, int to, QString receiverType, QString text, QString type, QDateTime sentTime)`：带消息ID的初始化。
- **析构函数**：`~Message()`。
- **成员函数**：
  - `toJsonString()`：将消息对象转换为JSON字符串。
  - `toMessage(QString jsonString)`：从JSON字符串创建消息对象。
- **成员变量**：
  - `messageId`：消息ID。
  - `fromUserUid`：发送者用户ID。
  - `toReceiver`：接收者ID。
  - `receiverType`：接收者类型。
  - `text`：消息文本。
  - `type`：消息类型。
  - `sentTime`：发送时间。
  - `isRead`：是否已读。

### Group 类
- **功能**：表示一个群组，包含群组的基本信息和一些操作该信息的方法。
- **构造函数**：
  - `Group()`：默认构造函数。
  - `Group(int groupid, QString groupname, int ownerid)`：初始化群组对象。
- **成员函数**：
  - `getGroupid()`：获取群组ID。
  - `getOwnerid()`：获取群组所有者ID。
  - `getGroupname()`：获取群组名称。
  - `setGroupid(int groupid)`：设置群组ID。
  - `setGroupname(QString groupname)`：设置群组名称。
  - `setOwnerid(int ownerid)`：设置群组所有者ID。
  - `toGroup(QJsonObject jsonObject)`：从JSON对象创建群组对象。
- **成员变量**：
  - `groupid`：群组ID。
  - `ownerid`：群组所有者ID。
  - `groupname`：群组名称。

## manager

### UserInfoManager 类 

- **功能**：用户信息管理器，提供用户注册、登录、信息获取等网络请求功能。
- **成员函数**：
  - `login(QString email, QString password)`：通过邮箱和密码登录。
  - `login(int UID, QString password)`：通过用户ID和密码登录。
  - `registerUser(QString username, QString email, QString password, QPixmap pixmap)`：用户注册。
  - `matchCaptcha(QString email, QString code)`：验证码匹配。
  - `getCaptchaByEmail(QString email)`：通过邮箱获取验证码。
  - `deleteUser(int UID)`：注销用户。
  - `isUserExist(int UID)`：检查用户是否存在。
  - `isEmailExist(QString email)`：检查邮箱是否存在。
  - `isUsernameValid(QString username)`：验证用户名是否合法。
  - `isEmailValid(QString email)`：验证邮箱是否合法。
  - `isPasswordValid(QString password)`：验证密码是否合法。
  - `encryptPassword(QString password)`：密码加密。
  - `changeUsername(int UID, QString newUsername)`：修改用户名。
  - `changeEmail(int UID, QString newEmail)`：修改邮箱。
  - `changePassword(QString email, QString newPassword)`：修改密码。
  - `getUser(int UID)`：通过用户ID获取用户信息。
  - `getUser(QString email)`：通过邮箱获取用户信息。
  - `getContactList(int Uid)`：获取用户的好友列表。
  - `getGroupList(int Uid)`：获取用户所有群组。
  - `getGroupByGid(int Gid)`：根据群ID获取群信息。
  - `getGroupMembers(int Gid)`：根据群ID获取群成员列表。
  - `getInstance()`：提供全局访问点，确保 UserInfoManager 类只有一个实例
- **私有成员**：
  - `networkManager`：网络请求管理器。

### FormManager 类
- **继承**：`QWidget`
- **成员变量**：
  - `LoginForm *loginForm`：指向登录表单的指针。
  - `RegisterForm *registerForm`：指向注册表单的指针。
  - `ResetPasswordForm *resetPasswordForm`：指向忘记密码表单的指针。
  - `QStackedLayout *stackedLayout`：指向堆叠布局管理器的指针。
  - `MainForm *mainForm`：指向主界面表单的指针。
- **公有成员函数**：
  - 构造函数 `FormManager(QWidget *parent = nullptr)`：初始化 FormManager。
  - 析构函数 `~FormManager()`：销毁 FormManager。
- **私有槽函数**：
  - `showRegisterForm()`：显示注册表单。
  - `showMainForm(User user)`：显示主界面，并传入用户信息。
  - `showLoginForm()`：显示登录表单。
  - `showResetPasswordForm()`：显示忘记密码表单。
- **静态成员变量**：
  - `ChatWebSocket &web`：引用 `ChatWebSocket` 单例的实例，用于 WebSocket 通信。

### DatabaseManager 类

**功能**：数据库管理类，提供数据库初始化、消息保存、消息加载和设置消息阅读状态的功能。

- **公有静态成员函数**：
  - `initializeDatabase(const QString &dbPath)`：初始化数据库并创建数据表。
  - `saveMessageToDatabase(const Message &msg)`：将消息保存到数据库。
  - `loadMessagesFromDatabase()`：从数据库加载消息。
  - `setMessageReadStatus(int messageId, bool isRead)`：设置特定消息的阅读状态。

## webSocket

### ChatWebSocket 类

- **继承**：`QObject`
- **功能**：管理与聊天服务器的 WebSocket 连接，发送和接收消息。
- **公有静态成员函数**：
  - `getInstance()`：提供对 `ChatWebSocket` 单例的访问。
- **公有成员函数**：
  - `connectToServer(const QUrl &url)`：连接到指定的 WebSocket 服务器。
  - `disconnectFromServer()`：从服务器断开 WebSocket 连接。
  - `sendMessage(Message message)`：通过 WebSocket 发送消息。
- **信号**：
  - `textMessageReceived(const QString &message)`：接收到文本消息时发出信号。
- **公有槽函数**：
  - `onConnected()`：连接成功时调用。
  - `onDisconnected()`：断开连接时调用。
  - `onTextMessageReceived(const QString &message)`：接收到文本消息时调用。
- **私有构造函数**：
  - `ChatWebSocket(QObject *parent = nullptr)`：私有构造函数，用于创建单例。
- **析构函数**：
  - `~ChatWebSocket()`：析构函数，清理资源。
- **私有成员变量**：
  - `webSocket`：`QWebSocket` 类型的指针，用于 WebSocket 通信。

## largeWidget

### MainForm 类
- **继承**：`QWidget`
- **功能**：主窗口界面，提供用户与联系人、群组聊天以及消息列表的管理。
- **公有成员函数**：
  - `MainForm(QWidget *parent = nullptr)`：构造函数。
  - `~MainForm()`：析构函数。
  - `formInit(User user)`：初始化表单，设置当前用户。
- **私有槽函数**：
  - `on_contactButton_clicked()`：处理联系人按钮点击事件。
  - `on_groupButton_clicked()`：处理群组按钮点击事件。
  - `open_the_chatWindow(int Uid)`：打开与指定用户ID的聊天窗口。
  - `open_the_groupWindow(int Gid)`：打开与指定群组ID的聊天窗口。
  - `on_applyButton_clicked()`：处理申请（或通知）按钮点击事件。
  - `on_addButton_clicked()`：处理添加按钮点击事件。
  - `on_massageButton_clicked()`：处理按摩按钮点击事件（可能是消息按钮的笔误）。
- **私有成员变量**：
  - `Ui::MainForm *ui`：指向用户界面布局的指针。
  - `contactMassage *current_c`、`groupMassage *current_g`：分别指向当前联系人消息和群组消息的指针。
  - `messageListForm *msgList`：指向消息列表表单的指针。
  - `contactForm *cform`、`groupForm *gform`：分别指向联系人表单和群组表单的指针。
  - `AddForm *addForm`、`FriendNotificationWindow *notificationWindow`：分别指向添加表单和好友通知窗口的指针。
  - `UserInfoManager &info`：引用用户信息管理器的单例。

## mediumWidget

### messageListForm 类
- **继承**：`QWidget`
- **功能**：消息列表表单，用于展示和管理消息对话。
- **公有成员函数**：
  - `messageListForm(QWidget *parent = nullptr)`：构造函数。
  - `~messageListForm()`：析构函数。
  - `addMessageBox(MessageBox *messageBox)`：添加消息框到消息列表。
  - `updataMessageBox(Message message)`：更新消息列表中的消息。
- **私有成员变量**：
  - `Ui::messageListForm *ui`：指向用户界面的指针。
  - `QMap<QPair<int,QString>,MessageBox*> messageBoxMap`：存储消息框的映射表，键为 `id` 和 `chatType` 的组合。
- **成员变量**：
  - `UserInfoManager &userInfoManager`：引用用户信息管理器的单例。
  - `User sendUser`：发送消息的用户信息。
- **信号**：
  - `passMessageBox(MessageBox *messageBox)`：选中消息框时发出的信号。

### groupForm 类
- **继承**：`QWidget`
- **功能**：群组表单界面，用于展示和管理群组信息。
- **公有成员函数**：
  - `groupForm(QWidget *parent = nullptr)`：构造函数。
  - `~groupForm()`：析构函数。
  - `formInit(User user)`：初始化表单，设置当前用户。
- **成员变量**：
  - `UserInfoManager &useIfo`：引用用户信息管理器的单例。
  - `User user`：当前用户信息。
- **私有成员变量**：
  - `Ui::groupForm *ui`：指向用户界面的指针。
- **信号**：
  - `passContactGid(int Gid)`：当在群组界面上进行操作时发出的信号，传递群组ID。

### contactForm 类
- **继承**：`QWidget`
- **功能**：联系人表单界面，用于展示和管理联系人信息。
- **公有成员函数**：
  - `contactForm(QWidget *parent = nullptr)`：构造函数。
  - `~contactForm()`：析构函数。
  - `formInit(User user)`：初始化表单，设置当前用户。
- **成员变量**：
  - `UserInfoManager &useIfo`：引用用户信息管理器的单例。
  - `User user`：当前用户信息。
- **私有成员变量**：
  - `Ui::contactForm *ui`：指向用户界面的指针。
- **信号**：
  - `passContactUid(int Uid)`：当联系人被双击时发出的信号，传递联系人的用户ID。

### ChatForm 类
- **继承**：`QWidget`
- **功能**：聊天表单界面，用于展示和管理聊天消息。
- **公有成员函数**：
  - `ChatForm(QWidget *parent = nullptr)`：构造函数。
  - `~ChatForm()`：析构函数。
  - `addRecvUsers(int id, QString chatType)`：添加接收用户信息。
- **成员变量**：
  - `ChatWebSocket &chatWebsocket`：引用 WebSocket 通信管理器的单例。
  - `UserInfoManager &userInfoManager`：引用用户信息管理器的单例。
  - `int toId`：目标用户或群组的ID。
  - `QString chatType`：聊天类型（用户或群组）。
  - `User sendUser`：发送消息的用户信息。
  - `QMap<int, User> recvUsers`：接收用户信息映射表。
- **信号**：
  - `saveToMessageBox(Message message)`：保存消息到消息盒的信号。
- **公有槽函数**：
  - `onMessageBoxPass(MessageBox *messageBox)`：处理消息盒传递的槽函数。

### AddForm 类
- **继承**：`QWidget`
- **功能**：添加联系人或群组的表单界面。
- **成员变量**：
  - `UserInfoManager &userinfomanage`：引用用户信息管理器的单例。
  - `int status`：用于标识搜索状态（0-全部，1-用户，2-群聊）。
  - 多个 `QPushButton`、`QLineEdit`、`QLabel`、`QStackedWidget` 和 `QVBoxLayout` 指针用于构建 UI。
  - `contactMassage *contactMassageWidget` 和 `*currentContactWidget`：用于显示搜索结果的 `contactMassage` 对象。
- **私有槽函数**：
  - `onFindAllButtonClicked()`
  - `onFindUserButtonClicked()`
  - `onFindGroupButtonClicked()`
  - `onSearchButtonClicked()`
- **私有成员函数**：
  - `updatePlaceholderText()`：更新搜索框占位符文本。
  - `updateStyles()`：更新界面样式。
  - `clearPreviousSearchResult()`：清除之前的搜索结果。

### FriendNotificationWindow 类
- **继承**：`QWidget`
- **功能**：好友通知窗口，用于展示和管理好友请求等通知。
- **私有槽函数**：
  - `toggleMaximizeRestore()`
  - `onMinimizeButtonClicked()`
  - `onCloseButtonClicked()`
  - `onFilterButtonClicked()`
  - `onDeleteButtonClicked()`
  - `onAcceptButtonClicked(QListWidgetItem *item)`
  - `onRejectButtonClicked(QListWidgetItem *item)`
  - `onDeleteAllButtonClicked()`
- **私有成员函数**：
  - `setupUI()`：设置用户界面。
  - `createNotificationWidget(const QString &text, QListWidgetItem *item)`：创建通知条目小部件。
- **UI组件**：
  - `minimizeButton`、`maximizeButton`、`closeButton`、`deleteAllButton`：控制窗口状态的按钮。
  - `notificationList`：用于展示通知的列表控件。

## smallWidget

### SendBox 类
- **继承**：`QWidget`
- **功能**：用于显示发送()的消息盒子的控件。
- **公有成员函数**：
  - `setTextColor(const QColor& textcolor)`：设置文本颜色。
  - `setBackgroundColor(const QColor& backgroundcolor)`：设置背景颜色。
  - `setBordetRadius(const int radius)`：设置边框圆角半径。
  - `setStyleSheet(const QString& style)`：设置样式表。
- **公有槽函数**：
  - `setAvatar(const QPixmap& avtar)`：设置头像。
  - `setText(const QString& text)`：设置文本。

### RecvBox 类

- **继承**：`QWidget`
- **功能**：用于显示接受的消息盒子的控件。
- **公有成员函数**：
  - `setTextColor(const QColor& textcolor)`：设置文本颜色。
  - `setBackgroundColor(const QColor& backgroundcolor)`：设置背景颜色。
  - `setBordetRadius(const int radius)`：设置边框圆角半径。
  - `setStyleSheet(const QString& style)`：设置样式表。
- **公有槽函数**：
  - `setAvatar(const QPixmap& avtar)`：设置头像。
  - `setText(const QString& text)`：设置文本。

### LoginForm 类
- **继承**：`QWidget`

- **功能**：登录表单界面，允许用户通过邮箱或用户ID登录。

- **成员变量**：
  - `UserInfoManager &userInfoManager`：引用用户信息管理器的单例。

- **信号**：
  - `showRegisterForm()`：触发显示注册表单的信号。
  - `loggedIn(User user)`：用户登录成功时发出的信号。
  - `showResetPasswordForm()`：触发显示忘记密码表单的信号。

 - **私有槽函数**
   - `on_showPasswordCheckBox_stateChanged(int state)`：根据复选框状态切换密码显示模式。
   - `on_accountLineEdit_editingFinished()`：账号输入完成后验证格式，区分邮箱和用户ID。
   - `on_passwordLineEdit_editingFinished()`：密码输入完成后验证格式，检查密码复杂度。
   - `on_loginPushButton_clicked()`：登录按钮点击事件，根据账号类型（邮箱或用户ID）执行登录操作，登录成功发出 `loggedIn` 信号，失败显示警告。
   - `on_registerPushButton_clicked()`：注册按钮点击事件，发出 `showRegisterForm` 信号。
   - `on_retrievePasswordPushButton_clicked()`：忘记密码按钮点击事件，发出 `showResetPasswordForm` 信号。


### RegisterForm 类
- **继承**：`QWidget`
- **功能**：注册表单界面，允许新用户注册账户。
- **成员变量**：
  - `UserInfoManager &userInfoManager`：引用用户信息管理器的单例。
  - `countdown`：用于验证码倒计时的整数。
  - 多个布尔值用于验证输入是否合法（用户名、密码1、密码2、账号）。
- **信号**：
  - `showLoginForm()`：显示登录窗口的信号。
  - `registered()`：用户注册成功的信号。

- **私有槽函数**
    - `on_userNameLineEdit_editingFinished()`：用户名输入完成后验证格式。
    - `on_accountLineEdit_editingFinished()`：账号（邮箱）输入完成后验证格式，并检查邮箱是否存在。
    - `on_passwordLineEdit1_editingFinished()` 和 `on_passwordLineEdit2_editingFinished()`：密码输入完成后验证格式，并检查两次输入是否一致。
    - `on_showPasswordCheckBox_stateChanged(int state)`：切换显示密码的功能。
    - `on_registerPushButton_clicked()`：处理用户注册请求，验证所有输入后调用 `userInfoManager` 的 `registerUser` 方法。
    - `on_getCaptchaPushButton_clicked()`：获取验证码，启动倒计时，禁用按钮直到倒计时结束。
    - `on_captchaLineEdit_editingFinished()`：验证码输入完成后验证长度。
    - `on_returnPushButton_clicked()`：返回登录界面。
    - `on_setAvatarPushButton_clicked()`：设置用户头像，从文件选择对话框中选择图片并显示。

### ResetPasswordForm 类
- **继承**：`QWidget`
- **功能**：重置密码表单界面，允许用户输入邮箱、验证码和新密码来重置密码。
- **成员变量**：
  - `UserInfoManager &userInfoManager`：引用用户信息管理器的单例。
- **信号**：
  - `showLoginForm()`：触发显示登录表单的信号。

 - **核心槽函数**
   - `on_accountLineEdit_editingFinished()`：邮箱输入完成后验证格式，并检查邮箱是否存在。
   - `on_captchaLineEdit_editingFinished()`：验证码输入完成后验证长度。
   - `on_returnPushButton_clicked()`：返回登录界面。
   - `on_getCaptchaPushButton_clicked()`：获取验证码，启动倒计时，禁用按钮直到倒计时结束。
   - `on_resetPasswordPushButton_clicked()`：重置密码按钮点击事件，验证所有输入后调用 `userInfoManager` 的 `changePassword` 方法。
   - `on_showPasswordCheckBox_stateChanged(int state)`：切换密码显示模式。
   - `on_passwordLineEdit1_editingFinished()` 和 `on_passwordLineEdit2_editingFinished()`：密码输入完成后验证格式，并检查两次输入是否一致。

### contactMassage 类

- **继承**：`QWidget`

- **功能描述**
  `contactMassage` 类是一个QWidget小部件，用于显示和管理联系人信息，如姓名、用户ID和头像。它还处理用户的双击事件，并通过信号与其他组件交互。

- **构造函数 (`contactmassage.cpp`)**
  - `contactMassage(QWidget *parent = nullptr)`：创建一个新的`contactMassage`对象，并设置其用户界面。

- **析构函数 (`contactmassage.cpp`)**
  - `~contactMassage()`：销毁`contactMassage`对象并清理分配的资源。

- **公有成员函数**
  - `setName(QString newName)`：设置联系人的姓名，并在用户界面上显示。
  - `getName()`：返回当前设置的联系人姓名。
  - `setUid(int newUid)`：设置并显示联系人的用户ID。
  - `getUid()`：返回当前设置的联系人用户ID。
  - `setImg(QPixmap img)`：设置并显示联系人的头像图片。

- **信号**
  - `doubleClicked(int uid)`：当联系人小部件被双击时发出，携带联系人的用户ID。
  - `mousePress()`：当鼠标按压事件发生时发出。

- **重写函数 (`contactmassage.cpp`)**
  - `mouseDoubleClickEvent(QMouseEvent *event)`：重写以处理鼠标双击事件。如果检测到左键双击，则输出调试信息并发出`doubleClicked`信号。

### groupMassage

- **继承**：`QWidget`

- **功能**：`groupMassage` 类是一个QWidget小部件，用于展示和管理群组信息，如群组名称和ID。它允许用户通过双击来触发一个信号，从而进行进一步的交互。
- **构造函数 (`groupmassage.cpp`)**
  - `groupMassage(QWidget *parent = nullptr)`：创建`groupMassage`对象，并设置其用户界面。
- **析构函数 (`groupmassage.cpp`)**
  - `~groupMassage()`：销毁`groupMassage`对象并清理资源。
- **公有成员函数**
  - `setName(QString newName)`：设置并显示群组的名称。
  - `getName()`：返回当前设置的群组名称。
  - `setGid(int newGid)`：设置并显示群组的ID。
  - `getGid()`：返回当前设置的群组ID。
- **重写函数 (`groupmassage.cpp`)**
  - `mouseDoubleClickEvent(QMouseEvent *event)`：重写以处理鼠标双击事件。如果检测到左键双击，则输出调试信息并发出`doubleClicked`信号。
- **信号**
  - `doubleClicked(int uid)`：当群组小部件被双击时发出，携带群组的ID。

### MessageBox 类

- **继承**：`QWidget`

- **功能**: `MessageBox` 类是一个QWidget小部件，用于展示和管理聊天消息。它包含消息列表、时间、未读消息数、新消息内容、聊天名称、聊天类型、头像、ID和用户ID等属性。用户可以通过点击来触发事件，进行进一步的交互。

- **构造函数 (`messagebox.cpp`)**:
  - `explicit MessageBox(QWidget *parent = nullptr)`: 创建一个`MessageBox`对象，并调用UI组件的setup方法。

- **析构函数 (`messagebox.cpp`)**:
  - `~MessageBox()`: 销毁`MessageBox`对象，并释放UI组件的内存。

- **公有成员函数**:
  - `void addMessage(Message message)`: 向消息列表中添加一条消息，并根据消息是否已读更新未读消息数和新消息内容。
  - `void setTime(const QDateTime &newTime)`: 设置消息框的时间，并更新时间标签的显示。
  - `void setNumUnread(int newNumUnread)`: 设置未读消息数，并更新未读标签的显示。
  - `void setNewMessage(const QString &newNewMessage)`: 设置新消息内容，并更新消息标签的显示。
  - `void setName(const QString &newName)`: 设置聊天框的名称，并更新名称标签的显示。
  - `void setChatType(const QString &newChatType)`: 设置聊天类型。
  - `void setAvatar(const QPixmap &newAvatar)`: 设置聊天框的头像，并更新头像标签的显示。
  - `void setId(int newId)`: 设置消息框的唯一标识符。
  - `void setBackgroundColor(const QColor &backgroundcolor)`: 设置消息框的背景颜色。
  - `void setStyleSheet(const QString &style)`: 设置消息框的样式表。

- **重写函数 (`messagebox.cpp`)**:
  - `void mousePressEvent(QMouseEvent *event)`: 重写鼠标点击事件处理函数。如果检测到左键点击，则输出调试信息，标记所有消息为已读，并发出`clicked`信号。

- **信号**:
  - `void clicked(MessageBox *messageBox)`: 当`MessageBox`被点击时发出，携带`MessageBox`对象的指针。

