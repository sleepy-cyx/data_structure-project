#include "demo.h"
#include <QApplication>
#include<controller.h>
int main(int argc, char *argv[])
{
QApplication a(argc, argv);
controller w;

w.dm->show();
w.show();


return a.exec();
}
