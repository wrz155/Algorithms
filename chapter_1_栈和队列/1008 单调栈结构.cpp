#include <vector>
#include <iostream>
using namespace std;



//O(n^2)
vector<vector<int>> rightWay(int arr[], int len) {
	vector<vector<int> > res(len, vector<int>(2));

	for (int i = 0; i < len; i++)
	{
		int leftLessIndex = -1;
		int rightLessIndex = -1;

		int cur = i - 1;				// cur再i的左边
		while (cur >= 0)
		{
			if (arr[cur] < arr[i])
			{
				leftLessIndex = cur;
				break;
			}
			cur--;
		}

		cur = i + 1;					// cur再i的右边
		while (cur < len)
		{
			if (arr[cur] < arr[i])
			{
				rightLessIndex = cur;
				break;
			}
			cur++;
		}
		res[i][0] = leftLessIndex;
		res[i][1] = rightLessIndex;
	}
	
	return res;
}






int main() {

	int arr[] = { 3,4,1,5,6,2,7 };
	vector<vector<int>> res = rightWay(arr, sizeof(arr) / sizeof(arr[0]));

	for (vector<vector<int>>::iterator iter = res.begin(); iter != res.end(); ++iter) 
	{ 
		for (int i = 0; i != (*iter).size(); ++i) {
			cout << (*iter)[i] << "	";
		}
		cout << endl;
	}

	getchar();
	return 0;
}