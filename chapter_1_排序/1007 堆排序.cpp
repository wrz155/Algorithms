/*
建立堆的代价为o(N);
堆排序的代价为o(N*logN);

堆排序的缺点：
	不稳定
	常数项比较大

时间复杂度O(N*logN)，额外空间复杂度O(1)，实现不能做到稳定性
关键步骤：heapInsert, heapify，堆的扩大和缩小操作

注意：
	1，堆排序中，建立堆的操作待见为O(N) 
	2，堆排序的核心数据结构：堆，也可以说是优先级队列
*/

#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;

void swap(int arr[], int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void heapInsert(int arr[], int index) {
	while (arr[index] > arr[(index - 1) / 2]) {
		swap(arr, index, (index - 1) / 2);
		index = (index - 1) / 2;
	}
}
void heapify(int arr[], int index, int size) {
	int left = index * 2 + 1;
	while (left < size) {
		int largest = left + 1 < size && arr[left + 1] > arr[left] ? left + 1 : left;
		largest = arr[largest] > arr[index] ? largest : index;
		if (largest == index) {
			break;
		}
		swap(arr, largest, index);
		index = largest;
		left = index * 2 + 1;
	}
}
void heapSort(int arr[], int len) {
	if (NULL == arr || len < 2) {
		return;
	}
	for (int i = 0; i < len; i++) {
		heapInsert(arr, i);
	}
	int size = len;
	swap(arr, 0, --size);
	while (size > 0) {
		heapify(arr, 0, size);
		swap(arr, 0, --size);
	}
}