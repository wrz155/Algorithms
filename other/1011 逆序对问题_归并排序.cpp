/*
求数组中的逆序对的数量----剑指offer36题 
	在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
	输入一个数组,求出这个数组中的逆序对的总数：
例：
	如数组{7,5,6,4}，逆序对总共有5对，{7,5}，{7,6}，{7,4}，{5,4}，{6,4}；

思路1：暴力解法
		顺序扫描整个数组，每扫描到一个数字的时候，逐个比较该数字和它后面的数字的大小。
		如果后面的数字比它小，则这两个数字就组成一个逆序对。
		假设数组中含有n个数字，由于每个数字都要和O(n)个数字作比较，因此这个算法的时间复杂度是O(n2)。

思路2：分治思想，采用归并排序的思路来处理。

*/
#include <iostream>
using namespace std;

int merge(int arr[], int L, int mid, int R) {
	int* help = new int[R - L + 1]();
	int i = 0;
	int left = L;
	int right = mid + 1;
	int reverseSum = 0;

	while (left <= mid && right <= R) {
		reverseSum += arr[left] > arr[right] ? R - right + 1 : 0;
		help[i++] = arr[left] > arr[right] ? arr[right++] : arr[left++];
	}
	while (left <= mid) {
		help[i++] = arr[left++];
	}
	while (right <= R) {
		help[i++] = arr[right++];
	}

	// 将有序的help数组复制会原来的arr数组中
	for (int i = 0; i < R - L + 1; i++) {
		arr[L + i] = help[i];
	}

	delete help;
	return reverseSum;
}


int partition(int arr[], int L, int R) {
	if (L == R) {
		return 0;
	}
	int mid = L + ((R - L) >> 1);
	return partition(arr, L, mid) + partition(arr, mid + 1, R) + merge(arr, L, mid, R);
}

int getReverseSum(int arr[], int len) {
	if (NULL == arr || len < 2) {
		return 0;
	}
	return partition(arr, 0, len - 1);
}

int main() {

	int arr[] = { 7,5,6,4 };
	cout << getReverseSum(arr, sizeof(arr) / sizeof(arr[0])) << endl;


	getchar();
	return 0;
}



