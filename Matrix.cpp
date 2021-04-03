#include <iostream>
#include<vector>

#include "Matrix.h"
using namespace std;

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
//

int main() {
	colV col1;
	rowV row1{ 0.0, 1.0 };
	rowV row2{ 2.0, 3.0 };
	col1.push_back(row1);
	col1.push_back(row2);
	Matrix m(col1);
	
	m.show();
	cout << endl<< "END";
};