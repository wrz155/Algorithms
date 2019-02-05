/*
	时间复杂度O(N^2)，额外空间复杂度O(1)，实现可以做到稳定性
*/

void swap(int arr[], int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void insertionSort(int arr[], int len) {
	if (len < 2) {
		return;
	}
	for (int i = 1; i < len; i++) {
		for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) {
			swap(arr, j, j + 1);
		}
	}
}