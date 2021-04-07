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
	bool issquare();

	// generate the Unit matrix of itself
	Matrix IMatrix();

	// transpose the matrix
	Matrix TMatrix();

	// change rowm and rown
	void changeRow(int i, int j);

	// change colm and coln
	void changeCol(int i, int j);

	// Multiply by scaler
	Matrix scaleMulti(int scale);

	// Add Matrix m and Matrix n
	Matrix add(Matrix n);

	// Reverse the Matrix m
	Matrix reverse();

	// Count the eigen number
	Matrix eigen();
};


//check the Matrix 's integrity
void Matrix::check()
{
	rowV::size_type  t = Matrix::row[0].size();
	//����Ѱ�����col
	for (rowV::iterator iterrow = row.begin(); iterrow != row.end(); ++iterrow) {
		if ((*iterrow).size() > t) {
			t = iterrow->size();
		}
	}
	//��¼���row�ĳ���Ϊlength
	rowV::size_type length = t;
	//�ڲ�Ϊlength���ȵĺ������ӵ�length�ĳ���
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
	if (Matrix::issquare()) {
		double deter = 0.0;
		//����д
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

 Matrix Matrix::scaleMulti(int scale)
{
	return Matrix();
}

 Matrix Matrix::add(Matrix n)
{
	 Matrix mr = Matrix(row.size(), row[0].size());
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

 Matrix Matrix::reverse()
{
	return Matrix();
}

 Matrix Matrix::eigen()
{
	return Matrix();
}
;