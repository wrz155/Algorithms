/*
某游戏是一个卡牌类游戏，玩家通过战斗或抽牌可以拿到一些 技能牌，每张技能牌都有对应的伤害值(伤 害值>=0)，
当你有 了组合技属性之后，你可以在自己手头上选择任意张技能牌， 以组合技的方式来攻击 boss，
组合技的总伤害将等于所组合的 各张技能牌的伤害值的乘积(只有一张牌时，组合技伤害值等于 这张牌 本身的伤害值)，
但是能发动组合技必须有个前提:所有 被选择的技能牌的伤害系数之和必须等于m(m>0) 以解开封印; 
你为了能赢得最终胜利，需要在所有技能牌中挑出若干张技能 牌触发组合技(每张牌只能用一 次)，以形成最大威力的组合技 攻击效果。 
例如:你有伤害值分别为1,2,3,4,5的五张牌，给定的解开封印的阈值(m)为10，
那形成最大组合攻击效果的组合为30(5*3*2)，而不是24(4*3*2*1)，也不是20(5*4*1)，
需要输 出的结果即30。

*/
#include <algorithm>
#include <iostream>
using namespace std;

//暴力递归
int process(int arr[], int len, int index, int sum) {
	if (sum < 0) {
		return -1;
	}
	if (index == len) {
		return sum == 0 ? 1 : -1;
	}
	int notInclude = process(arr, len, index + 1, sum);
	int include = arr[index] * process(arr, len, index + 1, sum - arr[index]);
	return notInclude > include ? notInclude : include;
}

//动态规划，搞出暴力递归，分析可变参数
int maxDamage(int arr[], int len, int sum) {
	if (NULL == arr || len == 0) {
		return 0;
	}
	vector<vector<int> > a3(rows, vector<int>(columns));
	int** dp = new int[len*(sum+1)]();
	if (arr[0] <= sum) {
		dp[0][arr[0]] = arr[0];
	}
	for (int i = 1; i < len; i++) {
		for (int j = 0; j <= sum; j++) {
			int no = dp[i - 1][j];
			int only = j - arr[i] == 0 ? arr[i] : 0;
			int part = j - arr[i] > 0 ? dp[i - 1][j - arr[i]] * arr[i] : 0;
			dp[i][j] = max(no, max(only, part));
		}
	}
	// printMatrix(dp); // 可以打印dp看看
	return dp[dp.length - 1][dp[0].length - 1];
}

void printMatrix(int** dp, int row, int column) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			printf("%d  ",dp[i][j]);
		}
		printf("\n");
	}
}


int main() {
	int arr[] = { 1,2,3,4,5 };
	cout << process(arr, 5, 0, 10) << endl;

	getchar();
	return 0;

}