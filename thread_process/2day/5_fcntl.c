#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define DEBUG

int main(int argc,char **argv)
{
      int fd;
      struct flock fl;
      char buf[40] = "helloworld\n";

      if( (fd = open(argv[1],O_WRONLY)) < 0){
	    perror("open");
	    exit(1);
      }
      //填充锁结构
      bzero(&fl,sizeof(fl));
      fl.l_type  = F_WRLCK;
      fl.l_whence  = SEEK_SET;
      fl.l_start  = 0;
      fl.l_len= 100;
#ifdef DEBUG
      //给文件上锁
      if(fcntl(fd,F_SETLKW,&fl) < 0){
	    perror("flock");
	    exit(1);
      }
#endif
      //向文件中写数据
      while(1){
	    write(fd,buf,strlen(buf));
	    printf("%s\n",buf);
	    sleep(1);
      }
#ifdef DEBUG
      //给文件上锁
      fl.l_type  = F_UNLCK;
      if(fcntl(fd,F_SETLKW,&fl) < 0){
	    perror("flock");
	    exit(1);
      }
#endif
      close(fd);

      return 0;
}

