#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node *next;
	Node(int value_) :value(value_), next(NULL) {}
};

struct DNode
{
	int value;
	DNode *last, *next;
	DNode(int value_) :value(value_), last(NULL), next(NULL) {}
};

void swap(int *i, int *j) {
	int tmp = *i;
	*i = *j;
	*j = tmp;
}

Node* partition(Node*head, Node*tail) {
	Node* start = head;
	Node* end = head->next;

	while (end != tail)
	{
		if (end->value < head->value)	//递增
		{
			start = start->next;
			swap(&start->value, &end->value);
		}
		end = end->next;
	}
	swap(&head->value, &start->value);
	return start;
}

void QuickSortNode(Node* head, Node* tail) {
	if (head != tail) {
		Node* mid = partition(head, tail);
		QuickSortNode(head, mid);
		QuickSortNode(mid->next, tail);
	}

}

void QuickSortDNode(DNode* head, DNode* tail) {
	if (head == tail ||head->next == tail){
		return;
	}

	DNode* start = head;
	DNode* end = start->next;

	while (end != tail) {
		if (end->value < head->value)		//递增
		{
			start = start->next;
			swap(&start->value, &end->value);
		}
		end = end->next;
	}
	swap(&head->value, &start->value);

	QuickSortDNode(head, start);
	QuickSortDNode(start->next, tail);
}

int main() {

	/*单链表测试*/
	Node* L = new Node(10);
	Node* L1 = new Node(5);
	Node* L2 = new Node(6);
	Node* L3 = new Node(11);
	Node* L4 = new Node(10);

	L->next = L1;
	L1->next = L2;
	L2->next = L3;
	L3->next = L4;
	L4->next = NULL;

	QuickSortNode(L, NULL);

	for (int i = 0; i < 5; i++)
	{
		cout << L->value << "  ";
		L = L->next;
	}
	cout << endl;


	/*双链表测试*/
	Node* D = new Node(10);
	Node* D1 = new Node(5);
	Node* D2 = new Node(6);
	Node* D3 = new Node(11);
	Node* D4 = new Node(10);

	D->next = D1;
	D1->next = D2;
	D2->next = D3;
	D3->next = D4;
	D4->next = NULL;

	QuickSortNode(D, NULL);

	for (int i = 0; i < 5; i++)
	{
		cout << D->value << "  ";
		D = D->next;
	}


	getchar();
	return 0;

}

