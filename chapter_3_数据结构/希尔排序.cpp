/*
 * 希尔排序的效率
		希尔排序的增量序列是影响希尔排序效率的最关键因素，至今为止还没有一个最完美的增量序列公式。可究竟应该选取什么样的增量才是最好，目前还是一个数学难题。
 * 看如下两个增量序列：
		n/2、n/4、n/8...1
		1、3、7...2^k-1
		第一个序列称为希尔增量序列，使用希尔增量时，希尔排序在最坏情况下的时间复杂度为O(n*n)。
		第二个序列称为Hibbard增量序列，使用Hibbard增量时，希尔排序在最坏情况下的时间复杂度为O(n^3/2)。
 * 对10W个无序数分别以希尔增量序列、Hibbard增量序列进行希尔排序，耗时比较如图所示，
		在10W量级的排序，Hibbard增量序列比希尔增量序列的效率已经高了几倍。
		尽管Hibbard并不是最完美的增量序列，但表现已经非常不错，因此在实际应用中希尔排序多采用Hibbard增量序列。
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int a[100];

#define BEGIN_RECORD            \
{                                \
	clock_t ____temp_begin_time___;    \
	____temp_begin_time___=clock();

	#define END_RECORD(dtime)        \
	dtime=float(clock()-____temp_begin_time___)/CLOCKS_PER_SEC;\
}

/*
	希尔插入排序过程
	a	  - 待排序数组
	index - 排序区域的起始边界
	delta - 增量
	len	  - 待排序数组长度
*/
void shellInsert(int a[], int index, int delta, int len)
{
	int tmp, i, j, k;
	for (i = index + delta; i < len; i += delta)
	{
		for (j = i - delta; j >= index; j -= delta) {
			if (a[j] > a[i]) {
				break;
			}
		}

		tmp = a[i];
		for (k = i; k > j; k -= delta)
		{
			a[i] = a[i - delta];
		}
		a[k + delta] = tmp;
	}
}

/*
 希尔排序
 a - 待排序数组
 len - 数组长度
*/
void shellSort(int a[], int len) {
	int delta = (len + 1) / 2 - 1;		//Hibbard增量序列公式
	while (delta > 0) {					
		for (int i = 0; i < delta; i++) {
			shellInsert(a, i, delta, len);
		}
		delta = (delta + 1) / 2 - 1;
	}
}

void shellSort2(int a[], int len) {
	int delta = len / 2;				//希尔增量序列公式
	while (delta > 0) {
		for (int i = 0; i < delta; i++) {
			shellInsert(a, i, delta, len);
		}
		delta /= 2;
	}
}


void printArray(int a[], int length) {
	cout << "数组内容：";
	for (int i = 0; i < length; i++) {
		if (i == 0)
			cout << a[i];
		else
			cout << "," << a[i];
	}
	cout << endl;
}

int main()
{
	float tim;
	int i;
	for (i = 0; i < 100; i++)
	{
		srand(unsigned int(time(NULL)));
		a[i] = int (rand() % 1000);
	}

	cout << "10W个数的希尔排序：" << endl;

	BEGIN_RECORD

		shellSort2(a, sizeof(a) / sizeof(int));
		printArray(a, 10);

	END_RECORD(tim)

		cout << "希尔增量序列运行时间：" << tim << "s" << endl;

	for (i = 0; i < 100; i++)
	{
		srand(unsigned int(time(NULL)));
		a[i] = int(rand() % 1000);
	}
	BEGIN_RECORD

		shellSort(a, sizeof(a) / sizeof(int));

	END_RECORD(tim)

		cout << "Hibbard增量序列运行时间：" << tim << "s" << endl;

	system("pause");
	return 0;
}