#include "net.h"

int main(int argc,char **argv)
{
      int sock_fd;
      struct sockaddr_in s_in;
      //1.创建套接字
      if((sock_fd = socket(AF_INET,SOCK_STREAM,0)) < 0){
	    perror("socket");
	    exit(1);
      }
      //2.初始化服务器地址
      bzero(&s_in,sizeof(s_in));
      s_in.sin_family = AF_INET;
      if(argc != 3){
      s_in.sin_port = htons(PORT);
      s_in.sin_addr.s_addr = inet_addr(SRV_IP);
      }else{
	    unsigned short port = atoi(argv[1]);
	    s_in.sin_port = htons(port);
	    s_in.sin_addr.s_addr = inet_addr(argv[2]);
      }
      //3.发送链接请求,connect会使当前进程阻塞，直到建立链接为止
      if(connect(sock_fd,(struct sockaddr*)&s_in,sizeof(s_in))< 0){
	    perror("accept");
	    exit(1);
      }
      //4.通信
      send(sock_fd,"heloworld",strlen("heloworld"),0);
      sleep(1);
      send(sock_fd,"farsight",strlen("farsight"),0);
      sleep(1);
      send(sock_fd,"mymsgoob_test",strlen("mymsgoob_test"),MSG_OOB);
      sleep(1);
      send(sock_fd,"abcdefg",strlen("abcdefg"),0);
      //5.关闭
      close(sock_fd);
      return 0;
}
