#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include<reverseui.h>
namespace Ui {
class mainscene;
}

class mainscene : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainscene(QWidget *parent = 0);
    ~mainscene();

private slots:
    void on_btn_reverse_clicked();

private:
    Ui::mainscene *ui;
};

#endif // MAINSCENE_H
