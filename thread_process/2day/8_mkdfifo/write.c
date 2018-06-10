#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE 40
int main(int argc,char **argv)
{
      int fd;
      char buf[SIZE];

      if(argc != 2){
	    fprintf(stderr,"Usage:%s <fifoname>\n",argv[0]);
	    exit(1);
      }
      if((fd = open(argv[1],O_WRONLY)) < 0){
	    perror("open");
	    exit(1);
      }
      while(1){
	    bzero(buf,SIZE);
	    fgets(buf,SIZE,stdin);
	    write(fd,buf,strlen(buf)); //向管道中写数据
	    if(strncmp(buf,"quit",4) == 0)
		  break;
      }
      return 0;
}
