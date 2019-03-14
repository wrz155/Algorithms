
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "linkqueue.h"
#include "linklist.h"

typedef struct _tag_LinkQueueNode
{
	LinkListNode node;
	void *item;
}TLinkQueueNode;
//˼�룺�����Ա���ģ�����

//����һ�����У��൱�ڴ���һ�����Ա�
LinkQueue* LinkQueue_Create() //O(1)
{
	return LinkList_Create();
}

void LinkQueue_Destroy(LinkQueue* queue) //O(1)
{
	LinkQueue_Clear(queue);
	LinkList_Destroy(queue);
	return;
}

void LinkQueue_Clear(LinkQueue* queue) //O(n)
{
	while (LinkQueue_Length(queue) > 0)
	{
		LinkQueue_Retrieve(queue);
	}
	//LinkQueue_Clear(queue);
	return;
}

//����������Ԫ�أ��൱������е�β������Ԫ��
int LinkQueue_Append(LinkQueue* queue, void* item) //O(n)
{
	int ret = 0;
	TLinkQueueNode *node = NULL;
	//��Ҫ��linklist�����ҵ��ڵ㣬��Ҫ��ҵ��ڵ��а���������
	//��Ҫ�����������ҵ��ڵ�ĵ�һ����Ա��

	//���β�item��ת��Ϊ linklistʶ���ҵ��ڵ�
	node = (TLinkQueueNode *)malloc(sizeof(TLinkQueueNode));
	if (node == NULL)
	{
		return -1;
	}
	memset(node, 0, sizeof(TLinkQueueNode));
	node->item = item;

	ret = LinkList_Insert(queue, (LinkListNode *)node, LinkList_Length(queue));
	if (ret != 0)
	{
		free(node);
		return ret;
	}

	return ret;
}

//�Ӷ���ɾ��Ԫ�أ��൱�ڴӶ��е�ͷ����Ԫ��
void* LinkQueue_Retrieve(LinkQueue* queue) //O(1)
{
	int ret = 0;
	void *item = NULL;
	TLinkQueueNode *node = NULL;
	//��Ҫ��linklist�����ҵ��ڵ㣬��Ҫ��ҵ��ڵ��а���������
	node = (TLinkQueueNode *)LinkList_Delete(queue, 0);
	if (node == NULL)
	{
		return NULL;
	}
	item = node->item;
	if (node != NULL)
	{
		free(node);
		node = NULL;
	}
	return item;
}

//��ȡ����ͷԪ�أ��൱�ڴӶ���0λ����Ԫ��
void* LinkQueue_Header(LinkQueue* queue) //O(1)
{
	int ret = 0;
	void *item = NULL;
	TLinkQueueNode *node = NULL;
	node = (TLinkQueueNode *)LinkList_Get(queue, 0);
	if (node == NULL)
	{
		return NULL;
	}
	item = node->item;
	return item;
}

int LinkQueue_Length(LinkQueue* queue)
{
	return LinkList_Length(queue);
}