#include <Winsock2.h>
#include <stdio.h>

void main()
{
	//加载套接字库
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(1, 1);

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		return;
	}


	if (LOBYTE(wsaData.wVersion) != 1 ||
		HIBYTE(wsaData.wVersion) != 1) {
		WSACleanup();
		return;
	}
	//创建套接字
	SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = inet_addr("192.168.1.20");//127.0.0.1
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);
	//发送链接请求
	connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	//接受数据
	int len = sizeof(SOCKADDR);

	while (1)
	{
		printf("client say:\n");
		char sendBuf[100];
		gets(sendBuf);
		send(sockClient, sendBuf, strlen(sendBuf) + 1, 0);
		char recvBuf[100];
		recv(sockClient, recvBuf, 100, 0);
		if ('q' == recvBuf[0])
		{
			sendto(sockClient, "q", strlen("q") + 1, 0,
				(SOCKADDR*)&addrSrv, len);
			printf("Chat end!\n");
			break;
		}
		char tempBuf[200];
		sprintf(tempBuf, "%s say : %s", inet_ntoa(addrSrv.sin_addr), recvBuf);
		printf("%s\n", tempBuf);

	}
	closesocket(sockClient);
	WSACleanup();
	system("pause");
}