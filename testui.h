#ifndef TESTUI_H
#define TESTUI_H

#include <QMainWindow>
#include"myqmatrix.h"
#include"inputui.h"
#include<QDebug>
#include<iostream>
namespace Ui {
class testui;
}

class testui : public QMainWindow
{
    Q_OBJECT

public:
    explicit testui(QWidget *parent = 0);
    ~testui();
    //类内应当包含三个矩阵：左，右，结果矩阵

    myQMatrix qml,qmr,qmoutput;

signals:
    void testui_back();

private slots:
    void on_calculate_clicked();
    void on_btn_back_clicked();

private:
    Ui::testui *ui;
};

#endif // TESTUI_H
