/*
@ ʵ���ڴ濽������memcpy
@ ע�⣺
	�����ڴ��ص�������
@ ����˼·��
	1����Դ��ַ���׵�ַ����Ŀ���ڴ���׵�ַʱ����Դ�ڴ���׵�ַ��ʼ����
	2����Դ��ַ���׵�ַС��Ŀ���ڴ���׵�ַʱ����Դ�ڴ���׵�ַ�Ӵ������ֽڵĳ��ȵĵ�ַ��ʼ������
*/

#include <iostream>
using namespace std;

void* my_memcpy(void* dst,const void* src,size_t num)
{
	if (dst == NULL || src == NULL)
		return NULL;
	char* pdst = (char*)dst;
	const char* psrc = (char*)src;

	//���ص��Ӻ���ǰ����
	if (pdst > psrc&&pdst < psrc + num)
	{
		for (size_t i = num - 1; i != -1; i--)
		{
			pdst[i] = psrc[i];
		}
	}
	//���ص�����ǰ������
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