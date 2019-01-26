#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef void(*pSort)(vector<int> &);

/*算法部分:快排*/
void swap(vector<int> &arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void partition(vector<int>& arr, vector<int>& p, int l, int r) {
	int less = l - 1;
	int more = r;
	while (l < more) {
		if (arr[l] < arr[r]) {
			swap(arr, ++less, l++);
		}
		else if (arr[l] > arr[r]) {
			swap(arr, --more, l);
		}
		else {
			l++;
		}
	}
	swap(arr, more, r);

	for (vector<int>::iterator iter = arr.begin() + less + 1; iter != arr.begin() + more; ++iter) {
		p.push_back(*iter);
	}
}

void quickSort(vector<int> &arr, int l, int r) {
	if (l < r) {
		srand((unsigned)time(NULL));
		swap(arr, l + (int)(rand() % (r - l + 1)), r);
		vector<int> p;
		partition(arr, p, l, r);
		quickSort(arr, l, p[0] - 1);
		quickSort(arr, p[1] + 1, r);
	}
}

void quickSort(vector<int> &arr) {
	if (arr.size() < 2) {
		return;
	}
	quickSort(arr, 0, arr.size() - 1);
}


/*测试部分：对数器*/
void comparator(vector<int> &arr) {
	sort(arr.begin(), arr.end());		//从小到大排序
}

void printArray(const vector<int> &arr) {
	for (auto it : arr) {
		cout << it << "  ";
	}
	cout << endl;
}

void generateRandomArray(int maxSize, int maxValue, vector<int> &arr) {
	srand((unsigned)time(NULL));
	int size = (int)((maxSize + 1) * (rand() % 10 / 10.0));
	for (int i = 0; i < size; i++) {
		arr.push_back((int)((maxValue + 1) * (rand() % 10 / 10.0)) - (int)((maxValue + 1) * (rand() % 10 / 10.0)));
	}
}

void copyArray(const vector<int> &arr, vector<int> &cpArr) {
	if (arr.size() == 0) {
		return;
	}
	for (auto it : arr) {
		cpArr.push_back(it);
	}
}

//对比两个数组是否一样
bool isEqual(const vector<int> &arr, const vector<int> &cpArr) {
	for (int i = 0; i < (int)arr.size(); i++) {
		if (arr[i] != cpArr[i]) {
			return false;
		}
	}
	return true;
}

void testFunction(int maxSize, int maxValue, int testTime, pSort pFunc) {
	vector<int> arr, cpArr;
	for (int i = 0; i < testTime; i++) {
		vector<int>().swap(arr);
		vector<int>().swap(cpArr);
		generateRandomArray(maxSize, maxValue, arr);
		copyArray(arr, cpArr);

		pFunc(arr);
		comparator(cpArr);

		if (!isEqual(arr, cpArr)) {
			cout << "Fucking fucked!" << endl;
			printArray(arr);
			printArray(cpArr);
			return;
		}
	}
	cout << "Nice!" << endl;
}


int main()
{
	testFunction(20, 100, 100000, quickSort);

	getchar();
	return 0;
}



