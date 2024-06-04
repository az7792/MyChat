#include "formmanager.h"

#include <QApplication>
#include <registerform.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FormManager widgetManager;
    widgetManager.show();
    return a.exec();
}
