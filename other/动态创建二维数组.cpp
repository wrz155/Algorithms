/*
@ C++版本：
	实现动态创建二维数组
*/
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int **pArray;
	int row, col;
	cin >> row >> col;//输入行数和列数

					  //创建行指针？
	pArray = new int*[row];
	//为每一行分配空间
	for (int p = 0; p<row; ++p)
	{
		pArray[p] = new int[col];
	}

	//为数组赋值
	for (int m = 0; m<row; ++m)
	{
		for (int n = 0; n<col; ++n)
		{
			cin >> pArray[m][n];
		}
	}
	//输出
	for (int i = 0; i<row; ++i)
	{
		for (int j = 0; j<col; ++j)
		{
			cout << pArray[i][j];
		}
	}

	for (int i = 0; i<row; i++)
	{
		delete[] pArray[i]; //先撤销指针元素所指向的数组
	}
	delete[] pArray;
	getchar();
	return 0;
}




/*
@ C版本：
	实现动态创建二维数组
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
int main(void)
{
	int **pArray;
	int row, col;
	scanf("%d%d", &row, &col);
	pArray = (int **)malloc(row*sizeof(int *));
	for (int i = 0; i < row; i++)
	{
		pArray[i] = (int*)malloc(col*sizeof(double));  //这个指针数组的每个指针元素又指向一个数组。
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			pArray[i][j] = i*col + j;//初始化数组元素
			printf("%d", pArray[i][j]);
		}
	}

	for (int i = 0; i < row; i++)
	{
		free(pArray[i]); //先撤销指针元素所指向的数组
	}
	free(pArray);

	getchar();
	getchar();
	return 0;
}