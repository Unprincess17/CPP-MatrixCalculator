#include "myqmatrix.h"

QTextEdit* myQMatrix::getTextEdit(){
    QString myblanks = QString("   ");
    for(int i = 0; i != row.size(); ++i){
        for(int j = 0; j != row[0].size(); ++j){
//            this->qtext->insertPlainText(QString::number(row[i][j]));
//            this->qtext->insertPlainText(myblanks);
            myblanks = QString("%1").arg(QString::number(row[i][j]),5,' ');
            this->qtext->insertPlainText(myblanks);
        }
        qtext->insertPlainText(QString('\n'));
    }
    return qtext;
}

vector<QLineEdit*> myQMatrix::getQLines(){
    return qlines;
}
