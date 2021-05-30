#include "reverseui.h"
#include "ui_reverseui.h"

reverseui::reverseui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reverseui)
{
    ui->setupUi(this);
    connect(inputpage,&inputui::inputui_back,this,&reverseui::showresult);
}

reverseui::~reverseui()
{
    delete inputpage;
    delete ui;
}

void reverseui::on_btn_input_clicked()
{
    //点击输入，调用inputui进行输入
    inputpage->show();
}

void reverseui::showresult(){
    myQMatrix mr = (inputpage->qinput).reverse();
    if(!mr.iszero()){
        QTextEdit* outputshow = new QTextEdit;
        outputshow = mr.getTextEdit();
        outputshow->resize(240,200);
        outputshow->setParent(this);
        outputshow->move(QPoint(40,150));
        outputshow->show();
    }
    else{
        QMessageBox::critical(this,"错误：无逆矩阵","请重新输入");
    }

}




void reverseui::on_btn_back_clicked()
{
    emit reverseui_back();
}
