#include "mainscene.h"
#include "ui_mainscene.h"
#include "testui.h"
#include<qlabel.h>
#include<QSpinBox>

mainscene::mainscene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainscene)
{
    ui->setupUi(this);
    setWindowTitle("矩阵计算器");

    //矩阵乘法
    testui *multiplypage = new testui;
    multiplypage->setWindowTitle("矩阵乘法");

    connect(ui->btn_multiple,&QPushButton::clicked,[=](){
        multiplypage->show();
        this->hide();
    });

    //其余通过槽函数而非构造函数实现
}

mainscene::~mainscene()
{
    delete ui;
}

void mainscene::on_btn_reverse_clicked()
{
    this->hide();
    reverseui* reversepage = new reverseui;
    reversepage->setWindowTitle("矩阵求逆");
    reversepage->show();
}
