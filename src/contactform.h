#ifndef CONTACTFORM_H
#define CONTACTFORM_H

#include <QWidget>
#include<QVBoxLayout>
#include<QEvent>
#include<QMouseEvent>
#include<QDebug>
#include"contactmassage.h"

namespace Ui {
class contactForm;
}

class contactForm : public QWidget
{
    Q_OBJECT

public:
    explicit contactForm(QWidget *parent = nullptr);
    ~contactForm();

private:
    Ui::contactForm *ui;

signals:
    void passContactUid(int Uid);
};

#endif // CONTACTFORM_H
