/*
* 运行结果有问题，只能输出小数点后面6位
* 能不能输出更多位
*/

#include<iostream>
using namespace std;
int main()
{
	double n(4.56123123), decimal;
	int integer;
	integer = int(n);
	decimal = n - integer;
	cout << "整数部分为：" << integer << endl;
	cout << "小数部分是：" << decimal << endl;

	getchar();
	return 0;
}