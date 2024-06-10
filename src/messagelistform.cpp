#include "messagelistform.h"
#include "ui_messagelistform.h"

messageListForm::messageListForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::messageListForm)
{
    ui->setupUi(this);
}

messageListForm::~messageListForm()
{
    delete ui;
}

void messageListForm::addMessageBox(MessageBox *messageBox)
{
    ui->scrollAreaWidgetContents->layout()->addWidget(messageBox);
}


