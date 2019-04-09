#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct TreeNode {
	int value;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :value(x), left(NULL), right(NULL) {};
};

class Serialize {
public:
	string serialByPre(TreeNode* head) {
		if (head == NULL) {
			return "#!";
		}
		string res = to_string(head->value) + "!";
		res += serialByPre(head->left);
		res += serialByPre(head->right);
		return res;
	}

	string serialByLevel(TreeNode* head) {
		if (head == NULL) {
			return "#!";
		}
		string res = to_string(head->value) + "!";
		queue<TreeNode*> que;
		que.push(head);
		while (!que.empty()) {
			head = que.front();
			if (head->left != NULL) {
				res += to_string(head->left->value) + "!";
				que.push(head->left);
			}
			else {
				res += "#!";
			}
			if (head->right != NULL) {
				res += to_string(head->right->value) + "!";
				que.push(head->right);
			}
			else {
				res += "#!";
			}
			que.pop();
		}
		return res;
	}


};


class Deserialize {
public:
	TreeNode* deseByPreString(string& preStr) {
		vector<string> vStr = split(preStr, "!");
		queue<string> que;
		for (int i = 0; i != vStr.size(); i++) {
			que.push(vStr[i]);
		}
		return reconPreOrder(que);
	}

	TreeNode* deseByLevelString(string& levelStr) {
		vector<string> vStr = split(levelStr, "!");
		int index = 0;
		TreeNode* head = generateNodeByString(vStr[index++]);
		queue<TreeNode*> que;
		if (NULL != head) {
			que.push(head);
		}

		TreeNode* node = NULL;
		while (!que.empty()) {
			node = que.front();
			que.pop();
			node->left = generateNodeByString(vStr[index++]);
			node->right = generateNodeByString(vStr[index++]);
			if (node->left != NULL) {
				que.push(node->left);
			}
			if (node->right != NULL) {
				que.push(node->right);
			}
		}
		return head;
	}

	TreeNode* generateNodeByString(string str) {
		if (!str.compare("#")) {
			return NULL;
		}
		return new TreeNode(stoi(str));
	}

	TreeNode* reconPreOrder(queue<string>& que) {
		string value = que.front();
		que.pop();
		if (!value.compare("#")) {
			return NULL;
		}
		TreeNode* head = new TreeNode(stoi(value));
		head->left = reconPreOrder(que);
		head->right = reconPreOrder(que);
		return head;
	}

	vector<string> split(const string& str, const string& delim) {
		vector<string> res;
		int cur = 0;
		if (0 == str.size()) 
			return  res;

		for (int i = 0; i < str.size(); ++i) {
			cur = str.find(delim, i); 
			if (cur < str.size()) {
				string s = str.substr(i, cur - i);//��i��ʼ����Ϊcur-i�����ַ���
				res.push_back(s);//���������ո�֮���и�����ַ���Ϊ���ַ���������û���ж�s�Ƿ�Ϊ�գ��������Ľ�����п��ַ��������
				i = cur + delim.size() - 1;
			}
		}
		return res;
	}


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
		string val = to + to_string(head->value) + to;
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
	PrintBinaryTree pTree;
	pTree.printTree(head);


	cout << "===================================" << endl;


	Serialize ser;
	Deserialize dSer;
	string str;

	str = ser.serialByPre(head);
	cout << str << endl;
	head = dSer.deseByPreString(str);
	pTree.printTree(head);


	cout << "===================================" << endl;

	createBT(&head, arr, 9);
	str = ser.serialByLevel(head);
	cout << str << endl;
	head = dSer.deseByLevelString(str);
	pTree.printTree(head);


	getchar();
	return 0;
}