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
