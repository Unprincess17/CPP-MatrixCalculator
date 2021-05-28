#include "inputui.h"
#include "ui_inputui.h"
#include <QDebug>

inputui::inputui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inputui)
{
    ui->setupUi(this);

    flag_built = false;

}

inputui::~inputui()
{
    delete ui;
}

//点击生成按钮
void inputui::on_build_clicked()
{
    if(!flag_built)
    {
        qDebug()<<"点击了输入";
        Qrownum =(int)( ui->rowspin->value());
        Qcolnum = (int) (ui->colspin->value());
        qinput = myQMatrix(Qrownum,Qcolnum);
        lines = qinput.getQLines();
        for(int i = 0; i != qinput.row.size(); ++i){
            for(int j = 0; j != qinput.row[0].size(); ++j){
                lines[i*Qcolnum + j]->setParent(this);
                lines[i*Qcolnum + j]->resize(this->width()/(2*Qcolnum+1),20
                                             );
                lines[i*Qcolnum + j]->move(QPoint((lines[i*Qcolnum + j]->width())*(2*j+1),150 + (this->width()-230)*(2*i)/(2*Qrownum+1)));
                lines[i*Qcolnum + j]->clear();
                lines[i*Qcolnum + j]->insert(QString::number(0.0));
                lines[i*Qcolnum + j]->show();
            }
        }
        flag_built = true;
    }
    else{ //如果已经设置过，再次点击生成，应当清理lines中的元素，并重新生成lines和矩阵
        for(int i = 0; i != qinput.row.size(); ++i){
            for(int j = 0; j != qinput.row[0].size(); ++j){
                delete lines[i*Qcolnum + j];
            }
        }
        Qrownum =(int)( ui->rowspin->value());
        Qcolnum = (int) (ui->colspin->value());
        qinput = myQMatrix(Qrownum,Qcolnum);
        lines = qinput.getQLines();
        for(int i = 0; i != qinput.row.size(); ++i){
            for(int j = 0; j != qinput.row[0].size(); ++j){
                lines[i*Qcolnum + j]->setParent(this);
                lines[i*Qcolnum + j]->resize(this->width()/(2*Qcolnum+1),20);
                lines[i*Qcolnum + j]->move(QPoint((lines[i*Qcolnum + j]->width())*(2*j+1),150 + (this->height()-230)*(2*i)/(2*Qrownum+1)));
                lines[i*Qcolnum + j]->clear();
                lines[i*Qcolnum + j]->insert(QString::number(0.0));
                lines[i*Qcolnum + j]->show();
            }
        }

    }
}

//点击返回按钮
void inputui::on_build_2_clicked()
{
    //获取输入的值
    for(int i = 0; i != qinput.row.size(); ++i){
        for(int j = 0; j != qinput.row[0].size(); ++j){
            qinput.row[i][j] = lines[i*Qcolnum + j]->text().toDouble();
        }
    }
    emit inputui_back();
    this->close();
}
