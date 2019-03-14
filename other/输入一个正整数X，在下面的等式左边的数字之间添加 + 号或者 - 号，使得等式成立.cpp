/********************************************************************************
*����һ��������X��������ĵ�ʽ��ߵ�����֮����� + �Ż��� - �ţ�ʹ�õ�ʽ������
*1 2 3 4 5 6 7 8 9 = X
*���磺
*12 - 34 + 5 - 67 + 89 = 5
*1 + 23 + 4 - 5 + 6 - 7 - 8 - 9 = 5
*���д����ͳ������������������������������
*���룺 ����������ʽ�ұߵ�����
*����� ʹ�õ�ʽ�����ĸ���
*�������룺5
*���������21
*********************************************************************************/
#include<iostream>  
using namespace std;

#define N 8   //���ּ��յ�������������9��������Ϊ8�������1 2 3 4����N=3  

/*
*����ṹ�����ݣ�����ʹ������ṹ��⣬ÿ���ṹ���ʾһ���Ϸ��ı��ʽ
*/
typedef struct MidResult
{
	int Sym[N];//�������ʾ��1��ʾ��+����0��ʾ��Ȼ���ţ�-1��ʾ��-��  
	int result;//���ʽ�ļ�����  
	int symnum;//���Ÿ���  
	struct MidResult* next;
}Node, *List;


/*�ж��������ʽ�Ƿ���ȫһ��*/
bool isEqual(Node* p, Node* q)
{
	if (p == NULL || q == NULL) return false;
	if (p->symnum != q->symnum) return false;//���Ÿ���  
											 //if (p->result != q->result) return false;  
	for (int i = 0; i < N; i++)//��������  
	{
		if (p->Sym[i] != q->Sym[i]) return false;
	}
	return true;
}

/*����A������cur��n֮��ġ�+����1��ʾ����-����0��ʾ�����ֵ�λ��
*Ĭ��û��ʱ����n;
*/
int findNextSymbol(int *A, int cur, int n)
{
	for (int i = cur; i < n; i++)
	{
		if (A[i] != 0) return i;
	}
	return n;
}

/*������... [+/-] s * * * e[+/-] ...�ı��ʽ��* * *��Щ���ŵ���
*ĸתΪ����������sΪ��һ��*�����֣�eΪ���һ����s��e����������
*/
int trans2Num(int s, int e)//s��e֮��Ĵ�ת��Ϊ����  
{
	int num = 0;
	for (int i = s; i <= e; i++)
	{
		num = 10 * num + i;
	}
	return num;
}

/*����ĳ�����������ߵ����γɵı��ʽ�ĺ�
����sum��ʾ���������߱��ʽ�ĺ�x��ʾ�ұߵ����ĺ�*/
int caculateSum(int sum, int sym, int x)
{
	if (sym == 1) return sum + x;
	else return sum - x;
}


/*����ṹ��Ԫ������ʾ���������ʽ�ĺ�*/
void caculateResult(Node *p)//����ʽ��  
{
	int num = 0, front = 0;//numΪλ���  
	int symbol;//��¼���������쵽�ķ��ŵĽ��  
	int next = findNextSymbol(p->Sym, 0, N);//�ҵ���һ�����������front��next֮��Ϊһ������  
	num = trans2Num(1, next + 1);//����������ֵ  
	front = next + 1;
	symbol = p->Sym[next];
	int x;
	for (int i = 0; i < p->symnum; i++)//���ݷ��Ϸָ������  
	{
		next = findNextSymbol(p->Sym, front, N);
		x = trans2Num(front + 1, next + 1);
		num = caculateSum(num, symbol, x);
		front = next + 1;
		symbol = p->Sym[next];
	}

	p->result = num;
}

bool hasElement(List list, Node *p)//����ڵ�Ԫ���Ƿ��������У�����ȥ�ؼ�֦  
{
	while (list != NULL)
	{
		if (isEqual(list, p)) return true;
		list = list->next;
	}
	return false;
}

int makeNextNode(Node* p, Node* &q, int cur, int sym)//������һ����Ҫ��ӵĽڵ�Ԫ�أ���һ���µ��������ʽ  
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

/*��������պ�����˼·�ȿ��������Ϊ0���ı��ʽ����������չ�����������Ϊ1����
*���ʽ������1��������ı��ʽ��չΪ2���ı��ʽ�������������Ҫ�����𵽼�֦����
*�Լ�С�����ռ�
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
			makeNextNode(list, q, cur, 1);//���м�����cur���ı�  
			if (!hasElement(list, q))//��֦�����  
			{
				caculateResult(q);
				tail->next = q;
				tail = q;
			}
			cur = makeNextNode(list, q, cur, -1) + 1;//��ɸı�  
			if (!hasElement(list, q))//��֦�����  
			{
				caculateResult(q);
				tail->next = q;
				tail = q;
			}
		}
		tmp = list;//ɾ��Ԫ��  
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