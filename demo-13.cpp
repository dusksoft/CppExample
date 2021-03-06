/*
 * 总结
 * 1、基本数据类型的存储请保证类型可表示的范围内进行存储
 * 2、整型转浮点型小数点后全部为零
 * 3、浮点转整型小数点会被清零
 * 4、任意类型转布尔类型非零转换后全部为1
 * 6、防止大容量向小容量的变量转换，如int转short，如果超出可表示的范围，转后数据会丢失，生成无意义的数据
 * 7、一个表达式中，请将类型转换为相同类型再操作
 * 8、无符号的减法，请保证减完后的值是大于零的数,否则对结果类型转换
 */
#include <iostream>
#include <climits>

using namespace std;

int main()
{
	bool a = 200;	// 部分编译器会警告
	bool b = 0;
	
	// 逻辑判断非0即真
	cout << boolalpha << a << endl;	// true
	cout << boolalpha << b << endl;	// false
	
	// 任何数值类型转bool，0保持不变，非0全部转换为1
	cout << a << endl;	// 1
	cout << b << endl;	// 0
	
	// 浮点类型转整型，只取小数点前的整数
	int c = 3.14;	// 部分浏览器报错
	cout << c << endl;	// 3
	
	// 整型转浮点型，小数点全部为0
	double d = 8;
	cout << d << endl; // 8.0
	
	// 超出可表示范围，从最大表示范围回退计数
	unsigned char e = -2;
	cout << int(e) << endl;	 // ASCII码 = 254
	
	// 超出可表示范围，将超出去的部分从0开始计数
	unsigned char f = 256; // 部分编译器会警告
	cout << int(f) << endl;	 // ASCII码 = 0
	
	// 超出可表示范围，从最大表示范围回退计数
	signed int g = -2147483649; // 部分编译器会警告
	cout << INT_MIN << endl;	//-2147483648
	cout << INT_MAX << endl;	//2147483647
	cout << g << endl;	// 2147483647  - 从最大表示的值开始回退
	
	// 超出可表示范围，将超出去的部分从最小可表示范围开始计数
	signed int h = 2147483648; // 部分编译器会警告
	cout << h << endl;	// -2147483648
	
	/*
		两个int类型运算，返回值是int类型
		要转成double需要强制类型转换，或者将其中一项改为double类型
		方案1：double i = 10 / 3.0;
		方案2：double i = (double)10 / 3;
	*/
	double i = 10 / 3;
	cout << i << endl;	// 3
	
	// 超出short能表示的范围，转换成无意义数据
	int k = 214748364;
	short w = k;
	cout << w << endl;	// -13108

	// 有符号和无符号的表达式，最终得到的是无符号的结果，需要进行类型转换
	// cout << (signed)(q + z) << endl;
	unsigned int q = 5;
	int z = -10;
	// int qz = q + z;  // 部分编译器是正常的，不过尽量不要不同类型之间进行操作，转换统一类型后再操作可靠
	cout << q + z << endl; // 4294967291
	
	// 两个无符号的数相见后得到的值也是无符号，如果值有可能是负数，需要对结果进行类型转换
	// cout << (signed)(aa - bb) << endl;
	unsigned int aa = 3;
	unsigned int bb = 150;
	cout << aa - bb << end;
	return 0;
}
