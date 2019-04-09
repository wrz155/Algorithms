#include<iostream>
#include <string>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {};
};

class PrintBinaryTree {
public:
	void printTree(TreeNode *head) {
		cout << "Correct Binary Tree:" << endl;
		printInOrder(head, 0, "H", 5);
		cout << endl;
	}
/*
 *�������ܣ��ȴ�ӡ���������ٴ�ӡ���ڵ㣬����ӡ������
 *��������� root	Ϊ���ڵ�,
			height	Ϊ��ǰ���ڶ���������һ�㣨��0�㿪ʼ��;
			to		Ϊ�������ҽڵ�����ַ��ţ�
			len		Ϊ��ʽ����ӡ�������̶�Ϊ17����ÿ���ڵ㶼��ռ��17���ַ���λ��
 *�����������
 *����ֵ����
 */
	void printInOrder(TreeNode *head, int height, string to, int len) {
		if (NULL == head) {
			return;
		}
		printInOrder(head->right, height + 1, "v", len);
		string val = to + to_string(head->val) + to;
		int lenM = val.length();
		int lenL = (len - lenM) / 2;
		int lenR = len - lenM - lenL;
		val = string(lenL, ' ') + val + string(lenR, ' ');
		cout << string(height*len, ' ') << val << endl;
		printInOrder(head->left, height + 1, "^", len);
	}

};

//	-1��ʾ�սڵ�
void createBT(TreeNode **head, int arr[], int len, int index = 0) {
	if (index > len - 1 || -1 == arr[index])
		return;
	(*head) = new TreeNode(arr[index]);
	createBT(&((*head)->left), arr, len, 2 * index + 1);
	createBT(&((*head)->right), arr, len, 2 * index + 2);
}

int main()
{
	int arr[] = { 1,2,3,4,-1,5,6,-1,7 };
	TreeNode *head = NULL;
	createBT(&head, arr, 9);

	PrintBinaryTree p;
	p.printTree(head);

	getchar();
	return 0;
}