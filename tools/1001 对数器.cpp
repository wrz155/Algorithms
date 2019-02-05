/*
应用：
	排序
	数组
	二叉树
	贪心
	...
*/


#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;



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

void generateNumber(int arr[], int len, int maxValue) {	// [-maxValue, maxValue]
	for (int i = 0; i < len; i++) {
		arr[i] = rand() % (2 * maxValue + 1) - maxValue;		//[a,b]随机整数，使用(rand() % (b-a+1))+ a;
	}
}

void generateString(char str[],int len){
	for (int i = 0; i < len - 1; ++i) {
		switch ((rand() % 3)) {
			case 1:	
				str[i] = 'A' + rand() % 26;		//rand() % 26  产生[0,25]
				break;		
			case 2:			
				str[i] = 'a' + rand() % 26;			
				break;		
			default:			
				str[i] = '0' + rand() % 10;			
				break;		
			}	
		}	
	str[len - 1] = '\0';
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
		generateNumber(arr, len, 20);
		int *cp = copyArray(arr, len);

		comparator(arr, len);
		//Sort(cp, len);

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