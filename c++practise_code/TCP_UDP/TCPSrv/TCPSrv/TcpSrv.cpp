#include <Winsock2.h>
#include <stdio.h>

void main()
{
	//加载套接字
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
	//创建用于监听的套接字
	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);
	//绑定套接字
	bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
	//将套接字设为监听模式，准备接受客户请求
	listen(sockSrv, 5);

	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);
	
	
	
		SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrClient, &len);
	while (1)
	{
		//等待客户请求
		
		//if (inet_ntoa(addrClient.sin_addr) == "127.0.0.1")
		//	continue;
		char sendBuf[100];
		sprintf(sendBuf, "Welcome %s\n ",
			inet_ntoa(addrClient.sin_addr));
		//数据
		char recvBuf[100];
		recv(sockConn, recvBuf, 100, 0);
		if ('q' == recvBuf[0])
		{
			sendto(sockConn, "q", strlen("q") + 1, 0, (SOCKADDR*)&addrClient, len);
			printf("Chat end!\n");
			break;
		}
		char tempBuf[200];
		sprintf(tempBuf, "%s say : %s", inet_ntoa(addrClient.sin_addr), recvBuf);
		printf("%s\n", tempBuf);
		printf("Sever say:\n");
		gets(sendBuf);
		send(sockConn, sendBuf, strlen(sendBuf) + 1, 0);
	}
	closesocket(sockSrv);
	WSACleanup();
	}
