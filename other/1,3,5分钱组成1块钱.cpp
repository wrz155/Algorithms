#include <iostream>
using namespace std;
int main()
{
	int k = 0;
	cout << "1�� " << "2�� " << "5�� " << endl;
	for (int m = 0; m <= 100 / 5; m++)
		for (int n = 0; n <= (100 - 5 * m) / 2; n++)
		{
			cout << 100 - 5 * m - 2 * n << " " << n << " " << m << endl;
			k++;
		}
	cout << "����" << k << "����Ϸ�ʽ" << endl;
	system("pause");
	return 0;
}