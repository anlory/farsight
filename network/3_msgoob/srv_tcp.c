#include "net.h"

int sock_fd,conn_fd;
void fun(int signo)
{
      char str[4];
      bzero(str,4);
      recv(conn_fd,str,4,MSG_OOB);
      printf("%s\n",str);
}
int main(int argc,char **argv)
{
      struct sockaddr_in s_in,c_in;
      int ret;
      //1.创建套接字
      if((sock_fd = socket(AF_INET,SOCK_STREAM,0)) < 0){
	    perror("socket");
	    exit(1);
      }
      //2.初始化本地地址
      bzero(&s_in,sizeof(s_in));
      s_in.sin_family = AF_INET;
      if(argc != 3){
	    s_in.sin_port = htons(PORT);
	    //s_in.sin_addr.s_addr = inet_addr(SRV_IP); //指定IP地址
	    s_in.sin_addr.s_addr = htonl(INADDR_ANY);//系统自动识别IP

      }else{
	    unsigned short port = atoi(argv[1]);
	    s_in.sin_port = htons(port);
	    s_in.sin_addr.s_addr = inet_addr(argv[2]);
      }
      //3.绑定本地地址
      if(bind(sock_fd,(struct sockaddr*)&s_in,sizeof(s_in)) < 0){
	    perror("bind");
	    exit(1);
      }
      //4.监听
      if(listen(sock_fd,N) < 0){
	    perror("listen");
	    exit(1);
      }
      //5.等待客户端链接请求,accept会使当前进程阻塞，直到有新的客户端请求链接为止
      printf("耐心等待着客户端的请求中....\n");
      socklen_t len = sizeof(c_in);
      if( (conn_fd = accept(sock_fd,(struct sockaddr*)&c_in,&len)) < 0){
	    perror("accept");
	    exit(1);
      }
      strcpy(ip,inet_ntoa(c_in.sin_addr));
      printf("IP为%s的客户端成功登录....\n",ip);

      //6.通信
      signal(SIGURG,fun);
      fcntl(conn_fd,F_SETOWN,getpid());

      while(1){
	    bzero(buf,SIZE);
	    if( (ret = recv(conn_fd,buf,SIZE,0)) < 0){
		  perror("read");
		  exit(1);
	    }else if(ret == 0)
		  break;
	    else
		  printf("%s\n",buf);
      }
      //7.关闭
      close(sock_fd);
      close(conn_fd);
      return 0;
}
