
#include<iostream>  
using namespace std;
int a[200001], n;
void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}


int partition(int p, int r){
	int rnd = rand() % (r - p + 1) + p;
	swap(a[rnd], a[r]);
	int pvt = r, i = p - 1;
	for (int j = i + 1; j < r; j++)
		if (a[j] < a[pvt])
			swap(a[j], a[++i]);
	swap(a[++i], a[pvt]);
	return i;
}


void qsort(int p, int r){
	if (p < r){
		int q = partition(p, r);
		qsort(p, q - 1);
		qsort(q + 1, r);
	}
}
int main5()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	qsort(0, n - 1);
	for (int i = 0; i < n; i++)
		cout << a[i];
	system("pause");
	return 0;
}
