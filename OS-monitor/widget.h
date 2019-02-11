#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "form1.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    Form1 *form1;
};

#endif // WIDGET_H
