
#include <iostream>
using namespace std;

void main2()
{
	int a[10];
	for (int i = 0; i < 10; i++)
		a[i] = rand() % 100;

	for (int i = 0; i < 10; i++)
	{

		for (int j = i; j < 10 - i; j++)
			if (a[j] < a[i])
			{
			int temp = a[j];
			a[j] = a[i];
			a[i] = temp;
			}
	}


	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	system("pause");
}