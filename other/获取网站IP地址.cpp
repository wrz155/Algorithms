// GetIpAddr.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
	1,ͨ������window ��̬���ӿ��ȡ
		#pragma comment(lib, "ws2_32")

		WSADATA

		WSAStartup();

		WSACleanup()

		Gethostbyname()

		�ڵ����κ�Winsock����֮ǰ�������ȵ���WSAStartup����
		
	2,ͨ��window�����л�ȡ
		Ping �����ܻ�ȡ��IP
		ִ��ping����
		��ȡping������
		���������ȡIP

*/
#include "stdafx.h"
#include<windows.h>
#include<winsock.h>
#include<stdlib.h>
#include<filesystem>

#define OK 0
#define ERR -1
#define IP_BUF_LEN 16
#define CMD_LINE_LEN 64
#pragma comment(lib, "ws2_32")
/*
	��������
	���ܣ�
	����ֵ��
	������
	��Σ�szHost
	���Σ�szIp
*/
int GetIpBySock(char szHost[], char szIp[])
{
	int iRet;
	WSADATA   stWsa;
	HOSTENT  *pHost = NULL;

	if (szHost == NULL || szIp == NULL)
	{
		return ERR;
	}
	//0x0101 ��ʾ�汾�� 1.1��0x0102 2.1,
	iRet = WSAStartup(0x0101, &stWsa);
	if (iRet != OK)
	{
		return ERR;
	}
	
	pHost = gethostbyname(szHost);
	if (pHost == NULL)
	{
		return ERR;
	}
	
	_snprintf(szIp, IP_BUF_LEN - 1, "%d.%d.%d.%d",
		pHost->h_addr_list[0][0] & 0xff,
		pHost->h_addr_list[0][1] & 0xff,
		pHost->h_addr_list[0][2] & 0xff,
		pHost->h_addr_list[0][3] & 0xff);

	WSACleanup();

	return OK;
}

int GetIpByCmd(char szHost[], char szIp[])
{
	char szFileName[] = "ipTmp";
	char szCmd[CMD_LINE_LEN] = { 0 };
	FILE *pFile = NULL;
	int cTmp;
	int iHit = 0;
	int iOffset = 0;

	if (szHost == NULL || szIp == NULL)
	{
		return ERR;
	}

	_snprintf(szCmd, CMD_LINE_LEN - 1, "ping %s -n 1> %s", szHost, szFileName);
	//system��ʵ�Ͼ��ǵ������ǵ�window����
	system(szCmd);
	pFile = fopen(szFileName, "r");
	if (pFile == NULL)
	{
		return ERR;
	}

	while ((cTmp = fgetc(pFile)) != EOF)
	{
		//ע��ǿ��ת��
		if (iHit == 1)
		{
			if ((char)cTmp == ']')
			{
				break;
			}
			*(szIp + iOffset) = (char)cTmp;
			iOffset++;
		}
		else if ((char)cTmp == '[')
		{
			iHit = 1;
		}

	}
	unlink(szFileName);
	fclose(pFile);
	return OK;
}

void usage(char szProjName[])
{
	printf("\t�÷���\n\t\t  %s HostName\n", szProjName);
}

int _tmain(int argc, _TCHAR* argv[])
{
	char szIpAddr[IP_BUF_LEN] = { 0 };
	if (argc != 2)
	{
		usage(argv[0]);
		return OK;
	}

	//GetIpBySock(argv[1], szIpAddr);
	GetIpByCmd(argv[1], szIpAddr);
	printf("Host:%s\n", argv[1]);
	printf("Ip:%s\n", szIpAddr);
	system("pause");
	return 0;
}

