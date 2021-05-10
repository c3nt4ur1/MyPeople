#include "mypeople.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyPeople w;
    w.show();
    return a.exec();
}
