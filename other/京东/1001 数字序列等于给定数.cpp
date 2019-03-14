/*
题目描述：
东东从京京那里了解到有一个无限长的数字序列: 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, ...(数字k在该序列中正好出现k次)。东东想知道这个数字序列的第n项是多少，你能帮帮他么。

输入描述：
输入包括一个整数n(1 ≤ n ≤ $10^{18}$) 。
输出描述：
输出一个整数，即数字序列的第n项。
示例：
输入
169
输出
18
*/
#include <math.h>
#include <iostream>
using namespace std;

int main() {

	int n = 0;
	cin >> n;
	return (int)ceil((sqrt(1 + 8 * ((double)n)) - 1) / 2);
}
