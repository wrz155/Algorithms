
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

static void PrintArr(int *pnArr, int nLen)
{
	for (int i = 0; i < nLen; i++)
	{
		printf("%d ", pnArr[i]);
	}
	printf("\n");
}

void CountSort(int *pnArr, int nArrR[], int nLen, int k)
{
	int *pnArrTmp = (int *)malloc(sizeof(int) * k);

	for (int i = 0; i < k; i++)
	{
		pnArrTmp[i] = 0;
	}

	for (int i = 0; i < nLen; i++)
	{
		pnArrTmp[pnArr[i]] = pnArrTmp[pnArr[i]] + 1;
	}

	PrintArr(pnArrTmp, k);

	for (int i = 1; i < k; i++)
	{
		pnArrTmp[i] = pnArrTmp[i] + pnArrTmp[i - 1];
	}

	PrintArr(pnArrTmp, k);

	
	for (int i = nLen - 1; i >= 0; i--)
	{
		nArrR[pnArrTmp[pnArr[i]] - 1] = pnArr[i];
		pnArrTmp[pnArr[i]] = pnArrTmp[pnArr[i]] - 1;
	}
}

int main9()
{
	int nArr[11] = { 0, 2, 1, 3, 2, 6, 9, 7, 4, 8, 6 };
	int nArrR[11]; //��������Ľ��
	PrintArr(nArr, 11);
	CountSort(nArr, nArrR, 11, 10);

	PrintArr(nArrR, 11);
	system("pause");
	return 0;
}
