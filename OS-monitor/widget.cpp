#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tabWidget->removeTab(0);
    ui->tabWidget->removeTab(0);
    form1 = new Form1();
    ui->tabWidget->insertTab(0, form1, tr("tab1"));
}

Widget::~Widget()
{
    delete ui;
}
