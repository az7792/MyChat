#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include "userinfomanager.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    UserInfoManager *userInfoManager;
    void handleLoginPushButtonClicked();

private:
    Ui::Widget *ui;
};
#endif // LOGINWIDGET_H
