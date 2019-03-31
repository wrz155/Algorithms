/*
归并排序
	时间复杂度O(N*logN)，额外空间复杂度O(N)，实现可以做到稳定性
	归并排序，存在额外空间复杂度O(1)的实现，叫做：内部缓存法，但是非常难，你不需要掌握 
	归并排序的扩展，小和问题，逆序对问题
*/

#include <iostream>

void merge(int arr[], int left, int mid, int right) {
	int *help = new int[right - left + 1];
	int i = 0;
	int p1 = left;
	int p2 = mid + 1;
	while (p1 <= mid && p2 <= right) {
		help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
	}
	while (p1 <= mid) {
		help[i++] = arr[p1++];
	}
	while (p2 <= right) {
		help[i++] = arr[p2++];
	}
	for (i = 0; i < right - left + 1; i++) {
		arr[left + i] = help[i];
	}
}

void partition(int arr[], int left, int right) {
	if (left == right) {
		return;
	}
	int mid = left + ((right - left) >> 1);		//防止溢出
	partition(arr, left, mid);
	partition(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

void mergeSort(int arr[], int len) {
	if (NULL == arr  || len < 2) {
		return;
	}
	partition(arr, 0, len - 1);
}



