#ifndef MESSAGELISTFORM_H
#define MESSAGELISTFORM_H

#include <QWidget>
#include "smallWidget/messagebox.h"
namespace Ui {
class messageListForm;
}

class messageListForm : public QWidget
{
    Q_OBJECT

public:
    explicit messageListForm(QWidget *parent = nullptr);
    ~messageListForm();
    void addMessageBox(MessageBox *messagebox);

private:
    Ui::messageListForm *ui;
};

#endif // MESSAGELISTFORM_H
