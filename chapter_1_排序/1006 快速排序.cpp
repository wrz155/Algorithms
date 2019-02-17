/*
随机快速排序
	时间复杂度O(N*logN)，额外空间复杂度O(logN)，常规实现做不到稳定性。
	分治法策略
		1）选择一个基准数，数据分成独立的两个部分，一个部分所有的数比另一个部分所有数都要小，再按此方法对这两个部分数据分别进行快速排序
		2）递归
注意：
	1，快速排序中，额外空间复杂度最低为O(logN)
	2，快速排序，可以做到稳定性的实现，但是非常难，你不需要掌握
	3，荷兰国旗问题的实现，和快速排序中的改进

扩展：
	快速排序可以做到稳定，论文 01 stable partition
陷阱：
	奇数放左边，偶数放右边，空间复杂度o(1)，相对次序保持不变。
*/
#include <time.h>
#include <iostream>
#include <algorithm>
using namespace std;

/*算法部分:快排*/
void swap(int arr[], int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

int* partition(int arr[], int L, int R)
{
	int less = L - 1;	// 小于区
	int more = R;		// 大于区
	while (L < more) {
		if (arr[L] < arr[R]) {
			swap(arr, ++less, L++);
		}
		else if (arr[L] > arr[R]) {
			swap(arr, --more, L);
		}
		else {
			L++;
		}
	}
	/*经历上面的循环之后下标为从0到L（包括L）的数就均为小于x的数了，
	现在将more的第一个元素和R位置上面的数进行交换*/
	swap(arr, more, R);
	return new int[2]{ less + 1,more };
}

void quickSort(int arr[], int L, int R) {
	if (L < R) {
		swap(arr, L + (int)(rand() % (R - L + 1)), R);
		int* p = partition(arr, L, R);
		quickSort(arr, L, p[0] - 1);
		quickSort(arr, p[1] + 1, R);
		delete p;
	}
}

void quickSort(int arr[], int len) {
	if (NULL == arr || len < 2) {
		return;
	}
	quickSort(arr, 0, len - 1);
}