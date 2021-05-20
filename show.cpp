#include<iostream>	

#include "Matrix.h"

int main() {
	Matrix m0 = Matrix(2);
	Matrix m1 = m0.IMatrix().scaleMulti(2);
	colV col1;
	col1.push_back(1.0);
	col1.push_back(3.0);
	col1.push_back(4.0);
	colV col2{ 1.0, 2.0,1.0 };
	colV col3{ 4.0,7.0, 1.0 };
	rowV row{ col1,col2, col3 };
	Matrix m2 = Matrix(row);
	m2.show();
	Matrix m3 = m2.step();
	m3.show();
	
	

};

