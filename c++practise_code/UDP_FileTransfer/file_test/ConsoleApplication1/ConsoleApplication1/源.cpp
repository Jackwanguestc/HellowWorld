#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define SERVER_PORT 6000 
#define BUFFER_SIZE 1025
#define FILE_NAME_MAX_SIZE 512 

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

int main()
{
	char file_name[FILE_NAME_MAX_SIZE + 1];
	//memset(file_name, 0, FILE_NAME_MAX_SIZE + 1);
	//strncpy(file_name, buffer, strlen(buffer)>FILE_NAME_MAX_SIZE ? FILE_NAME_MAX_SIZE : strlen(buffer));
	int filenum = 0;
	SendPack data;
	while (1)
	{
		printf("please input filename:");
		scanf_s("%s", file_name, FILE_NAME_MAX_SIZE);
		if ('q' == file_name[0])
		{
			break;
		}
		printf("filename:%s\n", file_name);
		++filenum;
		printf("open file:%d\n", filenum);
		/* 打开文件 */
		errno_t err; FILE *fp;
		err = fopen_s(&fp,file_name, "rb");
		if (NULL == fp)
		{
			printf("File:%s Not Found.\n", file_name);
			continue;
		}
		//write file
		//char write_file[sizeof(filenum) + 1];
		errno_t err1; FILE *fp_w; errno_t err2;
		//err2 = _itoa_s(filenum, write_file, 10);
		char write_file[6] = "2.bmp";
		err1 = fopen_s(&fp_w, "2.bmp", "wb");
		if (NULL == fp)
		{
			printf("File:\t%s Can Not Open To Write\n", write_file);
			exit(1);
		}
		/* 发送id */
		int send_id = 0;

		/* 接收id */
		int receive_id = 0;

		int iter = 0;
		/* 每读取一段数据，便将其发给客户端 */
		int dataLen = 0;
		PackInfo pack_info = {1,1024};
		while ((dataLen = fread(data.buf, sizeof(char), BUFFER_SIZE, fp))>0)
		{
			++iter;
			printf("iter:%d\n", iter);
			if (receive_id == send_id)
			{
				printf("receive_id == send_id\n");
				++send_id;//包编号
					data.head.id = send_id; /* 发送id放进包头,用于标记顺序 */
					data.head.buf_size = dataLen;
					fwrite(data.buf, sizeof(char), data.head.buf_size, fp_w);
					printf("pack_num:%d\n", send_id);
					receive_id = send_id;
			}
			else if (receive_id < send_id)
			{
				printf("receive_id%d < send_id%d\n", receive_id, send_id);
				send_id = receive_id;
				++send_id;//包编号
				dataLen = fread(data.buf, sizeof(char), BUFFER_SIZE, fp);
				data.head.id = send_id; /* 发送id放进包头,用于标记顺序 */
				data.head.buf_size = dataLen;
				fwrite(data.buf, sizeof(char), data.head.buf_size, fp_w);
				printf("pack_num:%d\n", send_id);
				receive_id = send_id;
			}
			else
			{
				printf("receive_id%d > send_id%d\n", receive_id, send_id);
			}   
		}
		printf("file end\n");
		fclose(fp);
		printf("File:%s read Successful!\n", file_name);

		printf("file %s write over\n", write_file);
		fclose(fp_w);
		continue;
	}
	return 0;
}