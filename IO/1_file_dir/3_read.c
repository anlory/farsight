#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE 40

int main(int argc,char **argv)
{
      int fd;
      char buf[SIZE];
      int ret;

      if(argc != 2){
	    fprintf(stderr,"Usage:%s <pathname>\n",argv[0]);
	    exit(1);
      }
      //打开文件
      if((fd = open(argv[1],O_RDONLY|O_CREAT,0644)) < 0){
	    perror("fopen");
	    exit(1);
      }
      //读文件
      while(1){
	    bzero(buf,SIZE);
	    if((ret = read(fd,buf,SIZE)) < 0){
		  perror("read");
		  exit(1);
	    }else if(ret == 0)
		  break;
	    else{
		  printf("%s",buf);
	    }
      }
      //关闭文件
      close(fd);
      return 0;
}
