/*
检测括号配对是否合法

链接：https://www.nowcoder.com/questionTerminal/52ddc307b6e74aa8a2bdf698b8b66138
来源：牛客网

输入为只包含'(', ')', '{', '}', '[' 和']'这六个括号字符的字符串。判断输入字符串中的括号是否符合代数算式规则。
例如, "()"、"({})" 和 "()[]" 是合法的括号。而 "(]" 和 "([)]" 不是。

输入描述:
输入包含一行: 包括一个只含'(',')','{','}','[',']'的字符串,长度小于等于50

输出描述:
	合法输出true，否则输出false。

示例1
	输入
	()
	输出
	true

*/
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stack>
#include <iostream>
using namespace std;

bool isValid(char exp[]) {
	stack<char> stack;

	for (int i = 0; i < strlen(exp); i++) {
		if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(') {
			stack.push(exp[i]);
		}
		if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')') {
			char match = exp[i] == '}' ? '{' : (exp[i] == ']' ? '[' : '(');
			if (stack.empty() || match != stack.top()) {
				return false;
			}
			else {
				stack.pop();
			}
		}
	}
	return stack.empty();
}

int main() {
	char exp[51] = { 0 };
	scanf("%s", exp);
	printf("%s", isValid(exp) ? "true" : "false");
	return 0;
}
