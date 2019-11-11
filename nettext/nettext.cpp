/* server.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<winsock2.h>

#pragma comment(lib,"ws2_32.lib")

int main(){
    //��ʼ��DLL
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	sockaddr_in sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));
	sockAddr.sin_family = PF_INET;  //ʹ��IPv4��ַ
	sockAddr.sin_addr.s_addr =inet_addr("127.0.0.1");
	sockAddr.sin_port = htons(1234);

	bind(servSock,(SOCKADDR*)&sockAddr,sizeof(SOCKADDR));

	listen(servSock, 20);

	SOCKADDR clntAddr;
	int nsize = sizeof(SOCKADDR);
	SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nsize);


	char *str = "Hello World!";
	send(clntSock, str, strlen(str) * sizeof(char), NULL);

	
	closesocket(clntSock);
	closesocket(servSock);

	WSACleanup();

	return 0;


}