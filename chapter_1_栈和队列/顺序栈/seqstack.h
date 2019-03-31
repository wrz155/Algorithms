/*
@ 顺序栈
	需要用到线性表；顾在实现文件中包含：#include "seqlist.h"  //线性表的顺序存储头文件

*/

#ifndef SEQSTACK_H
#define SEQSTACK_H

typedef void SeqStack;

SeqStack* SeqStack_Create(int capacity);

void SeqStack_Destroy(SeqStack* stack);

void SeqStack_Clear(SeqStack* stack);

int SeqStack_Push(SeqStack* stack, void* item);

void* SeqStack_Pop(SeqStack* stack);

void* SeqStack_Top(SeqStack* stack);

int SeqStack_Size(SeqStack* stack);

int SeqStack_Capacity(SeqStack* stack);

#endif //_MY_SEQSTACK_H_
