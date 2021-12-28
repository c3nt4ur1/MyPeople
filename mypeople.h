//  Copyright 2021 c3nt4ur1 (Adriano Naime Bonin)

#ifndef MYPEOPLE_H
#define MYPEOPLE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class mypeople; }
QT_END_NAMESPACE

class mypeople : public QMainWindow
{
    Q_OBJECT

public:
    mypeople(QWidget *parent = nullptr);
    ~mypeople();

private slots:
    void on_pb_exit_clicked();

    void on_pb_add_clicked();

    void on_pb_preview_clicked();

    void on_pb_clear_clicked();

    void on_pb_end_clicked();

private:
    Ui::mypeople *ui;
};
#endif // MYPEOPLE_H


vector<string> names;
vector<string> arrival_hour;
