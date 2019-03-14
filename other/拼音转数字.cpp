#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	string s;
	vector<int> number;
	cout << "please input a string" << endl;

	getline(cin, s);
	for (string::size_type i = 0; i < s.size(); ++i)
	{
		switch (s[i])
		{
		case 'y':   //1  
		{
			number.push_back(1);
			++i;
		}
		break;
		case 'e':
		{
			number.push_back(2);
			++i;
		}
		break;
		case 's':
		{
			++i;
			if (s[i] == 'a')
			{
				number.push_back(3);
			}
			else
			{
				number.push_back(4);
			}
		}
		break;
		case 'w':
		{
			number.push_back(5);
			++i;
		}
		break;
		case 'l':
		{
			number.push_back(6);
			++i;
		}
		break;
		case 'q':
		{
			number.push_back(7);
			++i;
		}
		break;
		case 'b':
		{
			number.push_back(8);
			++i;
		}
		break;
		case 'j':
		{
			number.push_back(9);
			++i;
		}
		break;

		default:
			break;
		}
	}

	cout << s << endl;
	//打印  
	vector<int>::iterator iter = number.begin();
	// number.end()是字符串结束标志位'\0'
	while (iter != number.end())
	{
		cout << *iter++;	// *的优先级高于++，先取值再自增
	}
	cout << endl;

	system("pause");
	return 0;

}