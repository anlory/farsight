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

      if(argc != 2){
	    fprintf(stderr,"Usage:%s <pathname>\n",argv[0]);
	    exit(1);
      }
      //打开文件
      if((fd = open(argv[1],O_RDONLY|O_CREAT,0644)) < 0){
	    perror("fopen");
	    exit(1);
      }
      bzero(buf,SIZE);
      lseek(fd,3,SEEK_SET);
      read(fd,buf,SIZE);
      printf("%s",buf);
      //关闭文件
      close(fd);
      return 0;
}
