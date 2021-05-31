#ifndef INPUT_DLG_H
#define INPUT_DLG_H

#include <QDialog>
#include <QSpinBox>
#include "myqmatrix.h"

namespace Ui {
class input_dlg;
}

class input_dlg : public QDialog
{
    Q_OBJECT

public:
    explicit input_dlg(int rownum = 0,int colnum = 0, QWidget *parent = 0);
    ~input_dlg();
    int Qrownum;
    int Qcolnum;
    bool flag_built;
    myQMatrix qinput;
    vector<QLineEdit*> lines;

private slots:
    void on_btn_input_clicked();

    void on_btn_bulid_clicked();

signals:
    void inputdlg_back();
private:
    Ui::input_dlg *ui;
};

#endif // INPUT_DLG_H
