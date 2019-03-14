/*
@ 实现内存拷贝函数memcpy
@ 注意：
	考虑内存重叠的问题
@ 处理思路：
	1，当源地址的首地址大于目标内存的首地址时，从源内存的首地址开始复制
	2，当源地址的首地址小于目标内存的首地址时，从源内存的首地址加待复制字节的长度的地址开始逆序复制
*/

#include <iostream>
using namespace std;

void* my_memcpy(void* dst,const void* src,size_t num)
{
	if (dst == NULL || src == NULL)
		return NULL;
	char* pdst = (char*)dst;
	const char* psrc = (char*)src;

	//有重叠从后往前复制
	if (pdst > psrc&&pdst < psrc + num)
	{
		for (size_t i = num - 1; i != -1; i--)
		{
			pdst[i] = psrc[i];
		}
	}
	//无重叠，从前往后复制
	else
	{
		for (size_t i = 0; i < num; i++)
		{
			pdst[i] = psrc[i];
		}
	}
	return dst;

}

int main(int argc, char* argv[])
{
	char src[] = "abc";
	char* dest = src + 1;
	dest = (char*)my_memcpy(dest, src, 4);
	cout << dest << endl;
	getchar();
	return 0;
}