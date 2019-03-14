#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define Generator 34943

int main()
{
	unsigned char c, flag;
	int count;
	union
	{
		unsigned int L;
		struct
		{
			unsigned char b1;
			unsigned char b2;
			unsigned char b3;
			unsigned char b4;
		}crc;
	}data;
	while (1)
	{
		count = 0;
		data.L = 0;
		while (scanf("%c", &c) && c != '\n')
		{
			count++;
			flag = c;
			data.L = ((data.L << 8) + c) % Generator;
		}
		data.L = ((data.L << 16) + c) % Generator;
		if (data.L != 0)
			data.L = Generator - data.L;
		if (count == 1 && flag == '#')
			break;
		printf("%02x%02x\n", (int)data.crc.b2, (int)data.crc.b1);

	}
	return 0;
}