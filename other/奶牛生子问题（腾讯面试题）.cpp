/*

	问题描述

		一只刚出生的奶牛，4年生1只奶牛，以后每一年生1只。现在给你一只刚出生的奶牛，求20年后有多少奶牛。

	问题分析

		本题是一个理想化的递归模型，在这20年中奶牛没有生老病死，并且全部都是具有正常生孕能力的母牛。
		大于等于四岁的奶牛会不间断的每年生一个小牛，小牛长到大于等于四岁也是如此，递归模型建立！





*/





#include <stdio.h>
#include <iostream>  
using namespace std;
int CalCowsNum(int iYear) {
	int iCnt = 0;
	long lCowsNum = 1;  //奶牛总数
	for (iCnt = 1; iCnt <= iYear; iCnt++) {
		if (iCnt >= 4) 
		{  //4年以后奶牛数量开始增多
			if ((iYear - iCnt) > 3) 
			{  //第2个4年开始后产的奶牛开始生新奶牛
				lCowsNum += CalCowsNum(iYear - iCnt);
			}
			else {
				lCowsNum++;
			}
		}
	}
	return lCowsNum;    //返回奶牛总数
}
int main() 
{
	int iYear = 0;
	printf("Please input require years:");
	scanf_s("%d", &iYear);  //输入年数
	printf("In %d years, There is %d cows.\n", iYear, CalCowsNum(iYear));  //输出结果
	

	system("pause");
	return 0;
}
