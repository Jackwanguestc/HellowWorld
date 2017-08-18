/*************************************************************************
> File Name: server.cpp

************************************************************************/
#include <Winsock2.h>
#include <stdio.h>
#include <string.h> 

#define SERVER_PORT 6000 
#define BUFFER_SIZE 1024
#define FILE_NAME_MAX_SIZE 512 

/* 包头 */
typedef struct
{
	int id;
	int buf_size;
}PackInfo;

/* 接收包 */
struct SendPack
{
	PackInfo head;
	char buf[BUFFER_SIZE];
} data;


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
	//创建套接字
	SOCKET sockSrv = socket(AF_INET, SOCK_DGRAM, 0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);
	//绑定套接字
	bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
	/* 定义一个地址，用于捕获客户端地址 */

	/* 数据传输 */

	SOCKADDR_IN addrClient;
	int addrLen = sizeof(SOCKADDR);
	while (true)
	{
		/* 接收数据 */
		char buffer[BUFFER_SIZE];
		memset(buffer, 0, BUFFER_SIZE);
		if (recvfrom(sockSrv, buffer, BUFFER_SIZE, 0, (SOCKADDR*)&addrClient, &addrLen) == -1)
		{
			perror("Receive Data Failed:");
			exit(1);
		}

		/* 从buffer中拷贝出file_name */
		char file_name[FILE_NAME_MAX_SIZE + 1];
		memset(file_name, 0, FILE_NAME_MAX_SIZE + 1);
		strncpy(file_name, buffer, strlen(buffer) > FILE_NAME_MAX_SIZE ? FILE_NAME_MAX_SIZE : strlen(buffer));
		printf("%s\n", file_name);
		/* 打开文件 */
		FILE *fp = fopen(file_name, "rb");
		if (NULL == fp)
		{
			printf("File:%s Not Found.\n", file_name);
			break;
		}

		/* 发送id */
		int send_id = 0;
		int iter = 0;
		/* 接收id */
		int receive_id = 0;

		int dataLen = 0;
        PackInfo pack_info;
		/* 每读取一段数据，便将其发给客户端 */
		while (dataLen = fread(data.buf, sizeof(char), BUFFER_SIZE, fp) > 0)
		{
			++iter;
			printf("iter:%d", iter);
			if (receive_id == send_id)
			{
				++send_id;//包编号
				data.head.id = send_id; /* 发送id放进包头,用于标记顺序 */
				data.head.buf_size = sizeof(data.buf); /* 记录数据长度 */
				if (sendto(sockSrv, (char*)&data, sizeof(data), 0, (SOCKADDR*)&addrClient, addrLen) < 0)
				{
					perror("Send File Failed:");
					//break;
				}
				else
				{
					printf("send pack:%d ,data.head.buf_size %d ", send_id, data.head.buf_size);
					/* 接收确认消息 */
					recvfrom(sockSrv, (char*)&pack_info, sizeof(pack_info), 0, (SOCKADDR*)&addrClient, &addrLen);
					printf("pack_num:%d \n", pack_info.id);
					receive_id = pack_info.id;
				}
			}
			else
			{
				printf("receive_id != send_id");
				/* 如果接收的id和发送的id不相同,重新发送 */
				if (sendto(sockSrv, (char*)&data, sizeof(data), 0, (SOCKADDR*)&addrClient, addrLen) < 0)
				{
					perror("Send File Failed:");
					//break;
				}
				/* 接收确认消息 */
				recvfrom(sockSrv, (char*)&pack_info, sizeof(pack_info), 0, (SOCKADDR*)&addrClient, &addrLen);
				receive_id = pack_info.id;
				printf("pack_num:%d \n", pack_info.id);
			}
		}
		/* 关闭文件 */
		fclose(fp);
		printf("File:%s Transfer Successful!\n", file_name);
		sendto(sockSrv, NULL, 0, 0, (SOCKADDR*)&addrClient, addrLen);
		continue;
	}
	closesocket(sockSrv);
	WSACleanup();
}