#include <iostream>

#include "commandControl.h"


void commandControl::welcome()
{
	cout << "��ӭʹ�þ�������� v1.0" << endl;
}

void commandControl::circulation()
{
	cout << "��������Ҫʹ�õĹ��ܵ����: " << "[0]�������� " << "[1]������� " << "[2]������� " << endl\
		<< "[3]����ת�� " << "[4]�������� " << "[5]����ʽֵ " << endl \
		<< "[6]�������� " << "[8]�ֶ��������" << endl;
	while (1) {
		unsigned int x = 0;
		cin >> x;
		switch (x)
		{
		case 0:
			int x,y,sc;
			cout<<"��������"<<endl;
			cout << "������������������7��5�еľ�����������7";
			cin >> x;
			cout << endl;
			cout << "������������������7��5�еľ�����������5";
			cin >> y;
			cout << endl;
			cout << "�������������" << endl;
			if (x > 0 && y > 0) {
				Matrix m(x, y);
				for (rowV::size_type r = 0; r != x - 1; ++r) {
					for (colV::size_type c = 0; c != y - 1; ++c) {
						double re;
						cin >> re;
						m.reload(r, c, re);
					}
				}
				cout << "���������" << endl;
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
