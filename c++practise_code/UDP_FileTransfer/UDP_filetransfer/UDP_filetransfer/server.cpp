/*************************************************************************
> File Name: server.cpp

************************************************************************/
#include <Winsock2.h>
#include <stdio.h>
#include <string.h> 

#define SERVER_PORT 6000 
#define BUFFER_SIZE 1024
#define FILE_NAME_MAX_SIZE 512 

/* ��ͷ */
typedef struct
{
	int id;
	int buf_size;
}PackInfo;

/* ���հ� */
struct SendPack
{
	PackInfo head;
	char buf[BUFFER_SIZE];
} data;


void main()
{


	//�����׽���
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
	//�����׽���
	SOCKET sockSrv = socket(AF_INET, SOCK_DGRAM, 0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);
	//���׽���
	bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
	/* ����һ����ַ�����ڲ���ͻ��˵�ַ */

	/* ���ݴ��� */

	SOCKADDR_IN addrClient;
	int addrLen = sizeof(SOCKADDR);
	while (true)
	{
		/* �������� */
		char buffer[BUFFER_SIZE];
		memset(buffer, 0, BUFFER_SIZE);
		if (recvfrom(sockSrv, buffer, BUFFER_SIZE, 0, (SOCKADDR*)&addrClient, &addrLen) == -1)
		{
			perror("Receive Data Failed:");
			exit(1);
		}

		/* ��buffer�п�����file_name */
		char file_name[FILE_NAME_MAX_SIZE + 1];
		memset(file_name, 0, FILE_NAME_MAX_SIZE + 1);
		strncpy(file_name, buffer, strlen(buffer) > FILE_NAME_MAX_SIZE ? FILE_NAME_MAX_SIZE : strlen(buffer));
		printf("%s\n", file_name);
		/* ���ļ� */
		FILE *fp = fopen(file_name, "rb");
		if (NULL == fp)
		{
			printf("File:%s Not Found.\n", file_name);
			break;
		}

		/* ����id */
		int send_id = 0;
		int iter = 0;
		/* ����id */
		int receive_id = 0;

		int dataLen = 0;
        PackInfo pack_info;
		/* ÿ��ȡһ�����ݣ��㽫�䷢���ͻ��� */
		while (dataLen = fread(data.buf, sizeof(char), BUFFER_SIZE, fp) > 0)
		{
			++iter;
			printf("iter:%d", iter);
			if (receive_id == send_id)
			{
				++send_id;//�����
				data.head.id = send_id; /* ����id�Ž���ͷ,���ڱ��˳�� */
				data.head.buf_size = sizeof(data.buf); /* ��¼���ݳ��� */
				if (sendto(sockSrv, (char*)&data, sizeof(data), 0, (SOCKADDR*)&addrClient, addrLen) < 0)
				{
					perror("Send File Failed:");
					//break;
				}
				else
				{
					printf("send pack:%d ,data.head.buf_size %d ", send_id, data.head.buf_size);
					/* ����ȷ����Ϣ */
					recvfrom(sockSrv, (char*)&pack_info, sizeof(pack_info), 0, (SOCKADDR*)&addrClient, &addrLen);
					printf("pack_num:%d \n", pack_info.id);
					receive_id = pack_info.id;
				}
			}
			else
			{
				printf("receive_id != send_id");
				/* ������յ�id�ͷ��͵�id����ͬ,���·��� */
				if (sendto(sockSrv, (char*)&data, sizeof(data), 0, (SOCKADDR*)&addrClient, addrLen) < 0)
				{
					perror("Send File Failed:");
					//break;
				}
				/* ����ȷ����Ϣ */
				recvfrom(sockSrv, (char*)&pack_info, sizeof(pack_info), 0, (SOCKADDR*)&addrClient, &addrLen);
				receive_id = pack_info.id;
				printf("pack_num:%d \n", pack_info.id);
			}
		}
		/* �ر��ļ� */
		fclose(fp);
		printf("File:%s Transfer Successful!\n", file_name);
		sendto(sockSrv, NULL, 0, 0, (SOCKADDR*)&addrClient, addrLen);
		continue;
	}
	closesocket(sockSrv);
	WSACleanup();
}