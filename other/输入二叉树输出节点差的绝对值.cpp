/*
@ 写一个函数，输入一颗二叉树，树中每个节点均存放了一个整数值
@ 函数返回：这棵树中相差最大的两个节点间差的绝对值
*/

int maxValue(Node* root)
{
	if (root == NULL)
		return 0;
	int left = maxValue(root->left);
	int right = maxValue(root->right);
	int max = left > right ? left : right;
	return root->value() > max ? root->value() : max;
}

int minValue(Node* root)
{
	if (root == NULL)
		return 32767;
	int left = minValue(root->left);
	int right = minValue(root->right);
	int min = left < right ? left : right;
	return root->value() < min ? root->value() : min;
}

int diff(Node *root)
{
	return maxValue(root) - minValue(root);
}