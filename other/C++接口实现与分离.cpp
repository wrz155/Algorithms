/*
@ ���õ����Ӧ��ֻ��¶�ӿڸ��û������е�ʵ��ϸ�ڶ��û���˵Ӧ�������صģ�
Ҳ����˵�û�ֻҪ���ӿڴ�����Ӧ�Ĳ��������ˣ�����Ҫ���ڲ������ʵ�ֵģ�
��������ʹ��fopen��fseek��CreateWindow�Ⱥ����ᷢ�ֺܺ��ã�
������Ҫ��fopen��fseek��CreateWindow�����ڲ����������ʵ�ֵģ����ݽṹ�������֯�ģ�
Ҳ����˵���Բ��ܱ�¶�κε�ϸ�ڸ��û�������������֯���ڡ�
*/

// C++ʵ��
// interface1.h
#ifndef INTERFACE1_H
#define INTERFACE1_H

class DATA
{
private:
	int _i;
	short _j;

public:
	DATA();
	~DATA();

	void set(int i, short j);
	void get(int* i, short* j);
};

#endif

// interface1.cpp 
// #include "interface1.h"
DATA::DATA()
{
	_i = _j = 0;
}

DATA::~DATA()
{
	_i = _j = 0;
}


void DATA::set(int i, short j)
{
	_i = i;
	_j = j;
}

void DATA::get(int* i, short* j)
{
	*i = _i;
	*j = _j;
}

#include <stdio.h>
//#include "interface1.h"

int main()
{
	DATA data;
	int i;
	short j;

	data.set(2, 3);
	data.get(&i, &j);

	printf("i = %d, j = %d\n", i, j);
	return 0;
}


