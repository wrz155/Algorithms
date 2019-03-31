/*
@ ���ݽṹ��˳���
@ ���裺
	��������SeqList������ͷ�������TSeqList�����໥ת��
	����������SeqListNode��ʵ�ʽ������teacher�����໥ת��
	����ת�����ڲ��� ���Ա�ĵײ�ʵ�ֲ���Ҫ�;������͹ҹ�

	�ڲ�ʹ��TSeqList��SeqListNode
	�ⲿʹ��SeqList�;�������teacher
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




