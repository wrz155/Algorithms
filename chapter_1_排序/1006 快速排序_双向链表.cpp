#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int value;
	Node *last, *next;
	Node() :value(0), last(NULL), next(NULL) {}
};

void main()
{
	DLinkList head;
	Node *p;
	int x;
	int i;
	DLinkList DCreateList(void);
	DLinkList DGetNode(DLinkList head, int i);
	void DInsertBefore(DLinkList p, int x);
	void DPrintList(DLinkList head);
	head = DCreateList();  /*建立双链表*/
	DPrintList(head);  /*打印双链表*/
	printf("请输入欲插入的元素：");
	scanf("%c", &x);
	printf("请输入欲插入元素的位置：");
	scanf("%d", &i);
	p = DGetNode(head, i);  /*寻找第i个结点*/
	if (p == NULL)
	{
		printf("插入位置非法\n");
		exit(0);
	}
	DInsertBefore(p, x);
	DPrintList(head);  /*打印双链表*/
}/*双链表的建立：*/
DLinkList DCreateList(void)
{
	char ch;
	DLinkList head = (Node *)malloc(sizeof(Node));
	Node *s, *r;
	head->next = NULL;
	head->last = NULL;
	r = head;     /*尾指针初值指向头结点*/
	while ((ch = getchar()) != '\n')
	{
		s = (Node *)malloc(sizeof(Node)); /*生成新结点*/
		s->value = ch;
		r->next = s;
		s->last = r;
		r = s;
	}
	r->next = head;
	head->last = r;
	return head;   /*返回头指针*/
}/*双链表的打印：*/
void DPrintList(DLinkList head)
{
	Node *p;
	for (p = head->next; p != head; p = p->next)
		printf("%c", p->value);
	printf("\n");
}/*双链表的查找*/
DLinkList DGetNode(DLinkList head, int i)
{/*在带头结点的双链表head中查找第i个结点*/
	int j;
	Node *p;
	p = head; j = 0;    /*从头结点开始扫描*/
	while (p->next != head && j < i)
	{
		p = p->next;
		j++;
	}
	if (i == j)
		return p;   /*找到了第i个结点*/
	else
		return NULL;  /*找不到满足条件的结点*/
}