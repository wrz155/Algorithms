//�ļ�����exp1-2.cpp
#include <stdio.h>
#include<iostream>
#include<stdlib.h>                   //	system("pause");
#include <math.h>
bool prime(int n)					//�ж�������n�Ƿ�Ϊ����
{                                   //һ������������������ƽ����֮�ڵ�������������
	int i;
	for (i=2;i<=(int)sqrt((double)n);i++)    //sqrt() ƽ��������
		if (n%i==0) 
			return false;			//��n��������,���˳�������false
	return true;
}
void main()
{
	int n,i,j=0;					//j�����ۼ���������
	printf("n:");
	scanf("%d",&n);
	printf("С�ڵ���%d������:\n",n);
	if (n>2)
	{	printf("%4d",2);
		j++;
	}
	for (i=3;i<=n;i+=2)
		if (prime(i))
		{	printf("%4d",i);
			if (j!=0 && ++j%10==0)	//ÿ�������ʾ10������
				printf("\n");
		}
	printf("\n");
	system("pause");
}
