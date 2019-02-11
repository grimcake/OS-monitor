#ifndef FORM1_H
#define FORM1_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class Form1;
}

class Form1 : public QWidget
{
    Q_OBJECT

public:
    explicit Form1(QWidget *parent = 0);
    ~Form1();

public slots:
    void showCpuUsage();
    void showMemUsage();

private:
    Ui::Form1 *ui;
    QTimer *timer;
};

#endif // FORM1_H
