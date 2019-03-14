
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
		//�Զ�������������������Ϊ0
	} while (nArgValue != NULL);
	va_end(arg_ptr);

	return sum;
}

int main()
{
	//������NULL ��0 ��β����Ϊ�����б�������ж������Ƕ���0ֹͣ
	cout << Test(NA, NB, NC, NULL) << endl;    
	
	getchar();
	return 0;
}