/*
@ дһ������������һ�Ŷ�����������ÿ���ڵ�������һ������ֵ
@ �������أ��������������������ڵ���ľ���ֵ
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