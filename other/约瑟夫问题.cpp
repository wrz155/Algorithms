/*

��Ѷ�з�����ʦA���Ծ�
@	Լɪ������
	n����Χ��һ��Ȧ��ÿ���˷ֱ��עΪ1��2��...��n��
	Ҫ���1�Ŵ�1��ʼ����������k���˳�Ȧ��������һ�����ִ�1��ʼ���������ѭ����ֱ��ֻʣ���һ����ʱ��
	���˼�Ϊʤ���ߡ����統n=10,k=4ʱ�����γ��е��˷ֱ�Ϊ4��8��2��7��3��10��9��1��6��5����5��λ�õ���Ϊʤ���ߡ�
	����n���ˣ������̼�������ʤ���߱��������Ҫ���õ�ѭ��������ɡ���
	��һ��Ϊ����n;
	�ڶ���Ϊ����m

	�û����� M,N ֵ,�� 1 �� N ��ʼ˳��ѭ������,ÿ���� M �������ֵ,ֱ��ȫ�������д�� C ����
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

	for (int i = 1; i <= n; i++)               ///β�巨����ѭ������  
	{
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = i;
		cur->next = s;
		cur = s;
	}

	//�����һ���������һ���ڵ�ָ��ͷ�������͹�����ѭ������
	cur->next = L->next;      

	LinkList *p;
	p = L->next;

	//��ʼģ�⣨�ж�����Ҫע�⣺��Ϊ���϶�ʣ��һ���ˣ� �������һ�����ݵ�next����������
	while (p->next != p)                  
	{
		//ÿk������һ����  
		//��pָ��Ҫɾ����Ԫ�ص�ǰһ��Ԫ��
		for (int i = 1; i < m - 1; i++)
		{
			p = p->next;                       
		}
		//���ýڵ��������ɾ����
		printf("%d\t", p->next->data);
		p->next = p->next->next;                    
		p = p->next;
	}
	printf("%d", p->data);

	system("pause");
	return 0;
}