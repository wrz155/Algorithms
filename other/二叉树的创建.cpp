#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <iostream>
using namespace std;
/*
typedef struct BiTNode
{
int data;
struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
*/

//二叉链表示法
struct BiTNode
{
	int value;
	struct BiTNode *left, *right;
};
typedef struct BiTNode	BiTNode;
typedef struct BiTNode*	BiTree;

// #法创建二叉树
//  ab#d##c#e## (先序法)

void CreateBinaryTree(BiTNode * &T)
{

	char data;
	cin >> data;
	if (data == '#')
		T = NULL;
	else
	{
		T = new BiTNode;
		T->value = data;

		CreateBinaryTree(T->left);
		CreateBinaryTree(T->right);
	}
}
// 先序遍历
void PreorderTree(BiTNode *T)
{
	if (T == NULL)
		return;
	cout << (char)T->value << " ";
	PreorderTree(T->left);
	PreorderTree(T->right);
}

void main()
{
	BiTNode *BiTHead;

	CreateBinaryTree(BiTHead);
	PreorderTree(BiTHead);

	system("pause");
	return;
}
