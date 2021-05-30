#include "stepui.h"
#include "ui_stepui.h"

stepui::stepui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stepui)
{
    ui->setupUi(this);
}

stepui::~stepui()
{
    delete ui;
}
