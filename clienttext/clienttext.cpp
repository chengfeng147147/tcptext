#include<stdio.h>
#include<winsock2.h>
#include<stdlib.h>

#pragma comment(lib,"ws2_32.lib")

int main()
{

	WSADATA wsaDATA;
	WSAStartup(MAKEWORD(2, 2), &wsaDATA);

	SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	sockaddr_in  sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));

	sockAddr.sin_family = PF_INET;
	sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	sockAddr.sin_port = htons(1234);
	connect(sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
	
	//���ܷ��������ص����ݣ�
	char szBuffer[MAXBYTE] = { 0 };
	recv(sock, szBuffer, MAXBYTE, NULL);
	//������յ�������
	printf("Message form server: %s\n", szBuffer);

	//�ر��׽���
	closesocket(sock);

	//��ֹʹ�� DLL
	WSACleanup();

	system("pause");
	return 0;

}