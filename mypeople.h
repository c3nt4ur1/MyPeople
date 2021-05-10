#ifndef MYPEOPLE_H
#define MYPEOPLE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MyPeople; }
QT_END_NAMESPACE

class MyPeople : public QMainWindow
{
    Q_OBJECT

public:
    MyPeople(QWidget *parent = nullptr);
    ~MyPeople();

private slots:
    void on_pb_cadastrar_clicked();

    void on_pb_lista_clicked();

    void on_pushButton_clicked();

private:
    Ui::MyPeople *ui;
};
#endif // MYPEOPLE_H
