#include<iostream>	

#include "commandControl.h"

int main() {
	Matrix m0 = Matrix(2);
	Matrix m1 = m0.IMatrix().scaleMulti(2);
	colV col1;
	col1.push_back(1.0);
	col1.push_back(2.0);
	col1.push_back(3.0);
	colV col2{ 4.0, 5.0,6.0 };
	colV col3{ 7.0,8.0, 10.0 };
	rowV row{ col1,col2, col3 };
	Matrix m2 = Matrix(row);
	cout << m2.determination() << endl;
	m2.show();
	Matrix m3 = m2.reverse();
	m3.show();

};

void cmdshow() {
	while (true) {

	}
}
