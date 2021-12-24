#include "mypeople.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mypeople w;
    w.show();
    return a.exec();
}
