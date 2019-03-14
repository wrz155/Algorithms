// C语言实现
// interface.h

#ifndef INTERFACE_H
#define INTERFACE_H

void* data_create();
void data_set(void* dummy, int i, short j);
void data_get(void* dummy, int* i, short * j);
void data_destroy(void* dummy);

#endif

// interface.c

#include <stdlib.h>

struct DATA
{
	int i;
	short j;
};

void* data_create()
{
	return malloc(sizeof(struct DATA));
}

void data_set(void* dummy, int i, short j)
{
	struct DATA* data = (struct DATA*)dummy;

	data->i = i;
	data->j = j;
}

void data_get(void* dummy, int* i, short * j)
{
	struct DATA* data = (struct DATA*)dummy;

	*i = data->i;
	*j = data->j;
}

void data_destroy(void* dummy)
{
	free(dummy);
}

#include <stdio.h>
//#include "interface.h"

int main()
{
	int i;
	short j;

	void* data = data_create();

	data_set(data, 2, 3);

	data_get(data, &i, &j);
	printf("i = %d, j = %d\n", i, j);

	data_destroy(data);

	return 0;
}
/*
@ 可以看的出来，C的实现只暴露了接口给用户，内部的实现细节都隐藏了起来，可是C++用类实现反而在头文件暴露了实现细节。
@ 当然用C++也可以做到只暴露接口给用户，不过实现起来会比较复杂，而且需要消耗更多的内存（使用了虚函数）。
@ 如下所示
*/

--------------------------------------parent.h--------------------------------------

#ifndef PARENT_H
#define PARENT_H

class PARENT
{
public:
	virtual void set(int i, short j) = 0;
	virtual void get(int* i, short* j) = 0;
};

PARENT* get_child();

#endif

--------------------------------------parent.cpp--------------------------------------

#include "parent.h"
#include "child.h"

PARENT* get_child()
{
	return new CHILD;
}

--------------------------------------child.h--------------------------------------

#ifndef CHILD_H
#define CHILD_H

#include "parent.h"

class CHILD : public PARENT
{
private:
	int _i;
	short _j;

public:
	CHILD();
	~CHILD();

	void set(int i, short j);
	void get(int* i, short* j);
};

#endif

--------------------------------------child.cpp--------------------------------------

#include "child.h"

CHILD::CHILD()
{
	_i = _j = 0;
}

CHILD::~CHILD()
{
	_i = _j = 0;
}


void CHILD::set(int i, short j)
{
	_i = i;
	_j = j;
}

void CHILD::get(int* i, short* j)
{
	*i = _i;
	*j = _j;
}

--------------------------------------test.cpp--------------------------------------

#include <stdio.h>
#include "parent.h"

int main()
{
	int i;
	short j;

	PARENT* parent = get_child();

	parent->set(2, 3);
	parent->get(&i, &j);

	printf("i = %d, j = %d\n", i, j);

	return 0;
}