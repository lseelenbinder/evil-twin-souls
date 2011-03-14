#include <QtGui/QApplication>
#include "etsgame.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    etsGame w;
    w.show();

    return a.exec();
}
