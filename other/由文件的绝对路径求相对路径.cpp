/*
@ 由文件的绝对路径求相对路径
@ a = "/qihoo/app/a/b/c/d/new.c"
  b = "/qihoo/app/1/2/test.c"
  求 b 相对于 a 的相对路径？
  相对路径是 "../../../../1/2/test.c"

@ 方法：
	除了相同路径之外，对于a来说每一级目录增加一个"../"，再加上b的剩余目录，就是答案

@ 核心：
	//用来指向两个路径中不同目录的起始地址
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
		cout << "参数不合法" << endl;
		return NULL;
	}
	//用来指向两个路径中不同目录的起始地址
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
		//不同目录
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
			//把path2的非公共部分的路径加在后面
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