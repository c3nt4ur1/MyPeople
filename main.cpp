//  Copyright 2021 c3nt4ur1 (Adriano Naime Bonin)

#include "mypeople.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mypeople w;
    w.show();
    return a.exec();
}
