#ifndef CHATFORM_H
#define CHATFORM_H

#include <QWidget>
#include "user.h"
namespace Ui {
class ChatForm;
}

class ChatForm : public QWidget
{
    Q_OBJECT

public:
    explicit ChatForm(QWidget *parent = nullptr);
    ~ChatForm();

private:
    Ui::ChatForm *ui;
};

#endif // CHATFORM_H
