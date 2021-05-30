#ifndef LINEARPAGE_H
#define LINEARPAGE_H

#include <QWidget>
#include "inputui.h"
#include "myqmatrix.h"
#include <QTextEdit>
#include <QDebug>
#include <QDialog>

namespace Ui {
class linearpage;
}

class linearpage : public QWidget
{
    Q_OBJECT

public:
    explicit linearpage(QWidget *parent = 0);
    ~linearpage();
    //属性：算符，操作数1，操作数2（是矩阵或系数）（用operand区分）
    bool flag_operand;
    int flag_operate;
    myQMatrix m1,m2,moutput;
    double colf;
    inputui* m1_input,*m2_input;
    QDialog* number_dlg;
    QLineEdit* number_qle;


signals:
    void linearpage_back();

private slots:
    void on_btn_back_clicked();

    void on_btn_calculate_clicked();

    void on_btn_left_clicked();

    void on_comboBox_currentIndexChanged(const int &index);

    void on_btn_right_matrix_clicked();

    void on_btn_right_number_clicked();

private:
    Ui::linearpage *ui;
};

#endif // LINEARPAGE_H
