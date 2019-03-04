#include "form2.h"
#include "ui_form2.h"
#include <sys/types.h>
#include <dirent.h>
#include <QDebug>
#include <sstream>
#include <unistd.h>
#include <fstream>

Form2::Form2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form2)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(getPid()));
    timer->start(5000);
}

Form2::~Form2()
{
    delete ui;
}


void Form2::getPid()
{
    ui->textBrowser->setText(tr("PID")+'\t'+tr("NAME")+'\t'+'\t'+tr("STATUS")+'\n');
    ui->textBrowser->moveCursor(QTextCursor::End);
    DIR *dir = 0;
    struct dirent *pt = 0;
    char fpath[20];
    char buf[50], key[10], val[20];


    dir = opendir("/proc");
    if(dir != NULL)
    {
        while((pt = readdir(dir)) != NULL)
        {
            if(strcmp(pt->d_name, ".") == 0 || strcmp(pt->d_name, "..") == 0)
            {
                continue;
            }
            if(isNum(pt->d_name) == false)
            {
                continue;
            }
            sprintf(fpath, "/proc/%s/stat", pt->d_name);

            std::fstream _file;
            _file.open(fpath, std::ios::in);

            if(!_file)
            {
                qDebug()<<fpath<<" don't exit\n";
            }
            else
            {
                char bigbuf[50];
                for(int i = 1; i<=3; i++)
                {
                    memset(buf, 0, sizeof(buf));
                    _file>>buf;
                    ui->textBrowser->insertPlainText(tr(buf)+"\t");
                    ui->textBrowser->moveCursor(QTextCursor::End);
                    if(i == 2)
                    {
                        strcpy(bigbuf, buf);
                        if(strlen(bigbuf)<=11)
                        {

                            ui->textBrowser->insertPlainText("\t");
                            ui->textBrowser->moveCursor(QTextCursor::End);
                        }
                    }

                }
                ui->textBrowser->insertPlainText("\n");
                _file.close();
            }
        }
    }
    closedir(dir);



}

bool Form2::isNum(std::string str)
{
    std::stringstream in(str);
    double d;
    char c;
    if(!(in>>d))
    {
        return false;
    }
    if(in >> c)
    {
        return false;
    }
    return true;
}
