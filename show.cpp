#include<iostream>	

#include "Matrix.h"

int main() {
	Matrix m0 = Matrix(2);
	Matrix m1 = m0.IMatrix().scaleMulti(2);
	colV col1;
	col1.push_back(0.0);
	col1.push_back(2.0);
	col1.push_back(3.0);
	colV col2{ 0.0, 5.0,6.0 };
	colV col3{ 0.0,8.0, 10.0 };
	rowV row{ col1,col2, col3 };
	Matrix m2 = Matrix(row);
	m2.show();
	/*Matrix m3 = m2.reverse();
	m3.show();
	m3.addCol(2, 1);
	m3.show();
	m3.addRow(1, 2);
	m3.show();
	m3.multiCol(2, 2);
	m3.show();
	m3.multiRow(2, 2);
	m3.show();*/
	
	cout<<"x: "<<m2.getxy().x<<"y: "<<m2.getxy().y;
	

};

