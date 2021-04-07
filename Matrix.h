#include<iostream>
#include<cmath>
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

	//Constructor for well-defined Matrix, Parameters: Matrix m
	Matrix(const Matrix &m):
		row(m.row)
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
	bool issquare();

	// change rowm and rown
	void changeRow(int i, int j);

	// change colm and coln
	void changeCol(int i, int j);

	// generate the Unit matrix of itself
	Matrix IMatrix();

	// transpose the matrix
	Matrix TMatrix();
	
	// Add Matrix m and Matrix n
	Matrix add(Matrix n);

	// Multiply by scaler
	Matrix scaleMulti(double scale);

	// Mutiple with another matrix
	Matrix matrixMulti(Matrix n);

	// count (double) algebraic cofactor
	double algeCof(rowV::size_type i, colV::size_type j);

	// Generate Adjugate Matrix
	Matrix adjugate();

	// Reverse the Matrix m
	Matrix reverse();

	// Count the eigen number
	Matrix eigen();
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
		//XXX: How to catch this exception?
		//	Matrix::reload(rownum, colnum, renum);
		cout << "index out of bounds!,please try correct index" << endl;
	}
};

//TODO: Determination
double Matrix::determination() {
	if (Matrix::issquare()) {
		double deter = 0.0;
		//不想写
	}
	return 0;
}

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
	Matrix Tm = Matrix(colnum, rownum);
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
		Matrix _IMatrix = Matrix(rownum);
		for (int i = 1; i != rownum+1; ++i) {
			_IMatrix.reload(i, i, 1);
		}
		return _IMatrix;
	}
	else {
		return Matrix();}
};

// Change row i and row j, where i and j greater than 0
 void Matrix::changeRow(int i, int j)
{
	 --i;
	 --j;
	 int size = row.size();
	 if (i <= size && i > 0 && j <= size && j > 0) {
		 colV tmp = colV(row[j]);
		 row[j] = row[i];
		 row[i] = tmp;
	 }
	 else {
		 cout << "Index out of bounds!" << endl;
	 }
}

 // Change col i and col j, where i and j greater than 0
void Matrix::changeCol(int i, int j)
{
	--i;
	--j;
	const int SIZE = row.size();
	int *tmp = new int[SIZE];
	for (int t = 0; t != SIZE; ++t) {
		tmp[t] = row[i][t];
		row[i][t] = row[j][t];
	}
	for (int t = 0; t != SIZE; ++t) {
		row[j][t] = tmp[t];
	}
	delete[] tmp;
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
	 Matrix mr = Matrix(row.size(), n.row[0].size());
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

 // TODO: count (double) algebraic cofactor
 double Matrix::algeCof(rowV::size_type i, colV::size_type j) {
	 double algecof = 0.0;

	 return algecof;
 }

 //Generate the adjugate matrix
 Matrix Matrix::adjugate()
 {
	 Matrix mr(row);
	 if (mr.issquare()) {
		 for (rowV::size_type i = 0; i != row.size(); ++i) {
			 for (colV::size_type j = 0; j != row[0].size(); ++j) {
				 mr.row[j][i] = algeCof(i - 1, j - 1);
			 }
		 }
	 }
	 else {
		 cout << "Not a square!" << endl;
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
	 }
	 else {
		 cout << "not a square" << endl;
	 }
	return Matrix();
}

 //TODO: 还没学
 Matrix Matrix::eigen()
{
	return Matrix();
}
;