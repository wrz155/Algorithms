int* partition(int arr[], int L, int R, int p) {
	int less = L - 1;
	int more = R + 1;
	while (L < more) {
		if (arr[L] < p) {
			swap(arr, ++less, L++);
		} else if (arr[L] > p) {
			swap(arr, --more, L);
		} else {
			L++;
		}
	}
	return new int[] { less + 1, more - 1 };
}