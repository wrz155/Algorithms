#include<iostream>
#include<vector>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

/**�������Ϊ�����֣���pivot��ߵĲ��ֶ�С�����ұߵĲ���**/
template <typename Comparable>
int partition(vector<Comparable> &vec, int low, int high){
	Comparable pivot = vec[low];  //��ѡԪ����Ϊ�ᣬ����ѡ��Ԫ��
	while (low < high){
		while (low < high && vec[high] >= pivot)
			high--;
		vec[low] = vec[high];
		while (low < high && vec[low] <= pivot)
			low++;
		vec[high] = vec[low];
	}
	//��ʱlow==high
	vec[low] = pivot;
	return low;
}

/**ʹ�õݹ��������**/
template<typename Comparable>
void quicksort1(vector<Comparable> &vec, int low, int high){
	if (low < high){
		int mid = partition(vec, low, high);
		quicksort1(vec, low, mid - 1);
		quicksort1(vec, mid + 1, high);
	}
}

/**ʹ��ջ�ķǵݹ��������**/
template<typename Comparable>
void quicksort2(vector<Comparable> &vec, int low, int high){
	stack<int> st;
	if (low < high){
		int mid = partition(vec, low, high);
		if (low < mid - 1){
			st.push(low);
			st.push(mid - 1);
		}
		if (mid + 1 < high){
			st.push(mid + 1);
			st.push(high);
		}
		//��ʵ������ջ����ÿһ���������Ӵ�����βԪ���±꣬��һ��whileѭ��ʱȡ�������Χ������������н���partition����
		while (!st.empty()){
			int q = st.top();
			st.pop();
			int p = st.top();
			st.pop();
			mid = partition(vec, p, q);
			if (p < mid - 1){
				st.push(p);
				st.push(mid - 1);
			}
			if (mid + 1 < q){
				st.push(mid + 1);
				st.push(q);
			}
		}
	}
}

int main11(){
	int len = 1000000;
	vector<int> vec;
	for (int i = 0; i < len; i++)
		vec.push_back(rand());
	clock_t t1 = clock();
	quicksort1(vec, 0, len - 1);
	clock_t t2 = clock();
	cout << "recurcive  " << 1.0*(t2 - t1) / CLOCKS_PER_SEC << endl;

	//���´���˳��
	random_shuffle(vec.begin(), vec.end());

	t1 = clock();
	quicksort2(vec, 0, len - 1);
	t2 = clock();
	cout << "none recurcive  " << 1.0*(t2 - t1) / CLOCKS_PER_SEC << endl;

	return 0;
}