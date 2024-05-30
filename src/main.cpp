#include "loginform.h"

#include <QApplication>
#include <registerform.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginForm w;
 //   RegisterForm w;
    w.show();
    return a.exec();
}
