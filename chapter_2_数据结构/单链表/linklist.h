/*
@ 数据结构：链表
@ 精髓：
	让业务节点包含LinkListNode；
	实现LinkListNode与业务节点之间的相互转换；
	链表头结点TLinkList和链表LinkList之间相互转换

@ 链表插入精髓：
	1，指针指向谁，就把谁的地址赋给指针
	2，分清楚链表的操作逻辑和辅助指针变量之间的关系

@ 注意：
	区分：TLinkList和header；
		TLinkList：头结点数据类型，是特殊的业务节点
		header：LinkListNode类型；是结构体
		header.next：是指针，指向下一个LinkListNode

	业务节点是从0号位置开始的
	
@ 问题：
	感觉删除节点时，没有释放内存
	答：
		我们只创建了头结点，其余结点都是main函数创建好了传入的，
		所以我们不需要释放内存，我们唯一要释放的内存就是头结点。
		业务节点内存不是底层库分配的，删除时，把业务节点首地址返回，让上层应用去析构
*/


#ifndef LINKLIST_H
#define LINKLIST_H

typedef void LinkList;

typedef struct _tag_LinkListNode
{
	struct _tag_LinkListNode* next;
}LinkListNode;

LinkList* LinkList_Create();

void LinkList_Destroy(LinkList* list);

void LinkList_Clear(LinkList* list);

int LinkList_Length(LinkList* list);

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);

LinkListNode* LinkList_Get(LinkList* list, int pos);

LinkListNode* LinkList_Delete(LinkList* list, int pos);

#endif

