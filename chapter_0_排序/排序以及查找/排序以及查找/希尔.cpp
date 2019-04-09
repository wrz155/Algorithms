
#include <iostream>
#include<stdlib.h>

using namespace std;
const int N = 10;
void shell_sort(const int len, int *array)

{

	int j, i, key;
	int gap = 0;
	if (len <= 0 || array == NULL)
		return;
	while (gap <= len)
	{

		gap = gap * 3 + 1;

	}
	while (gap > 0)

	{

		for (i = gap; i < len; i++)
		{
			j = i - gap;
			key = array[i];
			while ((j >= 0) && (array[j] > key))
			{
				array[j + gap] = array[j];
				j = j - gap;
			}
			array[j + gap] = key;
		}
		//display_array(len,array,gap);
		gap = (gap - 1) / 3;

	}

}

// 3  5  18   29     35   24   12  0
// 3                           12   
//     5                            0
// 3   0  18  29    35    24  12    5
//3                       24
//    0                       12
//        18                        5
//3   0   5  29     35    24  12    18
//3                  35
//   0                   24
//       5                   12
//           29                     18
//3  0   5   18   35   24   12     29   
//3          18             12
//   0            35               29
//        5            24
//3  0    5  12   29   24      18   35
//3       5       29            18
//   0        12        24          35
//3   0   5   12     18    24        29 35
//0    3  5 12    18  24   29  35


    



int main4()
{

	int array[N];
	for (int i = 0; i < 10; i++)
	{
		array[i] = rand() % 100;
		cout << array[i] << " ";
	}
	shell_sort(N - 1, array);
	cout << endl;
	for (int i = 0; i < 10; i++)
	{

		cout << array[i] << " ";
	}
	system("pause");
	return 0;
}

