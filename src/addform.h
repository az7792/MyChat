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
#include "userinfomanager.h"
#include "contactmassage.h"
#include <QObject>


class AddForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddForm(QWidget *parent = nullptr);
    UserInfoManager &userinfomanage = UserInfoManager::getInstance();

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


    void updatePlaceholderText();
    void updateStyles();
};

#endif // ADDFORM_H
