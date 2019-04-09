#include <iostream>

using namespace std;

const int N = 10;
int anthor[N];
void MergeSort(int *array, int begin, int end)
{
	if (end - begin > 1)
	{
		//
		MergeSort(array, begin, (begin + end) / 2);
		MergeSort(array, (begin + end) / 2 + 1, end);

		int i = begin;
		int j = (begin + end) / 2 + 1;
		int k = begin;

		while (i <= (begin + end) / 2 && j <= end)//�ϲ�ʱ����һ����ȫ��������һ��������һ���´���ʣ�µ�ֱ�ӷ���β��
		{
			if (array[i] > array[j])        //С��ֵ���룬������������
				anthor[k++] = array[j++];
			if (array[i] < array[j])
				anthor[k++] = array[i++];

		}
		while (i <= (begin + end) / 2)
		{
			anthor[k++] = array[i++];
		}
		while (j <= end)
		{
			anthor[k++] = array[j++];
		}

		for (k = begin; k <= end; k++)    //��������¿���������
			array[k] = anthor[k];

	}
	else      //������ֱ�ӽ���
	{
		if (array[end] < array[begin])
		{
			int temp = array[end];
			array[end] = array[begin];
			array[begin] = temp;
		}
	}
}


int main6()
{


	int array[N];
	for (int i = 0; i < 10; i++)
	{
		array[i] = rand() % 100;
		cout << array[i] << " ";
	}

	MergeSort(array, 0, N - 1);
	cout << endl;
	for (int i = 0; i < 10; i++)
	{

		cout << array[i] << " ";
	}
	system("pause");
	return 0;
}

