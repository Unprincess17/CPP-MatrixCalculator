#include "input_dlg.h"
#include "ui_input_dlg.h"

input_dlg::input_dlg(int rownum,int colnum,QWidget *parent)
    :    QDialog(parent),
    ui(new Ui::input_dlg)
{
    ui->setupUi(this);
    Qrownum = rownum;
    Qcolnum = colnum;
    flag_built = false;
    ui->rowspin->setValue(Qrownum);
    ui->colspin->setValue(Qcolnum);
}

input_dlg::~input_dlg()
{
    delete ui;
}


//点击生成，创建对话框
void input_dlg::on_btn_bulid_clicked()
{
    if(!flag_built)
    {
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

//点击确定，返回input_dlg的信息
void input_dlg::on_btn_input_clicked()
{
    //获取输入的值
    for(int i = 0; i != qinput.row.size(); ++i){
        for(int j = 0; j != qinput.row[0].size(); ++j){
            qinput.row[i][j] = lines[i*Qcolnum + j]->text().toDouble();
        }
    }
    emit inputdlg_back();
    this->close();
}
