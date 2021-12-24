#include "mypeople.h"
#include "./ui_mypeople.h"

mypeople::mypeople(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mypeople)
{
    ui->setupUi(this);
}

mypeople::~mypeople()
{
    delete ui;
}

