#include <QMessageBox>
#include "mypeople.h"
#include "ui_mypeople.h"

MyPeople::MyPeople(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyPeople)
{
    ui->setupUi(this);
}

MyPeople::~MyPeople()
{
    delete ui;
}

#define MAX_PEOPLE 200

QString nomes[MAX_PEOPLE] = {};
QString horarios_de_chegada[MAX_PEOPLE] ={};
int i = 0;

void MyPeople::on_pb_cadastrar_clicked()
{
    if(ui->le_nome->text().toStdString() != ""){
        nomes[i] = ui->le_nome->text();
        horarios_de_chegada[i] = ui->le_chegada->text();
        ui->le_nome->clear();
        ui->le_chegada->clear();
        i++;
    }
}

void MyPeople::on_pb_lista_clicked()
{
    QString outputs;
    if(i == 0){
        QMessageBox::information(this, "Convidados", "Ninguém chegou ainda  :(");
    }else{
        outputs = "NOME | HORÁRIO DE CHEGADA\n___________________________________\n";
        for(int j = 0; j < i; j++){
            outputs += nomes[j] + " | " + horarios_de_chegada[j] + "\n";
        }
        outputs += "\n                                                 "; //Organiza o tamanho da caixa
        QMessageBox::about(this, "Pessoas", outputs);
    }

}

void MyPeople::on_pb_limpar_clicked()
{
    QMessageBox::StandardButton deletar = QMessageBox::question(this, "Limpar lista", "Deletar todos os dados?");
    if(deletar == QMessageBox::Yes){
        QString* pNomesI;
        QString* pChegadas;
        for(; i > 0; i--){
            pNomesI = &nomes[i];
            *pNomesI = 0;
            pChegadas = &horarios_de_chegada[i];
            *pChegadas = 0;
        }
    }
}

