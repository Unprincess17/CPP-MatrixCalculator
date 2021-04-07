#include<iostream>	

#include "Matrix.h"

//using namespace std;

//实数矩阵运算器
// 
// Fuctions:
//1.add,multi-by-constant
//2.multi-by-matrix
//3.reverse
// 
// 预期效果
// 1.选择使用功能
//		若为加法，创建2个m*n矩阵
//		若为数乘，创建矩阵（m*n）和常数c
//		若为乘法，创建矩阵1（m*n），矩阵2（x*y）。判断n==x
//		若为求逆，创建m*n矩阵
// 2.预加载
//		创建单元格 通过tab和键盘进行输入
// 3.计算
//		若为加法，矩阵对应元素相加
//		若为数乘，矩阵各元素乘以常数c
//		若为乘法，采用算法matrixMulti
//		若为求逆，采用算法matrixRever
// 
//How to save a matrix
// By using Vector
//


int main() {
	Matrix m0 = Matrix(2);
	Matrix m1 = m0.IMatrix().scaleMulti(2);
	colV col1;
	col1.push_back(1.0);
	col1.push_back(2.0);
	col1.push_back(3.0);
	colV col2{4.0, 5.0, 6.0};
	colV col3{ 7.0,8.0,9.0 };
	rowV row{ col1,col2,col3 };
	Matrix m2 = Matrix(row);
	cout<<m2.algeCof(1, 1);

};