#include "linearpage.h"
#include "ui_linearpage.h"

linearpage::linearpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::linearpage)
{
    ui->setupUi(this);
    flag_operand = 0;
    flag_operate = 0;
    m1 = myQMatrix(3);
    m2 = myQMatrix(3);
    moutput = myQMatrix(3);
    colf = 0.0;
    m1_input = new inputui;
    m2_input = new inputui;
    number_dlg = new QDialog(this);
    number_qle = new QLineEdit;
}

linearpage::~linearpage()
{
    delete ui;
}

void linearpage::on_btn_back_clicked()
{
    emit linearpage_back();
}

void linearpage::on_btn_calculate_clicked()
{
    //点击计算，读取算符(1,2,3,4)，操作数1，操作数2(0是矩阵，1是系数），进行计算
    m1 = m1_input->qinput;
    //操作数2是矩阵
    if(flag_operand == 0){
        if(m1.xyend.x == m2.xyend.x && m1.xyend.y == m2.xyend.y)
        m2 = m2_input->qinput;
        switch (flag_operate) {
        case 0://+
            moutput = m1.add(m2);
            break;
        case 1:
            //应该使用sub函数，但是我没写
            moutput = m1.add(m2);
            break;
        case 2:
        case 3:
        default:
            qDebug()<<"Exception when Calculating the linear";
            break;
        }
    }
    //操作数2是实数
    else{
        colf = number_qle->text().toDouble();
        switch (flag_operate) {
        case 2:
            moutput = m1.scaleMulti(colf);
            break;
        case 3:
            if(abs(colf)<1e-6){
                moutput = m1.scaleMulti(1/colf);
            }
            break;
        case 0:
        case 1:
        default:
            qDebug()<<"Exception when Calculating the linear";
            break;
        }
    }
    QTextEdit* outputshow = new QTextEdit;
    outputshow = moutput.getTextEdit();
    outputshow->resize(240,200);
    outputshow->setParent(this);
    outputshow->move(QPoint(50,290));
    outputshow->show();
}

void linearpage::on_btn_left_clicked()
{
    m1_input->qinput =m1;
    m1_input->show();
}

void linearpage::on_comboBox_currentIndexChanged(const QString &arg1)
{
    flag_operate = ui->comboBox->currentIndex();//0是+，1是-,2是*，3是/
}



void linearpage::on_btn_right_matrix_clicked()
{
    flag_operand = false;
    m2_input->qinput = m2;
    m2_input->show();
}

void linearpage::on_btn_right_number_clicked()
{
    flag_operand = true;
    QPushButton* number_btn = new QPushButton;
    number_dlg->resize(250,100);
    number_dlg->setWindowTitle("请输入系数");
    number_btn->setText("返回");
    number_btn->setParent(number_dlg);
    number_btn->move(100,60);
    number_btn->setFixedSize(50,20);
    number_qle->setParent(number_dlg);
    number_qle->setFixedSize(50,20);
    number_qle->move(90,15);
    number_dlg->show();
    connect(number_btn,&QPushButton::clicked,number_dlg,&QDialog::close);
}
