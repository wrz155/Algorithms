/*
打印公共部分，没有说连续公共部分，也没法连续
*/
#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* next;
	Node(int data) :value(data),next(NULL) {};
};

void printCommonPart(Node* head1, Node* head2) {
	cout <<"Common Part: ";
	while (head1 != NULL && head2 != NULL) {
		if (head1->value < head2->value) {
			head1 = head1->next;
		} 
		else if (head1->value > head2->value) {
			head2 = head2->next;
		} 
		else {
			cout << head1->value << "  ";
				head1 = head1->next;
				head2 = head2->next;
			}
		}
	cout << endl;
}

void printLinkedList(Node* head) {
	while (head != NULL) {
		cout << head->value << "  ";
		head = head->next;
	}
	cout << endl;
}

int main() {
	Node* head1 = new Node(2);
	head1->next = new Node(3);
	head1->next->next = new Node(5);
	head1->next->next->next = new Node(6);

	Node* head2 = new Node(1);
	head2->next = new Node(2);
	head2->next->next = new Node(5);
	head2->next->next->next = new Node(7);
	head2->next->next->next->next = new Node(8);


	printLinkedList(head1);
	printLinkedList(head2);
	printCommonPart(head1, head2);

	getchar();
	return 0;

}


