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
 *函数介绍：先打印右子树，再打印根节点，最后打印左子树
 *输入参数： root	为根节点,
			height	为当前处于二叉树的那一层（从0层开始）;
			to		为根、左、右节点的区分符号；
			len		为格式化打印参数，固定为17，即每个节点都将占有17个字符的位置
 *输出参数：无
 *返回值：无
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

//	-1表示空节点
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