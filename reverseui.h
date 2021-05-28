#ifndef REVERSEUI_H
#define REVERSEUI_H

#include <QWidget>
#include"myqmatrix.h"
#include "inputui.h"
#include <QMessageBox>

namespace Ui {
class reverseui;
}

class reverseui : public QWidget
{
    Q_OBJECT

public:
    explicit reverseui(QWidget *parent = 0);
    ~reverseui();
    myQMatrix qorigin, qreverse;
    inputui* inputpage = new inputui;


private slots:
    void on_btn_input_clicked();
    void showresult();

private:
    Ui::reverseui *ui;
};

#endif // REVERSEUI_H
