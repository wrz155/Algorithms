#include <iostream>
using namespace std;


void main3()
{

	int a[10];
	for (int i = 0; i < 10; i++)
		a[i] = rand() % 100;
	for (int i = 0; i < 10; i++)     //总索引
		for (int j = 0; j < i; j++)   //前面排好的部分
		{
		int temp = a[i];
		if (a[i] < a[j])
		{
			for (int k = i; k >= j; k--)
			{
				a[k] = a[k - 1];
			}
			a[j] = temp;
		}
		}
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";

	system("pause");
}
