#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE 40

void my_write(int fd,const char *buf,int len)
{
      int ret = 0;
      
      while(1){
	    if( (ret = write(fd,buf+ret,len)) < 0){
		  perror("write");
		  exit(1);
	    }else if(ret == len)
		  break;
	    else{
		  len -= len-ret;
	    }
      }
}

int main(int argc,char **argv)
{
      int read_fd,write_fd;
      char buf[SIZE];
      int ret;

      if(argc != 3){
	    fprintf(stderr,"Usage:%s <src_pathname> <des_pathname>\n",argv[0]);
	    exit(1);
      }
      //打开文件
      if((read_fd = open(argv[1],O_RDONLY)) < 0){
	    perror("fopen");
	    exit(1);
      }
      if((write_fd = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0644)) < 0){
	    perror("fopen");
	    exit(1);
      }
      //拷贝文件
      while(1){
	    bzero(buf,SIZE);
	    if((ret = read(read_fd,buf,SIZE)) < 0){
		  perror("read");
		  exit(1);
	    }else if(ret == 0)
		  break;
	    else{
		  my_write(write_fd,buf,strlen(buf));
		  printf("%s",buf);
	    }
      }
      //关闭文件
      close(read_fd);
      return 0;
}
