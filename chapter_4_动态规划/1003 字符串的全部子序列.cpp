/*
	打印一个字符串的全部子序列，包括空字符串
	子序列：不破坏相对位置
*/
#include <string>
void process(char str[], int i) {
	if (i == strlen(str)) {
		System.out.println(String.valueOf(str));
		return;
	}
	process(str, i + 1);
	char tmp = str[i];
	str[i] = 0;
	process(str, i + 1);
	str[i] = tmp;
}

int main() {
	char test[] = "abc";
	process(test,0);

	getchar();
	return 0;
}
