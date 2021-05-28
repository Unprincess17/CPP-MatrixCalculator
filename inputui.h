#ifndef INPUTUI_H
#define INPUTUI_H

#include <QWidget>
#include <QSpinBox>
#include "myqmatrix.h"

namespace Ui {
class inputui;
}

class inputui : public QWidget
{
    Q_OBJECT

public:
    explicit inputui(QWidget *parent = 0);
    ~inputui();
    int Qrownum;
    int Qcolnum;
    bool flag_built;
    myQMatrix qinput;
    vector<QLineEdit*> lines;

private slots:
    void on_build_clicked();
    void on_build_2_clicked();

signals:
    void inputui_back();

private:
    Ui::inputui *ui;
};

#endif // INPUTUI_H
