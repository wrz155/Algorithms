/*
 * ϣ�������Ч��
		ϣ�����������������Ӱ��ϣ������Ч�ʵ���ؼ����أ�����Ϊֹ��û��һ�����������������й�ʽ���ɾ���Ӧ��ѡȡʲô��������������ã�Ŀǰ����һ����ѧ���⡣
 * �����������������У�
		n/2��n/4��n/8...1
		1��3��7...2^k-1
		��һ�����г�Ϊϣ���������У�ʹ��ϣ������ʱ��ϣ�������������µ�ʱ�临�Ӷ�ΪO(n*n)��
		�ڶ������г�ΪHibbard�������У�ʹ��Hibbard����ʱ��ϣ�������������µ�ʱ�临�Ӷ�ΪO(n^3/2)��
 * ��10W���������ֱ���ϣ���������С�Hibbard�������н���ϣ�����򣬺�ʱ�Ƚ���ͼ��ʾ��
		��10W����������Hibbard�������б�ϣ���������е�Ч���Ѿ����˼�����
		����Hibbard���������������������У��������Ѿ��ǳ����������ʵ��Ӧ����ϣ����������Hibbard�������С�
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int a[100];

#define BEGIN_RECORD            \
{                                \
	clock_t ____temp_begin_time___;    \
	____temp_begin_time___=clock();

	#define END_RECORD(dtime)        \
	dtime=float(clock()-____temp_begin_time___)/CLOCKS_PER_SEC;\
}

/*
	ϣ�������������
	a	  - ����������
	index - �����������ʼ�߽�
	delta - ����
	len	  - ���������鳤��
*/
void shellInsert(int a[], int index, int delta, int len)
{
	int tmp, i, j, k;
	for (i = index + delta; i < len; i += delta)
	{
		for (j = i - delta; j >= index; j -= delta) {
			if (a[j] > a[i]) {
				break;
			}
		}

		tmp = a[i];
		for (k = i; k > j; k -= delta)
		{
			a[i] = a[i - delta];
		}
		a[k + delta] = tmp;
	}
}

/*
 ϣ������
 a - ����������
 len - ���鳤��
*/
void shellSort(int a[], int len) {
	int delta = (len + 1) / 2 - 1;		//Hibbard�������й�ʽ
	while (delta > 0) {					
		for (int i = 0; i < delta; i++) {
			shellInsert(a, i, delta, len);
		}
		delta = (delta + 1) / 2 - 1;
	}
}

void shellSort2(int a[], int len) {
	int delta = len / 2;				//ϣ���������й�ʽ
	while (delta > 0) {
		for (int i = 0; i < delta; i++) {
			shellInsert(a, i, delta, len);
		}
		delta /= 2;
	}
}


void printArray(int a[], int length) {
	cout << "�������ݣ�";
	for (int i = 0; i < length; i++) {
		if (i == 0)
			cout << a[i];
		else
			cout << "," << a[i];
	}
	cout << endl;
}

int main()
{
	float tim;
	int i;
	for (i = 0; i < 100; i++)
	{
		srand(unsigned int(time(NULL)));
		a[i] = int (rand() % 1000);
	}

	cout << "10W������ϣ������" << endl;

	BEGIN_RECORD

		shellSort2(a, sizeof(a) / sizeof(int));
		printArray(a, 10);

	END_RECORD(tim)

		cout << "ϣ��������������ʱ�䣺" << tim << "s" << endl;

	for (i = 0; i < 100; i++)
	{
		srand(unsigned int(time(NULL)));
		a[i] = int(rand() % 1000);
	}
	BEGIN_RECORD

		shellSort(a, sizeof(a) / sizeof(int));

	END_RECORD(tim)

		cout << "Hibbard������������ʱ�䣺" << tim << "s" << endl;

	system("pause");
	return 0;
}