
#include <iostream>  
#include <stdio.h>
#include <cstdarg> 
using namespace std;

typedef enum POSITION_TRACKING_STATE
{
	NA = 11,
	NB,
	NC
} TRACKING_STATE;

int Test(TRACKING_STATE state, ...)
{
	va_list arg_ptr;
	int sum = 0;
	int nArgValue;
	sum += state;

	va_start(arg_ptr, state);
	do
	{
		nArgValue = va_arg(arg_ptr, TRACKING_STATE);
		sum += nArgValue;
		//自定义结束条件是输入参数为0
	} while (nArgValue != NULL);
	va_end(arg_ptr);

	return sum;
}

int main()
{
	//必须以NULL 或0 结尾，因为参数列表结束的判断条件是读到0停止
	cout << Test(NA, NB, NC, NULL) << endl;    
	
	getchar();
	return 0;
}