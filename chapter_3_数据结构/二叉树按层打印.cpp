#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
using namespace std;
vector<char>::size_type n = 0;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {};
};

class PrintBinaryTreeByLayer {
public:
	void printBinaryTreeByLayer_01(TreeNode* root) {
		queue<TreeNode*> que;
		que.push(root);
		TreeNode *last = root, *nlast = NULL, *cur = NULL;
		while (!que.empty()) {
			cur = que.front();
			cout << cur->val;
			if (cur->left) {
				que.push(cur->left);
				nlast = cur->left;
			}
			if (cur->right) {
				que.push(cur->right);
				nlast = cur->right;
			}
			if (cur == last) {
				last = nlast;
				cout << endl;
			}
			que.pop();
		}
	}

	vector< vector<int> > printBinaryTreeByLayer_02(TreeNode* root) {
		vector< vector<int> > res;
		vector<int> tmp;
		queue<TreeNode*> que;
		que.push(root);
		TreeNode *last = root, *nlast = NULL, *cur = NULL;
		while (!que.empty()){
			cur = que.front();
			cout << cur->val;
			tmp.push_back(cur->val);
			if (cur->left){
				que.push(cur->left);
				nlast = cur->left;
			}
			if (cur->right){
				que.push(cur->right);
				nlast = cur->right;
			}
			if (cur == last){
				res.push_back(tmp);
				tmp.clear();
				last = nlast;
				cout << endl;
			}
			que.pop();
		}
		return res;
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

	PrintBinaryTreeByLayer p;
	p.printBinaryTreeByLayer_01(head);
	
	getchar();
	return 0;
}