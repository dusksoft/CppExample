/**
 * C语言不支持函数名重载，C++支持
 */
#include <iostream>
using namespace std;

/*
 相同函数名，不同函数类型,函数重载
 这种情况，使用函数模板实现更合理
 */
void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void swap(float &a, float &b) {
	float tmp = a;
	a = b;
	b = tmp;
}

//相同函数名，不同函数个数实现重载
int add(int a, int b) {
	return a + b;
}
int add(int a, int b, int c) {
	return a + b + c;
}
int add(int a, int b, int c, int d) {
	return a + b + c + d;
}

int main(void) {
	int a = 10;
	int b = 20;
	cout << "a=" << a << ",b=" << b << endl;
	swap(a, b);
	cout << "a=" << a << ",b=" << b << endl;
	
	int num1 = 10;
	int num2 = 20;
	int num3 = 50;
	int num4 = 15;
	cout << add(num1, num2) << endl;
	cout << add(num1, num2, num3) << endl;
	cout << add(num1, num2, num3, num4) << endl;
	return 0;
}