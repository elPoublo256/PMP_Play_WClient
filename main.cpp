#include "mainwindow.h"
#include <QApplication>
#include <myclient.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyClient w("192.168.3.24",2323);
    w.show();

    return a.exec();
}
