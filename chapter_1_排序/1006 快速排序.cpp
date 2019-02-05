﻿/*
随机快速排序
	时间复杂度O(N*logN)，额外空间复杂度O(logN)，常规实现做不到稳定性。
注意： 
	1，快速排序中，额外空间复杂度最低为O(logN) 
	2，快速排序，可以做到稳定性的实现，但是非常难，你不需要掌握 
	3，荷兰国旗问题的实现，和快速排序中的改进

扩展：
	快速排序可以做到稳定，论文 01 stable partition
陷阱：
	奇数放左边，偶数放右边，空间复杂度o(1)，相对次序保持不变。
*/

#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef void(*pSort)(vector<int> &);

/*算法部分:快排*/
void swap(int arr[], int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void partition(vector<int>& arr, vector<int>& p, int l, int r) {
	int less = l - 1;
	int more = r;
	while (l < more) {
		if (arr[l] < arr[r]) {
			swap(arr, ++less, l++);
		}
		else if (arr[l] > arr[r]) {
			swap(arr, --more, l);
		}
		else {
			l++;
		}
	}
	swap(arr, more, r);

	for (vector<int>::iterator iter = arr.begin() + less + 1; iter != arr.begin() + more; ++iter) {
		p.push_back(*iter);
	}
}
int partition(int arr[], int L, int R)
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
	swap(arr, more, R);
	//经历上面的循环之后下标为从low到i（包括i）的数就均为小于x的数了，现在将主元和i+1位置上面的数进行交换
	arr[R] = arr[i + 1];
	arr[i + 1] = x;
	return i + 1;
}
void quickSort(int arr[], int L, int R) {
	if (L < R) {
		swap(arr, L + (int)(rand() % (R - L + 1)), R);
		vector<int> p;
		partition(arr, p, L, R);
		quickSort(arr, L, p[0] - 1);
		quickSort(arr, p[1] + 1, R);
	}
}

void quickSort(int arr[], int len) {
	if (NULL == arr || len < 2) {
		return;
	}
	quickSort(arr, 0, len - 1);
}

int main() {
	srand((unsigned)time(NULL));
}




