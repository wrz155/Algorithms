/*
������������ ��֪һ����������arr����һ������num��
���С��num���������������ߣ�����num��������������м䣬����num��������������ұߡ� 
Ҫ��
	ʱ�临�Ӷ�ΪO(N)������ռ临�Ӷ�O(1)
*/

void swap(int arr[], int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

int* partition(int arr[], int L, int R, int num) {
	int less = L - 1;
	int more = R + 1;
	while (L < more) {
		if (arr[L] < num) {
			swap(arr, ++less, L++);
		} else if (arr[L] > num) {
			swap(arr, --more, L);
		} else {
			L++;
		}
	}
	return new int[2] { less + 1, more - 1 };		//���ص�������ͷ��β
}