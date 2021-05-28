#ifndef MOREPAGE_H
#define MOREPAGE_H

#include <QWidget>

namespace Ui {
class morepage;
}

class morepage : public QWidget
{
    Q_OBJECT

public:
    explicit morepage(QWidget *parent = 0);
    ~morepage();

private:
    Ui::morepage *ui;
};

#endif // MOREPAGE_H
