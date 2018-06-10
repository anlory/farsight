#include "net.h"

int main(int argc,char **argv)
{
	int sock_fd;
	int ret = -1;
	struct sockaddr_in sin;
	char buf[BUFSIZ];
	/*创建socket*/
	if( (sock_fd = socket(AF_INET,SOCK_STREAM,0)) < 0)
		err("socket");

	/*填充网络地址*/
	bzero(&sin,sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORT);
	sin.sin_addr.s_addr = inet_addr(SRV_IP);

	if(connect(sock_fd,(struct sockaddr*)&sin,sizeof(sin)) < 0)
	{
		err("connect");
	}

	/*通过链接套接字和客户端进行通信*/
#if 0
	int fd;
	fd = open("1.txt",O_WRONLY|O_CREAT,0644);
	bzero(buf,BUFSIZ);
	while(1)
	{
		ret = read(sock_fd,buf,BUFSIZ);
		if(ret < 0)
			exit(1);
		else if(ret == 0)
			break;
		write(fd,buf,strlen(buf));
	}

#else
	do
	{
		bzero(buf,BUFSIZ);
		fgets(buf,BUFSIZ,stdin);
		write(sock_fd,buf,strlen(buf));

	}while(strncmp(buf,"quit",4) != 0);
#endif
	close(sock_fd);
	return 0;
}
