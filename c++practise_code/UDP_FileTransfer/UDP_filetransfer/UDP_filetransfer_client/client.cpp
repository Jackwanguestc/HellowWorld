/*************************************************************************
> File Name: client.c

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
struct RecvPack
{
	PackInfo head;
	char buf[BUFFER_SIZE];
} data;


void main()
{


	//�����׽��ֿ�
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
	SOCKET sockClient = socket(AF_INET, SOCK_DGRAM, 0);

	SOCKADDR_IN addrSrv;
	char IP_addr[15];
	printf("Please Input Server IP:");
	scanf("%s", IP_addr);
	addrSrv.sin_addr.S_un.S_addr = inet_addr(IP_addr);//127.0.0.1
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);
	int addrLen = sizeof(SOCKADDR);
	while (true)
	{
		/* �����ļ����������� */
		char file_name[FILE_NAME_MAX_SIZE + 1];
		memset(file_name, 0, FILE_NAME_MAX_SIZE + 1);
		printf("Please Input File Name On Server: ");
		scanf("%s", file_name);

		char buffer[BUFFER_SIZE];
		memset(buffer, 0, BUFFER_SIZE);
		strncpy(buffer, file_name, strlen(file_name) > BUFFER_SIZE ? BUFFER_SIZE : strlen(file_name));

		/* �����ļ��� */
		if (sendto(sockClient, buffer, BUFFER_SIZE, 0, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)) < 0)
		{
			perror("Send File Name Failed:");
			exit(1);
		}

		/* ���ļ���׼��д�� */
		FILE *fp = fopen(file_name, "wb");
		if (NULL == fp)
		{
			printf("File:\t%s Can Not Open To Write\n", file_name);
			exit(1);
		}

		/* �ӷ������������ݣ���д���ļ� */
		int id = 1;
		int datalen = 0;
		int iter = 0;
		
		while (datalen = recvfrom(sockClient, (char*)&data, sizeof(data), 0, (SOCKADDR*)&addrSrv, &addrLen) > 0)
		{
			++iter;
			printf("iter:%d ", iter);
			PackInfo pack_info;
			printf("receive pack:%d \n", data.head.id);
			//if (strcmp(data.buf,"quit") == 0)
			//{
			//	printf("file receive over\n");
			//	break;
			//}
			if (data.head.id == id)
			{
				printf("data.head.id:%d = id:%d ", data.head.id, id);
				pack_info.id = data.head.id;
				pack_info.buf_size = data.head.buf_size;
				++id;
				/* �������ݰ�ȷ����Ϣ */
				if (sendto(sockClient, (char*)&pack_info, sizeof(pack_info), 0, (SOCKADDR*)&addrSrv, addrLen) < 0)
				{
					printf("Send confirm information failed!");
					sendto(sockClient, (char*)&pack_info, sizeof(pack_info), 0, (SOCKADDR*)&addrSrv, addrLen);
				}
				else
				{
					printf("receive success\n");
					/* д���ļ� */
					if (fwrite(data.buf, sizeof(char), data.head.buf_size, fp) < data.head.buf_size)
					{
						printf("File:\t%s Write Failed\n", file_name);
						break;
					}
					else
					{
						printf("write pack%d \n", data.head.id, data.buf, data.head.buf_size);
					}
				}
			}
			else if (data.head.id < id) /* ������ط��İ� */
			{
				printf("data.head.id:%d < id:%d", data.head.id, id);
				pack_info.id = data.head.id;
				pack_info.buf_size = data.head.buf_size;
				/* �ط����ݰ�ȷ����Ϣ */
				if (sendto(sockClient, (char*)&pack_info, sizeof(pack_info), 0, (SOCKADDR*)&addrSrv, addrLen) < 0)
				{
					printf("Send confirm information failed!");
				}
			}
			else
			{
				printf("data.head.id:%d > id:%d \n", data.head.id, id);
				break;
			}
		}
		printf("Receive File:\t%s From Server IP Successful!\n", file_name);
		fclose(fp);
		continue;
	}
	closesocket(sockClient);
	WSACleanup();
}