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

	//初始化一个socket连接
	int st = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addr; //定义一个IP地址结构
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;//将addr结构的属性定位为TCP/IP地址
	addr.sin_port = htons(8081);//将本地字节顺序转化为网络字节顺序。
	addr.sin_addr.s_addr = inet_addr("192.168.137.2");//INADDR_ANY代表这个server上所有的地址192.168.137.2
   
	//建立连接
	if (connect(st, (struct sockaddr*)&addr, sizeof(addr)))
	{
		printf("connect failed %s\n", strerror(errno));
		return EXIT_FAILURE;
	}
	char s[1024];
	while (1)
	{ 
		//发送数据
		memset(s, 0, sizeof(s));
		read(STDIN_FILENO, s, sizeof(s));//从键盘读取用户输入stdin_fileno
		if (send(st, s, strlen(s), 0) == -1) //发送buf的数据
		{
			printf("send failed %s\n", strerror(errno));
			return EXIT_FAILURE;
		}
		//接收数据
		memset(s, 0, sizeof(s));
		if (recv(st, s, sizeof(s), 0) > 0)//如果接收数据失败，循环break
			printf("recv %s\n", s);
		else
			break;
	}
	return  0;

}