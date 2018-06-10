#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc,char **argv)
{
      int fd;
      int len;
      if(argc != 2){
	    fprintf(stderr,"Usage:%s <pathname>\n",argv[0]);
	    exit(1);
      }
      //打开文件
      if((fd = open(argv[1],O_WRONLY|O_CREAT,0644)) < 0){
	    perror("fopen");
	    exit(1);
      }
      //创建空洞文件
      printf("请输入文件大小:");
      scanf("%d",&len);
      lseek(fd,len-3,SEEK_SET);
      write(fd,"end",3);
      //关闭文件
      close(fd);
      return 0;
}
