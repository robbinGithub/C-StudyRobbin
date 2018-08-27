#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
//#include <netinet/in.h>

int main(){

	//��ʼ��һ��socket����
	int st = socket(AF_INET, SOCK_STREAM, 0); //��ʼ��socket
	int on = 1;
	if (setsockopt(st, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) == -1)
	{
		printf("setsockopt failed %s\n", strerror(errno));
		return EXIT_FAILURE;
	}

	struct sockaddr_in addr;//����һ��IP��ַ�ṹ
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;//��addr�ṹ�����Զ�λΪTCP/IP��ַ
	addr.sin_port = htons(8081);//�������ֽ�˳��ת��Ϊ�����ֽ�˳��
	addr.sin_addr.s_addr = htonl(INADDR_ANY);//INADDR_ANY�������server�����еĵ�ַ

	//��IP��server�����
	if (bind(st, (struct sockaddr *) &addr, sizeof(addr)) == -1)
	{
		printf("bind failed %s\n", strerror(errno));
		return EXIT_FAILURE;
	}

	//server�˿�ʼlisten��
	if (listen(st, 20) == -1)
	{
		printf("listen failed %s\n", strerror(errno));
		return EXIT_FAILURE;
	}
	char s[1024];
	int client_st = 0; //client��socket
	//socklen_t len = 0;
	struct sockaddr_in client_addr;//��ʾclient�˵�IP��ַ
	//void *p = &client_addr;
	int i;
	for (i = 0; i < 5; i++)
	{
		memset(&client_addr, 0, sizeof(client_addr));
		socklen_t len = sizeof(client_addr);
		//accept��������ֱ���пͻ������ӹ�����accept����client��socket������
		client_st = accept(st, (struct sockaddr *)&client_addr, &len);
		if (client_st == -1)
		{
			printf("accept failed %s\n", strerror(errno));
			return EXIT_FAILURE;
		}

		printf("accept by %s\n", inet_ntoa(client_addr.sin_addr));
		while (1)
		{   
			//��������
			memset(s, 0, sizeof(s));
			int rc = recv(client_st, s, sizeof(s), 0);//recv���������ã�
			if (rc > 0)//��������client����Ϣ
			{
				printf("revc is %s\n", s);
				memset(s, 0, sizeof(s));
				read(STDIN_FILENO, s, sizeof(s));
				//��������
				send(client_st, s, strlen(s), 0);
			}
			else
			{
				if (rc == 0)
				{
					printf("client socket closed\n");
				}
				else
					printf("recv failed %s\n", strerror(errno));
				break;
			}
		}
		close(client_st);//�ر�client��socket
	}
	close(st); 
	return  EXIT_SUCCESS;
}