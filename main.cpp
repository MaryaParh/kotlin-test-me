#include <QApplication>
#include "countip.h"

int main(int argc, char * argv[])
{
    QApplication a(argc, argv);

    CountIP w;
    w.show; 

    return a.exec();
}