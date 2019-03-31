#include <iostream> 
using namespace std;

typedef struct _BinaryTree
{	
	int value;	
	struct _BinaryTree *left;     //左儿子  	
	struct _BinaryTree *right;
}BinaryTree;  

BinaryTree* addToTree(int arr[], int start, int end)
{	
	if (start > end)		
		return NULL; 	
	int mid = start + ((end - start) >> 1);//避免溢出	
	BinaryTree *head = new BinaryTree;	
	head->value = arr[mid];//数组中值

	head->left = addToTree(arr, start, mid - 1);//左子树	
	head->right = addToTree(arr, mid + 1, end);//右子树

	return head;
} 

BinaryTree* createMinimalBST(int arr[], int len)
{	
	return addToTree(arr, 0, len - 1);
} 

int main()
{	
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };	
	int length = sizeof(arr) / sizeof(arr[0]); 	
	BinaryTree *Tree = createMinimalBST(arr, length);

	return 0;
}
