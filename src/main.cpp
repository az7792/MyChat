#include "manager/formmanager.h"
#include <QApplication>
#include <QBuffer>
#include <QPushButton>
#include <mediumWidget/messagelistform.h>
#include <smallWidget/messagebox.h>
#include <QColor>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FormManager widgetManager;
    widgetManager.show();

    return a.exec();
}
