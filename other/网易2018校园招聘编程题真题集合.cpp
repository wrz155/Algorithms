/*
链接：https://www.nowcoder.com/questionTerminal/a461395335c946c5b409e79847796cd0
来源：牛客网

小易有一个长度为N的正整数数列A = {A[1], A[2], A[3]..., A[N]}。
牛博士给小易出了一个难题:
对数列A进行重新排列,使数列A满足所有的A[i] * A[i + 1](1 ≤ i ≤ N - 1)都是4的倍数。
小易现在需要判断一个数列是否可以重排之后满足牛博士的要求。
输入描述:

输入的第一行为数列的个数t(1 ≤ t ≤ 10),
接下来每两行描述一个数列A,第一行为数列长度n(1 ≤ n ≤ 10^5)
第二行为n个正整数A[i](1 ≤ A[i] ≤ 10^9)


输出描述:

对于每个数列输出一行表示是否可以满足牛博士要求,如果可以输出Yes,否则输出No。
示例1
输入

2
3
1 10 100
4
1 2 3 4
输出

Yes
No


分类讨论下。
	显然，任意数和 4 的倍数相乘，其结果仍是 4 的倍数；
	显然，若存在任意数量 2 的倍数，两两之间乘起来就是 4 的倍数；
	如果存在一个数既不是 4 的倍数，也不是 2 的倍数（即因子里没有 2 ）：
	放在 2 的倍数旁边，一定不符合要求；
	放在 4 的倍数旁边，两两相乘一定是 4 的倍数。
	因此符合要求的排列一定是，所有 2 的倍数相邻排在一起，所有 4 的倍数和剩下的数相间排列，这些剩下的元素个数不能超过 4 的倍数的数量，不然所有 4 的倍数都被包起来了。

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int arr[100100];

int countMod4, countMod2;

void read() {
	countMod4 = 0;
	countMod2 = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
		if (arr[i] % 4 == 0) {
			++countMod4;
		}
		else if (arr[i] % 2 == 0) {
			++countMod2;
		}
	}
}

void work() {
	if (countMod4 >= (n - countMod4 - countMod2)) {
		puts("Yes");
	}
	else {
		puts("No");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		read();
		work();
	}
	return 0;
}



/*
小易准备去魔法王国采购魔法神器,购买魔法神器需要使用魔法币,但是小易现在一枚魔法币都没有,但是小易有两台魔法机器可以通过投入x(x可以为0)个魔法币产生更多的魔法币。
魔法机器1:如果投入x个魔法币,魔法机器会将其变为2x+1个魔法币
魔法机器2:如果投入x个魔法币,魔法机器会将其变为2x+2个魔法币
小易采购魔法神器总共需要n个魔法币,所以小易只能通过两台魔法机器产生恰好n个魔法币,小易需要你帮他设计一个投入方案使他最后恰好拥有n个魔法币。
输入描述:
输入包括一行,包括一个正整数n(1 ≤ n ≤ 10^9),表示小易需要的魔法币数量。


输出描述:
输出一个字符串,每个字符表示该次小易选取投入的魔法机器。其中只包含字符'1'和'2'。

输入例子1:
10

输出例子1:
122


*/




#include <iostream>
#include <vector>
using namespace std;

int n = 0;
vector<int> out;

void choice(int n)
{
	if (n == 0)
	{
		return;
	}
	if (n % 2 == 0)
	{
		out.insert(out.begin(), 2);
		choice(n / 2 - 1);
	}
	else
	{
		out.insert(out.begin(), 1);
		choice((n - 1) / 2);
	}
}




int main()
{
	while (cin >> n)
	{
		choice( n);
		for (vector<int>::iterator it = out.begin(); it != out.end(); it++)
		{
			cout << *it;
		}
		cout << endl;
	}
	return 0;
}