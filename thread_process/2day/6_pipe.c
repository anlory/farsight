#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define SIZE 40
int main(void)
{
      int fd[2];
      pid_t pid;
      char buf[SIZE];

      //创建管道
      if(pipe(fd) < 0){
	    perror("pipe");
	    exit(1);
      }
      printf("pid = %d\n",getpid()); 
      //创建子进程
      if((pid = fork()) < 0){
	    perror("fork");
	    exit(1);
      }else if(pid > 0){ //父进程
	    close(fd[0]);
	    while(1){
		  bzero(buf,SIZE);
		  fgets(buf,SIZE,stdin);
		  write(fd[1],buf,strlen(buf)); //向管道中写数据
		  if(strncmp(buf,"quit",4) == 0)
			break;
	    }
      }else{  //子进程
	    close(fd[1]);
	    while(1){
		  bzero(buf,SIZE);
		  read(fd[0],buf,SIZE);  //从管道中读数据
		  if(strncmp(buf,"quit",4) == 0)
			break;
		  printf("(%d)%s",getpid(),buf);
	    }
      }
      wait(NULL);
      return 0;
}
