/*
����ֲ���С�ĸ��arr����Ϊ1ʱ��arr[0]�Ǿֲ���С��
arr�ĳ��� ΪN(N>1)ʱ�����arr[0]<arr[1]����ôarr[0]�Ǿֲ���С��
��� arr[N-1]<arr[N-2]����ôarr[N-1]�Ǿֲ���С��
���0<i<N-1������ arr[i]<arr[i-1]������arr[i]<arr[i+1]����ôarr[i]�Ǿֲ���С��
������������arr����֪arr�������������ڵ���������ȡ�
дһ��������ֻ�践��arr������һ���ֲ���С���ֵ�λ�ü���

*/
#include <iostream>


int LocalMinimum(int arr[], int len) {
	if (arr == NULL || len == 0) {
		return -1; // no exist
	}
	if (len == 1 || arr[0] < arr[1]) {
		return 0;
	}
	if (arr[len - 1] < arr[len - 2]) {
		return len - 1;
	}

	int left = 1;
	int right = len - 2;
	int mid = 0;
	while (left < right) {
		mid = (left + right) / 2;
		if (arr[mid] > arr[mid - 1]) {
			right = mid - 1;
		}
		else if (arr[mid] > arr[mid + 1]) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}
	return left;
}
