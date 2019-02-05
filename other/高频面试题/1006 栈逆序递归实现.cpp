/*
题目： 
	一个栈依次压入1、2、3、4、5，那么栈顶到栈底分别为：5、4、3、2、1。 
	将这个栈逆置后栈顶到栈底分别为1、2、3、4、5。 
	用递归函数来实现，不能用其他数据结构。
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

void reverse(stack<int> &s) {
	if (s.empty()) {
		return;
	}
	int i = getAndRemoveLastElement(s);
	reverse(s);
	s.push(i);
}

int main() {
	stack<int> test;
	test.push(1);
	test.push(2);
	test.push(3);
	test.push(4);
	test.push(5);
	reverse(test);
	while (!test.empty()) {
		int result = test.top();
		test.pop();
		cout << result << endl;
	}

	getchar();
	return 0;
}
