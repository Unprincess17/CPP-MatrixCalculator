#include<iostream>	

#include "Matrix.h"

int main() {
	Matrix m0 = Matrix(2);
	Matrix m1 = m0.IMatrix().scaleMulti(2);
	colV col1;
	col1.push_back(0.0);
	col1.push_back(0.0);
	col1.push_back(3.0);
	colV col2{ 1.0, 0.0,6.0 };
	colV col3{ 0.0,8.0, 10.0 };
	rowV row{ col1,col2, col3 };
	Matrix m2 = Matrix(row);
	m2.show();
	xy tuple1;
	tuple1.x = 1;
	tuple1.y = 1;
	cout << "vertical " << "x: " << m2.getxy().x << "y: " << m2.getxy().y << endl;
	cout << "vertical " << "x: " << m2.getxy(m2.getxy()).x << "y: " << m2.getxy(m2.getxy()).y << endl;
	m2.TMatrix().show();
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
	Matrix m3 = m2.step();
	m3.show();
	
	

};

