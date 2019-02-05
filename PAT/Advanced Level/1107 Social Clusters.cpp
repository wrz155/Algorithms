/*
1107 Social Clusters （30 分）
When register on a social network, 
you are always asked to specify your hobbies in order to find some potential friends with the same hobbies. 
A social cluster is a set of people who have some of their hobbies in common. 
You are supposed to find all the clusters.

Input Specification:
Each input file contains one test case. 
For each test case, the first line contains a positive integer N (≤1000), 
the total number of people in a social network. Hence the people are numbered from 1 to N. 
Then N lines follow, each gives the hobby list of a person in the format:
Ki: hi[1] hi[2] ... hi[Ki]
where Ki(>0) is the number of hobbies, and hi[j] is the index of the j-th hobby, 
which is an integer in [1, 1000].

Output Specification:
For each case, print in one line the total number of clusters in the network. 
Then in the second line, 
print the numbers of people in the clusters in non-increasing order. 
The numbers must be separated by exactly one space, 
and there must be no extra space at the end of the line.

Sample Input:
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4

Sample Output:
3
4 3 1
*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> father, isRoot;
int cmp1(int a, int b) { return a > b; }
int findFather(int x) {
	int a = x;
	while (x != father[x])
		x = father[x];
	while (a != father[a]) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
void Union(int a, int b) {
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB) father[faA] = faB;
}

int main() {
	int n, k, t, cnt = 0;
	int course[1001] = { 0 };
	cin >> n;
	father.resize(n + 1);
	isRoot.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		father[i] = i;
	}
		
	for (int i = 1; i <= n; i++) {
		scanf("%d:", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &t);
			if (course[t] == 0)
				course[t] = i;
			Union(i, findFather(course[t]));
		}
	}
	for (int i = 1; i <= n; i++)
		isRoot[findFather(i)]++;
	for (int i = 1; i <= n; i++) {
		if (isRoot[i] != 0) cnt++;
	}
	printf("%d\n", cnt);
	sort(isRoot.begin(), isRoot.end(), cmp1);
	for (int i = 0; i < cnt; i++) {
		printf("%d", isRoot[i]);
		if (i != cnt - 1) printf(" ");
	}
	return 0;
}