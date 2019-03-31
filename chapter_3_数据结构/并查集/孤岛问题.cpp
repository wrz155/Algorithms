/*
给定一个二维数组，所有位置的值不是0就是1。规定每个位置可以和它上下左右位置上的值相连。
有一个叫做岛的概念，定义如下：
连成一片的1，如果周围都是0，那么这一片1，构成一个岛。
求整张图上有多少个岛。
例如：
0 0 0 0 0 0 0 0 0
0 1 1 0 0 1 1 1 0
0 1 1 1 0 0 0 1 0
0 1 1 0 0 0 0 0 0
0 0 0 0 0 1 1 0 0
0 0 0 0 1 1 1 0 0
0 0 0 0 0 0 0 0 0
这张图上有三个岛。

0 0 0 0 0 0 0 0 0
0 1 1 0 1 1 1 1 0
0 1 1 1 1 0 0 1 0
0 1 1 0 0 0 0 1 0
0 0 0 0 0 1 1 1 0
0 0 0 0 1 1 1 0 0
0 0 0 0 0 0 0 0 0
这张图上有一个岛。

进阶：
如果可以使用并行计算，如何来设计你的算法？
*/
#include <iostream>
#include <vector>
using namespace std;

void infect(vector<vector<int>> &arr, int i, int j, int m, int n) {
	if (i < 0 || i >= m || j < 0 || j >= n || arr[i][j] != 1) {
		return;
	}

	arr[i][j] = 2;
	infect(arr, i + 1, j, m, n);
	infect(arr, i - 1, j, m, n);
	infect(arr, i, j + 1, m, n);
	infect(arr, i, j - 1, m, n);
}


int countIslands(vector<vector<int>> &arr) {
	int m = arr.size();
	int n = arr[0].size();
	int res = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				res++;
				infect(arr, i, j, m, n);
			}
		}
	}
	return res;
}

int main() {
	vector<vector<int>> arr1 = { { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
								 { 0, 1, 1, 1, 0, 1, 1, 1, 0 },
								 { 0, 1, 1, 1, 0, 0, 0, 1, 0 },
								 { 0, 1, 1, 0, 0, 0, 0, 0, 0 },
								 { 0, 0, 0, 0, 0, 1, 1, 0, 0 },
								 { 0, 0, 0, 0, 1, 1, 1, 0, 0 },
								 { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, };

	cout << countIslands(arr1) << endl;

	vector<vector<int>> arr2 = { { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
								 { 0, 1, 1, 1, 1, 1, 1, 1, 0 },
								 { 0, 1, 1, 1, 0, 0, 0, 1, 0 },
								 { 0, 1, 1, 0, 0, 0, 1, 1, 0 },
								 { 0, 0, 0, 0, 0, 1, 1, 0, 0 },
								 { 0, 0, 0, 0, 1, 1, 1, 0, 0 },
								 { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, };
	cout << countIslands(arr2) << endl;

	getchar();
	return 0;
}
