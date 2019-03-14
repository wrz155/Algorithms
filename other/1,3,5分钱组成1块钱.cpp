#include <iostream>
using namespace std;
int main()
{
	int k = 0;
	cout << "1分 " << "2分 " << "5分 " << endl;
	for (int m = 0; m <= 100 / 5; m++)
		for (int n = 0; n <= (100 - 5 * m) / 2; n++)
		{
			cout << 100 - 5 * m - 2 * n << " " << n << " " << m << endl;
			k++;
		}
	cout << "共有" << k << "种组合方式" << endl;
	system("pause");
	return 0;
}