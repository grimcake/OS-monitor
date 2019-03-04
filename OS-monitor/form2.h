#ifndef FORM2_H
#define FORM2_H

#include <QWidget>
#include <QTimer>
#include <cstring>

namespace Ui {
class Form2;
}

class Form2 : public QWidget
{
    Q_OBJECT

public:
    explicit Form2(QWidget *parent = 0);
    ~Form2();
    bool isNum(std::string str);

public slots :
    void getPid();

private:
    Ui::Form2 *ui;
    QTimer *timer;
};

#endif // FORM2_H
