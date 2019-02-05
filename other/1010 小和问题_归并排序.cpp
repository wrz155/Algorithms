/*
小和问题：
	在随机元素，随机数组大小的数组中，找出左边比右边元素小的所有元素之和。    
	例如：数组[4,2,5,1,7,3,6] 
	第一个元素4比2大，不算小和，5比4和2都大，那就是4+2=6；
	1比4和2和5都小，不算小和；7比前面的都大，那就是上次小和6+4+2+5+1=18；
	然后3前面比2和1大，那就是18+2+1=21；
	最后6比4、2、5、1、3都大，结果就是21+4+2+5+1+3=36。那么最后的结果就是36。    
	解法：使用归并排序来进行求和，在归并的时候把数组分成左右两个，在归并排序进行左右两个数组进行合并排序的时候进行计算。
	如果左边数组元素N，小于右边数组元素M，那么从右边数组右指针P到右边数组最后R就有(R-P+1)个N，依次累计相加，最后求出最小和。      
	如果要求逆序对，所谓逆序对就是[4,2],[4,1],[5,1].....,  
	那么就是左边比右边大，那么有多少个逆序对就是,中间位置mid减去左指针下坐标P1+1个逆序对，也就是(mid-P1+1)个逆序对，
	把逆序对相加进行返回就是共有多少逆序对。
*/
#include <iostream>
using namespace std;

int merge(int arr[], int L, int mid, int R) {
	int* help = new int[R - L + 1]();
	int i = 0;
	int left = L;
	int right = mid + 1;
	int smallSum = 0;
	while (left <= mid && right <= R) {
		smallSum += arr[left] < arr[right] ? (R - right + 1) * arr[left] : 0;
		help[i++] = arr[left] < arr[right] ? arr[left++] : arr[right++];
	}
	while (left <= mid) {
		help[i++] = arr[left++];
	}
	while (right <= R) {
		help[i++] = arr[right++];
	}
	// 将有序的help数组复制会原来的arr数组中
	for (i = 0; i < R - L + 1; i++) {
		arr[L + i] = help[i];
	}
	delete help;
	return smallSum;
}


int partition(int arr[], int L, int R) {
	if (L == R) {
		return 0;
	}
	int mid = L + ((R - L) >> 1);
	return partition(arr, L, mid) + partition(arr, mid + 1, R) + merge(arr, L, mid, R);
}

int getSmallSum(int arr[], int len) {
	if (NULL == arr || len == 0) {
		return 0;
	}
	return partition(arr, 0, len - 1);
}

int main() {
	int arr[] = { 3, 1, 2, 4, 6, 2, 7, 8, 1 };
	cout << getSmallSum(arr, sizeof(arr) / sizeof(arr[0])) << endl;

	getchar();
	return 0;
}
