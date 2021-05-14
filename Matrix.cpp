﻿#include<iostream>	
#include<cmath>
#include<vector>
#include<iomanip>

#include "Matrix.h"

using namespace std;

//check the Matrix 's integrity
void Matrix::check()
{
	rowV::size_type  t = Matrix::row[0].size();
	//遍历寻找最长的col
	for (rowV::iterator iterrow = row.begin(); iterrow != row.end(); ++iterrow) {
		if ((*iterrow).size() > t) {
			t = iterrow->size();
		}
	}
	//记录最长的row的长度为length
	rowV::size_type length = t;
	//在不为length长度的后面增加到length的长度
	for (rowV::size_type i = 0; i != row.size(); ++i) {
		for (colV::size_type isize = row[i].size(); isize != length; ++isize) {
			row[i].push_back(0);
		}
	}
}

//show the Matrix by col * row
void Matrix::show() {
	for (rowV::size_type i = 0; i != row.size(); ++i) {
		for (colV::size_type j = 0; j != row[i].size(); ++j) {
			cout << setiosflags(ios::right) << setprecision(2) <<setw(5) <<row[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

//three parameters: int rownum, int colnum, renum
void Matrix::reload(rowV::size_type rownum, colV::size_type colnum, double renum) {
	if (rownum > 0 && rownum <= row.size()) {
		if (colnum > 0 && colnum <= row[0].size()) {
			row[rownum - 1][colnum - 1] = renum;
		}
	}
	else {
		//XXX: How to catch this exception?
		//	Matrix::reload(rownum, colnum, renum);
		cout << "index out of bounds!,please try correct index" << endl;
	}
};

// judge if the Matrix is a square
bool Matrix::issquare()
{
	bool issqure = false;
	if (row.size() == row[0].size()) { issqure = true; }
	return issqure;
}

//Calculate the transpose matrix
Matrix Matrix::TMatrix()
{
	rowV::size_type rownum = row.size();
	colV::size_type colnum = row[0].size();//col.size
	Matrix Tm = Matrix((int)colnum, (int)rownum);
	for (int i = 0; i != rownum; ++i) {
		for (int j = 0; j != colnum; ++j) {
			Tm.row[j][i] = row[i][j];
		}
	}
	return Tm;
}

//Generate a side Matrix whose size is equal to its father
Matrix Matrix::IMatrix() {
	if (Matrix::issquare()) {
		rowV::size_type rownum = row.size();
		Matrix _IMatrix = Matrix((int)rownum);
		for (int i = 1; i != rownum + 1; ++i) {
			_IMatrix.reload(i, i, 1);
		}
		return _IMatrix;
	}
	else {
		return Matrix();
	}
};

// Change row i and row j 计算机下标
void Matrix::changeRow(int i, int j)
{
	if (i != j) {
		int size = (int)row.size();
		if (i <= size && i >= 0 && j <= size && j >= 0) {
			colV tmp = colV(row[j]);
			row[j] = row[i];
			row[i] = tmp;
		}
		else {
			cout << "Row index out of bounds!" << endl;
		}
	}
}

// Change row i and col j 计算机下标
void Matrix::changeCol(int i, int j)
{
	if (i != j) {
		if (i >= 0 && i <= row.size() && j >= 0 && j <= row[0].size()) {
			const int SIZE = (int)row.size();
			for (int t = 0; t != SIZE; ++t) {
				double tmp = row[t][i];
				row[t][i] = row[t][j];
				row[t][j] = tmp;
			}
		}
		else {
			cout << " Col index out of bounds!" << endl;
		}
	}
}

void Matrix::addRow(rowV::size_type rownew, rowV::size_type rowold)
{
	if (rownew != rowold) {
		if (rownew >= 0 && rownew <= row.size() && rowold >= 0 && rowold <= row.size()) {
			for(rowV::size_type i = 0; i != row.size(); ++i){
				row[rownew][i] += row[rowold][i];
			}
		}
		else {
			cout << " Row index out of bounds!" << endl;
		}
	}
}

void Matrix::addCol(colV::size_type colnew, colV::size_type colold)
{
	if (colnew != colold) {
		if (colnew >= 0 && colnew <= row.size() && colold >= 0 && colold <= row[0].size()) {
			for (colV::size_type i = 0; i != row[0].size(); ++i) {
				row[i][colnew] += row[i][colold];
			}
		}
		else {
			cout << " col index out of bounds!" << endl;
		}
	}
}

void Matrix::multiRow(rowV::size_type rownum, double scale)
{
	if (rownum >= 0 && rownum <= row.size()) {
		for (rowV::size_type i = 0; i != row.size(); ++i) {
			row[i][rownum] *= scale;
		}
	}
	else {
		cout << " Row index out of bounds!" << endl;
	}
}

void Matrix::multiCol(colV::size_type col, double scale)
{
	if (col >= 0 && col <= row[0].size()) {
		for (colV::size_type i = 0; i != row[0].size(); ++i) {
			row[i][col] *= scale;
		}
	}
	else {
		cout << " col index out of bounds!" << endl;
	}
}

// generate a matrix by add this matrix and matrix n
Matrix Matrix::add(Matrix n)
{
	Matrix mr = Matrix(n);
	if (row.size() == n.row.size()) {
		if (row[0].size() == n.row[0].size()) {
			for (rowV::size_type i = 0; i != row.size(); ++i) {
				for (colV::size_type j = 0; j != row[0].size(); ++j) {
					mr.row[i][j] = row[i][j] + n.row[i][j];

				}
			}
		}
		else {
			cout << "unequal coloum size" << endl;
		}
	}
	else {
		cout << " unequal row size" << endl;
	}
	return mr;
}

// generate a Matrix by scaling
Matrix Matrix::scaleMulti(double scale)
{
	Matrix mr = Matrix(row);
	for (rowV::size_type i = 0; i != row.size(); ++i) {
		for (colV::size_type j = 0; j != row[0].size(); ++j) {
			mr.row[i][j] *= scale;
		}
	}
	return mr;
}

// generate matrix by mutiply calling matrix and matrix n
Matrix Matrix::matrixMulti(Matrix n)
{
	Matrix mr = Matrix((int)row.size(), (int)n.row[0].size());
	if (row[0].size() == n.row.size()) {
		for (int i = 0; i != mr.row.size(); ++i) {
			for (int j = 0; j != mr.row[0].size(); ++j) {
				for (int k = 0; k != row[0].size(); ++k) {
					mr.row[i][j] += row[i][k] * n.row[k][j];
				}
			}
		}
	}
	else {
		cout << "Cannot multiply!" << endl;
	}
	return mr;
}


// Determination
double Matrix::determination() {
	double deter = 0.0;
	if (Matrix::issquare()) {
		if (row.size() == 1) {
			deter = row[0][0];
			return deter;
		}
		else {
			for (colV::size_type j = 0; j != row[0].size(); ++j) {
				deter += row[0][j] * algeCof(0, j);
			}
			return deter;

		}
	}
	cout << "Not a square! No determination" << endl;
	return deter;
}

// count (double) algebraic cofactor
double Matrix::algeCof(rowV::size_type rownum, colV::size_type colnum) {
	double algecof = 0.0;
	if (row.size() == 1 && row[0].size() == 1) {
		algecof = row[0][0];
	}
	else {
		if (issquare()) {
			if (rownum >= 0 && rownum <= row.size()) {
				if (colnum >= 0 && colnum <= row[0].size()) {
					Matrix tmp(row);
					Matrix mr(int(row.size() - 1));
					for (int bias = 0; bias != (int)colnum; ++bias) {
						tmp.changeCol(int(colnum - bias), int(colnum - bias - 1));
					}
					for (int bias = 0; bias != (int)rownum; ++bias) {
						tmp.changeRow(int(rownum - bias), int(rownum - bias - 1));
					}
					for (rowV::size_type i = 0; i != row.size() - 1; ++i) {
						for (colV::size_type j = 0; j != row[0].size() - 1; ++j) {
							mr.row[i][j] = tmp.row[i + 1][j + 1];
						}
					}
					algecof = pow(-1, rownum + colnum) * mr.determination();
				}
			}
			else {
				cout << "Not a square! No algecofactor" << endl;
			}
		}
	}
	return algecof;
}

//Generate the adjugate matrix
Matrix Matrix::adjugate()
{
	Matrix mr(row);
	if (mr.issquare()) {
		for (rowV::size_type i = 0; i != row.size(); ++i) {
			for (colV::size_type j = 0; j != row[0].size(); ++j) {
				mr.row[j][i] = algeCof(i, j);
			}
		}
	}
	else {
		cout << "Not a square! No adjugate!" << endl;
	}
	return mr;
}

//Generate the reversed Matrix
Matrix Matrix::reverse()
{
	Matrix mr = Matrix(row);
	if (issquare()) {
		if (determination() != 0 && 1e-6 < abs(determination())) {
			mr = adjugate().scaleMulti((1 / determination()));
		}
		else {
			cout << "Determination is zero, So no reverse!" << endl;
		}
	}
	else {
		cout << "not a square, no reverse" << endl;
	}
	return mr;
}

//TODO: 还没学
Matrix Matrix::eigen()
{
	return Matrix();
}

Matrix Matrix::diagonalize()
{
	return Matrix();
}

//r*c阶矩阵的上三角化
//
Matrix Matrix::upperize()
{
	return Matrix();
}
