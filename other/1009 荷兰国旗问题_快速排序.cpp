/*
荷兰国旗问题 已知一个整型数组arr，和一个整数num，
请把小于num的数放在数组的左边，等于num的数放在数组的中间，大于num的数放在数组的右边。 
要求：
	时间复杂度为O(N)，额外空间复杂度O(1)
*/

void swap(int arr[], int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

int* partition(int arr[], int L, int R, int num) {
	int less = L - 1;
	int more = R + 1;
	while (L < more) {
		if (arr[L] < num) {
			swap(arr, ++less, L++);
		} else if (arr[L] > num) {
			swap(arr, --more, L);
		} else {
			L++;
		}
	}
	return new int[2] { less + 1, more - 1 };		//返回等于区的头和尾
}