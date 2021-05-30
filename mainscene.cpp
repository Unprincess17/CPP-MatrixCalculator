#include "mainscene.h"
#include "ui_mainscene.h"
#include "testui.h"
#include "linearpage.h"
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
        connect(multiplypage,&testui::testui_back,[=](){
           multiplypage->hide();
           this->show();
        });
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
    connect(reversepage,&reverseui::reverseui_back,[=](){
       delete reversepage;
       this->show();
    });
}

void mainscene::on_btn_linear_clicked()
{
    this->hide();
    linearpage* linearpage_ = new linearpage;
    linearpage_->setWindowTitle("矩阵线性运算");
    linearpage_->show();
    connect(linearpage_,&linearpage::linearpage_back,[=](){
       delete linearpage_;
       this->show();
    });
}
