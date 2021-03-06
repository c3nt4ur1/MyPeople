//  Copyright 2021 c3nt4ur1 (Adriano Naime Bonin)

#include <iostream>
#include <vector>
#include <fstream>
#include <QMessageBox>
#include "mypeople.h"
#include "./ui_mypeople.h"
using namespace std;

vector<string> names;
vector<string> arrival_hour;
static const char* initial_time;
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
    if(!(ui->le_name->text().isEmpty())){

        names.push_back(ui->le_name->text().toStdString());
        QString qsArrival = ui->te_arrival->time().toString();
        arrival_hour.push_back(qsArrival.toStdString());
        ++total_guests;

        QTime midnight(00, 00);

        ui->le_name->clear();
        ui->te_arrival->setTime(midnight);
    }
}



void mypeople::on_pb_preview_clicked()
{    
    string output = "NAME  |  ARRIVAL TIME   <br>_______________________<br>";


    vector<string>::iterator it1 = names.begin();
    vector<string>::iterator it2 = arrival_hour.begin();

    for(int i = 0; it1 != names.end(); it1++, it2++, i++){
        output += *it1 + "  |  " + *it2 + "<br>";
    }

    output += "<br>";

    QMessageBox::about(this, "Guests", QString::fromStdString(output));
}


void mypeople::on_pb_clear_clicked()
{
    //Will erase the content of the names vector
    QMessageBox::StandardButton clear = QMessageBox::question(this, "", "Delete register?");

    if(clear == QMessageBox::Yes){
        vector<string>::iterator it1 = names.begin();
        for (; it1 != names.end(); it1++){
            *it1 = false;
        }

        it1 = arrival_hour.begin();
        for(; it1 != arrival_hour.end(); it1++){
            *it1 = false;
        }
    }
}

void mypeople::on_pb_end_clicked(){
    if(total_guests){
        ofstream target;

        target.open("Guests.txt", ios::app);

        target << "NAME   |     " << endl;

        vector<string>::iterator it1 = names.begin();
        vector<string>::iterator it2 = arrival_hour.begin();

        for(; it1 != names.end(); it1++, it2++){
            target << *it1 << "    |    " << *it2 << endl;
        }

        target.close();

        QMessageBox::information(this, "", "Guests logged successfully!");
    }else{
        QMessageBox::warning(this, "", "No guests registered yet");
    }
}
