/*
已知一个字符串都是由左括号(和右括号)组成，判断该字符串是否是有效的括号组合。

例子：
	有效的括号组合:()(),(()),(()())
	无效的括号组合:(,()),((),()(()

题目进阶：
	已知一个字符串都是由左括号(和右括号)组成，返回最长有效括号子串的长度。

补充：
	子串和子数组要求连续的
	子序列随意
*/
#include <string>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

bool isValid(string str) {
	if (str.empty() || str.size() < 2) {
		return false;
	}

	int status = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			status++;
		}
		if (str[i] == ')' && --status < 0) {
			return false;
		}
	}
	return status == 0;
}

bool isValid1(string str) {
	if (str.empty() || str.size() < 2) {
		return false;
	}
	stack<char> s;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push('(');
		}
		if (str[i] == ')') {
			if (s.size() == 0) {
				return false;
			}
			else{
				s.pop();
			}
		}
	}
	return s.size() == 0;
}



int maxLength(string str) {
	if (str.empty() || str.size() < 2) {
		return 0;
	}
	int* dp = new int[str.size()]();
	int pre = 0;
	int res = 0;
	for (int i = 1; i < str.size(); i++) {
		if (str[i] == ')') {
			pre = i - dp[i - 1] - 1;
			if (pre >= 0 && str[pre] == '(') {
				dp[i] = dp[i - 1] + 2 + (pre > 0 ? dp[pre - 1] : 0);	//最重要的例子：()( () () )
			}
		}
		res = max(res, dp[i]);
	}
	delete dp;
	return res;
}

int main() {
	string str1 = "((())())";
	if (isValid(str1)) {
		cout << "Valid" << endl;
	}
	else {
		cout << "Invalid" << endl;
	}
	cout << "Max	" << maxLength(str1) << endl;

	string str2 = "(())(()(()))";
	if (isValid(str2)) {
		cout << "Valid" << endl;
	}
	else {
		cout << "Invalid" << endl;
	}
	cout << "Max	" << maxLength(str2) << endl;

	string str3 = "()(()()(";
	if (isValid(str3)) {
		cout << "Valid" << endl;
	}
	else {
		cout << "Invalid" << endl;
	}
	cout << "Max	" << maxLength(str3) << endl;

	getchar();
	return 0;
}
