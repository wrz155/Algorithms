#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;

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

/*对数器*/
void comparator(int arr[], int len) {
	sort(arr, arr + len);			//从小到大排序
}

void printArray(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void generateRandomArray(int arr[], int len, int maxValue) {	// [-maxValue, maxValue]
	for (int i = 0; i < len; i++) {
		arr[i] = rand() % (2 * maxValue + 1) - maxValue;		//[a,b]随机整数，使用(rand() % (b-a+1))+ a;
	}
}

int* copyArray(const int arr[], int len) {
	if (len == 0) {
		return NULL;
	}
	int* cp = new int[len];
	for (int i = 0; i < len; i++) {
		cp[i] = arr[i];
	}
	return cp;
}

//对比两个数组是否一样
bool isEqual(const int arr[], const int cp[], int len) {
	for (int i = 0; i < len; i++) {
		if (arr[i] != cp[i]) {
			return false;
		}
	}
	return true;
}

int main()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100; i++) {
		int len = rand() % 20 + 1;
		int *arr = new int[len];
		generateRandomArray(arr, len, 20);
		int *cp = copyArray(arr, len);

		comparator(arr, len);
		bubbleSort(cp, len);

		if (!isEqual(arr, cp, len)) {
			printArray(arr, len);
			printArray(cp, len);
			break;
		}
	}

	cout << "Nice!" << endl;
	getchar();
	return 0;
}