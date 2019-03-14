/********************************************************************************
*输入一个正整数X，在下面的等式左边的数字之间添加 + 号或者 - 号，使得等式成立。
*1 2 3 4 5 6 7 8 9 = X
*比如：
*12 - 34 + 5 - 67 + 89 = 5
*1 + 23 + 4 - 5 + 6 - 7 - 8 - 9 = 5
*请编写程序，统计满足输入整数的所有整数个数。
*输入： 正整数，等式右边的数字
*输出： 使该等式成立的个数
*样例输入：5
*样例输出：21
*********************************************************************************/
#include<iostream>  
using namespace std;

#define N 8   //数字键空挡个数，这里有9个，所以为8，如果是1 2 3 4，则N=3  

/*
*定义结构体数据，后面使用链表结构求解，每个结构体表示一个合法的表达式
*/
typedef struct MidResult
{
	int Sym[N];//运算符表示，1表示‘+’，0表示仍然空着，-1表示‘-’  
	int result;//表达式的计算结果  
	int symnum;//符号个数  
	struct MidResult* next;
}Node, *List;


/*判断两个表达式是否完全一样*/
bool isEqual(Node* p, Node* q)
{
	if (p == NULL || q == NULL) return false;
	if (p->symnum != q->symnum) return false;//符号个数  
											 //if (p->result != q->result) return false;  
	for (int i = 0; i < N; i++)//符号序列  
	{
		if (p->Sym[i] != q->Sym[i]) return false;
	}
	return true;
}

/*查找A数组中cur到n之间的‘+’（1表示）或‘-’（0表示）出现的位置
*默认没有时返回n;
*/
int findNextSymbol(int *A, int cur, int n)
{
	for (int i = cur; i < n; i++)
	{
		if (A[i] != 0) return i;
	}
	return n;
}

/*将形如... [+/-] s * * * e[+/-] ...的表达式中* * *这些连着的字
*母转为整数，其中s为第一个*的数字，e为最后一个，s到e是连续整数
*/
int trans2Num(int s, int e)//s到e之间的串转化为整数  
{
	int num = 0;
	for (int i = s; i <= e; i++)
	{
		num = 10 * num + i;
	}
	return num;
}

/*计算某个符号与两边的数形成的表达式的和
其中sum表示运算符号左边表达式的和x表示右边的数的和*/
int caculateSum(int sum, int sym, int x)
{
	if (sym == 1) return sum + x;
	else return sum - x;
}


/*计算结构体元素所表示的完整表达式的和*/
void caculateResult(Node *p)//求表达式和  
{
	int num = 0, front = 0;//num为位结果  
	int symbol;//记录接下来考察到的符号的结果  
	int next = findNextSymbol(p->Sym, 0, N);//找到下一个运算符，则front和next之间为一个整数  
	num = trans2Num(1, next + 1);//计算整数的值  
	front = next + 1;
	symbol = p->Sym[next];
	int x;
	for (int i = 0; i < p->symnum; i++)//根据符合分割求加数  
	{
		next = findNextSymbol(p->Sym, front, N);
		x = trans2Num(front + 1, next + 1);
		num = caculateSum(num, symbol, x);
		front = next + 1;
		symbol = p->Sym[next];
	}

	p->result = num;
}

bool hasElement(List list, Node *p)//计算节点元素是否在链表中，用于去重剪枝  
{
	while (list != NULL)
	{
		if (isEqual(list, p)) return true;
		list = list->next;
	}
	return false;
}

int makeNextNode(Node* p, Node* &q, int cur, int sym)//产生下一个需要添加的节点元素，即一个新的完整表达式  
{
	q = new Node;
	q->next = NULL;
	q->symnum = p->symnum + 1;
	for (int i = 0; i < N; i++)
	{
		q->Sym[i] = p->Sym[i];
	}
	for (int i = cur; i < N; i++)
	{
		if (q->Sym[i] == 0)
		{
			q->Sym[i] = sym;
			return i;
		}
	}
	return -1;
}

/*本体的最终函数，思路先考察运算符为0个的表达式，接下来扩展出所有运算符为1个的
*表达式，再有1个运算符的表达式扩展为2个的表达式，这个过程中需要查重起到剪枝作用
*以减小搜索空间
*/
int GetTotal(int result)
{
	int total = 0;
	List list = new Node;
	for (int i = 0; i < N; i++)
	{
		list->Sym[i] = 0;
	}
	list->next = NULL;
	list->symnum = 0;
	caculateResult(list);
	Node *tail = list;
	Node *q;
	Node *tmp;
	int cur;
	while (list != NULL)
	{
		if (list->result == result) total++;
		cur = 0;
		for (int i = 0; i < (N - list->symnum); i++)
		{
			makeNextNode(list, q, cur, 1);//还有剪发，cur不改变  
			if (!hasElement(list, q))//剪枝和添加  
			{
				caculateResult(q);
				tail->next = q;
				tail = q;
			}
			cur = makeNextNode(list, q, cur, -1) + 1;//完成改变  
			if (!hasElement(list, q))//剪枝和添加  
			{
				caculateResult(q);
				tail->next = q;
				tail = q;
			}
		}
		tmp = list;//删除元素  
		list = list->next;
		delete tmp;
	}
	return total;
}

int main()
{
	cout << GetTotal(5) << endl;
	getchar();
	return 0;
}