#include "net.h"

int main(int argc, char **argv)
{
      int sock_fd,conn_fd;
      struct sockaddr_in sin,cin;
      //创建套接字
      if( (sock_fd = socket(AF_INET,SOCK_STREAM,0)) < 0){
	    perror("socket");
	    exit(1);
      }

      //填充地址
      bzero(&sin,sizeof(sin));
      sin.sin_family = AF_INET;
      if(argc != 3){
	    sin.sin_port = htons(8888);
	    sin.sin_addr.s_addr = inet_addr("192.168.7.5");
      }else{
	    sin.sin_port = htons(atoi(argv[1]));
	    sin.sin_addr.s_addr = inet_addr(argv[2]);
      }

      //绑定地址
      if(bind(sock_fd,(struct sockaddr*)&sin,sizeof(sin)) < 0){
	    perror("bind");
	    exit(1);
      }
      //监听套接字
      if(listen(sock_fd,8) < 0){
	    perror("listen");
	    exit(1);
      }
      //等待接收链接,使进程阻塞，直到有新的客户端请求链接为止
      bzero(&cin,sizeof(cin));
      socklen_t len = sizeof(cin);
      printf("listen....\n");
      if( (conn_fd = accept(sock_fd,(struct sockaddr*)&cin,&len)) < 0){
	    perror("accept");
	    exit(1);
      }
      printf("客户端%s链接成功!\n",inet_ntoa(cin.sin_addr));
      //和客户端进行通信
      char buf[SIZE];
      int ret;
      //将链接套接字改为非阻塞状态
      fcntl(conn_fd,F_SETFL,O_NONBLOCK);
      while(1){
	    bzero(buf,SIZE);
	    if( (ret = read(conn_fd,buf,SIZE)) < 0){
		  perror("read");
		  //exit(1);
	    }
	    if( ret == 0){
		  printf("客户端已断开\n");
		  break;
	    }

	    {
		  if(strncmp(buf,"quit",4) == 0)
			break;
		  printf("%s",buf);
	    }
	    sleep(1);
      }

      close(sock_fd);
      close(conn_fd);
      return 0;
}
