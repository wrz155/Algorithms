/*
@ C++�汾��
	ʵ�ֶ�̬������ά����
*/
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int **pArray;
	int row, col;
	cin >> row >> col;//��������������

					  //������ָ�룿
	pArray = new int*[row];
	//Ϊÿһ�з���ռ�
	for (int p = 0; p<row; ++p)
	{
		pArray[p] = new int[col];
	}

	//Ϊ���鸳ֵ
	for (int m = 0; m<row; ++m)
	{
		for (int n = 0; n<col; ++n)
		{
			cin >> pArray[m][n];
		}
	}
	//���
	for (int i = 0; i<row; ++i)
	{
		for (int j = 0; j<col; ++j)
		{
			cout << pArray[i][j];
		}
	}

	for (int i = 0; i<row; i++)
	{
		delete[] pArray[i]; //�ȳ���ָ��Ԫ����ָ�������
	}
	delete[] pArray;
	getchar();
	return 0;
}




/*
@ C�汾��
	ʵ�ֶ�̬������ά����
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
		pArray[i] = (int*)malloc(col*sizeof(double));  //���ָ�������ÿ��ָ��Ԫ����ָ��һ�����顣
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			pArray[i][j] = i*col + j;//��ʼ������Ԫ��
			printf("%d", pArray[i][j]);
		}
	}

	for (int i = 0; i < row; i++)
	{
		free(pArray[i]); //�ȳ���ָ��Ԫ����ָ�������
	}
	free(pArray);

	getchar();
	getchar();
	return 0;
}