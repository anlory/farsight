#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char **argv)
{
      int fd;

      if(argc != 2){
	    fprintf(stderr,"Usage:%s <pathname>\n",argv[0]);
	    exit(1);
      }
      //打开文件
      if((fd = open(argv[1],O_RDONLY|O_CREAT,0644)) < 0){
	    perror("fopen");
	    exit(1);
      }
      //关闭文件
      close(fd);
      return 0;
}
