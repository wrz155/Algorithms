/*

腾讯研发工程师A笔试卷
@	约瑟夫问题
	n个人围成一个圈，每个人分别标注为1、2、...、n，
	要求从1号从1开始报数，报到k的人出圈，接着下一个人又从1开始报数，如此循环，直到只剩最后一个人时，
	该人即为胜利者。例如当n=10,k=4时，依次出列的人分别为4、8、2、7、3、10，9、1、6、5，则5号位置的人为胜利者。
	给定n个人，请你编程计算出最后胜利者标号数。（要求用单循环链表完成。）
	第一行为人数n;
	第二行为报数m

	用户输入 M,N 值,从 1 至 N 开始顺序循环数数,每数到 M 输出该数值,直至全部输出。写出 C 程序。
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>  
#include <malloc.h>  
typedef struct List
{
	int  data = 0;
	struct List *next = NULL;
}LinkList;


int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	LinkList *L, *cur, *s;
	L = (LinkList *)malloc(sizeof(LinkList));
	cur = L;

	for (int i = 1; i <= n; i++)               ///尾插法建立循环链表  
	{
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = i;
		cur->next = s;
		cur = s;
	}

	//让最后一个链表的下一个节点指向开头，这样就构建了循环链表
	cur->next = L->next;      

	LinkList *p;
	p = L->next;

	//开始模拟（判断条件要注意：因为最后肯定剩下一个人， 所以最后一个数据的next还是他本身）
	while (p->next != p)                  
	{
		//每k个数死一个人  
		//把p指向要删除的元素的前一个元素
		for (int i = 1; i < m - 1; i++)
		{
			p = p->next;                       
		}
		//将该节点从链表上删除。
		printf("%d\t", p->next->data);
		p->next = p->next->next;                    
		p = p->next;
	}
	printf("%d", p->data);

	system("pause");
	return 0;
}