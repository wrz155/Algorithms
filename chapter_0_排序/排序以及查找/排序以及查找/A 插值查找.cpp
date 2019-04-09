#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h>
int Bin_Search(int *a, int key, int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = low + (high - low) * (key - a[low]) / (a[high] - a[low]); //�˴��ڶ��ֲ��Ҳ�ͬ,���ò�ֵ��ʽ  
		if (a[mid] > key)         //���key�Ȳ�ֵС,�Ѹ�λ����Ϊ��ֵ�±����һλ            
			high = mid - 1;
		else if (a[mid] < key)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
int mainA()
{
	int a[] = { 1, 5, 17, 25, 33, 38, 46, 55, 69, 75, 99 };
	int key;
	int len = sizeof(a) / sizeof(*a);
	printf("������Ҫ���ҵ�ֵ:\n");
	scanf("%d", &key);
	int pos = Bin_Search(a, key, len);
	if (pos != -1)
		printf("������ĵ�%d��λ���ҵ�:%d\n", pos + 1, key);
	else
		printf("δ���������ҵ�Ԫ��:%d\n", key);


	system("pause");
	return 0;
}
