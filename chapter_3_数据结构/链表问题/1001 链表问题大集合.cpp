#include <iostream>

struct ListNode {
	int value;
	struct ListNode *next;
	ListNode(int x) :value(x), next(NULL) {};
};


/*
@ 求链表倒数第K个节点
*/
ListNode* findKthToTail(ListNode* head, unsigned int k) {
	if (NULL == head || k == 0) {
		return NULL;
	}

	// 快慢指针
	ListNode *fast = head;
	ListNode *slow = head;

	for (unsigned int i = 0; i < k - 1; i++) {
		if (fast->next != NULL) {
			fast = fast->next;
		}
		else {
			return NULL;
		}
	}

	// 第k个节点开始，两个指针同时遍历
	while (fast->next != NULL) {
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

/*
@ 判断链表是否有环,如果有环，返回环的入口地址
@ 要求：1）不允许改变链表结构，2）时间复杂度O(n)，空间复杂度O(1)
@ 寻找环入口的方法就是采用两个指针，一个从头出发，一个从相遇点出发，一次都只移动一步，当二者相等时便是环入口的位置
*/
ListNode* isCircle(ListNode* head)
{ 
	ListNode* fast = head;
	ListNode* slow = head;
	while (slow->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow) { 
			fast = head;
			while (slow->next != NULL && fast->next != NULL) {
				slow = slow->next;
				fast = fast->next;
				if (fast == slow) {
					return slow;
				}
			}
		} 
	}
	return NULL; 
}  

/*
@ 给定链表的头指针和节点指针，O(1)时间删除该节点
@ 前提不能是尾节点，否则是做不到O(1)的
*/
void deleteLinkNode(ListNode* head, ListNode* pDelete) {
	if (NULL == head || NULL == pDelete || NULL == pDelete->next) {
		return;
	}
	ListNode* next = pDelete->next;
	pDelete->value = next->value;
	pDelete->next = next->next;
	delete next;
}

/*
这个是各种情况下，都能删除的方法，但是没有整理

void deleteNode(struct ListNode **pListHead, struct ListNode *pToBeDeleted) {
	if (!pListHead || !pToBeDeleted)
		return;
	//中间节点
	if (pToBeDeleted->next != NULL)	{
		struct ListNode *pNext = pToBeDeleted->next;
		pToBeDeleted->data = pNext->data;
		pToBeDeleted->next = pNext->next;
		free(pNext);
		pNext = NULL;
	}
	//头结点
	else if (*pListHead == pToBeDeleted)
	{
		free(pToBeDeleted);
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}
	//尾结点	else
	{
		struct ListNode *pNode = *pListHead;
		while (pNode->next != pToBeDeleted)		{
			pNode = pNode->next;		}
		pNode->next = NULL;
		free(pToBeDeleted);
		pToBeDeleted = NULL;	}
}

*/

/*
@ 单链表转置，即逆序
@ 循环方法
*/
ListNode* reverseByLoop(ListNode* head) {
	if (NULL == head || NULL == head->next) {
		return head;
	}
	ListNode* pre = NULL;
	ListNode* next = NULL;

	while (NULL != head) {
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}
	return pre;
}

/*
@ 求链表的中间节点
@ 链表长度为偶数,返回中间两个节点的任意一个。
*/
ListNode* findTheMiddle(ListNode* head) {
	if (NULL == head) {
		return NULL;
	}
	ListNode* fast;
	ListNode* slow;
	//如果需要返回偶数情况下，两个节点中的第一个，使用下面的循环条件
	//while (fast && fast->next != NULL && fast->next->next != NULL)
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}