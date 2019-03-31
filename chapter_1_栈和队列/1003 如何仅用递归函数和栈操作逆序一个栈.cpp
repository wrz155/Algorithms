/*
分步：
	1、递归实现：将栈底元素移除并返回
	2、递归实现：逆序一个栈
*/

#include <stack>
#include <iostream>
using namespace std;

int getAndRemoveLastElement(stack<int> &s) {
	int result = s.top();
	s.pop();
	if (s.empty()) {
		return result;
	}
	else {
		int last = getAndRemoveLastElement(s);
		s.push(result);
		return last;
	}
}

void reverseStack(stack<int> &s) {
	if (s.empty()) {
		return;
	}
	int i = getAndRemoveLastElement(s);
	reverseStack(s);
	s.push(i);
}

int main() {
	stack<int> test;
	test.push(1);
	test.push(2);
	test.push(3);
	test.push(4);
	test.push(5);
	reverseStack(test);
	while (!test.empty()) {
		int result = test.top();
		test.pop();
		cout << result << endl;
	}

	getchar();
	return 0;
}
