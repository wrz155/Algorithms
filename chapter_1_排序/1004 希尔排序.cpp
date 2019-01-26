/*
 * 希尔排序的效率
		希尔排序的增量序列是影响希尔排序效率的最关键因素，至今为止还没有一个最完美的增量序列公式。
		可究竟应该选取什么样的增量才是最好，目前还是一个数学难题。
 * 看如下两个增量序列：
		n/2、n/4、n/8...1
		1、3、7...2^k-1
		第一个序列称为希尔增量序列，使用希尔增量时，希尔排序在最坏情况下的时间复杂度为O(n*n)。
		第二个序列称为Hibbard增量序列，使用Hibbard增量时，希尔排序在最坏情况下的时间复杂度为O(n^3/2)。
*/

/*
	index - 排序区域的起始边界
	delta - 增量
*/
void shellInsert(int arr[], int index, int delta, int len)
{
	int tmp, i, j, k;
	for (i = index + delta; i < len; i += delta)
	{
		for (j = i - delta; j >= index; j -= delta) {
			if (arr[j] > arr[i]) {
				break;
			}
		}
		tmp = arr[i];
		for (k = i; k > j; k -= delta)
		{
			arr[i] = arr[i - delta];
		}
		arr[k + delta] = tmp;
	}
}

/*
 希尔排序
 a - 待排序数组
 len - 数组长度
*/
void shellSort(int arr[], int len) {
	int delta = (len + 1) / 2 - 1;		//Hibbard增量序列公式
	while (delta > 0) {					
		for (int i = 0; i < delta; i++) {
			shellInsert(arr, i, delta, len);
		}
		delta = (delta + 1) / 2 - 1;
	}
}

void shellSort2(int arr[], int len) {
	int delta = len / 2;				//希尔增量序列公式
	while (delta > 0) {
		for (int i = 0; i < delta; i++) {
			shellInsert(arr, i, delta, len);
		}
		delta /= 2;
	}
}