#include "ppal.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PPal w;
    w.show();
    return a.exec();
}
