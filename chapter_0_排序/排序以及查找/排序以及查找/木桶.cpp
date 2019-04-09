#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
void bucket_sort(unsigned *, int);//桶排序函数的原型
void print(unsigned *, int);//打印函数的原型
int main8()
{
	unsigned array[SIZE];
	int i = 0;

	//为数组元素随机赋值
	for (i = 0; i < SIZE; ++i)
		array[i] = rand();

	printf("排序前\n");
	print(array, SIZE);

	//排序
	bucket_sort(array, SIZE);

	printf("排序后\n");
	print(array, SIZE);
	system("pause");
	return 0;
}
void bucket_sort(unsigned * arr, int len)
{
	unsigned *buckets[10];//指针数组
	unsigned n = 1;//用于取整数各位上的值
	int index;//数组下标计数索引
	int indexs[10];//各个桶下标计数索引
	int i, j;

	//分配动态内存作为桶
	for (i = 0; i < 10; ++i)
		buckets[i] = (unsigned *)malloc(sizeof(unsigned)*len);

	while (1)
	{
		//计数索引清零
		index = 0;
		for (i = 0; i < 10; ++i)
			indexs[i] = 0;

		//数组至桶
		for (i = 0; i < len; ++i)
			buckets[arr[i] / n % 10][indexs[arr[i] / n % 10]++] = arr[i];

		//桶至数组
		for (i = 0; i < 10; ++i)
			for (j = 0; j < indexs[i]; ++j)
				arr[index++] = buckets[i][j];

		//为取元素的下一位做准备
		n *= 10;

		//判断是否该结束
		for (i = 0; arr[i] < n&&i < len; ++i);
		if (i == len) break;
	}

	//释放动态内存
	for (i = 0; i < 10; ++i)
		free(buckets[i]);
}
void print(unsigned * arr, int len)
{
	int i = 0;
	for (i = 0; i < len; ++i)
	{
		printf("%8d", arr[i]);

		//5个元素一行
		if ((i + 1) % 5 == 0)
			printf("\n");
	}
}
