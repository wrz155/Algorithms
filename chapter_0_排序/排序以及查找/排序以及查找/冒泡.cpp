

#include <iostream>
#include<stdlib.h>
using namespace std;

int main1()
{
	int a[10];
	for (int i = 0; i < 10; i++)
		a[i] = rand() % 100;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10 - i; j++)
		{
		if (a[j] < a[j + 1])
		{
			int temp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = temp;
		}
		}
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	system("pause");

	return 0;
}


