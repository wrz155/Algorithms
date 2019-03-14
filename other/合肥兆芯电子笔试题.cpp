/*
	合肥兆芯电子笔试题
	printf("0x%x\n", info.misc.misc2.a + info.misc.misc2.c);

*/


#include <iostream>
using namespace std;

struct  info_struct
{
	union 
	{
		struct 
		{
			unsigned char a;
			unsigned char b;
			unsigned char c;
		}misc2;

		unsigned long d;

	}misc;

};

void main()
{
	info_struct info;
	info.misc.misc2.a = 0xAB;
	info.misc.misc2.b = 0xCD;
	info.misc.misc2.c = 0xEF;

	info.misc.d = 0x12345678;


	// 求下列输出值是多少？
	printf("0x%x\n", info.misc.misc2.a + info.misc.misc2.c);

	cout << sizeof(info) << endl;

	getchar();


}