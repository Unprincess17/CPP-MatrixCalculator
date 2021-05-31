#ifndef STEPUI_H
#define STEPUI_H

#include <QWidget>
#include <QDebug>
#include "inputui.h"
#include "input_dlg.h"
#include "myqmatrix.h"
#include <QTextEdit>
namespace Ui {
class stepui;
}

class stepui : public QWidget
{
    Q_OBJECT

public:
    explicit stepui(QWidget *parent = 0);
    ~stepui();
    //应该保存一个输入的矩阵、输出的矩阵
    //管理一个输入界面
    input_dlg* dlg;
    myQMatrix minput,moutput;

private slots:
    void on_btn_back_clicked();

    void on_btn_input_clicked();

signals:
    void step_back();

private:
    Ui::stepui *ui;
};

#endif // STEPUI_H
