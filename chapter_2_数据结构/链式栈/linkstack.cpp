
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "linkstack.h"
#include "linklist.h"

typedef struct _tag_LinkStackNode
{
	LinkListNode node; //ռλ�ṹ������ֻҪ����һ����node�ڴ�Сһ�������ݼ���
	void *item;
}TLinkStackNode;

//��Ҫ����һ��linkstack��׼����linklistȥģ��ʵ��
//�൱���� linkstack.c��д linklist��Ĳ��Գ��򡣡���������
LinkStack* LinkStack_Create()
{
	//����һ��ջ��ͨ�����Ա�ȥģ�⡣����������һ��ջ���൱�ڴ���һ�����Ա�
	return LinkList_Create();
}

void LinkStack_Destroy(LinkStack* stack)
{
	LinkStack_Clear(stack); //ע�� destory��ʱ����Ҫ��ջ�е�����Ԫ�ض����
	LinkList_Destroy(stack);
}

void LinkStack_Clear(LinkStack* stack)
{
	//LinkList_Clear(stack);
	while (LinkStack_Size(stack) > 0)
	{
		LinkStack_Pop(stack); //����������������ڴ��ͷź���
	}
	return;
}

//��ջ�з�Ԫ�أ��൱�� �����Ա��в���һ��Ԫ��
int LinkStack_Push(LinkStack* stack, void* item)
{
	int ret = 0;
	//��Ҫitem���ݣ�ת���� linklist��ҵ��ڵ�
	TLinkStackNode *pTe = (TLinkStackNode *)malloc(sizeof(TLinkStackNode));
	if (pTe == NULL)
	{
		return -1;
	}
	pTe->item = item;

	//ͷ�巨 �������Ա��в���Ԫ�أ�ֻ�����ǲ���Ԫ�ص�ʱ����Ҫ����ҵ��ڵ���ѡ�����������
	ret = LinkList_Insert(stack, (LinkListNode *)(&pTe->node), 0);
	if (ret != 0)
	{
		free(pTe);
	}
	return ret;
}

void* LinkStack_Pop(LinkStack* stack)
{
	void *myItem = NULL;
	TLinkStackNode *pTmp = NULL;
	pTmp = (TLinkStackNode *)LinkList_Delete(stack, 0);
	if (pTmp == NULL)
	{
		return NULL;
	}
	myItem = pTmp->item;

	//ע�������Ա��У�����Ԫ�ص�ʱ������ڵ㣬�����ڴ棻
	//����Ԫ��ʱ����Ҫ�ͷŽڵ��ڴ棬��Ҫ����

	if (pTmp != NULL)
	{
		free(pTmp);
	}
	return myItem;
}

void* LinkStack_Top(LinkStack* stack)
{
	void *myItem = NULL;
	TLinkStackNode *pTmp = NULL;
	pTmp = (TLinkStackNode *)LinkList_Get(stack, 0);
	if (pTmp == NULL)
	{
		return NULL;
	}
	myItem = pTmp->item;
	return myItem;
}

int LinkStack_Size(LinkStack* stack)
{
	return LinkList_Length(stack);
}