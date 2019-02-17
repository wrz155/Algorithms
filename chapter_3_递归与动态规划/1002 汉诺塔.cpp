/*
汉诺塔问题
	打印n层汉诺塔从最左边移动到最右边的全部过程
*/
#include <iostream>
#include <string>
using namespace std;

void process(int n, string from, string mid, string to) {
	if (n == 1) {
		cout << "move from " + from + " to " + to;
	}
	else {
		process(n - 1, from, to, mid);
		process(1, from, mid, to);
		process(n - 1, mid, from, to);
	}
}

void hanoi(int n) {
	if (n > 0) {
		process(n, "left", "mid", "right");
	}
}

int main() {
	int n = 3;
	hanoi(n);

	getchar();
	return 0;
}
