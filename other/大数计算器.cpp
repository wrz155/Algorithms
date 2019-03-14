/*
	�˷�����ԭ��
		��0λ ��1λ ��2λ		1��0λ  2��1λ	3�ǵڶ�λ
		123 * 456 =  56088
		
		����ĸ�λ�� ��4λ  4�����2+2����3*6 = 18
		�����ʮλ�� ��3λ	3�����1+2��2+1��2*6+3*5 = 27
		����İ�λ�� ��2λ  2�����1+1 �� 0+2 2+0
		�����ǧλ�� ��1λ	1�����0+1 �� 1+0
		�������λ�� ��0λ	0�����0+0

*/
#include<stdlib.h>
#include<string.h>
#define OK 0
#define ERR -1 
#define NUM_MAX_SIZE 100

#define NUM_PLUS 1
#define NUM_SUB  -1
#define NUM_ZERO 0

int SuperAdd(char szFirstNum[], char szLastNum[], char szRstNum[])
{
	int iFirstLen;
	int iLastLen;
	int iMaxLen;
	int i;
	int iTmp = 0;
	int iIsOver = 0;

	if (szFirstNum == NULL || szLastNum == NULL || szRstNum == NULL)
	{
		return ERR;
	}
	iFirstLen = strlen(szFirstNum);
	iLastLen = strlen(szLastNum);
	iMaxLen = 1 + (iFirstLen > iLastLen ? iFirstLen : iLastLen);
	//printf("%d\n", iMaxLen);
	for (i = 1; i < iMaxLen; i++)
	{
		if (iFirstLen < i)
		{
			iTmp = szLastNum[iLastLen - i];
		}
		else if (iLastLen < i)
		{
			iTmp = szFirstNum[iFirstLen - i];
		}
		else
		{
			iTmp = szLastNum[iLastLen - i] + szFirstNum[iFirstLen - i] - '0';
		}

		iTmp += iIsOver;
		//9 �� ASCII �� ��9���� 9 +��0����
		if (iTmp > 9 + '0')
		{
			szRstNum[iMaxLen - i] = iTmp - 10;
			iIsOver = 1;
		}
		else
		{
			szRstNum[iMaxLen - i] = iTmp;
			iIsOver = 0;
		}
	}
	szRstNum[0] = iIsOver + '0';

	return OK;
}

int SuperSub(char szFirstNum[], char szLastNum[], char szRstNum[])
{
	int iFirstLen;
	int iLastLen;
	int iMaxLen;
	int i;
	int iIsLow = 0;
	int iTmp;

	if (szFirstNum == NULL || szLastNum == NULL || szRstNum == NULL)
	{
		return ERR;
	}

	iFirstLen = strlen(szFirstNum);
	iLastLen = strlen(szLastNum);

	iMaxLen = iFirstLen;
	for (i = 1; i <= iMaxLen; i++)
	{
		if (iLastLen < i)
		{
			iTmp = szFirstNum[iFirstLen - i] - iIsLow ;
		}
		else
		{
			iTmp = szFirstNum[iFirstLen - i] - szLastNum[iLastLen - i] + '0' - iIsLow;
		}
		
		if (iTmp < '0')
		{
			szRstNum[iMaxLen - i] = iTmp + 10;
			iIsLow = 1;
		}
		else
		{
			szRstNum[iMaxLen - i] = iTmp;
			iIsLow = 0;
		}
	}
	return OK;
}

int SuperSubEx(char szFirstNum[], char szLastNum[], char szRstNum[], char *pcSign)
{
	int iFirstLen;
	int iLastLen;
	int i;

	if (szFirstNum == NULL || szLastNum == NULL || szRstNum == NULL)
	{
		return ERR;
	}

	iFirstLen = strlen(szFirstNum);
	iLastLen = strlen(szLastNum);

	*pcSign = NUM_ZERO;

	if (iFirstLen > iLastLen)
	{
		*pcSign = NUM_PLUS;
		return SuperSub(szFirstNum, szLastNum, szRstNum);		
	}
	else if (iFirstLen < iLastLen)
	{
		*pcSign = NUM_SUB;
		return SuperSub(szLastNum, szFirstNum, szRstNum);				
	}
	else
	{
		for (i = 0; i < iFirstLen; i++)
		{
			if (szFirstNum[i] > szLastNum[i])
			{
				*pcSign = NUM_PLUS;
				return SuperSub(szFirstNum, szLastNum, szRstNum);
			}
			else if (szFirstNum[i] < szLastNum[i])
			{
				return SuperSub(szLastNum, szFirstNum, szRstNum);
			}
		}
	}

	szRstNum[0] = '0';
	return OK;

}

int CheckParam(int argc, char* argv[])
{
	if (argc != 4)
	{
		return ERR;
	}

	return OK;
}



void usage()
{
	return;
}

void PrintNum(char szNum[], char cSign)
{
	int index = 0;
	
	while (szNum[index] == '0')
	{
		index++;
	}
	if (cSign == NUM_SUB)
	{
		printf("-");
	}
	printf("%s\n", szNum+index);
}
//��Ҫ��������ǰ���� 0 �����
int _tmain(int argc, char* argv[])
{
	char szRstNum[NUM_MAX_SIZE] = {0};
	char cSign = NUM_PLUS;

	if (CheckParam(argc, argv) != OK)
	{
		usage();
		return OK;
	}

	switch (*argv[2])
	{
		case '+':
			SuperAdd(argv[1], argv[3], szRstNum);
			break;
		case '-':
			SuperSubEx(argv[1], argv[3], szRstNum, &cSign);
			//printf("cSign:%d\n", cSign);
			break;
		case '*':
		case '/':
		default:
			return OK;
	}

	PrintNum(szRstNum, cSign);
	return 0;
}

