﻿/*
	时间复杂度O(N^2)，额外空间复杂度O(1)，实现可以做到稳定性
*/

void swap(int arr[], int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void selectionSort(int arr[], int len) {
	if (len < 2) {
		return;
	}
	for (int i = 0; i < len - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < len; j++) {
			minIndex = arr[j] < arr[minIndex] ? j : minIndex;
		}
		swap(arr, i, minIndex);
	}
}