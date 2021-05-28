#include "morepage.h"
#include "ui_morepage.h"

morepage::morepage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::morepage)
{
    ui->setupUi(this);
}

morepage::~morepage()
{
    delete ui;
}
