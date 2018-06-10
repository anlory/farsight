#include "net.h"

int main(int argc,char **argv)
{
	int sock_fd,conn_fd;
	int ret = -1,val;
	struct sockaddr_in sin,cin;
	socklen_t len;
	char buf[BUFSIZ];
	int maxfd = -1;
	fd_set read_fds;
	struct timeval tm;
	p_node h,p;

	init_link(&h); //初始化一个新的链表

	/*创建socket*/
	if( (sock_fd = socket(AF_INET,SOCK_STREAM,0)) < 0)
		err("socket");

	/*填充网络地址*/
	bzero(&sin,sizeof(sin));
	sin.sin_family = AF_INET;
	if(argc != 3){
	      sin.sin_port = htons(PORT);
	      sin.sin_addr.s_addr = inet_addr(SRV_IP);
	}else{
	      sin.sin_port = htons(atoi(argv[1]));
	      sin.sin_addr.s_addr = inet_addr(argv[2]);
	}
	int on = 1;
	setsockopt(sock_fd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
	/*绑定地址*/
	if(bind(sock_fd,(struct sockaddr*)&sin,sizeof(sin)) < 0)
		err("bind");

	/*监听*/
	if(listen(sock_fd,N) < 0)
		err("listen");
	printf("listen...\n");
	maxfd = sock_fd;
	
	while(1)
	{
		FD_ZERO(&read_fds);  //清空文件描述符的集合
		FD_SET(sock_fd,&read_fds); //将监听套接字的文件描述符加入到集合中
		//用单向链表来存储和管理连接套接字的文件描述符
		if(!isempty(h))  
		{
			p = h->next;
			while(p != NULL)
			{
				FD_SET(p->fd,&read_fds);//将链表中的连接套接字的文件描述符加入到集合中
				p = p->next;
			}
		}
		//超时设置
		tm.tv_sec = 3;
		tm.tv_usec = 0;

		val = select(maxfd+1,&read_fds,NULL,NULL,&tm);//调用select函数对集合中的文件描述符进行监控
		if(val < 0)
		{
			err("select");
		}else if(val == 0)
		{
			printf("timeout!\n");
		//	continue;
		}
		if(FD_ISSET(sock_fd,&read_fds))
		{
			printf("new client..\n");
			len = sizeof(cin);
			conn_fd = accept(sock_fd,(struct sockaddr*)&cin,&len);
			printf("connect from %s\n",inet_ntoa(cin.sin_addr));
			insert_link(h,conn_fd);
			if(maxfd < conn_fd)
				maxfd = conn_fd;
		}
		if(!isempty(h))
		{
			p = h->next;
			while(p != NULL)
			{
				if(FD_ISSET(p->fd,&read_fds))
				{
					bzero(buf,BUFSIZ);
					ret = read(p->fd,buf,BUFSIZ);
					if(ret < 0)
					{
						err("read");
					}
					else if(ret == 0)
					{
						printf("客户端断开链接\n");
						close(p->fd);
						del_link(h,p->fd);
						break;
					}
					printf("%s",buf);

				}
				p = p->next;
			}
		}
	}
	close(sock_fd);
	return 0;
}
