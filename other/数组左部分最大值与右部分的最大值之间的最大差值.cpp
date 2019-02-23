/*
已知一个整型数组arr，数组长度为size且size大于2，arr有size-1种 可以划分成左右两部分的方案。 
比如： arr = {3, 2, 3, 4, 1, 2} 
	第1种划分左部分为[3]，右部分为[2, 3, 4, 1, 2] 
	第2种划分左部分为[3, 2]，右部分为[3, 4, 1, 2] 
	第3种划分左部分为[3, 2, 3]，右部分为[4, 1, 2] 
	第4种划分左部分为[3, 2, 3, 4]，右部分为[1, 2] 
	第5种划分左部分为[3, 2, 3, 4, 1]，右部分为[2]

每一种划分下，左部分都有最大值记为max_left，右部分都有最大值记 为max_right。 
求|max_left-max_right|(左部分最大值与右部分最大值之差的绝对值)， 最大是多少？ 

要求：
	时间复杂度为O(N)，额外空间复杂度O(1)

三种解法
	暴力
	预处理数组法
	基于标准（即题目条件和问法）本身的分析，去优化

算法思想：
	1、数据样本本身去抽象出一个很好的算法思路
	2、从标准出发去思考出一个方法
*/

#include <cmath>
#include <limits.h>
#include <algorithm>

// 暴力求解
int MaxValueBetweenLeftAndRight_2(int arr[], int len) {
	int max = INT_MIN;
	int max_left = 0;
	int max_right = 0;

	for (int i = 0; i != len - 1; i++) {
		max_left = INT_MIN;
		for (int j = 0; j != i + 1; j++) {
			max_left = std::max(arr[j], max_left);
		}
		max_right = INT_MIN;
		for (int j = i + 1; j != len; j++) {
			max_right = std::max(arr[j], max_right);
		}
		max = std::max(abs(max_left - max_right), max);
	}
	return max;
}

//辅助数组法，左数组记录从左到右单调递增，右数组从右到左单调递增
int MaxValueBetweenLeftAndRight_1(int arr[], int len) {
	int* left_arr = new int[len];
	int* right_arr = new int[len];
	left_arr[0] = arr[0];
	right_arr[len - 1] = arr[len - 1];

	for (int i = 1; i < len; i++) {
		left_arr[i] = std::max(left_arr[i - 1], arr[i]);
	}
	for (int i = len - 2; i > -1; i--) {
		right_arr[i] = std::max(right_arr[i + 1], arr[i]);
	}

	int max = 0;
	for (int i = 0; i < len - 1; i++) {
		max = std::max(max, abs(left_arr[i] - right_arr[i + 1]));
	}
	return max;
}

/*
	求出整个数组最大值，头尾比较出较小值，两者相减即为最大值
*/
int MaxValueBetweenLeftAndRight_3(int arr[], int len) {
	int max = INT_MAX;
	for (int i = 0; i < len; i++) {
		max = std::max(arr[i], max);
	}
	return max - std::min(arr[0], arr[len - 1]);
}
