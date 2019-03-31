#include "stdio.h"
#include "string.h"
#include "stdio.h"
#include "seqqueue.h"
#include "seqlist.h"

//java ssh 
//�������У��൱�ڴ���һ�����Ա�
SeqQueue* SeqQueue_Create(int capacity)
{
	return SeqList_Create(capacity);
}

void SeqQueue_Destroy(SeqQueue* queue)
{
	SeqList_Destroy(queue);
}

void SeqQueue_Clear(SeqQueue* queue)
{
	SeqList_Clear(queue);
}

//����������Ԫ�أ��൱�� �����Ա��У�β������Ԫ��
int SeqQueue_Append(SeqQueue* queue, void* item)
{
	return SeqList_Insert(queue, item, SeqList_Length(queue));
}

//�Ӷ�����ɾ��Ԫ�أ��൱�ڴ����Ա���ɾ����һ��Ԫ��
void* SeqQueue_Retrieve(SeqQueue* queue)
{
	return SeqList_Delete(queue, 0);
}

void* SeqQueue_Header(SeqQueue* queue)
{
	return SeqList_Get(queue, 0);
}

int SeqQueue_Length(SeqQueue* queue)
{
	return SeqList_Length(queue);
}

int SeqQueue_Capacity(SeqQueue* queue)
{
	return SeqList_Capacity(queue);
}