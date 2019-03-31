/*
@ 数据结构：顺序表
@ 精髓：
	链表类型SeqList和链表头结点类型TSeqList二者相互转化
	链表结点类型SeqListNode和实际结点类型teacher二者相互转化
	这种转换就掩藏了 线性表的底层实现不需要和具体类型挂钩

	内部使用TSeqList和SeqListNode
	外部使用SeqList和具体类型teacher
*/

#ifndef  SEQLIST_H
#define	 SEQLIST_H

typedef void SeqList;
typedef void SeqListNode;

SeqList* SeqList_Create(int capacity);

void SeqList_Destroy(SeqList* list);

void SeqList_Clear(SeqList* list);

int SeqList_Length(SeqList* list);

int SeqList_Capacity(SeqList* list);

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);

SeqListNode* SeqList_Get(SeqList* list, int pos);

SeqListNode* SeqList_Delete(SeqList* list, int pos);


#endif  //__MY_SEQLIST_H__




