//  Copyright 2021 c3nt4ur1 (Adriano Naime Bonin)

#include <iostream>
#include <vector>
#include <fstream>
#include "mypeople.h"
#include "./ui_mypeople.h"
using namespace std;


static const char* initial_time;

vector<QString> names;
vector<QString> arrival_hour;
static int total_guests = 0;

mypeople::mypeople(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mypeople)
{
    ui->setupUi(this);
    initial_time = __TIMESTAMP__;

}

mypeople::~mypeople()
{
    delete ui;
}


void mypeople::on_pb_exit_clicked()
{
    close();
}


void mypeople::on_pb_add_clicked()
{
    names.push_back(ui->le_name->text());
    arrival_hour.push_back(QString::number(ui->te_arrival->time().hour()) + QString::number(ui->te_arrival->time().minute()));
    ++total_guests;

}


void mypeople::on_pb_preview_clicked()
{

}

