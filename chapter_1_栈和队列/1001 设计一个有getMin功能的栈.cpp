/*
返回栈中最小元素

增加一个辅助栈，两种压栈方法均可：
	1）需要压入数字时，比辅助栈顶小或相等就压栈，否则不压
	2）需要压入数字时，比辅助栈顶小或相等就压栈，如果大于就重复压入辅助栈的栈顶
*/

#include <stack>
#include <iostream>
using namespace std;

class GetMinStack_1
{
public:
	void push(int num) {
		stack_.push(num);

		if (min_stack_.empty()) {
			min_stack_.push(num);
		}
		else if(num <= min_stack_.top()) {//这里不能用stack_代替,因为pop()函数调用了getMin()函数
			min_stack_.push(num);
		}
	}

	int pop() {
		if (stack_.empty()){
			cout << "stack is empty" << endl;
			return -1;
		}
		int help = stack_.top();
		stack_.pop();

		if (help == getMin()) {
			min_stack_.pop();
		}
		return help;
	}

	int getMin() {
		if (min_stack_.empty()) {	//这里不能用stack_代替,因为pop()函数调用了getMin()函数
			cout << "stack is empty" << endl;
			return -1;
		}
		return min_stack_.top();
	}




private:
	stack<int> stack_;
	stack<int> min_stack_;
};

class GetMinStack_2
{
public:
	void push(int num) {
		stack_.push(num);
		if (min_stack_.empty()) {
			min_stack_.push(num);
		}
		else if (num <= min_stack_.top()) {	//比辅助栈顶小或相等就压栈，如果大于就重复压入辅助栈的栈顶
			min_stack_.push(num);
		}
		else {
			min_stack_.push(min_stack_.top());
		}
	}

	int pop() {
		if (stack_.empty()) {
			cout << "stack is empty" << endl;
			return -1;
		}
		int num = stack_.top();
		stack_.pop();
		min_stack_.pop();
		return num;
	}

	int getMin() {
		if (min_stack_.empty()) {	//这里不能用stack_代替
			cout << "stack is empty" << endl;
			return -1;
		}
		return min_stack_.top();
	}

private:
	stack<int> stack_;
	stack<int> min_stack_;
};

int main() {

	GetMinStack_1 s1;
	s1.push(5);
	s1.push(4);
	s1.push(3);
	s1.push(2);
	s1.push(1);

	for (int i = 0; i < 5; i++)
	{
		cout << s1.getMin() << endl;
		s1.pop();
	}

	cout << "===============================" << endl;

	GetMinStack_1 s2;
	s2.push(5);
	s2.push(4);
	s2.push(3);
	s2.push(2);
	s2.push(1);

	for (int i = 0; i < 5; i++)
	{
		cout << s2.getMin() << endl;
		s2.pop();
	}

	getchar();
	return 0;
}