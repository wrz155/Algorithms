#include <iostream>
using namespace std;


struct Node{
	int value;
	Node* next;
	Node(int data) :value(data), next(NULL) {};
};

struct DNode{
	int value;
	DNode* last;
	DNode* next;
	DNode(int data) :value(data), last(NULL), next(NULL) {};
};


Node* reverseList(Node* head) {
	Node* pre = NULL;
	Node* next = NULL;

	while (head != NULL) {
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}
	return pre;
}

DNode* reverseList(DNode* head) {
	DNode* pre = NULL;
	DNode* next = NULL;
	
	while (head != NULL) {
		next = head->next;
		head->next = pre;
		head->last = next;
		pre = head;
		head = next;
	}
	return pre;
}

void printLinkedList(Node* head) {
	cout << "Linked List: ";
	while (head != NULL) {
		cout << head->value << " ";
			head = head->next;
		}
	cout << endl;
}

void printDoubleLinkedList(DNode* head) {
	cout << "Double Linked List: ";
	DNode* end = NULL;
	while (head != NULL) {
		cout << head->value + " ";
		end = head;
		head = head->next;
	}

	cout << "| ";

	while (end != NULL) {
		cout << end->value << " ";
		end = end->last;
	}
	cout << endl;
}

int main() {
	Node* head1 = new Node(1);
	head1->next = new Node(2);
	head1->next->next = new Node(3);

	printLinkedList(head1);
	head1 = reverseList(head1);
	printLinkedList(head1);

	DNode* head2 = new DNode(1);
	head2->next = new DNode(2);
	head2->next->last = head2;
	head2->next->next = new DNode(3);
	head2->next->next->last = head2->next;
	head2->next->next->next = new DNode(4);
	head2->next->next->next->last = head2->next->next;

	printDoubleLinkedList(head2);
	printDoubleLinkedList(reverseList(head2));

	getchar();
	return 0;
}


