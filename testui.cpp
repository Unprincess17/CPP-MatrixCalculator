#include "testui.h"
#include "ui_testui.h"


testui::testui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::testui)
{
    ui->setupUi(this);
    qml = myQMatrix();
    qmr = myQMatrix();
    qmoutput = myQMatrix();
    inputui *inputpage_left = new inputui;
    inputui *inputpage_right = new inputui;

    //点击左输入
    connect(ui->leftinput,&QPushButton::clicked,[=](){
        inputpage_left->setWindowTitle("输入左矩阵");
        inputpage_left->qinput = myQMatrix(qml);
        inputpage_left->show();
    });
    //点击右输入
    connect(ui->rightinput,&QPushButton::clicked,[=](){
        inputpage_right->setWindowTitle("输入右矩阵");
        inputpage_left->qinput = myQMatrix(qmr);
        inputpage_right->show();
    });

    //监听到左输入的的返回
    connect(inputpage_left,&inputui::inputui_back,[=](){
       qDebug()<<"监听到了左返回信息";
       qml = myQMatrix(inputpage_left->qinput);

    });

    //监听到右输入的返回
    connect(inputpage_right,&inputui::inputui_back,[=](){
       qDebug()<<"监听到了右返回信息";
       qmr = myQMatrix(inputpage_right->qinput);
    });

}

testui::~testui()
{
    delete ui;
}

//点击计算按钮
void testui::on_calculate_clicked()
{
    cout<<"mleft"<<endl;
    qml.show();
    cout<<"mright"<<endl;
    qmr.show();
    cout<<"qmoutput"<<endl;
    qmoutput = qml.matrixMulti(qmr);
    qmoutput.show();
    QTextEdit* outputshow = new QTextEdit;
    outputshow = qmoutput.getTextEdit();
    outputshow->resize(240,200);
    outputshow->setParent(this);
    outputshow->move(QPoint(50,290));
    outputshow->show();
}

void testui::on_btn_back_clicked()
{
    emit testui_back();
}
