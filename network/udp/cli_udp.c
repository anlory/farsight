#include "net.h"

int main(int argc,char **argv)
{
      int sock_fd;
      struct sockaddr_in sin;

      //创建socket
      if((sock_fd = socket(AF_INET,SOCK_DGRAM,0)) < 0){
	    perror("socket");
	    exit(1);
      }

      //填充服务器地址
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
      //绑定地址和端口
      if(bind(sock_fd,(struct sockaddr*)&sin,sizeof(sin)) < 0){
	    perror("bind");
	    exit(1);
      }
#endif 
      //与客户端进行通信
      char buf[SIZE];
      while(1){
	    bzero(buf,SIZE);
	    fgets(buf,SIZE,stdin);
	    if(sendto(sock_fd,buf,strlen(buf),0,(struct sockaddr*)&sin,sizeof(sin)) < 0){
	    perror("recvfrom");
	    exit(1);
	    }
	    if(strncmp(buf,"quit",4) == 0)
		  break;
      }
      shutdown(sock_fd,2);
      return 0;
}
