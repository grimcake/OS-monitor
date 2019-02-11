#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tabWidget->removeTab(0); //删除初始化的两个tab
    ui->tabWidget->removeTab(0);
    form1 = new Form1(this);
    ui->tabWidget->insertTab(0, form1, tr("内存"));

    form2 = new Form2(this);
    ui->tabWidget->insertTab(1, form2, tr("进程"));
}

Widget::~Widget()
{
    delete ui;
}
