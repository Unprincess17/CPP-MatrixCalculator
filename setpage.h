#ifndef SETPAGE_H
#define SETPAGE_H

#include <QWidget>

namespace Ui {
class setpage;
}

class setpage : public QWidget
{
    Q_OBJECT

public:
    explicit setpage(QWidget *parent = 0);
    ~setpage();

private:
    Ui::setpage *ui;
};

#endif // SETPAGE_H
