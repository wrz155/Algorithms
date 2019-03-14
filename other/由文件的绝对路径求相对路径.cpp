/*
@ ���ļ��ľ���·�������·��
@ a = "/qihoo/app/a/b/c/d/new.c"
  b = "/qihoo/app/1/2/test.c"
  �� b ����� a �����·����
  ���·���� "../../../../1/2/test.c"

@ ������
	������ͬ·��֮�⣬����a��˵ÿһ��Ŀ¼����һ��"../"���ټ���b��ʣ��Ŀ¼�����Ǵ�

@ ���ģ�
	//����ָ������·���в�ͬĿ¼����ʼ��ַ
	char* diff1 = path1;
	char* diff2 = path2;
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

char* getRelativePath(char* path1, char* path2, char* relativePath)
{
	if (path1 == NULL || path2 == NULL)
	{
		cout << "�������Ϸ�" << endl;
		return NULL;
	}
	//����ָ������·���в�ͬĿ¼����ʼ��ַ
	char* diff1 = path1;
	char* diff2 = path2;
	
	while (*path1 != '\0'&&*path2 != '\0')
	{
		if (*path1 == *path2)
		{
			if (*path1 == '/')
			{
				diff1 = path1;
				diff2 = path2;
			}
			path1++;
			path2++;
		}
		//��ͬĿ¼
		else	
		{
			diff1++;
			while (*diff1!='\0')
			{
				if (*diff1 == '/')
				{
					strcat(relativePath, "../");
				}
				diff1++;
			}
			//��path2�ķǹ������ֵ�·�����ں���
			diff2++;
			strcat(relativePath, diff2);
			break;
		}
	}

	return relativePath;

}


int main(int argc, char* argv[])
{
	char* a = "/qihoo/app/a/b/c/d/new.c";
	char* b = "/qihoo/app/1/2/test.c";
	char relativePath[1024] = { 0 };

	cout << getRelativePath(a, b, relativePath) << endl;
	getchar();
	return 0;
}