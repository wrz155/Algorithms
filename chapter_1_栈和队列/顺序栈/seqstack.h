/*
@ ˳��ջ
	��Ҫ�õ����Ա�����ʵ���ļ��а�����#include "seqlist.h"  //���Ա��˳��洢ͷ�ļ�

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
