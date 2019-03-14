#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<stdlib.h>                  
#include <math.h>

#include <stdio.h>
int func(int num)
{
	int s = 0;
	while (num)
	{
		s += num % 10;
		num /= 10;
	}
	return(s);
}
int main()
{
	int n;
	printf("输入一个整数:");
	scanf("%d", &n);
	printf("各位数字之和:%d\n", func(n));
	printf("\n");

	system("pause");
	return 0;
}
