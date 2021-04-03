#include <iostream>
#include<vector>
using namespace std;

typedef vector<vector<double>> colV;
typedef vector<double> rowV;

class Matrix {
private:
	vector<vector<double>> col;

public:
	void show();

	void reload(int colnum, int rownum, double renum);

	double determination();

	Matrix IMatrix();

	//Constructor for test, an pre-input matrix m
	//
	Matrix(colV col0) :
		col(col0)
	{}
}; 


void Matrix::show() {
	for (colV::size_type i = 0; i != col.size(); ++i) {
		for (rowV::size_type j = 0; j != col[i].size(); ++j) {
			cout << col[i][j] << ' ';
		}
		cout << endl;
	}
}

//three parameters: int colnum, int rownum, renum
void Matrix::reload(int colnum, int rownum, double renum) {
	col[colnum][rownum] = renum;
};


//TODO: Determination
double Matrix::determination() {

	return 0;
};

//TODO: IMatrix
//Matrix IMatrix(int n) {
//	return ;
//};

