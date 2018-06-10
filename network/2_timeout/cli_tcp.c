#include "net.h"

int main(int argc, char **argv)
{
      int sock_fd;
      struct sockaddr_in sin;
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
#if 0
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
      if( (conn_fd = accept(sock_fd,NULL,NULL)) < 0){
	    perror("accept");
	    exit(1);
      }
#else 
      if(connect(sock_fd,(struct sockaddr*)&sin,sizeof(sin)) < 0){
	    perror("connect");
	    exit(1);
      }
#endif

      //和客户端进行通信
      char buf[SIZE];
      while(1){
	    fgets(buf,SIZE,stdin);
	    write(sock_fd,buf,strlen(buf));
	    if(strncmp(buf,"quit",4) == 0)
		  break;
      }

      close(sock_fd);
      return 0;
}
