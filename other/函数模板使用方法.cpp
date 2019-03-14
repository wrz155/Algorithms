/*
* 定义 函数模板
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
* 定义 函数模板
*/
template <class T>
inline void PRINT_ELEMENTS(const T& coll, const char* optcstr = "")
{
	// const  迭代器呢，你把它理解为 指向对象的  常指针，即指针是常量
	// const_iterator 迭代器呢，你把它理解为 指向 常对象 的指针，即指针指向的对象是常量
	// typename后面的字符串为一个类型名称
	// pos 为 const_iterator 的对象
	typename T::const_iterator pos;

	std::cout << optcstr;
	for (pos = coll.begin(); pos != coll.end(); ++pos) {
		std::cout << *pos << ' ';
	}
	std::cout << std::endl;
}
