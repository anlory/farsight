#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(void)
{
      int fd,newfd;
      fd = open("1.txt",O_RDWR|O_CREAT,0644);
      newfd = open("2.txt",O_RDWR|O_CREAT,0644);
      write(fd,"hello",5);
      //newfd = dup(fd); //复制文件描述符
      dup2(fd,newfd);
      write(newfd,"world",5);
      close(fd);
      close(newfd);
      return 0;
}
