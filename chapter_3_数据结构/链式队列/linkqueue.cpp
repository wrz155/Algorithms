
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
//思想：用线性表来模拟队列

//创建一个队列，相当于创建一个线性表
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

//向队列中添加元素，相当于向队列的尾部插入元素
int LinkQueue_Append(LinkQueue* queue, void* item) //O(n)
{
	int ret = 0;
	TLinkQueueNode *node = NULL;
	//需要向linklist中添加业务节点，需要在业务节点中包含链表结点
	//需要让链表结点放在业务节点的第一个成员域。

	//把形参item，转换为 linklist识别的业务节点
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

//从队列删除元素，相当于从队列的头部拿元素
void* LinkQueue_Retrieve(LinkQueue* queue) //O(1)
{
	int ret = 0;
	void *item = NULL;
	TLinkQueueNode *node = NULL;
	//需要向linklist中添加业务节点，需要在业务节点中包含链表结点
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

//获取队列头元素，相当于从队列0位置拿元素
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