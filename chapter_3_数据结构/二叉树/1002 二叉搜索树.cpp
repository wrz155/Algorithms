#include <stack>
#include <iostream>
using namespace std;

struct TreeNode {
	int value;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :value(x), left(NULL), right(NULL) {};
};

TreeNode* searchBSTreeByReverse(TreeNode* root, int key) {
	if (NULL == root || root->value == key) {
		return root;
	}
	if (key < root->value) {
		return searchBSTreeByReverse(root->left, key);
	}
	else {
		return searchBSTreeByReverse(root->right, key);
	}
}

TreeNode* searchBSTreeByUnReverse(TreeNode* root, int key) {
	while ((NULL != root) && (root->value != key)) {
		if (key < root->value) {
			root = root->left;
		}
		else {
			root = root->right;
		}
	}
	return root;
}