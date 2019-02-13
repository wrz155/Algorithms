/*
完美洗牌
题目详情：
	有个长度为2n的数组{a1,a2,a3,...,an,b1,b2,b3,...,bn}，
	希望排序后{a1,b1,a2,b2,....,an,bn}，
	请考虑有无时间复杂度o(n)，空间复杂度0(1)的解法。

题目来源：
	此题是去年2013年UC的校招笔试题，看似简单，按照题目所要排序后的字符串蛮力变化即可，
	但若要完美的达到题目所要求的时空复杂度，则需要我们花费不小的精力。OK，请看下文详解，一步步优化。

输入数组　A[1..2 * n]
	1、找到 2 * m = 3^k - 1 使得 3^k <= 2 * n < 3^(k +1)
	2、把a[m + 1..n + m]那部分循环移m位
	3、对每个i = 0,1,2..k - 1，3^i是个圈的头部，做cycle_leader算法，数组长度为m，所以对2 * m + 1取模。
	4、对数组的后面部分A[2 * m + 1.. 2 * n]继续使用本算法, 这相当于n减小了m。

*/

#include <iostream>
using namespace std;

void cycles(int arr[], int base, int bloom, int k) {
	for (int i = 0, trigger = 1; i < k; i++, trigger *= 3) {
		int next = (2 * trigger) % bloom;
		int cur = next;
		int record = arr[next + base];
		int tmp = 0;
		arr[next + base] = arr[trigger + base];
		while (cur != trigger) {
			next = (2 * cur) % bloom;
			tmp = arr[next + base];
			arr[next + base] = record;
			cur = next;
			record = tmp;
		}
	}
}

void rotate(int arr[], int L, int m, int R) {
	reverse(arr, L, m);
	reverse(arr, m + 1, R);
	reverse(arr, L, R);
}

void reverse(int arr[], int L, int R) {
	while (L < R) {
		int tmp = arr[L];
		arr[L++] = arr[R];
		arr[R--] = tmp;
	}
}
void shuffle(int arr[], int L, int R) {
	while (R - L + 1 > 0) {
		int lenAndOne = R - L + 2;
		int bloom = 3;
		int k = 1;
		while (bloom <= lenAndOne / 3) {
			bloom *= 3;
			k++;						//step1 计算出k的值，其次计算出bloom
		}
		int m = (bloom - 1) / 2;		//step2 计算出m的值
		int mid = (L + R) / 2;
		rotate(arr, L + m, mid, mid + m);
		cycles(arr, L - 1, bloom, k);
		L = L + bloom - 1;
	}
}

// https://arxiv.org/pdf/0805.1598.pdf
void shuffleProblem(int arr[], int len) {
	// len必须是偶数
	if (NULL != arr && len != 0 && (len & 1) == 0) {	//len起码是2
		shuffle(arr, 0, len - 1);
	}
}


	// for test
	public static void printArray(int[] arr) {
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}

	// for test
	public static int[] generateArray() {
		int len = (int)(Math.random() * 10) * 2;
		int[] arr = new int[len];
		for (int i = 0; i < len; i++) {
			arr[i] = (int)(Math.random() * 100);
		}
		return arr;
	}

	// for test
	public static void shuffleTest(int[] arr) {
		int[] tarr = new int[arr.length];
		int bloom = arr.length + 1;
		for (int i = 1; i <= arr.length; i++) {
			tarr[((2 * i) % bloom) - 1] = arr[i - 1];
		}
		arr[i] = tarr[i];
		for (int i = 0; i < arr.length; i++) {
		}
	}

	public static boolean equalArrays(int[] arr1, int[] arr2) {
		if (arr1 == null || arr2 == null || arr1.length != arr2.length) {
			return false;
		}
		for (int i = 0; i < arr1.length; i++) {
			if (arr1[i] != arr2[i]) {
				return false;
			}
		}
		return true;
	}

public static void main(String[] args) {
		for (int i = 0; i < 5000000; i++) {
			int[] arr = generateArray();
			int[] arr1 = Arrays.copyOfRange(arr, 0, arr.length);
			int[] arr2 = Arrays.copyOfRange(arr, 0, arr.length);
			shuffle(arr1);
			shuffleTest(arr2);
			if (!equalArrays(arr1, arr2)) {
				System.out.println("ooops!");
				printArray(arr);
				printArray(arr1);
				printArray(arr2);
				break;
			}
		}

	}

}
