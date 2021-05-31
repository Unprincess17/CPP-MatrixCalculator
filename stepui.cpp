#include "stepui.h"
#include "ui_stepui.h"
#include <QDebug>


stepui::stepui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stepui)
{
    ui->setupUi(this);
    minput = myQMatrix();
    moutput = myQMatrix();

}

stepui::~stepui()
{
    delete ui;
}

void stepui::on_btn_back_clicked()
{
    emit step_back();
}

//点击生成，输入行列信息
void stepui::on_btn_input_clicked()
{
    int tmprow = ui->spinbox_row->value();
    int tmpcol = ui->spinbox_col->value();
    dlg = new input_dlg(tmprow,tmpcol,this);
    dlg->qinput = this->minput;
    dlg->show();
    connect(dlg,&input_dlg::inputdlg_back,[=](){
       qDebug()<<"接收到了返回信息";
       moutput = (dlg->qinput).step();
       moutput.show();
       QTextEdit* outputshow = new QTextEdit;
       outputshow = moutput.getTextEdit();
       outputshow->resize(240,200);
       outputshow->setParent(this);
       outputshow->move(QPoint(45,230));
       outputshow->show();
    });
}


