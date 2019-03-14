/*
@ 良好的设计应该只暴露接口给用户，所有的实现细节对用户来说应该是隐藏的，
也就是说用户只要给接口传递相应的参数就行了，不需要管内部是如何实现的，
比如我们使用fopen，fseek，CreateWindow等函数会发现很好用，
而不需要管fopen，fseek，CreateWindow函数内部代码是如何实现的，数据结构是如何组织的，
也就是说绝对不能暴露任何的细节给用户，包括数据组织在内。
*/

// C++实现
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


