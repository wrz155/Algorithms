//�ļ�����exp1-2.cpp
#include<stdlib.h>                   //	system("pause");
#include<iostream>

#include <math.h>
#include <string.h>

#define MAX 100					//�ַ�������󳤶�

bool func(char s[])             //char s[]�ȼ���char s[232]�ȼ���char* s
{
	bool flag=true;
	int i,j,slen=strlen(s);		//slenΪ�ַ���s�ĳ���
	for (i=0,j=slen-1;i<j;i++,j--)
		if (s[i]!=s[j])
		{	
			flag=false;
			break;
		}
	return(flag);
}
void main()
{
	char s[MAX];
	printf("����һ�ַ���:");
	scanf("%s",s);
	if (func(s))
		printf("%s�ַ����ǻ���\n",s);
	else
		printf("%s�ַ������ǻ���\n",s);

	system("pause");

}
