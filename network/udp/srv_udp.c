#include "net.h"

int main(int argc,char **argv)
{
      int sock_fd;
      struct sockaddr_in sin,cin;

      //创建socket
      if((sock_fd = socket(AF_INET,SOCK_DGRAM,0)) < 0){
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
      
      //绑定地址和端口
      if(bind(sock_fd,(struct sockaddr*)&sin,sizeof(sin)) < 0){
	    perror("bind");
	    exit(1);
      }
      
      //与客户端进行通信
      char buf[SIZE];
      int ret;
      bzero(&cin,sizeof(cin));
      socklen_t len = sizeof(cin);
      while(1){
	    bzero(buf,SIZE);
	    if( (ret = recvfrom(sock_fd,buf,SIZE,0,(struct sockaddr*)&cin,&len)) < 0){
	    perror("recvfrom");
	    exit(1);
	    }else if(ret == 0){
		  printf("客户端断开!\n");
		  break;
	    }else{
		  if(strncmp(buf,"quit",4) == 0)
			break;
		  buf[strlen(buf)-1] = '\0';
		  printf("%s from %s\n",buf,inet_ntoa(cin.sin_addr));
	    }
      }
      close(sock_fd);
      return 0;
}
