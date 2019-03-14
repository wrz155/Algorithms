/*
2017/10/5
	�ɺ���	server.sin_addr.s_addr = inet_addr(Ip); //ָ����ɨ���IP��ַ
	�º���	inet_pton(AF_INET, Ip, &server.sin_addr); //����ʹ�����º���
ʹ���º�����Ҫ���ͷ�ļ�
	#include <Ws2tcpip.h>

*/


#include <stdio.h>
#include <WinSock2.h>
#include <Ws2tcpip.h>
#pragma comment(lib, "Ws2_32")


int scan(char *Ip, int StartPort, int EndPort)
{
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);  //ʹ��winsock����֮ǰ��������WSAStartup������װ�벢��ʼ����̬���ӿ�

	struct sockaddr_in server;
	server.sin_family = AF_INET;  //ָ����ַ��ʽ����winsock��ֻ��ʹ��AF_INET
	inet_pton(AF_INET, Ip, &server.sin_addr);   //ָ����ɨ���IP��ַ
	
	for (int CurrPort = StartPort; CurrPort <= EndPort; CurrPort++)
	{
		SOCKET s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
		server.sin_port = htons(CurrPort); //ָ����ɨ��IP��ַ�Ķ˿ں�
		int ret = connect(s, (struct sockaddr *)&server, sizeof(server)); //����

		if (0 == ret) //�ж������Ƿ�ɹ�
		{
			printf("%s:%d Success O(��_��)O\n", Ip, CurrPort);
			closesocket(s);
		}
		else {
			printf("%s:%d Failed\n", Ip, CurrPort);
		}
	}

	WSACleanup();  //�ͷŶ�̬���ӿⲢ�ͷű��������׽���
	return 1;
}

int main_test()
{
	scan("127.0.0.1", 9999, 10001);

	getchar();
	return 0;
}
