/*
* ���� ����ģ��
*/
#include <iostream>
#include <string>
using namespace std;

template < class T>
T Add(T a, T b)
{
	T result = a + b;
	return result;
}

int main()
{
	cout << "2+3=" << Add(2, 3) << endl;
	cout << "sdf+123=" << Add(string("sdf"), string("123")) << endl;

	getchar();
	return 0;
}


/*
* ���� ����ģ��
*/
template <class T>
inline void PRINT_ELEMENTS(const T& coll, const char* optcstr = "")
{
	// const  �������أ���������Ϊ ָ������  ��ָ�룬��ָ���ǳ���
	// const_iterator �������أ���������Ϊ ָ�� ������ ��ָ�룬��ָ��ָ��Ķ����ǳ���
	// typename������ַ���Ϊһ����������
	// pos Ϊ const_iterator �Ķ���
	typename T::const_iterator pos;

	std::cout << optcstr;
	for (pos = coll.begin(); pos != coll.end(); ++pos) {
		std::cout << *pos << ' ';
	}
	std::cout << std::endl;
}
