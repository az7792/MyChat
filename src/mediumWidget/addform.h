#ifndef ADDFORM_H
#define ADDFORM_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "manager/userinfomanager.h"
#include "smallWidget/contactmassage.h"
#include <QObject>

class AddForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddForm(QWidget *parent = nullptr);
    UserInfoManager &userinfomanage = UserInfoManager::getInstance(); // 获取单例实例
    int status = 0;

private slots:
    void onFindAllButtonClicked();
    void onFindUserButtonClicked();
    void onFindGroupButtonClicked();
    void onSearchButtonClicked();

private:
    QPushButton *findAllButton;
    QPushButton *findUserButton;
    QPushButton *findGroupButton;
    QLineEdit *searchLineEdit;
    QPushButton *searchButton;
    QLabel *searchIconLabel;
    QLabel *searchHintLabel;
    QStackedWidget *contentStack;
    QVBoxLayout *resultLayout; // 用于显示搜索结果的布局

    //QWidget *currentContactWidget = nullptr; // 将类型改为 QWidget*
    contactMassage *contactMassageWidget = nullptr; // 当前的 contactMassage 对象
    contactMassage *currentContactWidget = nullptr; // 当前显示的搜索结果 widget

    void updatePlaceholderText();
    void updateStyles();
    void clearPreviousSearchResult(); // 新增的用于清除上次搜索结果的方法
    void onApplyButtonClicked(contactMassage *contactMassageWidget) ;
};

#endif // ADDFORM_H
