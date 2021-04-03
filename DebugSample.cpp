#include<iostream>
#include<stdio.h>

using namespace std;

class Calculator {
public:
	double Calculate(double x, char oper, double y);
};

double Calculator::Calculate(double x, char oper, double y) {
	switch (oper) {
	case'+':return x + y;
	case'-':return x - y;
	case'*':return x * y;
	case'/':return x / y;
	defalut:return 0.0;

	}
}
//int main() {
//	double x = 0.0;
//	double y = 0.0;
//	double result = 0.0;
//	char oper = '+';
//
//
//	cout << "算术运算示例程序" << endl << endl;
//
//	Calculator c;
//	while (oper != '$') {
//		cout << "请输入运算式，格式如： a + b |  a - b | a * b | a / b" << endl;
//		cin >> x >> oper >> y;
//		cout << &oper << endl;
//		if (oper == '/' && y == 0) {
//			cout << "Division by 0 exception" << endl;
//			continue;
//		}
//		else {
//			result = c.Calculate(x, oper, y);
//		}
//		cout << "Result is: " << result << endl;
//	}
//	return 0;
// }