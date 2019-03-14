/*
@ ���ݽṹ������
@ ���裺
	��ҵ��ڵ����LinkListNode��
	ʵ��LinkListNode��ҵ��ڵ�֮����໥ת����
	����ͷ���TLinkList������LinkList֮���໥ת��

@ ������뾫�裺
	1��ָ��ָ��˭���Ͱ�˭�ĵ�ַ����ָ��
	2�����������Ĳ����߼��͸���ָ�����֮��Ĺ�ϵ

@ ע�⣺
	���֣�TLinkList��header��
		TLinkList��ͷ����������ͣ��������ҵ��ڵ�
		header��LinkListNode���ͣ��ǽṹ��
		header.next����ָ�룬ָ����һ��LinkListNode

	ҵ��ڵ��Ǵ�0��λ�ÿ�ʼ��
	
@ ���⣺
	�о�ɾ���ڵ�ʱ��û���ͷ��ڴ�
	��
		����ֻ������ͷ��㣬�����㶼��main�����������˴���ģ�
		�������ǲ���Ҫ�ͷ��ڴ棬����ΨһҪ�ͷŵ��ڴ����ͷ��㡣
		ҵ��ڵ��ڴ治�ǵײ�����ģ�ɾ��ʱ����ҵ��ڵ��׵�ַ���أ����ϲ�Ӧ��ȥ����
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

