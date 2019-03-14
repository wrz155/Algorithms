//文件名：exp1-2.cpp
#include<stdlib.h>                   //	system("pause");
#include<iostream>

#include <math.h>
#include <string.h>

#define MAX 100					//字符串的最大长度

bool func(char s[])             //char s[]等价于char s[232]等价于char* s
{
	bool flag=true;
	int i,j,slen=strlen(s);		//slen为字符串s的长度
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
	printf("输入一字符串:");
	scanf("%s",s);
	if (func(s))
		printf("%s字符串是回文\n",s);
	else
		printf("%s字符串不是回文\n",s);

	system("pause");

}
