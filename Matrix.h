#include<vector>
using namespace std;

typedef vector<vector<double>> rowV;
typedef vector<double> colV;
typedef struct xy {
	rowV::size_type x = 0;
	colV::size_type y = 0;
}xy;

#define horizontal 1
#define vertical 0

class Matrix {
private:
	vector<vector<double>> row;
	xy xyend;
	
public:
	//Default Constructor, Generate [[0.0]]
	Matrix() {
		colV col;
		col.push_back(0.0);
		row.push_back(col);
		xyend.x = 0;
		xyend.y = 0;
	}

	//Constructor for square matrix(rownum * rownum)
	Matrix(int rownum) {
		for (int i = 0; i != rownum; ++i) {
			colV colrow(rownum, 0.0);
			row.push_back(colrow);
		}
		xyend.x = rownum-1;
		xyend.y = rownum-1;
	}

	//Constructor for Matrix O(rownum*colnum)
	Matrix(int rownum, int colnum)
	{
		for (int i = 0; i != rownum; ++i) {
			colV colrow(colnum, 0.0);
			row.push_back(colrow);
		}
		xyend.x = rownum-1;
		xyend.y = colnum-1;
	}

	//Constructor for well-defined Matrix, Parameters: rowV _col
	Matrix(rowV _row) :
		row(_row)
	{
		xyend.x = row.size()-1;
		xyend.y = row[0].size()-1;
	}

	//Constructor for well-defined Matrix, Parameters: Matrix m
	Matrix(const Matrix& m) :
		row(m.row)
	{
		xyend.x = row.size()-1;
		xyend.y = row[0].size()-1;
	}


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

	//check if the Matrix is a Zero
	bool iszero();

	// change rowm and rown
	void changeRow(rowV::size_type i, rowV::size_type j);

	// change colm and coln
	void changeCol(colV::size_type i, colV::size_type j);

	void addRow(rowV::size_type rownew, rowV::size_type rowold);

	void addCol(colV::size_type colnew, colV::size_type colold);

	void multiRow(rowV::size_type row, double scale);

	void multiCol(colV::size_type col, double scale);

	// generate the Unit matrix of itself
	Matrix IMatrix();

	// transpose the matrix
	Matrix TMatrix();

	// Add Matrix m and Matrix n
	Matrix add(Matrix& n);

	// Multiply by scaler
	Matrix scaleMulti(double scale);

	// Mutiple with another matrix
	Matrix matrixMulti(Matrix& n);

	// count (double) algebraic cofactor
	double algeCof(rowV::size_type i, colV::size_type j);

	// Generate Adjugate Matrix
	Matrix adjugate();

	// Reverse the Matrix m
	Matrix reverse();

	// Count the eigen number
	Matrix eigen();

	//calculate the stepped(?) Matrix
	Matrix step();

	//矩阵对角化
	Matrix diagonalize(Matrix& m);

	//矩阵上三角化
	Matrix upperize();

	//求秩
	int getRank();

	
	//列遍历求第一个非零元素
	xy getxy(xy xy_t , bool method = vertical);

	xy getxy(bool method = vertical);
};
