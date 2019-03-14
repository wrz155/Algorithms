/*
	1.循环计数法，（设置一个计数器）。
	2.递归法，（函数调用自身进行计算）
	3.指针-指针法，（库函数使用的是此方法）
*/
#include <iostream>
using namespace std;

int my_strlen_1(char *str)
{
	int number = 0;
	while (*str)
	{
		number++;
		str++;
	}
	return number;
}
int my_strlen_2(char *str)
{
	if (*str != '\0')
	{
		str++;
		return 1 + my_strlen_2(str);
	}
	else
		return 0;
}

int my_strlen_3(char *str)
{
	char *p = str;
	while (*str)
	{
		p++;
	}
	return str - p;
}

int main()
{
	char * str = "www.baidu.com";

	int len1 = my_strlen_1(str);
	cout << len1 << endl;
	int len2 = my_strlen_1(str);
	cout << len2 << endl;
	int len3 = my_strlen_1(str);
	cout << len3 << endl;
	cin.get();

	return 0;
}