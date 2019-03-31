/*
战争游戏的至关重要环节就要到来了，这次的结果将决定王国的生死存亡，小B负责首都的防卫工作。
首都位于一个四面环山的盆地中，周围的n个小山构成一个环，
作为预警措施，小B计划在每个小山上设置一个观察哨，日夜不停的瞭望周围发生的情况。 
一旦发生外地入侵事件，山顶上的岗哨将点燃烽烟，
若两个岗哨所在的山峰之间没有更高的山峰遮挡且两者之间有相连通路，
则岗哨可以观察到另一个山峰上的烽烟是否点燃。
由于小山处于环上，任意两个小山之间存在两个不同的连接通路。
满足上述不遮挡的条件下，一座山峰上岗哨点燃的烽烟至少可以通过一条通路被另一端观察到。
对于任意相邻的岗哨，一端的岗哨一定可以发现一端点燃的烽烟。 
小B设计的这种保卫方案的一个重要特性是能够观测到对方烽烟的岗哨对的数量，她希望你能够帮她解决这个问题。 

输入描述:
输入中有多组测试数据，每一组测试数据的
第一行为一个整数n(3<=n<=10^6),为首都周围的小山数量，
第二行为n个整数，依次表示为小山的高度h（1<=h<=10^9）.

输出描述:
对每组测试数据，在单独的一行中输出能相互观察到的岗哨的对数。

输入例子1:
5
1 2 4 5 3

输出例子1:
7

*/
/* 
	如果环中没有重复值，一共有2n-3对。
*/
#include <stack>
#include <iostream>
using namespace std;

// 求出从组合n个数，取2个，一共有多少种取法
long long getInternalSum(int n) {
	return n == 1L ? 0 : (long long)n * (long long)(n - 1) / 2L;
}

// 环形，当i = size - 1是，下一个index是0
int nextIndex(int size, int i) {
	return i < (size - 1) ? (i + 1) : 0;
}

long long communications(int arr[], int len) {
	if (NULL == arr || len < 2) {
		return 0;
	}
	//找到最高的山峰，不一定只有一个，就找到第一个就可以
	int maxIndex = 0;
	for (int i = 0; i < len; i++) {
		maxIndex = arr[maxIndex] < arr[i] ? i : maxIndex;
	}
	int value = arr[maxIndex];
	int index = nextIndex(len, maxIndex);
	long long res = 0;
	stack<pair<int, int>> stack;
	stack.push(make_pair(value, 1));
	while (index != maxIndex) {
		value = arr[index];
		while (!stack.empty() && stack.top().first < value) {
			int times = stack.top().second;
			stack.pop();
			res += getInternalSum(times) + times * 2;
		}
		if (!stack.empty() && stack.top().first == value) {
			stack.top().second++;
		}
		else {
			stack.push(make_pair(value, 1));
		}
		index = nextIndex(len, index);
	}
	while (!stack.empty()) {
		int times = stack.top().second;
		stack.pop();
		res += getInternalSum(times);
		if (!stack.empty()) {
			res += times;
			if (stack.size() > 1) {
				res += times;
			}
			else {
				res += stack.top().second > 1 ? times : 0;
			}
		}
	}
	return res;
}
int main() {
	int len;
	cin >> len;
	int *arr = new int[len]();
	for (int i = 0; i < len; i++)
	{
		cin >> arr[i];
	}
	cout << communications(arr,len) << endl;
	return 0;
}