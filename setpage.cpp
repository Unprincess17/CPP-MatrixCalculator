#include "setpage.h"
#include "ui_setpage.h"

setpage::setpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setpage)
{
    ui->setupUi(this);
}

setpage::~setpage()
{
    delete ui;
}
