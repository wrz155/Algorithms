/*
	时间复杂度O(N^2)，额外空间复杂度O(1)，实现可以做到稳定性
*/

void swap(int arr[], int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void bubbleSort(int arr[], int len) {
	if (len < 2) {
		return;
	}
	for (int end = len - 1; end > 0; end--) {
		for (int i = 0; i < end; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr, i, i + 1);
			}
		}
	}
}

void optimizeBubbleSort(int arr[], int len) {
	if (len < 2) {
		return;
	}
	bool flag = true;
	for (int end = len - 1; end > 0; end--) {
		for (int i = 0; i < end; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr, i, i + 1);
				flag = false;
			}
		}
		if (flag) break;
	}
}