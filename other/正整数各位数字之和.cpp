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
	printf("����һ������:");
	scanf("%d", &n);
	printf("��λ����֮��:%d\n", func(n));
	printf("\n");

	system("pause");
	return 0;
}
