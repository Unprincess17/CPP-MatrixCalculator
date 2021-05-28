#ifndef MYQMatrix_H
#define MYQMatrix_H

#include "Matrix.h"
#include <QTextEdit>
#include <QLineEdit>
//使用myQMatrix，实现在qt中操作和显示matrix的功能
//应当添加的功能：show功能
//textedit myQMatrix：：show（int x，int y， int width， int height）
//
//
class myQMatrix : public Matrix
{
private:
    vector<QLineEdit*> qlines;
    QTextEdit* qtext;

public:

    //default constructor, form a 3*3 matrix
    myQMatrix():Matrix(3,3)
    {
        xyend.x = 2;
        xyend.y = 2;
        qtext = new QTextEdit;
        for(int i = 0; i != 9; ++i){
            qlines.push_back(new QLineEdit(QString::number(0)));
        }
    }

    //Constructor for square matrix(rownum * rownum)
    myQMatrix(int rownum):Matrix(rownum)
    {
        xyend.x = rownum-1;
        xyend.y = rownum-1;
        qtext = new QTextEdit;
        for(int i = 0; i != rownum*rownum; ++i){
            qlines.push_back(new QLineEdit(QString::number(0)));
        }
    }

    //Constructor for Matrix(rownum*colnum)
    myQMatrix(int rownum, int colnum):Matrix(rownum,colnum){
        qtext = new QTextEdit;
        for(int i = 0; i != row.size()*row[0].size(); ++i){
            qlines.push_back(new QLineEdit(QString::number(0)));
        }
    }

    //Constructor for well-defined Matrix, Parameters: rowV _col
    myQMatrix(rowV _row) :Matrix(_row){
        qtext = new QTextEdit;
        for(int i = 0; i != row.size()*row[0].size(); ++i){
            qlines.push_back(new QLineEdit(QString::number(row[i/row.size()][i%row[0].size()])));
        }
    }

    //Constructor for well-defined Matrix, Parameters: Matrix m
    myQMatrix(const Matrix& m) :Matrix(m){
        qtext = new QTextEdit;
        for(int i = 0; i != row.size()*row[0].size(); ++i){
            qlines.push_back(new QLineEdit(QString::number(row[i/row.size()][i%row[0].size()])));
        }
    }

    myQMatrix(const myQMatrix &m):Matrix(m.row){
        qtext = new QTextEdit;
        for(int i = 0; i != row.size()*row[0].size(); ++i){
            qlines.push_back(new QLineEdit(QString::number(row[i/row.size()][i%row[0].size()])));
        }
    }

    QTextEdit* getTextEdit();

    vector<QLineEdit*> getQLines();

};

#endif // myQMatrix_H
