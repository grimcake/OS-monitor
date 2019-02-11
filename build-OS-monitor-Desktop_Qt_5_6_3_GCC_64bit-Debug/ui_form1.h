/********************************************************************************
** Form generated from reading UI file 'form1.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM1_H
#define UI_FORM1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form1
{
public:
    QProgressBar *progressBar;
    QLabel *label;
    QLabel *label_2;
    QProgressBar *progressBar_2;

    void setupUi(QWidget *Form1)
    {
        if (Form1->objectName().isEmpty())
            Form1->setObjectName(QStringLiteral("Form1"));
        Form1->resize(400, 300);
        progressBar = new QProgressBar(Form1);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(70, 30, 251, 21));
        progressBar->setValue(0);
        label = new QLabel(Form1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 41, 21));
        label_2 = new QLabel(Form1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 150, 41, 17));
        progressBar_2 = new QProgressBar(Form1);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        progressBar_2->setGeometry(QRect(70, 150, 251, 23));
        progressBar_2->setValue(0);

        retranslateUi(Form1);

        QMetaObject::connectSlotsByName(Form1);
    } // setupUi

    void retranslateUi(QWidget *Form1)
    {
        Form1->setWindowTitle(QApplication::translate("Form1", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Form1", "CPU:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Form1", "\345\206\205\345\255\230:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form1: public Ui_Form1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM1_H
