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
