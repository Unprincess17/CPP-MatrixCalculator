//ʵ������������
// 
// Fuctions:
//1.add,multi-by-constant
//2.multi-by-matrix
//3.reverse
// 
// Ԥ��Ч��
// 1.ѡ��ʹ�ù���
//		��Ϊ�ӷ�������2��m*n����
//		��Ϊ���ˣ���������m*n���ͳ���c
//		��Ϊ�˷�����������1��m*n��������2��x*y�����ж�n==x
//		��Ϊ���棬����m*n����
// 2.Ԥ����
//		������Ԫ�� ͨ��tab�ͼ��̽�������
// 3.����
//		��Ϊ�ӷ��������ӦԪ�����
//		��Ϊ���ˣ������Ԫ�س��Գ���c
//		��Ϊ�˷��������㷨matrixMulti
//		��Ϊ���棬�����㷨matrixRever
// 
//How to save a matrix
// By using Vector
//
#include<iostream>	

#include "Matrix.h"
#include "commandControl.h"
int main() {
	//Matrix m0 = Matrix(2);
	//Matrix m1 = m0.IMatrix().scaleMulti(2);
	//colV col1;
	//col1.push_back(1.0);
	//col1.push_back(2.0);
	//col1.push_back(3.0);
	//colV col2{ 4.0, 5.0,6.0 };
	//colV col3{ 7.0,8.0, 10.0 };
	//rowV row{ col1,col2, col3 };
	//Matrix m2 = Matrix(row);
	//cout << m2.determination() << endl;
	//m2.show();
	//Matrix m3 = m2.reverse();
	//m3.show();
	/*cmdshow();*/
	int i, * j, * p = &i;
	j = &i;
	cout << i << endl;
	cout << *j << endl;
	cout << j << endl;
	cout << &i << endl;
	*p = 2;
	cout << i << endl;

};

void cmdshow() {
	while (true) {

	}
}
