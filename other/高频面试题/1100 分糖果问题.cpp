﻿/*
【题目】
　　一群孩子做游戏，现在请你根据游戏得分来发糖果，要求如下：
　　1、每个孩子不管得分多少，起码分到1个糖果
　　2、任意两个相邻的孩子之间，得分较多的孩子必须多拿一些糖果

　　给定一个数组arr代表得分数组，请返回最少需要多少糖果。
　　例如：arr = [1,2,2]，糖果分配[1,2,1]，即可满足要求且数量最少，所以返回4.

【进阶题目】
　　原题目中的两个规则不变，再加一条规则：
　　3、任意两个相邻的孩子之间如果得分相同，糖果数必须相同

　　给定一个数组arr代表得分数组，返回最少需要多少糖果。
　　例如：arr = [1,2,2]，糖果分配[1,2,2]，即可满足要求且数量最少，所以返回5.

【要求】
　　原文题和进阶问题的时间复杂度都为O(N)，空间复杂度O(1)。

*/

#include <iostream>
using namespace std;

//	返回值表示下个点大于或等于当前点，递增。
int raiseIndex(int arr[], int len, int start) {
	for (int i = start; i != len - 1; i++) {
		if (arr[i] <= arr[i + 1]) {
			return i;
		}
	}
	return len - 1;
}

int rightCands(int arr[], int left, int right) {
	int n = right - left + 1;
	return n + n * (n - 1) / 2;
}

int candyBasic(int arr[], int len) {
	if (NULL == arr || 0 == len) {
		return 0;
	}
	int index = raiseIndex(arr, len, 0);
	int res = rightCands(arr, 0, index++);
	int lbase = 1;
	int next = 0;
	int rcands = 0;
	int rbase = 0;
	while (index != len) {
		if (arr[index] > arr[index - 1]) {
			res += ++lbase;
			index++;
		}
		else if (arr[index] < arr[index - 1]) {
			next = raiseIndex(arr, index - 1);
			rcands = rightCands(arr, index - 1, next++);
			rbase = next - index + 1;
			res += rcands + (rbase > lbase ? -lbase : -rbase);
			lbase = 1;
			index = next;
		}
		else {
			res += 1;
			lbase = 1;
			index++;
		}
	}
	return res;
}



int candyAdvanced(int arr[], int len) {
		if (arr == null || arr.length == 0) {
			return 0;
		}
		int index = nextMinIndex2(arr, 0);
		int[] data = rightCandsAndBase(arr, 0, index++);
		int res = data[0];
		int lbase = 1;
		int same = 1;
		int next = 0;
		while (index != arr.length) {
			if (arr[index] > arr[index - 1]) {
				res += ++lbase;
				same = 1;
				index++;
			}
			else if (arr[index] < arr[index - 1]) {
				next = nextMinIndex2(arr, index - 1);
				data = rightCandsAndBase(arr, index - 1, next++);
				if (data[1] <= lbase) {
					res += data[0] - data[1];
				}
				else {
					res += -lbase * same + data[0] - data[1] + data[1] * same;
				}
				index = next;
				lbase = 1;
				same = 1;
			}
			else {
				res += lbase;
				same++;
				index++;
			}
		}
		return res;
	}

	public static int nextMinIndex2(int[] arr, int start) {
		for (int i = start; i != arr.length - 1; i++) {
			if (arr[i] < arr[i + 1]) {
				return i;
			}
		}
		return arr.length - 1;
	}

	public static int[] rightCandsAndBase(int[] arr, int left, int right) {
		int base = 1;
		int cands = 1;
		for (int i = right - 1; i >= left; i--) {
			if (arr[i] == arr[i + 1]) {
				cands += base;
			}
			else {
				cands += ++base;
			}
		}
		return new int[] { cands, base };
	}

	public static void main(String[] args) {
		int[] test1 = { 3, 0, 5, 5, 4, 4, 0 };
		System.out.println(candy1(test1));

		int[] test2 = { 3, 0, 5, 5, 4, 4, 0 };
		System.out.println(candy2(test2));
	}

}
