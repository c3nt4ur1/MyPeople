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

private:
    Ui::mypeople *ui;
};
#endif // MYPEOPLE_H
