#include <iostream>
#include<vector>
	using namespace std;

typedef vector<vector<double>> rowV;
typedef vector<double> colV;

class Matrix {
private:
	vector<vector<double>> row;

public:
	//Default Constructor, Generate [[0.0]]
	Matrix() {
		colV col;
		col.push_back(0.0);
		row.push_back(col);
	}

	//Constructor for square matrix(rownum * rownum)
	Matrix(int rownum) {
		{
			for (int i = 0; i != rownum; ++i) {
				colV colrow(rownum, 0.0);
				row.push_back(colrow);
			}
		}
	}

	//Constructor for Matrix O(rownum*colnum)
	Matrix(int rownum, int colnum)
	{
		for (int i = 0; i != rownum; ++i) {
			colV colrow(colnum, 0.0);
			row.push_back(colrow);
		}
	}
	//Constructor for well-defined Matrix, Parameters: rowV _col
	Matrix(rowV _row) :
		row(_row)
	{}

	//check, and conpensate for the offset
	void check();

	//print the matrix
	void show();

	//change element's value of matrix 
	void reload(rowV::size_type rownum, colV::size_type colnum, double renum);

	//calculate the determination of matrix
	double determination();

	//Check if the Matrix is a square
	bool ifsquare();

	// generate the Unit matrix of itself
	Matrix IMatrix();

	// transpose the matrix
	Matrix TMatrix();
};

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
			cout << row[i][j] << ' ';
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
		cout << "index out of bounds!,please try correct index" << endl;
		//How to catch this exception?
		//	Matrix::reload(rownum, colnum, renum);
	}
};

//TODO: Determination
double Matrix::determination() {

	return 0;
}

// judge if the Matrix is a square
bool Matrix::ifsquare()
{
	bool issqure = false;
	if (row.size() == row[1].size()) { issqure = true; }
	return issqure;
}

//Calculate the transpose matrix
Matrix Matrix::TMatrix()
{
	rowV::size_type rownum = row.size();
	colV::size_type colnum = row[0].size();//col.size
	Matrix Tm = Matrix(colnum, rownum);
	for (int i = 0; i != rownum; ++i) {
		for (int j = 0; j != colnum; ++j) {
			Tm.row[j][i] = row[i][j];
		}
	}
	return Tm;
}
;

//Generate a side Matrix whose size is equal to its father
Matrix Matrix::IMatrix() {
	if (Matrix::ifsquare()) {
		rowV::size_type rownum = row.size();
		Matrix _IMatrix = Matrix(rownum);
		for (int i = 1; i != rownum+1; ++i) {
			_IMatrix.reload(i, i, 1);
		}
		return _IMatrix;
	}
};