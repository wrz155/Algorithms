/*
	阿里巴巴笔试题：
		将一个由：连接的网卡地址字符串拆分并存储到 char buf[6],
	例子：
		00：24：E8：FA：A5：09
		char buf[6] = 0x00, 0x24, 0xE8, 0xFA, 0xA5, 0x09
		
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void macStr2Byte(char *str)
{
	char buf[6];
	int k = 0;
	int res = 0;
	int temp = 0;

	if (!str)
		return;

	for (int i = 0; i < (int)strlen(str); i++)
	{
		if (str[i] == ':')
		{
			printf("%d, ", res);
			buf[k++] = res;
			res = 0;
			temp = 0;
		}
		else
		{
			if (str[i] - 'A' >= 0)
				temp = str[i] - 'A' + 10;
			else
				temp = str[i] - '0';
			res = res * 16 + temp;
		}
	}
}



int main()
{
	char *str = "00:24:E8:FA:A5:09";
	macStr2Byte(str);


	system("pause");
	getchar();
	return 0;
}