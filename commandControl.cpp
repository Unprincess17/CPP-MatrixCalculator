#include <iostream>

#include "commandControl.h"


void commandControl::welcome()
{
	cout << "欢迎使用矩阵计算器 v1.0" << endl;
}

void commandControl::circulation()
{
	cout << "请输入想要使用的功能的序号: " << "[0]矩阵数乘 " << "[1]矩阵相乘 " << "[2]矩阵相加 " << endl\
		<< "[3]矩阵转置 " << "[4]矩阵求逆 " << "[5]行列式值 " << endl \
		<< "[6]求伴随矩阵 " << "[8]手动计算矩阵" << endl;
	while (1) {
		unsigned int x = 0;
		cin >> x;
		switch (x)
		{
		case 0:
			int x,y,sc;
			cout<<"矩阵数乘"<<endl;
			cout << "请输入矩阵的行数，如7行5列的矩阵，则请输入7";
			cin >> x;
			cout << endl;
			cout << "请输入矩阵的列数，如7行5列的矩阵，则请输入5";
			cin >> y;
			cout << endl;
			cout << "请逐项输入矩阵" << endl;
			if (x > 0 && y > 0) {
				Matrix m(x, y);
				for (rowV::size_type r = 0; r != x - 1; ++r) {
					for (colV::size_type c = 0; c != y - 1; ++c) {
						double re;
						cin >> re;
						m.reload(r, c, re);
					}
				}
				cout << "请输入标量" << endl;
				cin >> sc;
				
			}
			
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;


		default:
			break;
		}
	}
}
