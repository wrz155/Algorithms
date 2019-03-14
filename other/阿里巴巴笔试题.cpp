/*
正在挑战一个CrackMe的你，把需要填写的前面几位密码都正确猜出了，可是这最后一位密码，好像藏得有点深。CrackMe的作者还挑衅般的在里面藏了个.tar.gz文件，解压缩出来，里面写道你要的最后一个字符就在下面这个字符串里。这个字符是下面整个字符串中第一个只出现一次的字符。 （比如，串是abaccdeff，那么正确字符就是b了）然而下面给出来的字符串好像太长太长了，单靠人力完全无法找出来。于是，你需要写一个程序代劳了。输入文件体积较大，请使用一些快速的输入输出手段，不推荐使用cin/cout，对Java并不推荐使用Scanner直接读写。

输入描述:

第一行，一个正整数T(T≤20)  ，表示输入数据组数。
之后T行，每行一个字符串S。( 1≤S  的长度≤10 6   ，保证字符串中出现的字符的ASCII码在[0x21,0x7F)范围内，即均为可显示的非空白符，同时保证一定有解
输出描述:

一共T 行，每行一个字符C ，表示所给的相应字符串中第一个只出现一次的字符。
输入例子:

2
abaccdeff
testonline
输出例子:
b
s

这个答案在VS中能够运行成功！因为for循环都是1次，所以我认为时间复杂度应该为0(N)。但是在提交答案是确出现问题，

运行超时！你的答案未能在规定的时间内运行通过。

一出现这个问题，我首先想到了时间复杂度估计很高，估计不是我想的O(N),但是是哪里出现了问题了，经过了一天的检查，终于发现了出问题的地方

for(int i=0; i<(int)strlen(str); i++) 就是这条语句，每一次for循环时，都会去重新计算一次(int)(strlen(str));这样时间复杂度就上去了，测试就通不过。
我只要在前面加上一个变量m.然后另
m=(int)(strlen(str));这样就可以了，程序也正常测试成功！

教训，以后再for循环里尽量不要出现像strlen这里需要求得变量。不然时间复杂度上可能会有意料之外的结果。
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define N 1000000


int main()
{
	int strN[255] = { 0 };
	char str[N] = { '0' };
	int T = 0;
	int m = 0;
	while (scanf("%d", &T) != EOF)
	{
		for (int i = 0; i<T; i++)
		{
			char firstchar = '0';
			scanf("%s", &str);
			//m=(int)strlen(str);

			for (int i = 0; i<255; i++)
				strN[i] = 0;

			for (int i = 0; i<(int)strlen(str); i++)
			{
				strN[(int)(*(str + i))]++;
			}

			for (int i = 0; i<(int)strlen(str); i++)
			{
				if (strN[(int)(*(str + i))] == 1)
				{
					firstchar = *(str + i); break;
				}
			}
			//memset(str, 0, m);
			printf("%c\n", firstchar);
		}
		getchar();
		getchar();
		return 0;
	}
}