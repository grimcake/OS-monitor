#include "form1.h"
#include "ui_form1.h"
#include <stdio.h>
#include <QDebug>
#include <fstream>

Form1::Form1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form1)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showCpuUsage()));
    connect(timer, SIGNAL(timeout()), this, SLOT(showMemUsage()));
    timer->start(1000);
}

Form1::~Form1()
{
    delete ui;
}

void Form1::showCpuUsage()
{
    FILE *fp;
    long int user, nice, sys, idle, iowait, irq, softirq;
    long int all1, idle1;
    long int static_all = 0;
    long int static_idle = 0;
    float usage = 0;
    char buf[128], cpu[5];

    fp = fopen("/proc/stat", "r");
    if(fp == NULL)
    {
        qDebug("cpu open error");
    }
    else
    {
        fgets(buf, sizeof(buf), fp);
        sscanf(buf, "%s%d%d%d%d%d%d%d", cpu, &user, &nice, &sys, &idle, &iowait, &irq, &softirq);
        all1 = user+nice+sys+idle+iowait+irq+softirq;
        idle1 = idle;
        usage = (float)(all1-static_all-(idle1-static_idle)) / (all1-static_all)*100 ;
        static_all=all1;
        static_idle=idle1;
        fclose(fp);
        if(usage<50 && usage>0)
        {
            //qDebug("%f", usage);
            ui->progressBar->setValue(usage);
        }
    }
}

void Form1::showMemUsage()
{
    int memtotal, memfree;
    char buf[128], str[20];

    float memusage = 0;

    std::ifstream in("/proc/meminfo");
    if(!in.is_open())
    {
        qDebug("mem open error");
    }
    in.getline(buf, 120);
    sscanf(buf, "%s%d", str, &memtotal);
    in.getline(buf, 120);
    sscanf(buf, "%s%d", str, &memfree);
    memusage = (memtotal-memfree)*100.0/memtotal*1.0;
    ui->progressBar_2->setValue(memusage);
}
