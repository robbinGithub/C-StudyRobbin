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
	int st = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addr; //����һ��IP��ַ�ṹ
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;//��addr�ṹ�����Զ�λΪTCP/IP��ַ
	addr.sin_port = htons(8081);//�������ֽ�˳��ת��Ϊ�����ֽ�˳��
	addr.sin_addr.s_addr = inet_addr("192.168.137.2");//INADDR_ANY�������server�����еĵ�ַ192.168.137.2
   
	//��������
	if (connect(st, (struct sockaddr*)&addr, sizeof(addr)))
	{
		printf("connect failed %s\n", strerror(errno));
		return EXIT_FAILURE;
	}
	char s[1024];
	while (1)
	{ 
		//��������
		memset(s, 0, sizeof(s));
		read(STDIN_FILENO, s, sizeof(s));//�Ӽ��̶�ȡ�û�����stdin_fileno
		if (send(st, s, strlen(s), 0) == -1) //����buf������
		{
			printf("send failed %s\n", strerror(errno));
			return EXIT_FAILURE;
		}
		//��������
		memset(s, 0, sizeof(s));
		if (recv(st, s, sizeof(s), 0) > 0)//�����������ʧ�ܣ�ѭ��break
			printf("recv %s\n", s);
		else
			break;
	}
	return  0;

}