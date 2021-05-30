#ifndef STEPUI_H
#define STEPUI_H

#include <QWidget>

namespace Ui {
class stepui;
}

class stepui : public QWidget
{
    Q_OBJECT

public:
    explicit stepui(QWidget *parent = 0);
    ~stepui();

private:
    Ui::stepui *ui;
};

#endif // STEPUI_H
